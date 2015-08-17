#ifndef MYUTIL_H
#define MYUTIL_H

class MyUtil
{
 public:
    static void drawTransparentRect(cv::Mat input, cv::Rect rect, cv::Scalar color, double alpha)
    {
        cv::Mat context;
        input.copyTo(context);
        cv::rectangle(context, rect, color,CV_FILLED, CV_AA, 0);
        cv::addWeighted(context, alpha, input, 1.0 - alpha , 0.0, input); 
    }
    static void drawRois(cv::Mat img, std::vector<std::vector<cv::Point > > rois, cv::Scalar color, int highLightIndex=-1, double alpha=0.4)
    {
        if(rois.size() < 1)
        {
            return;
        }
        if(img.type() == CV_8UC1)
        {        
            cv::cvtColor(img, img, CV_GRAY2BGR);
        }
        
        
        cv::drawContours(img, rois, -1, color, 2);
        
        if(highLightIndex > -1)
        {
            cv::Mat m_mask = cv::Mat::zeros(img.size(), CV_8UC3);
            cv::drawContours(m_mask, rois, highLightIndex, cv::Scalar(1, 1, 1), CV_FILLED);
            cv::multiply(m_mask, img, m_mask);
            cv::addWeighted(m_mask, alpha, img, 1.0 - alpha , 0.0, img); 
        }
        
    }

    static cv::Mat calculateKde(cv::Mat stdHis, int bandWith = 20, int a2 = 20)
    {
        cv::Mat ked_Result = cv::Mat::zeros(stdHis.rows, stdHis.cols, CV_32FC1);
        //step1 calculate Gussian curve
        cv::Mat matGussian = cv::Mat::zeros(1, bandWith, CV_32FC1);
        for(int i = 0; i< matGussian.cols; i++)
        {
            matGussian.at<float>(0,i) = bandWith/2*-1+i;
        }
        cv::pow(matGussian, 2, matGussian);
        matGussian = matGussian/2/a2;
        cv::exp(-1*matGussian, matGussian);
        matGussian = matGussian/sqrt(2*CV_PI*a2);
        //step2 transform historgam to KDE
        for(int i = 0; i < stdHis.cols; i++)
        {
            cv::Mat kde_data_roi;
            cv::Mat gussian_data_roi;
            int roi_width = 0;
            int kde_roi_org = 0;
            int gus_roi_org = 0;
            // determin Roi boundary issue
            if(i <= bandWith)
            {
               roi_width = i;
               kde_roi_org = 0;
               gus_roi_org = bandWith/2 - i/2;
            }
            else if(stdHis.cols-i+1 <= bandWith)
            {
                roi_width = stdHis.cols - i +1;
                kde_roi_org = i-2;
                gus_roi_org = bandWith/2 - (stdHis.cols-i+1)/2;
            }
            else
            {
                kde_roi_org = i-bandWith/2;
                gus_roi_org = 0;
                roi_width = bandWith;
            }
            
            //get roi and calculate pdf(KDE) in colum "i"
            kde_data_roi        = cv::Mat(ked_Result, cv::Rect(kde_roi_org, 0, roi_width, 1));
            gussian_data_roi    = cv::Mat(matGussian, cv::Rect(gus_roi_org, 0, roi_width, 1));
            kde_data_roi        = kde_data_roi + gussian_data_roi * stdHis.at<float>(0,i);
            
        
        }
        
        return ked_Result;
    }


};
#endif
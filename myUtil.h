
#ifndef MYUTIL_H
#define MYUTIL_H
#include "MainFrame.h"

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

    static cv::Mat calculateKde(cv::Mat stdHis, int Kze = 30, double normalizeConst = 1.0)
    {
        // local variable
        double sigma_sqare      = Kze;
        int bandWith            = Kze;
        cv::Mat ked_Result      = cv::Mat::zeros(stdHis.rows, stdHis.cols, CV_32FC1);
        cv::Mat matGussian      = cv::Mat::zeros(1, bandWith, CV_32FC1);
        
        //step1 calculate Gussian curve
        for(int i = 0; i< matGussian.cols; i++)
        {
            matGussian.at<float>(0,i) = bandWith/2*-1+i;
        }
        cv::pow(matGussian, 2, matGussian);
        matGussian = matGussian/2/sigma_sqare;
        cv::exp(-1*matGussian, matGussian);
        matGussian = normalizeConst*matGussian/sqrt(2*CV_PI*sigma_sqare);
        
        //step2 transform historgam to KDE
        for(int i = 0; i <= stdHis.cols; i++)
        {
            cv::Mat kde_data_roi;
            cv::Mat gussian_data_roi;
            int roi_width = 0;
            int kde_roi_org = 0;
            int gus_roi_org = 0;
            // determin Roi boundary issue
            if(i < bandWith)
            {
                continue;
               roi_width = i;
               kde_roi_org = 0;
               gus_roi_org = (bandWith - i)*0.5;
            }
            else if(stdHis.cols-i+1 <= bandWith)
            {
                continue;
                roi_width = stdHis.cols - i +1;
                kde_roi_org = stdHis.cols-i;
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

    static float getKdeMode(cv::Mat data){
        float   ret             = -1;
        float   slope           = 1;
        bool    b_slope_pos     = false;
        for(int i = 0; i < data.cols; i++)
        {
            if(i==0)
                continue;
            slope = data.at<float>(0, i) - data.at<float>(0, i-1);
            if(slope > 1)
                b_slope_pos = true;
            if(slope < -1 && b_slope_pos)
            {
                ret = i;
                break;
            }
        }
        
        
        
        return ret;
        
        
        
    }
};
#endif
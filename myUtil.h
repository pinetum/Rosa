



void drawTransparentRect(cv::Mat input, cv::Rect rect, cv::Scalar color, double alpha)
{
    cv::Mat context;
    input.copyTo(context);
    cv::rectangle(context, rect, color,CV_FILLED, CV_AA, 0);
    cv::addWeighted(context, alpha, input, 1.0 - alpha , 0.0, input); 
}
void drawRois(cv::Mat img, std::vector<std::vector<cv::Point > > rois, cv::Scalar color, int highLightIndex=-1, double alpha=0.4)
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





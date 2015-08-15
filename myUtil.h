



void drawTransparentRect(cv::Mat input, cv::Rect rect, cv::Scalar color, double alpha)
{
    cv::Mat context;
    input.copyTo(context);
    cv::rectangle(context, rect, color,CV_FILLED, CV_AA, 0);
    cv::addWeighted(context, alpha, input, 1.0 - alpha , 0.0, input); 
}
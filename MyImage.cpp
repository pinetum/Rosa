#include "MyImage.h"
#include "MainFrame.h"
#include <wx/log.h> 
#include <vector>
#include "math.h"

#define HISTORGAM_IMG_WIDTH     512
#define HISTORGAM_IMG_HEIGHT    300
#define HISTORGAM_LINE_THICKNESS 1

MyImage::MyImage()
{
	m_oralCancerKdeMode = -1;
}
MyImage::MyImage(cv::Mat mat)
{
	mat.copyTo(m_cvMat);
    m_oralCancerKdeMode = -1;
	
}
MyImage::MyImage(int w, int h, int stride, int type, uchar *pixeldata)
{
	
	m_cvMat.create(h, w, type);
	uchar* data = m_cvMat.data;
	int step = m_cvMat.step[0];
	for(int i=0; i<h; i++)
		memcpy(data + i*step, pixeldata + i*stride, step);
	
}
MyImage::~MyImage()
{
	
}



cv::Mat 	MyImage::getMatHistogram(){

	cv::Mat cvMat_HisRet(HISTORGAM_IMG_HEIGHT, HISTORGAM_IMG_WIDTH, CV_8UC3, cv::Scalar( 0,0,0) );
	int 			histSize 	= 256;// Establish the number of bins
	float 			range[] 	= { 0, 255 } ;// Set the ranges ( for B,G,R) )
	const float* 	histRange 	= { range };
	bool 			uniform 	= true; 
	bool 			accumulate 	= false;
	int 			hist_h		= cvMat_HisRet.rows;
	int 			hist_w		= cvMat_HisRet.cols;
	int 			bin_w 		= cvRound( (double) hist_w/256 );
	switch(m_cvMat.type()){
			case CV_8UC3:
			{
                std::vector<cv::Mat> bgr_planes;
                cv::split( m_cvMat, bgr_planes );
                cv::Mat b_hist, g_hist, r_hist;
                cv::calcHist( &bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
                cv::calcHist( &bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
                cv::calcHist( &bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
                cv::normalize(b_hist, b_hist, 0, cvMat_HisRet.rows, cv::NORM_MINMAX, -1, cv::Mat() );
                cv::normalize(g_hist, g_hist, 0, cvMat_HisRet.rows, cv::NORM_MINMAX, -1, cv::Mat() );
                cv::normalize(r_hist, r_hist, 0, cvMat_HisRet.rows, cv::NORM_MINMAX, -1, cv::Mat() );
                
                for( int i = 1; i < histSize; i++ )
                {
                    cv::line( cvMat_HisRet, cv::Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                                cv::Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                                cv::Scalar( 255, 0, 0), 1, CV_AA, 0  );
                    cv::line( cvMat_HisRet, cv::Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                                cv::Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                                cv::Scalar( 0, 255, 0), 1, CV_AA, 0  );
                    cv::line( cvMat_HisRet, cv::Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                                cv::Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                                cv::Scalar( 0, 0, 255), 1, CV_AA, 0  );
                }
                break;
			}
			
			case CV_8UC1:
			{
                    cv::Mat hist;
                    cv::calcHist( &m_cvMat, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange, uniform, accumulate );
                    
                    hist.convertTo(hist, CV_32F);
                    cv::transpose(hist, hist);
                    cv::Mat kde = MyUtil::calculateKde(hist);
                    
//                    double min, max;
//                    cv::minMaxLoc(hist, &min, &max);
//                    double scale = (cvMat_HisRet.rows -20)/max;
//                    hist = hist * scale;
//                    kde = kde * scale;
                    cv::normalize(hist, hist, 0, cvMat_HisRet.rows -20, cv::NORM_MINMAX, -1, cv::Mat() );
                    cv::normalize(kde, kde, 0, cvMat_HisRet.rows -20, cv::NORM_MINMAX, -1, cv::Mat() );
                    for( int i = 0; i < histSize; i++ )
                    {
                        //bins
                        int bin_x = i*cvMat_HisRet.cols/256;
                        int bin_y = cvMat_HisRet.rows - (int)floor(hist.at<float>(0, i));
                        cv::line(   cvMat_HisRet,
                                    cv::Point(bin_x, bin_y),
                                    cv::Point(bin_x, cvMat_HisRet.rows),
                                    cv::Scalar(10,128,10),
                                    cvMat_HisRet.cols/256);
                        
                        // Kde
                        if(i==0)
                            continue;
                        int x1 = (i-1)*cvMat_HisRet.cols/256;
                        int x2 = i*cvMat_HisRet.cols/256;
                        int y1 = cvMat_HisRet.rows - (int)floor(kde.at<float>(0, i-1));
                        int y2 = cvMat_HisRet.rows - (int)floor(kde.at<float>(0, i));
                        //MainFrame::showMessage(wxString::Format("%d\n",(int)floor(hist.at<float>(0, i))));
                        cv::line(cvMat_HisRet,
                                cv::Point(x1, y1),
                                cv::Point(x2, y2),
                                cv::Scalar(255,255,255),
                                HISTORGAM_LINE_THICKNESS,
                                CV_AA);
                    }
                    break;
			}
		
	}
		
	
	return cvMat_HisRet;
}
MyImage* 	MyImage::clone(){
	MyImage* pNew = new MyImage();
	pNew->m_cvMat = m_cvMat.clone();
	return pNew;
}
bool 		MyImage::readImage(wxString &pathName){
	bool bRet = false ;
	m_cvMat = cv::imread(pathName.ToStdString() , CV_LOAD_IMAGE_UNCHANGED);
	if(m_cvMat.data) bRet = true;
	if(bRet){
		int nChannel = m_cvMat.channels();
		wxString title = pathName.AfterLast('\\').AfterLast('/');
		wxString str = wxString::Format(_("readImage: %s channel %d ,w %d h %d ,step %d \n"), title, nChannel, m_cvMat.cols, m_cvMat.rows, m_cvMat.step[0]);
		MainFrame::showMessage(str);
		
	}
	else
	{
			wxLogMessage("read Image Error!");
	}
	
	return bRet;
		
}
wxString 	MyImage::getFormatString(){
	wxString strFormat;
	wxString strDepth;
	int nChannel = m_cvMat.channels();
	int nDepth = m_cvMat.depth();
	switch (nDepth) {
		case CV_8U: strDepth = "8U"; break;
		case CV_8S: strDepth = "8S"; break;
		case CV_16U: strDepth = "16U"; break;
		case CV_16S: strDepth = "16S"; break;
		case CV_32S: strDepth = "32S"; break;
		case CV_32F: strDepth = "32F"; break;
		case CV_64F: strDepth = "64F"; break;
		default: strDepth = "unknown"; break;
	}
	strFormat.Printf("%sC%d", strDepth, nChannel );
	return strFormat;
}
MyImage* 	MyImage::Gray2BGR(){
	MyImage* pNew = new MyImage();
	cv::cvtColor(m_cvMat , pNew->m_cvMat , CV_GRAY2BGR);
	return pNew;
	
}
MyImage* 	MyImage::BGR2Gray(){
	MyImage* pNew = new MyImage();
	cv::cvtColor(m_cvMat , pNew->m_cvMat , CV_BGR2GRAY);
	return pNew;
	
}
MyImage* 	MyImage::split(int nTargetCh){
		MyImage* pNew = new MyImage();
		std::vector<cv::Mat> mats_splited;
		if(m_cvMat.channels() <= nTargetCh){
			MainFrame::showMessage("Error:chanel not exist.");
			return this;
		}
		cv::split(m_cvMat, mats_splited);
		pNew->m_cvMat = mats_splited[nTargetCh];
		MainFrame::showMessage( wxString::Format("split: chanel %d", nTargetCh));
		return pNew;
	
	
}
bool 		MyImage::saveBmpImage(std::string filename){
	
	return cv::imwrite(filename,m_cvMat);
}
bool 		MyImage::saveHisBmpImage(std::string filename){
	
	return cv::imwrite(filename,getMatHistogram());
}
MyImage* 	MyImage::Threshold(int thV,bool inverse){
	
	MyImage* pNew = NULL;
	int type = getType();
	double thsValue = thV;
	if(type==CV_8UC1)
		pNew = clone();
	else if(type==CV_8UC3){
		pNew = BGR2Gray();
	}
	
	if(thV < 0 ){		//CV_THRESH_OTSU
		if(inverse)
			thsValue = cv::threshold(pNew->m_cvMat, pNew->m_cvMat, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
		else
			thsValue = cv::threshold(pNew->m_cvMat, pNew->m_cvMat, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
		
		
		
	}
	else{				//threshold by input value
		if(inverse)
			cv::threshold(pNew->m_cvMat, pNew->m_cvMat, thV, 255, CV_THRESH_BINARY_INV);
		else
			cv::threshold(pNew->m_cvMat, pNew->m_cvMat, thV, 255, CV_THRESH_BINARY);
	}
		
	
	MainFrame::showMessage(wxString::Format(_("Threshold: value = %.3f \n") , thsValue));
	return pNew;
}
MyImage* 	MyImage::HoughCircles(){
	
	MyImage* pNew;
	int type = getType();
	if(type==CV_8UC1)
		pNew = clone();
	else if(type==CV_8UC3){
		pNew = BGR2Gray();
	}
	else{
		wxLogMessage("not Support");
		pNew = clone();
		return pNew;
	}
	std::vector<cv::Vec3f> circles;
	//cv::HoughCircles( pNew->m_cvMat, circles, CV_HOUGH_GRADIENT, 1, pNew->m_cvMat.rows/8, 200, 50, 2, 30 );
    /*cv::HoughCircles(pNew->m_cvMat, circles, CV_HOUGH_GRADIENT,1, 10,
						100, 30, 1,40 // change the last two parameters
										// (min_radius & max_radius) to detect larger circles
						);*/
	 cv::HoughCircles(pNew->m_cvMat, circles, CV_HOUGH_GRADIENT,1, 6,
						120, 30, 1,40 // change the last two parameters
										// (min_radius & max_radius) to detect larger circles
						);
	pNew->Gray2BGR();
	for( size_t i = 0; i < circles.size(); i++ )
    {
         cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
         int radius = cvRound(circles[i][2]);
         // draw the circle center
         cv::circle( pNew->m_cvMat, center, 3, cv::Scalar(255,0,0), 1, 8, 0 );
         // draw the circle outline
         cv::circle( pNew->m_cvMat, center, radius, cv::Scalar(255,0,0), 3, 8, 0 );
    }
	wxLogMessage(wxString::Format("find circles : %d",circles.size()));
	return pNew;
}
MyImage* 	MyImage::medianBlur(int k_size){
	MyImage* pNew;
	pNew = clone();
	cv::medianBlur(pNew->m_cvMat,pNew->m_cvMat,k_size);
	MainFrame::showMessage(wxString::Format(_("MedianBlur: k_size = %d \n") , k_size));
	
	return pNew;
	
	
}





MyImage* 	MyImage::faceDetection(){
    //http://docs.opencv.org/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html

    wxString face_cascade_name = "obj_det_xml//haarcascade_frontalface_alt.xml";
    wxString mouth_cascade_name = "obj_det_xml//haarcascade_mcs_mouth.xml";
    cv::CascadeClassifier face_cascade;
    cv::CascadeClassifier mouth_cascade;
    MyImage* pNew;
    pNew = clone();
    cv::Mat src_gray;
    int type = getType();
    if(type==CV_8UC1)
        src_gray = m_cvMat.clone();
    else if(type==CV_8UC3){
        src_gray = BGR2Gray()->m_cvMat;
    }
    else{
        wxLogMessage("not Support");
        return pNew;
    }

    if( !face_cascade.load( face_cascade_name.ToStdString() ) ){ wxLogMessage("--(!)Error loading\n"); return pNew; };
    if( !mouth_cascade.load( mouth_cascade_name.ToStdString() ) ){ wxLogMessage("--(!)Error loading\n"); return pNew; };


    //轉灰階完成
    std::vector<cv::Rect> faces;
    cv::equalizeHist( src_gray, src_gray );
    face_cascade.detectMultiScale( src_gray, faces, 1.1, 1, 0, cv::Size(30, 30) );


    for (size_t i = 0 ;i < faces.size(); i++) {
        cv::rectangle(
            pNew->m_cvMat,
            cv::Point(faces[i].x,faces[i].y),
            cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
            CV_RGB(255, 0, 0),
            1);
        //只看臉的下半部
        faces[i].y = faces[i].y + faces[i].height/2;
        faces[i].height = faces[i].height /2;
        cv::rectangle(
            pNew->m_cvMat,
            cv::Point(faces[i].x,faces[i].y),
            cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
            CV_RGB(0, 0, 255),
            1);
        cv::Mat faceROI = pNew->m_cvMat( faces[i] );
        //cv::imshow("a" + i ,faceROI);
        std::vector<cv::Rect> mouth;
        //-- In each face, detect mouth
        mouth_cascade.detectMultiScale( faceROI, mouth, 1.1, 2, 0 , cv::Size(faces[i].width/4, faces[i].height/5),cv::Size(faces[i].width/2, faces[i].height/3) );
        //---text-----MainFrame::showMessage(wxString::Format(_("Find face ------------\n") , mouth.size()));
        for( size_t j = 0; j < mouth.size(); j++ ){
            cv::Mat mouthROI = faceROI( mouth[j] );
            
            //cv::imshow("mouth" + j ,mouthROI);
            //---text-----MainFrame::showMessage(wxString::Format(_(" mouth  %d - size : w %d h %d\n") , j, mouth[j].width, mouth[j].height ));
            cv::rectangle(
            faceROI,
            cv::Point(mouth[j].x, mouth[j].y),
            cv::Point(mouth[j].x + mouth[j].width, mouth[j].y + mouth[j].height),
            CV_RGB(0, 255, 0),
            1);

            cv::putText(mouthROI,
                        std::string(wxString::Format(_("%d"),j)),
                        cv::Point(0, mouthROI.rows-5),
                        cv::FONT_HERSHEY_SIMPLEX,
                        0.3,
                        cv::Scalar ( 255, 255,  255),
                        1,
                        8,
                        false);
		}
		
	}

	return pNew;
	
}
MyImage* 	MyImage::mouthDetection(){
	MyImage* pNew;
	pNew = clone();
	return pNew;
}
MyImage* 	MyImage::resize(cv::Size size){
	MyImage* pNew;
	pNew = clone();
	cv::resize(pNew->m_cvMat,pNew->m_cvMat,size);
	return pNew;
}
MyImage* 	MyImage::resize(double zoom){
	MyImage* pNew;
	pNew = clone();
	cv::resize(pNew->m_cvMat,pNew->m_cvMat,cv::Size(0, 0), zoom, zoom);
	return pNew;
}

cv::Mat MyImage::getContourHistorgam(std::vector<cv::Point > contour)
{
    int bandWidh = 20;
    int a2 = bandWidh;
    cv::Mat his_bin = cv::Mat::zeros(1, 256, CV_32FC1);
    cv::Mat points = cv::Mat(1, 1, CV_32FC1);
    cv::Mat matGussian = cv::Mat::zeros(1, bandWidh, CV_32FC1);
    //calculate gussian
    for(int i = 0; i< matGussian.cols; i++)
    {
        matGussian.at<float>(0,i) = bandWidh/2*-1+i;
    }
    cv::pow(matGussian, 2, matGussian);
    matGussian = matGussian/2/a2;
    cv::exp(-1*matGussian, matGussian);
    matGussian = matGussian/sqrt(2*M_PI*a2);
//    FILE* fp_g = fopen("gussian.txt","w");
//    for(int i = 0; i< matGussian.cols; i++)
//    {
//        fprintf(fp_g, "%f\n", matGussian.at<float>(0,i));
//    }
//    fclose(fp_g);
    for(int j = 0; j < m_cvMat.rows-10; j++ )
    {   
        for(int i = 0; i < m_cvMat.cols-10; i++ )
        {
            //判斷是不是在ROI之內
            if(cv::pointPolygonTest(contour, cv::Point(i, j), false) > 0 )
            {
                int v = (int)m_cvMat.at<uchar>(j, i);
                his_bin.at<float>(0, v)+=1;
            }
        }
    }


    cv::Mat ked_Result = MyUtil::calculateKde(his_bin);
    m_oralCancerKdeMode = (int)MyUtil::getKdeMode(ked_Result);
    
    cv::Mat retHis = cv::Mat::zeros(HISTORGAM_IMG_HEIGHT, HISTORGAM_IMG_WIDTH, CV_8UC3);
   
    
//    double min, max;
//    cv::minMaxLoc(his_bin, &min, &max);
//    double scale = (retHis.rows -20)/max;
//    his_bin = his_bin * scale;
//    ked_Result = ked_Result * scale;
    //
    cv::normalize(his_bin, his_bin, 0, retHis.rows-20, cv::NORM_MINMAX, -1, cv::Mat() );
    cv::normalize(ked_Result, ked_Result, 0, retHis.rows-20, cv::NORM_MINMAX, -1, cv::Mat() );

//    FILE* fpHis = fopen("his.txt", "w");
//    FILE* fpKde = fopen("kde.txt", "w");


    // drawing kde and historgam bin
    for(int i = 0; i<256; i++)
    {
        //bins
        int bin_x = i*retHis.cols/256;
        int bin_y = retHis.rows - (int)floor(his_bin.at<float>(0, i));
        //fprintf(fpHis, "%d\n", (int)floor(his_bin.at<float>(0, i) ));
        //fprintf(fpKde, "%d\n", (int)floor(ked_Result.at<float>(0,i)));
        cv::line(   retHis,
                    cv::Point(bin_x, bin_y),
                    cv::Point(bin_x, retHis.rows),
                    cv::Scalar(10,128,10),
                    retHis.cols/256);
        
        // Kde
        if(i==0)
            continue;
        int x1 = (i-1)*retHis.cols/256;
        int x2 = i*retHis.cols/256;
        int y1 = retHis.rows - (int)floor(ked_Result.at<float>(0, i-1));
        int y2 = retHis.rows - (int)floor(ked_Result.at<float>(0, i));
        cv::line(retHis,
                cv::Point(x1, y1),
                cv::Point(x2, y2),
                cv::Scalar(255,255,255),
                HISTORGAM_LINE_THICKNESS,
                CV_AA);
        
    }
    //fclose(fpHis);
    //fclose(fpKde);
    return retHis;
}
int MyImage::getOralCancerMode()
{
    return m_oralCancerKdeMode;
}
MyImage* MyImage::meanShift(int *x, int* y){
    double dBandwidth_k = 10;
    
    
    
    
	MyImage* pNew;
	pNew = clone();
    cv::Mat mDataMat = pNew->m_cvMat;
    
	return pNew;
}
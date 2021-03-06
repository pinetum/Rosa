#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <opencv2/opencv.hpp>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <string>

#define ORAL_IMG_NADH_BLUE    true
#define ORAL_IMG_FAD_GREEN    false


class MyImage
{
public:
	MyImage();
	MyImage(cv::Mat mat);
	MyImage(int w, int h, int stride, int type, uchar *pixeldata);
	~MyImage();
	int m_oralCancerKdeMode;
	MyImage* clone();
	bool readImage(wxString &pathName);
	bool saveBmpImage(std::string filename);
	bool saveHisBmpImage(std::string filename);
	cv::Size getSize(){return cv::Size(m_cvMat.cols, m_cvMat.rows);}
    wxString title;
	int getImgWidth(){return m_cvMat.cols;}
	int getImgHeight() { return m_cvMat.rows; }
	int getType() { return m_cvMat.type(); }
	int getChannel() { return m_cvMat.channels(); }
	int getStep() { return m_cvMat.step[0]; }
	uchar* getPixelAddr() { return m_cvMat.data; }
	cv::Mat getMat(){ return m_cvMat;}
	cv::Mat& getMatRef() { return m_cvMat; }
	cv::Mat getMatHistogram();
	cv::Mat getContourHistorgam(std::vector<cv::Point > contour);
    cv::Mat getGaborKernel( bool realPart, 
                            cv::Size ksize, 
                            double sigma, 
                            double theta, 
                            double lambd, 
                            double gamma, 
                            double psi = CV_PI*0.5, 
                            int ktype = CV_64F);
    
    cv::Mat* getMatAddr() { return &m_cvMat; }
	wxString getFormatString();
	template <class T>
	void getPixelValue(wxPoint pt, T& v) { v = m_cvMat.at<T>(pt.y, pt.x);}
	
    
	MyImage* Gray2BGR();
	MyImage* BGR2Gray();
	MyImage* Threshold(int thV,bool inverse);
	MyImage* HoughCircles();
	MyImage* medianBlur(int k_size);
	MyImage* faceDetection();
	MyImage* mouthDetection();
	MyImage* resize(cv::Size size);
    MyImage* resize(double zoom);
	MyImage* split(int nTargetCh);
    MyImage* getRedoxOral(cv::Mat inputAnother, bool AnotherType, int median_k_sz);
    MyImage* gaborFilter(   bool realPart, 
                            int ksz=43, 
                            double sigma=3, 
                            double theta=12, 
                            double lambd=36, 
                            double gamma=0.2, 
                            double psi=CV_PI*0.5);
    MyImage* meanShift(int *x, int* y);
    int getOralCancerMode();
private:
	cv::Mat m_cvMat;
};

#endif // MYIMAGE_H

#ifndef HIGHDMEANSHIFT_H
#define HIGHDMEANSHIFT_H
#include <opencv2/opencv.hpp>
class highDMeanShift
{
public:
	highDMeanShift(int d, int n_items);
	~highDMeanShift();
	void cal();
	void 		base2DMS();
	void 		AdativeMeanShift();
	int 		m_nDimensions;
	cv::Mat 	m_matData;
	
	
	
};

#endif // HIGHDMEANSHIFT_H

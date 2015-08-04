#include "highDMeanShift.h"
#include "MainFrame.h"
#include <stdio.h>
#include <math.h>
highDMeanShift::highDMeanShift(int d, int n_items)
{
	//m_nDimensions = d;
	//m_matData.Create(n_items, m_nDimensions, CV_64FC1, cv::Scalar::all(0));
}

highDMeanShift::~highDMeanShift()
{
}

void highDMeanShift::cal(){
	
}

void highDMeanShift::AdativeMeanShift(){
	
	
}


void highDMeanShift::base2DMS(){
	char* 		fileName 	= "featurePoint_XY.csv"; // csv file name
	FILE*		fp 			= fopen(fileName, "r"); //oopen file
	cv::Mat   matData	(765, 765, CV_8UC1, cv::Scalar(0)); // 3 
	cv::Mat	mat2show;		// rgb copy
	//readFile to matData
	if(fp==NULL)
	{
		MainFrame::showMessage(_("file open error :") + wxString(fileName, wxConvUTF8));
		return;
	}
    MainFrame::showMessage("start to read");
	while(!feof(fp)){
		int d2,d3;
		int n = fscanf(fp,"%d,%d", &d2, &d3);
		if(n != 2)
			MainFrame::showMessage(wxString::Format("fscanf error :n not equal to 2 = %d",n));
        //matData.at<char>(255 - d3, d2) = 255;
		else
        cv::circle(matData, cv::Point(d2*3, (255 - d3)*3), 1, cv::Scalar(255), -1 ); // 8UC1 scalar
	}
	cv::imwrite("input.jpg", matData);
	fclose(fp);
	
	//make rgb copy
	cv::cvtColor(matData, mat2show, CV_GRAY2BGR);
	cv::imshow("data",mat2show);
    

	 int h = 30;
    for (int x = 0; x<matData.cols; x++)
    {
        for(int y = 0; y<matData.rows; y++)
        {
            // get all data point
            if(matData.at<char>(x, y) != -1)
                continue;
           // MainFrame::showMessage(wxString::Format("%d,%d=%d\n", x, y, matData.at<char>(x, y)));
            for(int rect_x = x-h/2; rect_x<x+h/2; rect_x++)
            {
                for(int rect_y = y-h/2; rect_y<y+h/2; rect_y++)
                {
                    if(matData.at<char>(rect_x, rect_y) != -1)
                        continue;
                    // get neighbor point
                }
            }
                
        }
        
    }
}
#include "MLP.h"
#include <wx/textfile.h>
MLP::MLP(wxString FileName)
{
    str_errorMsg = "None";
}

MLP::~MLP()
{
    
}
wxString MLP::getErrorMessage()
{
    return str_errorMsg;
}
bool MLP::train()
{
    bool b_ret = true;
    if(m_data.cols < 1 || m_data.rows < 1)
    {
        str_errorMsg = "data matrix is empty....";
        return false;
    }
    
//    cv::Mat m = cv::Mat::ones(4, 3, CV_64F);    // 3 cols, 4 rows
//cv::Mat row = cv::Mat::ones(1, 3, CV_64F);  // 3 cols
//m.push_back(row);                       
    
    return b_ret;
}
void MLP::dataScale()
{
    
}
bool MLP::writeModule()
{
    
}
bool MLP::readModule()
{
    
}
double MLP::getAccuracy()
{
    double d_acc = 0;
    return d_acc;
}
void MLP::readMat(wxString inputName, cv::Mat data)
{
    
}
void MLP::writeMat(wxString outputName, cv::Mat data)
{
    
}
void MLP::openFile(wxString fileName){
    wxString    str_buffer = "";
    wxTextFile  tfile;
    tfile.Open(fileName);
    str_buffer = tfile.GetFirstLine();
    readDataLine(str_buffer);
    while(!tfile.Eof())
    {
        str_buffer = tfile.GetNextLine();
        readDataLine(str_buffer); // placeholder, do whatever you want with the string
    }

}
void MLP::readDataLine(wxString line)
{
    
}
#ifndef MLP_H
#define MLP_H
#include <opencv2/opencv.hpp>
#include <wx/string.h>
#include <wx/thread.h>
#include <wx/event.h> 
class MLP: public wxThreadHelper
{
public:
    MLP();
    ~MLP();
    bool train();
    bool writeModule();
    bool readModule();
    wxString getErrorMessage();
    double getAccuracy();
    void openSampleFile(wxString fileName);
    
    
    void dumpTrainData(wxString fileName){writeMat(fileName, &m_data_Train);}
    
    
private:
    wxString    str_errorMsg;
    cv::Mat     m_data_Train;
    cv::Mat     m_weight;
    void dataScale();
    void readMat(wxString inputName, cv::Mat* data);
    void writeMat(wxString outputName, cv::Mat* data);

    void readDataLine(cv::Mat* data, wxString line);
protected:
    virtual wxThread::ExitCode Entry();
    wxCriticalSection m_dataCS;
};
#endif // MLP_H

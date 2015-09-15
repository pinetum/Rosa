#ifndef MLP_H
#define MLP_H
#include <opencv2/opencv.hpp>
#include <wx/string.h>
class MLP
{
public:
    MLP(wxString FileName);
    ~MLP();
    bool train();
    bool writeModule();
    bool readModule();
    wxString getErrorMessage();
    double getAccuracy();
private:
    wxString    str_errorMsg;
    cv::Mat     m_data_Train;
    cv::Mat     m_weight;
    void dataScale();
    void readMat(wxString inputName, cv::Mat data);
    void writeMat(wxString outputName, cv::Mat data);
    void openFile(wxString fileName);
    void readDataLine(wxString line);
};

#endif // MLP_H

#ifndef CMYPLOTWIN_H
#define CMYPLOTWIN_H
#include "wxcrafter.h"
#include <vector>
class CMyPlotWin : public CMyPlotWinBase
{
public:
    CMyPlotWin(wxWindow* parent);
    virtual ~CMyPlotWin();
    void draw3dLine(std::vector<double > x, std::vector<double > y, std::vector<double > z);
    void draw3dSurface(std::vector<double > x, std::vector<double > y, std::vector<double > z);
    
    
    
protected:
#if wxUSE_WEBVIEW
    virtual void OnWebViewLoaded(wxWebViewEvent& event);
#endif // wxUSE_WEBVIEW
};
#endif // CMYPLOTWIN_H

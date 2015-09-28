#ifndef CMYPLOTWIN_H
#define CMYPLOTWIN_H
#include "wxcrafter.h"

class CMyPlotWin : public CMyPlotWinBase
{
public:
    CMyPlotWin(wxWindow* parent);
    virtual ~CMyPlotWin();
    void loadJsFile(wxString jsFilePath);
protected:
#if wxUSE_WEBVIEW
    virtual void OnWebViewLoaded(wxWebViewEvent& event);
#endif // wxUSE_WEBVIEW
};
#endif // CMYPLOTWIN_H

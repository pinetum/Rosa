#include "CMyPlotWin.h"
#include <wx/textfile.h>



CMyPlotWin::CMyPlotWin(wxWindow* parent)
    : CMyPlotWinBase(parent)
{
    SetSize(400, 400);
    m_webView->SetPage("<body><div id=\"mygraph\"></div><div id=\"info\">info Div</div></body>", "./");
   



     //m_webView->LoadURL("http://www.youtube.com/");
}

CMyPlotWin::~CMyPlotWin()
{
}
void CMyPlotWin::loadJsFile(wxString jsFilePath)
{
    wxTextFile t_visJs;
    t_visJs.Open(jsFilePath);
    wxString jsBuffer = t_visJs.GetFirstLine();
    while(t_visJs.Eof())
    {
        jsBuffer.Append(t_visJs.GetNextLine());
    }
    t_visJs.Close();
    m_webView->RunScript(jsBuffer);
}
#if wxUSE_WEBVIEW
void CMyPlotWin::OnWebViewLoaded(wxWebViewEvent& event)
{
     loadJsFile("./js/vis.js");
    loadJsFile("./js/test.js");
    m_webView->RunScript("drawVisualization();");
}
#endif // wxUSE_WEBVIEW

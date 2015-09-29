#include "CMyPlotWin.h"
#include <wx/textfile.h>

#define PATH_HTML   "file:///Users/Pinetum/coding/Rosa/myplot/plot.html"
#define PATH_JS     "/Users/Pinetum/coding/Rosa/myplot/js/test.js"


CMyPlotWin::CMyPlotWin(wxWindow* parent)
    : CMyPlotWinBase(parent)
{
    SetSize(600, 600);
}

CMyPlotWin::~CMyPlotWin()
{
}
void CMyPlotWin::draw3dLine(std::vector<double > x, std::vector<double > y, std::vector<double > z)
{
    if(x.size() != y.size())
        return;
    if(z.size() != y.size())
        return;
        
    wxTextFile tf;
    tf.Open(PATH_JS);
    tf.Clear();
    tf.AddLine("var data = null;var graph = null;");
    tf.AddLine("function drawVisualization() {\
    data = new vis.DataSet();"
    );
    //datas
    for(int i = 0; i< x.size(); i++)
    {
        wxString dataLine = wxString::Format("data.add({x:%f,y:%f,z:%f});", x[i], y[i], z[i]);
        tf.AddLine(dataLine);
    
    }
    //options
    tf.AddLine("var options = {\
        width:  '600px',\
        height: '600px',\
        style: 'line',\
        showPerspective: false,\
        showGrid: true,\
        keepAspectRatio: true,\
        verticalRatio: 0.5\
        };");
      
      // create our graph
    tf.AddLine("var container = document.getElementById('mygraph');\
    graph = new vis.Graph3d(container, data, options);\
    graph.setCameraPosition(1.0, undefined, undefined);\
    graph.redraw();}");
    tf.Write();
    tf.Close();
    m_webView->LoadURL(PATH_HTML);
    Show();
}
void CMyPlotWin::draw3dSurface(std::vector<double > x, std::vector<double > y, std::vector<double > z)
{
    if(x.size() != y.size())
        return;
    if(z.size() != y.size())
        return;
        
    wxTextFile tf;
    tf.Open(PATH_JS);
    tf.Clear();
    tf.AddLine("var data = null;var graph = null;");
    tf.AddLine("function drawVisualization() {\
    data = new vis.DataSet();"
    );
    //datas
    for(int i = 0; i< x.size(); i++)
    {
        wxString dataLine = wxString::Format("data.add({id:%d,x:%f,y:%f,z:%f, style:%f});", i, x[i], y[i], z[i], z[i]);
        tf.AddLine(dataLine);
    }
    //options
    tf.AddLine("var options = {\
        width:  '600px',\
        height: '600px',\
        style: 'surface',\
        showPerspective: true,\
        showGrid: true,\
        showShadow: false,\
        keepAspectRatio: true,\
        verticalRatio: 0.5\
        };");
      
      // create our graph
    tf.AddLine("var container = document.getElementById('mygraph');\
    graph = new vis.Graph3d(container, data, options);\
    }");
    tf.Write();
    tf.Close();
    m_webView->LoadURL(PATH_HTML);
    Show();
}


#if wxUSE_WEBVIEW
void CMyPlotWin::OnWebViewLoaded(wxWebViewEvent& event)
{

}
#endif // wxUSE_WEBVIEW

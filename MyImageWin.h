#ifndef MYIMAGEWIN_H
#define MYIMAGEWIN_H

#include <wx/scrolwin.h> // Base class: wxScrolledWindow
#include <wx/string.h>
#include <wx/msgdlg.h>
#include <opencv2/opencv.hpp>
#include <wx/dc.h>
class MyImageWin : public wxScrolledWindow
{
public:
MyImageWin(wxWindow *parent, wxWindowID id = -1,
 const wxPoint &pos=wxDefaultPosition,
 const wxSize &size=wxDefaultSize, 
 long style=wxHSCROLL|wxVSCROLL);
	~MyImageWin();
	
	wxBitmap* m_pBitmap;
	wxSize setImage(cv::Mat mat);
	void OnDraw(wxDC& dc);

};

#endif // MYIMAGEWIN_H

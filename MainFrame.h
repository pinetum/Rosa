#ifndef MAINFRAME_H
#define MAINFRAME_H

#define ROI_RECT_SIZE 15
#include "MyImageWin.h"
#include "MyImage.h"
//#include "gnuplot_i.hpp"
#include "wxcrafter.h"

#include <deque>

class MainFrame : public MainFrameBaseClass
{
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();
	static void showMessage(wxString msg);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnDropFile(wxDropFilesEvent& event);
	void openFile(wxString &pathName);
	void DeleteContents();
	void addNewImageState(MyImage* plmg);
	void UpdateView();
	MyImage* getCurrentImg();
	//Gnuplot g1;
	
	
protected:
    virtual void OnMenuItemResizeFitWindow(wxCommandEvent& event);
    virtual void OnMenuItemResizeManual(wxCommandEvent& event);
    virtual void OnItemDestroyWindowClose(wxCommandEvent& event);
    virtual void OnMeanShiftBase(wxCommandEvent& event);
    virtual void OnGnuplotSample(wxCommandEvent& event);
    virtual void OnMenuItemSplit(wxCommandEvent& event);
   
    virtual void OnImageFindFace(wxCommandEvent& event);
    virtual void OnImageFindMouth(wxCommandEvent& event);
    virtual void OnUpdateSaveAs(wxUpdateUIEvent& event);
    virtual void OnUpdateImageFunction(wxUpdateUIEvent& event);
    virtual void OnSaveAsFile(wxCommandEvent& event);
    virtual void OnImageMedianBlur(wxCommandEvent& event);
    virtual void OnImageThresholdOtsu(wxCommandEvent& event);
    virtual void OnImageConnectComponents(wxCommandEvent& event);
    virtual void OnImageFindCircles(wxCommandEvent& event);
    virtual void OnImageThreshold(wxCommandEvent& event);
    virtual void OnUpdateItemRedo(wxUpdateUIEvent& event);
    virtual void OnUpdateItemUndo(wxUpdateUIEvent& event);
    virtual void OnMouseMotion(wxMouseEvent& event);
    virtual void OnMenuItemRedo(wxCommandEvent& event);
    virtual void OnMenuItemUndo(wxCommandEvent& event);
    virtual void OnOpenFile(wxCommandEvent& event);
	static MainFrame * m_pThis;
	std::deque<MyImage*> m_imgList;
	int m_nCurrentImg;
	wxString m_Filename;
};
#endif // MAINFRAME_H

#ifndef MAINFRAME_H
#define MAINFRAME_H

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
    void loadCancerRoi(wxString filePath);
    void loadNormalRoi(wxString filePath);
	MyImage* getCurrentImg();
	//Gnuplot g1;
	
	
protected:
    virtual void OnColorChangeCancer(wxColourPickerEvent& event);
    virtual void OnColorChangeNormal(wxColourPickerEvent& event);
    virtual void OnMouseLeaveScrollWinHis(wxMouseEvent& event);
    virtual void OnUpdateCheckBoxRoiCancer(wxUpdateUIEvent& event);
    virtual void OnUpdateCheckBoxRoiNormal(wxUpdateUIEvent& event);
    virtual void OnCheckBoxCheckRoi(wxCommandEvent& event);
    virtual void updateHistorgamAndDrawFilter(wxMouseEvent& event);
    virtual void OnSliderChangeFilterWidth(wxScrollEvent& event);
    
    virtual void OnMenuClickLoadOralCancerRois(wxCommandEvent& event);
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
    int m_nFilterWidth;
	wxString m_strFileName;
    wxString m_strFileFolder;
    std::vector<std::vector<cv::Point > > m_rois_cancer;
    std::vector<std::vector<cv::Point > > m_rois_normal;
    cv::Scalar m_c_roi_cancer;
    cv::Scalar m_c_roi_normal;
};
#endif // MAINFRAME_H

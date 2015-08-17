//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODING_ROSA_WXCRAFTER_BASE_CLASSES_H
#define CODING_ROSA_WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include "MyImageWin.h"
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/clrpicker.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/slider.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class MainFrameBaseClass : public wxFrame
{
public:
    enum {
        wxID_RESIZE_FIT_WINDOW = 1001,
        wxID_SAVE_AS = 1002,
    };
protected:
    MyImageWin* m_scrollWin;
    wxStaticText* m_staticTextCancerRoiCount;
    wxCheckBox* m_checkBoxCancerRoi;
    wxColourPickerCtrl* m_colourPickerCancerRoi;
    wxStaticText* m_staticTextNormalRoiCount;
    wxCheckBox* m_checkBoxNormalRoi;
    wxColourPickerCtrl* m_colourPickerNormalRoi;
    wxStaticLine* m_staticLine74;
    wxPanel* m_mainPanel;
    wxRichTextCtrl* m_richTextCtrl;
    wxStaticText* m_staticTextSlideValue;
    wxSlider* m_sliderFilterWidth;
    MyImageWin* m_scrollWinHis;
    wxMenuBar* m_menuBar;
    wxMenu* m_nenuFile;
    wxMenuItem* m_menuItemOpenFile;
    wxMenuItem* m_menuItemSaveAsFile;
    wxMenuItem* m_menuItemExit;
    wxMenu* m_nenuHelp;
    wxMenuItem* m_menuItem9;
    wxMenu* m_menuEdit;
    wxMenuItem* m_menuItemUndo;
    wxMenuItem* m_menuItemRedo;
    wxMenuItem* m_menuItemDestroyAllWindow;
    wxMenu* m_menuImage;
    wxMenu* m_menuFind;
    wxMenuItem* m_menuItemFindFace;
    wxMenuItem* m_menuItemFindMouth;
    wxMenuItem* m_menuImageFindCircles;
    wxMenu* m_menuResize;
    wxMenuItem* m_menuItemResizeFitWindow;
    wxMenuItem* m_menuItemResizeManual;
    wxMenuItem* m_menuImageThreshold;
    wxMenuItem* m_menuImageThresholdOtsu;
    wxMenuItem* m_menuImageConnectComponents;
    wxMenuItem* m_menuItemMedianBlur;
    wxMenuItem* m_menuItemSplitChnl;
    wxMenu* m_menu_gnuEtc;
    wxMenuItem* m_menuPlot1;
    wxMenu* m_menu104;
    wxMenuItem* m_menuItemMSBase;
    wxMenu* m_menuOralCancer;
    wxMenuItem* m_menuItemLoadRois;
    wxToolBar* m_mainToolbar;
    wxStatusBar* m_statusBar;

protected:
    virtual void OnMouseMotion(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMouseLeftUp(wxMouseEvent& event) { event.Skip(); }
    virtual void UpdateUITextRoiCount(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnCheckBoxCheckRoi(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateCheckBoxRoiCancer(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnColorChangeCancer(wxColourPickerEvent& event) { event.Skip(); }
    virtual void OnUpdateCheckBoxRoiNormal(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnColorChangeNormal(wxColourPickerEvent& event) { event.Skip(); }
    virtual void UpdateUISliderText(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnUpdateUISliderFilterWidth(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnSliderChangeFilterWidth(wxScrollEvent& event) { event.Skip(); }
    virtual void OnMouseMotionScrollWinHistorgam(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMouseLeaveScrollWinHis(wxMouseEvent& event) { event.Skip(); }
    virtual void OnScrollWinHisLineUp(wxScrollWinEvent& event) { event.Skip(); }
    virtual void OnScrollWinHisLineDown(wxScrollWinEvent& event) { event.Skip(); }
    virtual void OnOpenFile(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveAsFile(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateSaveAs(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnExit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMenuItemUndo(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateItemUndo(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnMenuItemRedo(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateItemRedo(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnItemDestroyWindowClose(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateImageFunction(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnImageFindFace(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImageFindMouth(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImageFindCircles(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMenuItemResizeFitWindow(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMenuItemResizeManual(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImageThreshold(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImageThresholdOtsu(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImageConnectComponents(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImageMedianBlur(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMenuItemSplit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnGnuplotSample(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMeanShiftBase(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMenuClickLoadOralCancerRois(wxCommandEvent& event) { event.Skip(); }

public:
    MyImageWin* GetScrollWin() { return m_scrollWin; }
    wxStaticText* GetStaticTextCancerRoiCount() { return m_staticTextCancerRoiCount; }
    wxCheckBox* GetCheckBoxCancerRoi() { return m_checkBoxCancerRoi; }
    wxColourPickerCtrl* GetColourPickerCancerRoi() { return m_colourPickerCancerRoi; }
    wxStaticText* GetStaticTextNormalRoiCount() { return m_staticTextNormalRoiCount; }
    wxCheckBox* GetCheckBoxNormalRoi() { return m_checkBoxNormalRoi; }
    wxColourPickerCtrl* GetColourPickerNormalRoi() { return m_colourPickerNormalRoi; }
    wxStaticLine* GetStaticLine74() { return m_staticLine74; }
    wxRichTextCtrl* GetRichTextCtrl() { return m_richTextCtrl; }
    wxStaticText* GetStaticTextSlideValue() { return m_staticTextSlideValue; }
    wxSlider* GetSliderFilterWidth() { return m_sliderFilterWidth; }
    MyImageWin* GetScrollWinHis() { return m_scrollWinHis; }
    wxPanel* GetMainPanel() { return m_mainPanel; }
    wxMenuBar* GetMenuBar() { return m_menuBar; }
    wxToolBar* GetMainToolbar() { return m_mainToolbar; }
    wxStatusBar* GetStatusBar() { return m_statusBar; }
    MainFrameBaseClass(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Rosa"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,600), long style = wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxCLOSE_BOX);
    virtual ~MainFrameBaseClass();
};


class CDlgGetValueBase : public wxDialog
{
public:
    enum {
        wxID_Submit = 1001,
    };
protected:
    wxStaticText* m_staticTextTitle;
    wxTextCtrl* m_textValue;
    wxButton* m_buttonSubmit;

protected:
    virtual void OnButtonSubmit(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticTextTitle() { return m_staticTextTitle; }
    wxTextCtrl* GetTextValue() { return m_textValue; }
    wxButton* GetButtonSubmit() { return m_buttonSubmit; }
    CDlgGetValueBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("getValue"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CDlgGetValueBase();
};

#endif

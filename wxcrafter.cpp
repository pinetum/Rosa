//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;


MainFrameBaseClass::MainFrameBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    wxBoxSizer* boxSizer70 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer1->Add(boxSizer70, 4, wxALL|wxEXPAND, 0);
    
    wxBoxSizer* boxSizer150 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer70->Add(boxSizer150, 4, wxALL|wxEXPAND, 5);
    
    m_scrollWin = new MyImageWin(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxHSCROLL|wxVSCROLL);
    m_scrollWin->SetBackgroundColour(wxColour(wxT("rgb(205,205,205)")));
    m_scrollWin->SetScrollRate(5, 5);
    
    boxSizer150->Add(m_scrollWin, 1, wxALL|wxEXPAND, 1);
    
    wxBoxSizer* boxSizer152 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer70->Add(boxSizer152, 1, wxEXPAND, 5);
    
    wxBoxSizer* boxSizer160 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer152->Add(boxSizer160, 0, wxALL, 5);
    
    m_staticTextCancerRoiCount = new wxStaticText(this, wxID_ANY, _("0/0"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer160->Add(m_staticTextCancerRoiCount, 0, wxALL, 5);
    
    m_checkBoxCancerRoi = new wxCheckBox(this, wxID_ANY, _("Cancer Roi"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxCancerRoi->SetValue(true);
    
    boxSizer160->Add(m_checkBoxCancerRoi, 0, wxALL, 5);
    
    m_colourPickerCancerRoi = new wxColourPickerCtrl(this, wxID_ANY, wxColour(wxT("rgb(255,34,34)")), wxDefaultPosition, wxSize(-1,-1), wxCLRP_DEFAULT_STYLE);
    
    boxSizer160->Add(m_colourPickerCancerRoi, 0, 0, 5);
    
    wxBoxSizer* boxSizer162 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer152->Add(boxSizer162, 0, wxALL, 5);
    
    m_staticTextNormalRoiCount = new wxStaticText(this, wxID_ANY, _("0/0"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer162->Add(m_staticTextNormalRoiCount, 0, wxALL, 5);
    
    m_checkBoxNormalRoi = new wxCheckBox(this, wxID_ANY, _("Normal Roi"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxNormalRoi->SetValue(true);
    
    boxSizer162->Add(m_checkBoxNormalRoi, 0, wxALL, 5);
    
    m_colourPickerNormalRoi = new wxColourPickerCtrl(this, wxID_ANY, wxColour(wxT("rgb(0,255,255)")), wxDefaultPosition, wxSize(-1,-1), wxCLRP_DEFAULT_STYLE);
    
    boxSizer162->Add(m_colourPickerNormalRoi, 0, 0, 5);
    
    m_staticLine74 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);
    
    boxSizer1->Add(m_staticLine74, 0, wxALL|wxEXPAND, 5);
    
    m_mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    boxSizer1->Add(m_mainPanel, 1, wxEXPAND, 0);
    
    wxBoxSizer* boxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    m_mainPanel->SetSizer(boxSizer11);
    
    m_richTextCtrl = new wxRichTextCtrl(m_mainPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_MULTILINE|wxTE_PROCESS_TAB|wxTE_PROCESS_ENTER|wxWANTS_CHARS);
    m_richTextCtrl->SetBackgroundColour(wxColour(wxT("rgb(204,204,204)")));
    
    boxSizer11->Add(m_richTextCtrl, 4, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer78 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer11->Add(boxSizer78, 3, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer146 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer78->Add(boxSizer146, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextSlideValue = new wxStaticText(m_mainPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_CENTRE);
    
    boxSizer146->Add(m_staticTextSlideValue, 0, wxALL|wxEXPAND, 5);
    
    m_sliderFilterWidth = new wxSlider(m_mainPanel, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxSize(-1,-1), wxSL_INVERSE|wxSL_VERTICAL);
    
    boxSizer146->Add(m_sliderFilterWidth, 1, wxALL, 5);
    
    m_scrollWinHis = new MyImageWin(m_mainPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxHSCROLL|wxVSCROLL);
    m_scrollWinHis->SetScrollRate(5, 5);
    
    boxSizer78->Add(m_scrollWinHis, 1, wxALL|wxEXPAND, 1);
    
    m_menuBar = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar);
    
    m_nenuFile = new wxMenu();
    m_menuBar->Append(m_nenuFile, _("File"));
    
    m_menuItemOpenFile = new wxMenuItem(m_nenuFile, wxID_OPEN, _("OpenFile\tCtrl+O"), wxT(""), wxITEM_NORMAL);
    m_nenuFile->Append(m_menuItemOpenFile);
    
    m_menuItemSaveAsFile = new wxMenuItem(m_nenuFile, wxID_SAVE_AS, _("Save as..\tCtrl+S"), wxT(""), wxITEM_NORMAL);
    m_nenuFile->Append(m_menuItemSaveAsFile);
    
    m_menuItemExit = new wxMenuItem(m_nenuFile, wxID_EXIT, _("Exit\tAlt-X"), _("Quit"), wxITEM_NORMAL);
    m_nenuFile->Append(m_menuItemExit);
    
    m_nenuHelp = new wxMenu();
    m_menuBar->Append(m_nenuHelp, _("Help"));
    
    m_menuItem9 = new wxMenuItem(m_nenuHelp, wxID_ABOUT, _("About..."), wxT(""), wxITEM_NORMAL);
    m_nenuHelp->Append(m_menuItem9);
    
    m_menuEdit = new wxMenu();
    m_menuBar->Append(m_menuEdit, _("Edit"));
    
    m_menuItemUndo = new wxMenuItem(m_menuEdit, wxID_UNDO, _("Undo"), wxT(""), wxITEM_NORMAL);
    m_menuEdit->Append(m_menuItemUndo);
    
    m_menuItemRedo = new wxMenuItem(m_menuEdit, wxID_REDO, _("Redo"), wxT(""), wxITEM_NORMAL);
    m_menuEdit->Append(m_menuItemRedo);
    
    m_menuItemDestroyAllWindow = new wxMenuItem(m_menuEdit, wxID_ANY, _("close windows"), wxT(""), wxITEM_NORMAL);
    m_menuEdit->Append(m_menuItemDestroyAllWindow);
    
    m_menuImage = new wxMenu();
    m_menuBar->Append(m_menuImage, _("Image..."));
    
    m_menuFind = new wxMenu();
    m_menuImage->AppendSubMenu(m_menuFind, _("Find..."));
    
    m_menuItemFindFace = new wxMenuItem(m_menuFind, wxID_ANY, _("Find face"), wxT(""), wxITEM_NORMAL);
    m_menuFind->Append(m_menuItemFindFace);
    
    m_menuItemFindMouth = new wxMenuItem(m_menuFind, wxID_ANY, _("Find mouth"), wxT(""), wxITEM_NORMAL);
    m_menuFind->Append(m_menuItemFindMouth);
    
    m_menuImageFindCircles = new wxMenuItem(m_menuFind, wxID_ANY, _("FindCircles"), wxT(""), wxITEM_NORMAL);
    m_menuFind->Append(m_menuImageFindCircles);
    
    m_menuResize = new wxMenu();
    m_menuImage->AppendSubMenu(m_menuResize, _("Resize.."));
    
    m_menuItemResizeFitWindow = new wxMenuItem(m_menuResize, wxID_RESIZE_FIT_WINDOW, _("Fit Window"), wxT(""), wxITEM_NORMAL);
    m_menuResize->Append(m_menuItemResizeFitWindow);
    
    m_menuItemResizeManual = new wxMenuItem(m_menuResize, wxID_ANY, _("Manual"), wxT(""), wxITEM_NORMAL);
    m_menuResize->Append(m_menuItemResizeManual);
    
    m_menuImageThreshold = new wxMenuItem(m_menuImage, wxID_ANY, _("Threshold"), wxT(""), wxITEM_NORMAL);
    m_menuImage->Append(m_menuImageThreshold);
    
    m_menuImageThresholdOtsu = new wxMenuItem(m_menuImage, wxID_ANY, _("Threshold - OTSU"), wxT(""), wxITEM_NORMAL);
    m_menuImage->Append(m_menuImageThresholdOtsu);
    
    m_menuImageConnectComponents = new wxMenuItem(m_menuImage, wxID_ANY, _("ConnectComponents"), wxT(""), wxITEM_NORMAL);
    m_menuImage->Append(m_menuImageConnectComponents);
    
    m_menuItemMedianBlur = new wxMenuItem(m_menuImage, wxID_ANY, _("Smooth - Median Blur"), wxT(""), wxITEM_NORMAL);
    m_menuImage->Append(m_menuItemMedianBlur);
    
    m_menuItemSplitChnl = new wxMenuItem(m_menuImage, wxID_ANY, _("split"), wxT(""), wxITEM_NORMAL);
    m_menuImage->Append(m_menuItemSplitChnl);
    
    m_menu_gnuEtc = new wxMenu();
    m_menuBar->Append(m_menu_gnuEtc, _("gnuplot"));
    
    m_menuPlot1 = new wxMenuItem(m_menu_gnuEtc, wxID_ANY, _("Item18"), wxT(""), wxITEM_NORMAL);
    m_menu_gnuEtc->Append(m_menuPlot1);
    
    m_menu104 = new wxMenu();
    m_menuBar->Append(m_menu104, _("Mean-shift"));
    
    m_menuItemMSBase = new wxMenuItem(m_menu104, wxID_ANY, _("base"), wxT(""), wxITEM_NORMAL);
    m_menu104->Append(m_menuItemMSBase);
    
    m_menuOralCancer = new wxMenu();
    m_menuBar->Append(m_menuOralCancer, _("OralCancer"));
    
    m_menuItemLoadRois = new wxMenuItem(m_menuOralCancer, wxID_ANY, _("Load Rois From jsFile(*.txt)"), wxT(""), wxITEM_NORMAL);
    m_menuOralCancer->Append(m_menuItemLoadRois);
    
    m_menuItemRunAllOralCncer = new wxMenuItem(m_menuOralCancer, wxID_ORALCANCER_RUN_ALL, _("Run All"), wxT(""), wxITEM_NORMAL);
    m_menuOralCancer->Append(m_menuItemRunAllOralCncer);
    
    m_menuPlayGround = new wxMenu();
    m_menuBar->Append(m_menuPlayGround, _("PlayGround"));
    
    m_menuItemRaiseArmDetect = new wxMenuItem(m_menuPlayGround, wxID_ANY, _("raise arm Detect"), wxT(""), wxITEM_NORMAL);
    m_menuPlayGround->Append(m_menuItemRaiseArmDetect);
    
    m_menuItemScrennshot = new wxMenuItem(m_menuPlayGround, wxID_ANY, _("GetScreenShot\tCtrl+T"), wxT(""), wxITEM_NORMAL);
    m_menuPlayGround->Append(m_menuItemScrennshot);
    
    m_mainToolbar = this->CreateToolBar(wxTB_FLAT, wxID_ANY);
    m_mainToolbar->SetToolBitmapSize(wxSize(32,32));
    m_mainToolbar->SetMargins(1,1);
    
    m_mainToolbar->AddTool(wxID_OPEN, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("open-file-icon")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_SAVE_AS, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("Actions-document-save-icon")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_UNDO, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("Undo-icon")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_REDO, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("Redo-icon")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_RESIZE_FIT_WINDOW, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("Full-Screen-2-icon")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_ANY, _("Rotaion"), wxXmlResource::Get()->LoadBitmap(wxT("Rotation-icon")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddSeparator();
    
    m_mainToolbar->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("creeper")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("enderman")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("wizard-icon")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddSeparator();
    
    m_bmpToggleBtnMarkNormalRoi = new wxBitmapToggleButton(m_mainToolbar, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("polygon")), wxDefaultPosition, wxSize(-1,-1), 0);
    m_bmpToggleBtnMarkNormalRoi->SetValue(false);
    m_mainToolbar->AddControl(m_bmpToggleBtnMarkNormalRoi);
    m_mainToolbar->Realize();
    
    m_statusBar = new wxStatusBar(this, wxID_ANY, wxSTB_DEFAULT_STYLE);
    m_statusBar->SetFieldsCount(1);
    this->SetStatusBar(m_statusBar);
    
    m_taskBarIcon = new wxTaskBarIcon(wxTBI_DEFAULT_TYPE);
    {
        wxIcon icn;
        icn.CopyFromBitmap(wxXmlResource::Get()->LoadBitmap(wxT("tnt")));
        m_taskBarIcon->SetIcon(icn, wxT(""));
    }
    
    SetBackgroundColour(wxColour(wxT("rgb(205,205,205)")));
    SetName(wxT("MainFrameBaseClass"));
    SetSizeHints(800,600);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_scrollWin->Connect(wxEVT_MOTION, wxMouseEventHandler(MainFrameBaseClass::OnMouseMotion), NULL, this);
    m_scrollWin->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MainFrameBaseClass::OnMouseLeftUp), NULL, this);
    m_scrollWin->Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(MainFrameBaseClass::OnMouseRightUp), NULL, this);
    m_staticTextCancerRoiCount->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::UpdateUITextRoiCount), NULL, this);
    m_checkBoxCancerRoi->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnCheckBoxCheckRoi), NULL, this);
    m_checkBoxCancerRoi->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiCancer), NULL, this);
    m_colourPickerCancerRoi->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MainFrameBaseClass::OnColorChangeCancer), NULL, this);
    m_colourPickerCancerRoi->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiCancer), NULL, this);
    m_staticTextNormalRoiCount->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::UpdateUITextRoiCount), NULL, this);
    m_checkBoxNormalRoi->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnCheckBoxCheckRoi), NULL, this);
    m_checkBoxNormalRoi->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiNormal), NULL, this);
    m_colourPickerNormalRoi->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MainFrameBaseClass::OnColorChangeNormal), NULL, this);
    m_colourPickerNormalRoi->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiNormal), NULL, this);
    m_staticTextSlideValue->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::UpdateUISliderText), NULL, this);
    m_sliderFilterWidth->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateUISliderFilterWidth), NULL, this);
    m_sliderFilterWidth->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrameBaseClass::OnSliderChangeFilterWidth), NULL, this);
    m_scrollWinHis->Connect(wxEVT_MOTION, wxMouseEventHandler(MainFrameBaseClass::OnMouseMotionScrollWinHistorgam), NULL, this);
    m_scrollWinHis->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MainFrameBaseClass::OnMouseLeaveScrollWinHis), NULL, this);
    m_scrollWinHis->Connect(wxEVT_SCROLLWIN_LINEUP, wxScrollWinEventHandler(MainFrameBaseClass::OnScrollWinHisLineUp), NULL, this);
    m_scrollWinHis->Connect(wxEVT_SCROLLWIN_LINEDOWN, wxScrollWinEventHandler(MainFrameBaseClass::OnScrollWinHisLineDown), NULL, this);
    this->Connect(m_menuItemOpenFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnOpenFile), NULL, this);
    this->Connect(m_menuItemSaveAsFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSaveAsFile), NULL, this);
    this->Connect(m_menuItemSaveAsFile->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateSaveAs), NULL, this);
    this->Connect(m_menuItemExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Connect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    this->Connect(m_menuItemUndo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemUndo), NULL, this);
    this->Connect(m_menuItemUndo->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateItemUndo), NULL, this);
    this->Connect(m_menuItemRedo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemRedo), NULL, this);
    this->Connect(m_menuItemRedo->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateItemRedo), NULL, this);
    this->Connect(m_menuItemDestroyAllWindow->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnItemDestroyWindowClose), NULL, this);
    m_menuFind->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemFindFace->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemFindFace->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageFindFace), NULL, this);
    this->Connect(m_menuItemFindMouth->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemFindMouth->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageFindMouth), NULL, this);
    this->Connect(m_menuImageFindCircles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageFindCircles), NULL, this);
    this->Connect(m_menuImageFindCircles->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemResizeFitWindow->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemResizeFitWindow), NULL, this);
    this->Connect(m_menuItemResizeFitWindow->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemResizeManual->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemResizeManual), NULL, this);
    this->Connect(m_menuItemResizeManual->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuImageThreshold->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageThreshold), NULL, this);
    this->Connect(m_menuImageThreshold->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuImageThresholdOtsu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageThresholdOtsu), NULL, this);
    this->Connect(m_menuImageThresholdOtsu->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuImageConnectComponents->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageConnectComponents), NULL, this);
    this->Connect(m_menuImageConnectComponents->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemMedianBlur->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageMedianBlur), NULL, this);
    this->Connect(m_menuItemMedianBlur->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemSplitChnl->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Connect(m_menuItemSplitChnl->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemSplit), NULL, this);
    this->Connect(m_menuPlot1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnGnuplotSample), NULL, this);
    this->Connect(m_menuItemMSBase->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMeanShiftBase), NULL, this);
    this->Connect(m_menuItemLoadRois->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuClickLoadOralCancerRois), NULL, this);
    this->Connect(m_menuItemRunAllOralCncer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemClkRunAllOralCancer), NULL, this);
    this->Connect(m_menuItemRaiseArmDetect->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemClkRaisArmDetect), NULL, this);
    this->Connect(m_menuItemScrennshot->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemScreenShot), NULL, this);
    m_bmpToggleBtnMarkNormalRoi->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnTogBtnMarkNormalRoi), NULL, this);
    m_taskBarIcon->Connect(wxEVT_TASKBAR_LEFT_DOWN, wxTaskBarIconEventHandler(MainFrameBaseClass::OnTaskBarIconLeftDown), NULL, this);
    
}

MainFrameBaseClass::~MainFrameBaseClass()
{
    m_scrollWin->Disconnect(wxEVT_MOTION, wxMouseEventHandler(MainFrameBaseClass::OnMouseMotion), NULL, this);
    m_scrollWin->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(MainFrameBaseClass::OnMouseLeftUp), NULL, this);
    m_scrollWin->Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(MainFrameBaseClass::OnMouseRightUp), NULL, this);
    m_staticTextCancerRoiCount->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::UpdateUITextRoiCount), NULL, this);
    m_checkBoxCancerRoi->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnCheckBoxCheckRoi), NULL, this);
    m_checkBoxCancerRoi->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiCancer), NULL, this);
    m_colourPickerCancerRoi->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MainFrameBaseClass::OnColorChangeCancer), NULL, this);
    m_colourPickerCancerRoi->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiCancer), NULL, this);
    m_staticTextNormalRoiCount->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::UpdateUITextRoiCount), NULL, this);
    m_checkBoxNormalRoi->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnCheckBoxCheckRoi), NULL, this);
    m_checkBoxNormalRoi->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiNormal), NULL, this);
    m_colourPickerNormalRoi->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MainFrameBaseClass::OnColorChangeNormal), NULL, this);
    m_colourPickerNormalRoi->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateCheckBoxRoiNormal), NULL, this);
    m_staticTextSlideValue->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::UpdateUISliderText), NULL, this);
    m_sliderFilterWidth->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateUISliderFilterWidth), NULL, this);
    m_sliderFilterWidth->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrameBaseClass::OnSliderChangeFilterWidth), NULL, this);
    m_scrollWinHis->Disconnect(wxEVT_MOTION, wxMouseEventHandler(MainFrameBaseClass::OnMouseMotionScrollWinHistorgam), NULL, this);
    m_scrollWinHis->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MainFrameBaseClass::OnMouseLeaveScrollWinHis), NULL, this);
    m_scrollWinHis->Disconnect(wxEVT_SCROLLWIN_LINEUP, wxScrollWinEventHandler(MainFrameBaseClass::OnScrollWinHisLineUp), NULL, this);
    m_scrollWinHis->Disconnect(wxEVT_SCROLLWIN_LINEDOWN, wxScrollWinEventHandler(MainFrameBaseClass::OnScrollWinHisLineDown), NULL, this);
    this->Disconnect(m_menuItemOpenFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnOpenFile), NULL, this);
    this->Disconnect(m_menuItemSaveAsFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSaveAsFile), NULL, this);
    this->Disconnect(m_menuItemSaveAsFile->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateSaveAs), NULL, this);
    this->Disconnect(m_menuItemExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Disconnect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    this->Disconnect(m_menuItemUndo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemUndo), NULL, this);
    this->Disconnect(m_menuItemUndo->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateItemUndo), NULL, this);
    this->Disconnect(m_menuItemRedo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemRedo), NULL, this);
    this->Disconnect(m_menuItemRedo->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateItemRedo), NULL, this);
    this->Disconnect(m_menuItemDestroyAllWindow->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnItemDestroyWindowClose), NULL, this);
    m_menuFind->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemFindFace->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemFindFace->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageFindFace), NULL, this);
    this->Disconnect(m_menuItemFindMouth->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemFindMouth->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageFindMouth), NULL, this);
    this->Disconnect(m_menuImageFindCircles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageFindCircles), NULL, this);
    this->Disconnect(m_menuImageFindCircles->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemResizeFitWindow->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemResizeFitWindow), NULL, this);
    this->Disconnect(m_menuItemResizeFitWindow->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemResizeManual->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemResizeManual), NULL, this);
    this->Disconnect(m_menuItemResizeManual->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuImageThreshold->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageThreshold), NULL, this);
    this->Disconnect(m_menuImageThreshold->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuImageThresholdOtsu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageThresholdOtsu), NULL, this);
    this->Disconnect(m_menuImageThresholdOtsu->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuImageConnectComponents->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageConnectComponents), NULL, this);
    this->Disconnect(m_menuImageConnectComponents->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemMedianBlur->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImageMedianBlur), NULL, this);
    this->Disconnect(m_menuItemMedianBlur->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemSplitChnl->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBaseClass::OnUpdateImageFunction), NULL, this);
    this->Disconnect(m_menuItemSplitChnl->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemSplit), NULL, this);
    this->Disconnect(m_menuPlot1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnGnuplotSample), NULL, this);
    this->Disconnect(m_menuItemMSBase->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMeanShiftBase), NULL, this);
    this->Disconnect(m_menuItemLoadRois->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuClickLoadOralCancerRois), NULL, this);
    this->Disconnect(m_menuItemRunAllOralCncer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemClkRunAllOralCancer), NULL, this);
    this->Disconnect(m_menuItemRaiseArmDetect->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemClkRaisArmDetect), NULL, this);
    this->Disconnect(m_menuItemScrennshot->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnMenuItemScreenShot), NULL, this);
    m_bmpToggleBtnMarkNormalRoi->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnTogBtnMarkNormalRoi), NULL, this);
    m_taskBarIcon->Disconnect(wxEVT_TASKBAR_LEFT_DOWN, wxTaskBarIconEventHandler(MainFrameBaseClass::OnTaskBarIconLeftDown), NULL, this);
    
wxDELETE(m_taskBarIcon);

}

CDlgGetValueBase::CDlgGetValueBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer48 = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(boxSizer48);
    
    m_staticTextTitle = new wxStaticText(this, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer48->Add(m_staticTextTitle, 0, wxALL, 5);
    
    m_textValue = new wxTextCtrl(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textValue->SetHint(wxT(""));
    #endif
    
    boxSizer48->Add(m_textValue, 0, wxALL, 5);
    
    m_buttonSubmit = new wxButton(this, wxID_Submit, _("Submit"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonSubmit->SetDefault();
    
    boxSizer48->Add(m_buttonSubmit, 0, wxALL, 5);
    
    SetName(wxT("CDlgGetValueBase"));
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_buttonSubmit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CDlgGetValueBase::OnButtonSubmit), NULL, this);
    
}

CDlgGetValueBase::~CDlgGetValueBase()
{
    m_buttonSubmit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CDlgGetValueBase::OnButtonSubmit), NULL, this);
    
}

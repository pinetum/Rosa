#include "MainFrame.h"
#include <wx/aboutdlg.h>
#include <wx/filedlg.h>
#include <wx/dcclient.h>
#include <wx/dnd.h>
#include "CDlgGetValue.h"
#include "gnuplot_i.hpp"
#include "highDMeanShift.h"
#include "MyJSParser.h"



#define ROI_RECT_SIZE 13

Gnuplot g1("lines");
MainFrame *MainFrame::m_pThis = NULL;


// some inital action
MainFrame::MainFrame(wxWindow* parent): MainFrameBaseClass(parent)
{
    
	m_nCurrentImg       = -1;
	m_pThis             = this;  // for some static fun use. ex:MainFrame::showMessage()
    int statuWidth[4]   = { 250, 80, 40, 140};
    
	m_statusBar->SetFieldsCount(4, statuWidth);
	m_scrollWin->Connect(wxEVT_DROP_FILES, wxDropFilesEventHandler(MainFrame::OnDropFile), NULL, this);
    m_scrollWin->DragAcceptFiles(true);
    //SetSize(900, 800);
	//Center();
    
    m_mainToolbar->SetToolBitmapSize(wxSize(24, 24));
    Maximize(true);
}

MainFrame::~MainFrame()
{
    m_scrollWin->Disconnect(wxEVT_DROP_FILES, wxDropFilesEventHandler(MainFrame::OnDropFile), NULL, this);
	DeleteContents();
}
void MainFrame::showMessage(wxString msg){
		m_pThis->m_richTextCtrl->AppendText(msg);
		int last_pos = m_pThis->m_richTextCtrl->GetLastPosition();
		m_pThis->m_richTextCtrl->ShowPosition(last_pos);
}
void MainFrame::OnExit(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    
/*    wxUnusedVar(event);
    wxAboutDialogInfo info;
    info.SetCopyright(_("My MainFrame"));
    info.SetLicence(_("GPL v2 or later"));
    info.SetDescription(_("Short description goes here"));
    ::wxAboutBox(info);*/
}
void MainFrame::OnDropFile(wxDropFilesEvent& event){
    if (event.GetNumberOfFiles() == 1) {
        wxString* dropped = event.GetFiles();
        openFile(dropped[0]);
    }
}
void MainFrame::OnOpenFile(wxCommandEvent& event)
{
	wxString fileType = _("All suported graphic formats(*.jpg,*.bmp,*.jpeg,*.*.png)|*.jpg;*.bmp;*.jpeg;*.png;*.tif");
	wxFileDialog* openDialog = new wxFileDialog(this,_("openFile"),wxEmptyString,wxEmptyString,fileType,wxFD_OPEN,wxDefaultPosition);
	if(openDialog->ShowModal() == wxID_OK){
		wxString pathName = openDialog->GetPath();
		openFile(pathName);
	}
	
	openDialog->Destroy();
}
void MainFrame::OnMenuItemRedo(wxCommandEvent& event)
{
	int sz = m_imgList.size();
	if(m_nCurrentImg < sz -1 )
		m_nCurrentImg ++ ;
	UpdateView();
}
void MainFrame::OnMenuItemUndo(wxCommandEvent& event)
{
	if(m_nCurrentImg >0)
		m_nCurrentImg -- ;
	UpdateView();
}
void MainFrame::OnMouseMotion(wxMouseEvent& event)
{
	wxClientDC dc(this);
	wxPoint pt1 = event.GetLogicalPosition(dc);
	wxPoint pt ;
	m_scrollWin->CalcUnscrolledPosition(pt1.x,pt1.y,&pt.x,&pt.y);
	
	MyImage* pImg = getCurrentImg();
	if(pImg == NULL) return;
	cv::Size sz = pImg->getSize();
	if(pt.x >=sz.width || pt.y >= sz.height) return;
	wxString str;
	int type = pImg->getType();
	switch(type){
			case CV_8UC3:{
				cv::Vec3b c;
				pImg->getPixelValue(pt, c);
				uchar b = c.val[0];
				uchar g = c.val[1];
				uchar r = c.val[2];
				str.Printf("(%d, %d) [%d %d %d]", pt.x, pt.y, r, g, b); }
				break;
			case CV_8UC4:{
				cv::Vec4b c;
				pImg->getPixelValue(pt, c);
				uchar b = c.val[0];
				uchar g = c.val[1];
				uchar r = c.val[2];
				uchar u = c.val[3];
				str.Printf("(%d, %d) [%d %d %d %d]", pt.x, pt.y, r, g, b,u);}
				break;
			case CV_8UC1: {
				uchar c;
				pImg->getPixelValue(pt, c);
				str.Printf("(%d, %d) [%d]", pt.x, pt.y, c); }
				break; 
			case CV_16UC1: {
				ushort c;
				pImg->getPixelValue(pt, c);
				str.Printf("(%d, %d) [%d]", pt.x, pt.y, c); }
				break;
			case CV_16SC1: {
				short c;
				pImg->getPixelValue(pt, c);
				str.Printf("(%d, %d) [%d]", pt.x, pt.y, c); }
				break;
			case CV_32FC1: {
				float c;
				pImg->getPixelValue(pt, c);
				str.Printf("(%d, %d) [%.3f]", pt.x, pt.y, c); }
				break;
			case CV_64FC1: {
				double c;
				pImg->getPixelValue(pt, c);
				str.Printf("(%d, %d) [%.4f]", pt.x, pt.y, c); }
				break;
				
		}
	m_statusBar->SetStatusText(str, 3);
    
    
	cv::Mat mat = pImg->getMatRef().clone();
	if(mat.data)
    {
        cv::rectangle(mat, cv::Rect(pt.x-ROI_RECT_SIZE, pt.y-ROI_RECT_SIZE, ROI_RECT_SIZE, ROI_RECT_SIZE), cv::Scalar(255, 255, 255));
        m_scrollWin->setImage(mat);
    
    }
    
    
	
}
void MainFrame::openFile(wxString &pathName)
{
	bool bRet = false;
	DeleteContents();
	MyImage* pImg = new MyImage;
	bRet = pImg->readImage(pathName);
	if(bRet == false){
		delete pImg;
		wxLogMessage("OnFileOpen: open file error\n");
		return ;
	}
	m_imgList.push_back(pImg);
	m_nCurrentImg=0;
	m_Filename = pathName;
	wxString title = pathName.AfterLast('\\');
	SetTitle(wxString("Edit - ") << title);
	UpdateView();
}
void MainFrame::UpdateView()
{
	MyImage* pImg = getCurrentImg();
	cv::Mat & mat = pImg->getMatRef();
	cv::Mat histogram = pImg->getMatHistogram();
	if(mat.empty())
		showMessage("UpdateView:Mat is empty");
	else
		m_scrollWin->setImage(mat);
	if(histogram.empty())
		showMessage("UpdateView:Histogram is empty");
	else
    {
        wxSize size_window = m_scrollWinHis->GetClientSize();
        cv::resize(histogram, histogram, cv::Size(size_window.x, size_window.y));
        m_scrollWinHis->setImage(histogram);
    }
	

	wxString strSize;
	strSize.Printf("W%d H%d",mat.cols, mat.rows);
	m_statusBar->SetStatusText(strSize, 1);
	m_statusBar->SetStatusText(pImg->getFormatString(), 2);
}
void MainFrame::DeleteContents(){
	int sz = m_imgList.size();
	for(int i = 0 ; i <sz ; i++){
			MyImage* img = m_imgList[i];
			delete img ; 
		
	}
	m_imgList.clear();
	m_nCurrentImg = -1 ;
	
}
MyImage* MainFrame::getCurrentImg()
{
	if(m_nCurrentImg >=0)
		return m_imgList[m_nCurrentImg];
	else
		return NULL;
}
void MainFrame::OnUpdateItemRedo(wxUpdateUIEvent& event)
{
	int sz = m_imgList.size();
	event.Enable(m_nCurrentImg<sz-1);
}
void MainFrame::OnUpdateItemUndo(wxUpdateUIEvent& event)
{

	event.Enable(m_nCurrentImg>0);
}
void MainFrame::OnUpdateImageFunction(wxUpdateUIEvent& event)
{
	event.Enable(m_nCurrentImg>=0);
}
void MainFrame::OnUpdateSaveAs(wxUpdateUIEvent& event)
{
	event.Enable(m_nCurrentImg>0);
}
void MainFrame::addNewImageState(MyImage* plmg){
	
	int szList = m_imgList.size();
	int current = m_nCurrentImg;
	if(plmg == NULL )
		return;
	if(current != szList-1){
		for(int i = current +1 ; i<szList ; i++){
				MyImage* ppO = m_imgList[i];
				delete ppO;
		}
		m_imgList.erase(m_imgList.begin()+current+1,m_imgList.end() );
	}
	if(szList > 6){
			MyImage* pObj = m_imgList.front();
			delete pObj;
			m_imgList.pop_front();
			m_nCurrentImg -- ;
		
	}

	m_imgList.push_back(plmg);
	m_nCurrentImg++;
}



void MainFrame::OnImageConnectComponents(wxCommandEvent& event)
{
}
void MainFrame::OnImageFindCircles(wxCommandEvent& event)
{
	MyImage* pImg = getCurrentImg();
	MyImage* pNewImg = pImg->HoughCircles();
	if(pNewImg != NULL){
		addNewImageState(pNewImg);
		UpdateView();
	}
}
void MainFrame::OnImageThreshold(wxCommandEvent& event)
{
	CDlgGetValue dlg(this);
	dlg.SetTitle(_("Threshold"));
	dlg.setItemTitle(_("Value:(0~255)"));
	dlg.setDefaultValue(_("-1"));
	if( dlg.ShowModal() == 1001 )
	{
		MyImage* pImg = getCurrentImg();
		MyImage* pNewImg = pImg->Threshold(dlg.getIntValue(),false);
		if(pNewImg != NULL){
			addNewImageState(pNewImg);
			UpdateView();
		}
	}
	
}
void MainFrame::OnImageThresholdOtsu(wxCommandEvent& event)
{	
	
	MyImage* pImg = getCurrentImg();
	MyImage* pNewImg = pImg->Threshold(-1,false);
	if(pNewImg != NULL){
		
		addNewImageState(pNewImg);
		UpdateView();
	}
	
}
void MainFrame::OnImageMedianBlur(wxCommandEvent& event)
{
	CDlgGetValue dlg(this);
	dlg.setDefaultValue(_("5"));
	dlg.setItemTitle(_("K Size"));
	dlg.SetTitle(_("MedianBlur"));
	if( dlg.ShowModal() != 1001 )
		return;
	MyImage* pImg = getCurrentImg();
	MyImage* pNewImg = pImg->medianBlur(dlg.getIntValue());
	if(pNewImg != NULL){
		
		addNewImageState(pNewImg);
		UpdateView();
	}
}
void MainFrame::OnSaveAsFile(wxCommandEvent& event)
{
	MyImage* pImg = getCurrentImg();
	wxString fileType = _("All suported graphic formats(*.jpg,*.bmp,*.jpeg,*.png,*.tif)|*.jpg;*.bmp;*.jpeg;*.png;*.tif");
	wxFileDialog* saveDialog = new wxFileDialog(this,_("SaveFile"),wxEmptyString,wxEmptyString,fileType,wxFD_SAVE|wxFD_OVERWRITE_PROMPT,wxDefaultPosition);
	if(saveDialog->ShowModal() == wxID_OK){
		wxString pathName = saveDialog->GetPath();
		if(!pImg->saveBmpImage(pathName.ToStdString()))
			wxLogMessage("save File Error!");
		showMessage("save file : " + pathName);
	}
	
	saveDialog->Destroy();
}


void MainFrame::OnImageFindFace(wxCommandEvent& event)
{
	MyImage* pImg = getCurrentImg();
	MyImage* pNewImg = pImg->faceDetection();
	if(pNewImg != NULL){
		
		addNewImageState(pNewImg);
		UpdateView();
	}
}
void MainFrame::OnImageFindMouth(wxCommandEvent& event)
{
	MyImage* pImg = getCurrentImg();
	MyImage* pNewImg = pImg->mouthDetection();
	if(pNewImg != NULL){
		
		addNewImageState(pNewImg);
		UpdateView();
	}
}


void MainFrame::OnMenuItemSplit(wxCommandEvent& event)
{
	CDlgGetValue dlg(this);
	dlg.setDefaultValue(_("0"));
	dlg.setItemTitle(_("target Chanel:"));
	dlg.SetTitle(_("Split Chanel"));
	if( dlg.ShowModal() != 1001 )
		return;
	MyImage* pImg = getCurrentImg();
	MyImage* pNewImg = pImg->split(dlg.getIntValue());
	if(pNewImg != NULL){
		
		addNewImageState(pNewImg);
		UpdateView();
	}
}
void MainFrame::OnGnuplotSample(wxCommandEvent& event)
{
	//g1 = Gnuplot("lines");
	g1.reset_all();
	g1.set_title("gnuPlotSample");
	g1.plot_slope(1.0,0.0,"y=x");
	g1.plot_equation("sin(12*x)*exp(-x)").plot_equation("exp(-x)");
	g1.showonscreen();
}
void MainFrame::OnMeanShiftBase(wxCommandEvent& event)
{
	highDMeanShift myMS(2,200);
	myMS.base2DMS();
}
void MainFrame::OnItemDestroyWindowClose(wxCommandEvent& event)
{
    cv::destroyAllWindows();
}
void MainFrame::OnMenuItemResizeFitWindow(wxCommandEvent& event)
{
    wxSize size_window = m_scrollWin->GetClientSize();
    MyImage* pImg = getCurrentImg();
    
    
    
    
    double src_width = pImg->getSize().width;
    double src_height = pImg->getSize().height;
    double scale_w = size_window.x/src_width;
    double scale_h = size_window.y/src_height;
    double scale = 0;
    if(scale_h>=scale_w)
        scale = scale_w;
    else
        scale = scale_h;
    if(scale>0)
    {
        MyImage* pNewImg = pImg->resize(scale);
        if(pNewImg != NULL)
        {
            addNewImageState(pNewImg);
            UpdateView();
        }
    }
	else
        MainFrame::showMessage("resize scale is zero...");
    
    
}
void MainFrame::OnMenuItemResizeManual(wxCommandEvent& event)
{
    
}
void MainFrame::OnMenuClickLoadOralCancerRois(wxCommandEvent& event)
{
    //open Dialog
    wxString str_fileName = "";
    wxString fileType = _("All suported formats(*.txt)|*.txt");
	wxFileDialog* openDialog = new wxFileDialog(this,_("openFile"),wxEmptyString,wxEmptyString,fileType,wxFD_OPEN,wxDefaultPosition);
	if(openDialog->ShowModal() == wxID_OK){
		str_fileName = openDialog->GetPath();
	}
	openDialog->Destroy();
    if(!str_fileName.empty())
    {
        FILE* fp                = NULL;
        char* str_filecontent   = NULL;
        int   n_contentSizr     = 0;
        fp = fopen(str_fileName.mb_str(), "r");
        // Is open file success?
        if(fp==NULL)
        {
            MainFrame::showMessage("open Roi json File fail.");
            return;
        }
        
        fseek(fp, 0L, SEEK_END);                                            // get the number of char in txt file.
        n_contentSizr = ftell(fp) + 1;
        
        str_filecontent = new char[n_contentSizr];                          // new char array.
        fseek(fp, 0L, SEEK_SET);
        
        fgets(str_filecontent, n_contentSizr, fp);                          // read content of txt to char array.
        
        MyJSParser parser;                              
        parser.setJsonStr(str_filecontent);                                 // parse!
        std::vector<std::vector<cv::Point > > rois = parser.getRois();      // get Rois (二階Vector，最裡面存放cv::Point)
        if(rois.size() > 0)
        {
            MyImage* img = getCurrentImg();
            for(int n_iRoi= 0; n_iRoi< rois.size(); n_iRoi++)
            {
                if(img == NULL)
                    break;
                img = img->drawPolygon(rois[n_iRoi]);
            
                if(img != NULL)
                {
                    addNewImageState(img);
                    UpdateView();
                }
                else
                {
                    MainFrame::showMessage("img pt NULL when Call \"drawPolygon\"");
                }
            }
            
        }
        else
        {
            MainFrame::showMessage("ROI size is zero");
        }
         
    }
}

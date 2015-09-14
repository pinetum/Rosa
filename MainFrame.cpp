#include "MainFrame.h"
#include <wx/aboutdlg.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/dcclient.h>
#include <wx/dir.h>
#include <wx/dnd.h>
#include "CDlgGetValue.h"

#include "MyJSParser.h"
#include <wx/arrstr.h> 
#include <wx/dcscreen.h>
#include <wx/colour.h>
#include <wx/dcmemory.h>
#include "gnuplot_i.hpp"

#define SLIDER_MAX_VALUE 128
#define ROI_RECT_SIZE 13

MainFrame *MainFrame::m_pThis = NULL;


// some inital action
MainFrame::MainFrame(wxWindow* parent): MainFrameBaseClass(parent)
{
    // for redo undo function (index)
	m_nCurrentImg       = -1;
    
    //for all statice function use ex: MainFrame::showMessage(wxString str);
	m_pThis             = this;  // for some static fun use. ex:MainFrame::showMessage()
    
    
    //setting slider's Max value~~
    m_sliderFilterWidth->SetMax(SLIDER_MAX_VALUE);
    m_nFilterWidth      = 0;
    
    //stroe rois~~
    m_rois_cancer.clear();
    m_rois_normal.clear();
    
    // record which roi is active?!
    m_n_index_ofSelCancerRoi = -1;
    m_n_index_ofSelNormalRoi = -1;
    
    //record for point in scroll win for change slider(filter width) can draw realtime
    m_wxpt_lastptInScrollWinHis.x = 0;
    m_wxpt_lastptInScrollWinHis.y = 0;
    
    // roi copntour drawing color
    m_c_roi_cancer = cv::Scalar(34, 34, 255);
    m_c_roi_normal = cv::Scalar(255, 255, 0);
    
    //set status bar width
    int statuWidth[4]   = { 250, 80, 40, 140};
	m_statusBar->SetFieldsCount(4, statuWidth);
	
   
    // connect drag file event (can drag file into windw to open)
    m_scrollWin->Connect(wxEVT_DROP_FILES, wxDropFilesEventHandler(MainFrame::OnDropFile), NULL, this);
    m_scrollWin->DragAcceptFiles(true);
    
    //timer use
    m_str_TimerName = "";
    
    // in mac os x
    SetSize(800, 700);
	Center();
    //Maximize(true);
    m_taskBarIcon->setPopUpMenu(m_menuPlayGround);
    m_plot_win = new CMyPlotWin(this);
    m_plot_win->Show();
}

MainFrame::~MainFrame()
{
    // disconnect drag event
    m_scrollWin->Disconnect(wxEVT_DROP_FILES, wxDropFilesEventHandler(MainFrame::OnDropFile), NULL, this);
	DeleteContents();
    m_plot_win->Destroy();
}
void MainFrame::showMessage(wxString msg){
		m_pThis->m_richTextCtrl->AppendText(msg<<"\n");
		int last_pos = m_pThis->m_richTextCtrl->GetLastPosition();
		m_pThis->m_richTextCtrl->ShowPosition(last_pos);
}
void MainFrame::OnExit(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}
void MainFrame::startTimer()
{
    m_time_start = clock();
}
void MainFrame::stopTimer(wxString TimerName)
{
    m_time_end = clock();
   unsigned long seconds, milliseconds;
   seconds = (m_time_end-m_time_start)/CLOCKS_PER_SEC;
   milliseconds = ((1000*(m_time_end-m_time_start))/CLOCKS_PER_SEC) - 1000*seconds;
   showMessage(wxString::Format(_("[Time]%s:%d:%d(s:ms)"),TimerName, seconds, milliseconds));
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
void MainFrame::OnMouseRightUp(wxMouseEvent& event)
{
    if(m_rois_normal.size() > 0)
    {
        if(m_rois_normal.back().size() > 0)
            m_rois_normal.back().pop_back();
    }
    UpdateView();
    writeRois();
}
void MainFrame::writeRois()
{
    FILE* fp = fopen(m_str_normalRoiTxtPath.mb_str().data(), "w");
        
    fprintf(fp,"[");
    for(int i = 0; i<m_rois_normal.size(); i++)
    {
        fprintf(fp,"[");
        for(int j= 0; j < m_rois_normal[i].size(); j++)
        {
            fprintf(fp,"{\"x\":%d,\"y\":%d}", m_rois_normal[i][j].x, m_rois_normal[i][j].y);
            if(j != m_rois_normal[i].size()-1)
                fprintf(fp,",");
        }
        if(i != m_rois_normal.size()-1)
            fprintf(fp,",");
        fprintf(fp,"]");
    }
    fprintf(fp,"]");
    fclose(fp);
}
void MainFrame::OnMouseLeftUp(wxMouseEvent& event)
{
    //get mouse position
    wxClientDC dc(this);
	wxPoint pt1 = event.GetLogicalPosition(dc);
	wxPoint pt ;
	m_scrollWin->CalcUnscrolledPosition(pt1.x,pt1.y,&pt.x,&pt.y);
    
    if(m_bmpToggleBtnMarkNormalRoi->GetValue())
    {
        std::vector<cv::Point > roi;
        if(m_rois_normal.size() > 0)
        {
            roi = m_rois_normal[0];
            m_rois_normal.pop_back();
        }
        cv::Point cvPt(pt.x, pt.y);
        roi.push_back(cvPt);
        m_rois_normal.push_back(roi); 
        writeRois();
        
        UpdateView();
        return;
    }
    
    
    
    
    
    
    
    if(m_rois_cancer.size() < 1 && m_rois_normal.size() <1)
        return;
        
    m_n_index_ofSelCancerRoi = -1;
    m_n_index_ofSelNormalRoi = -1;
    
    for(int i = 0; i< m_rois_cancer.size(); i++)
    {
        if(cv::pointPolygonTest(m_rois_cancer[i], cv::Point(pt.x, pt.y), true) > 0 )
        {
            m_n_index_ofSelCancerRoi = i;
            break;
        }
    }
    for(int i = 0; i< m_rois_normal.size() && m_n_index_ofSelCancerRoi < 0; i++)
    {
        if(cv::pointPolygonTest(m_rois_normal[i], cv::Point(pt.x, pt.y), true) > 0 )
        {
            m_n_index_ofSelNormalRoi = i;
            break;
        }
    }
    UpdateView();
}
void MainFrame::OnMouseMotion(wxMouseEvent& event)
{
    // get position in the scroll win 
	wxClientDC dc(this);
	wxPoint pt1 = event.GetLogicalPosition(dc); // position in screen in scrollwin
	wxPoint pt ; // position in "scrllWin" (mouse on image's position)
	m_scrollWin->CalcUnscrolledPosition(pt1.x,pt1.y,&pt.x,&pt.y);
	
    // get image information..
	MyImage* pImg = getCurrentImg();
	if(pImg == NULL) return;
	cv::Size sz = pImg->getSize();
	if(pt.x >=sz.width || pt.y >= sz.height) return;
	
    // setting staturBar info string:image type and num of channel and depth
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
    
    
    // very low effective
    //draw block
    //UpdateView();
//	cv::Mat mat = m_scrollWin->getBGRMat();
//	if(mat.data)
//    {
//        
//        cv::rectangle(mat, cv::Rect(pt.x-ROI_RECT_SIZE, pt.y-ROI_RECT_SIZE, ROI_RECT_SIZE, ROI_RECT_SIZE), cv::Scalar(255, 255, 255));
//        m_scrollWin->setImage(mat);
//    
//    }
    
    
	
}
void MainFrame::openFile(wxString &pathName)
{
    m_n_index_ofSelCancerRoi = -1;
    m_n_index_ofSelNormalRoi = -1;
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
#if defined(__WINDOWS__)
    m_strFileName = pathName.AfterLast('\\');
    m_strFileFolder = pathName.BeforeLast('\\').append("\\");
#else
    m_strFileName = pathName.AfterLast('/');
    m_strFileFolder = pathName.BeforeLast('/').append("/");
#endif
    SetTitle(wxString("Edit - ") << m_strFileName);

    //get roi file path and call to load
    wxString partName = m_strFileName.AfterFirst('_').BeforeFirst('.');
    partName.Replace("_","-",true);
    m_str_cancerRoiTxtPath = wxString::Format("%scancerRoi-%s.txt", m_strFileFolder, partName);
    m_str_normalRoiTxtPath = wxString::Format("%snormalRoi-%s.txt", m_strFileFolder, partName);
//    MainFrame::showMessage(m_str_cancerRoiTxtPath);
//    MainFrame::showMessage(m_str_normalRoiTxtPath);
      loadCancerRoi(m_str_cancerRoiTxtPath);
      loadNormalRoi(m_str_normalRoiTxtPath);
      
      //split image...

#if defined(__WINDOWS__)
   if(pathName.AfterLast('\\').StartsWith("460"))
    {
        
        addNewImageState(pImg->split(1));
        
    }
    else if(pathName.AfterLast('\\').StartsWith("375"))
    {
        addNewImageState(pImg->split(0));
    }
#else
    if(pathName.AfterLast('/').StartsWith("460"))
    {
        addNewImageState(pImg->split(1));
    }
    else if(pathName.AfterLast('/').StartsWith("375"))
    {
        addNewImageState(pImg->split(0));
    }
#endif  
      
      UpdateView();
}
void MainFrame::UpdateView()
{
	MyImage* pImg = getCurrentImg();
    if(pImg == NULL)
        return;
    
	cv::Mat histogram;
	cv::Mat mat_view = pImg->getMatRef().clone();
    if(mat_view.empty())
    {
        showMessage("UpdateView:Mat is empty");
    }
	else
    {
        if(mat_view.type() == CV_8UC1)
            cv::cvtColor(mat_view, mat_view, CV_GRAY2BGR);
        drawAllRois(mat_view);
        
        m_scrollWin->setImage(mat_view);
        
        //get historgam
        histogram = getHistorgram();
        
    }
	if(histogram.empty())
		showMessage("UpdateView:Histogram is empty");
	else
    {
        wxSize size_window = m_scrollWinHis->GetClientSize();
        cv::resize(histogram, histogram, cv::Size(size_window.x, size_window.y));
        m_scrollWinHis->setImage(histogram);
    }
	
    
    
    // update..texts
	m_statusBar->SetStatusText(wxString::Format("W%d H%d",mat_view.cols, mat_view.rows), 1);
	m_statusBar->SetStatusText(pImg->getFormatString(), 2);
    m_staticTextCancerRoiCount->SetLabel(wxString::Format("%d/%d", m_n_index_ofSelCancerRoi+1, m_rois_cancer.size()));
    m_staticTextNormalRoiCount->SetLabel(wxString::Format("%d/%d", m_n_index_ofSelNormalRoi+1, m_rois_normal.size()));
    m_staticTextSlideValue->SetLabel(wxString::Format("%d", m_nFilterWidth));
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
	Gnuplot g1("lines");
	g1.reset_all();
	g1.set_title("gnuPlotSample");
	g1.plot_slope(1.0,0.0,"y=x");
	g1.plot_equation("sin(12*x)*exp(-x)").plot_equation("exp(-x)");
	g1.showonscreen();
}
void MainFrame::OnMeanShiftBase(wxCommandEvent& event)
{
	
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
       
         
    }
}
void MainFrame::loadCancerRoi(wxString filePath)
{
    m_rois_cancer.clear();
    FILE* fp                = NULL;
    char* str_filecontent   = NULL;
    int   n_contentSizr     = 0;
    fp = fopen(filePath.mb_str(), "r");
    // Is open file success?
    if(fp==NULL)
    {
        MainFrame::showMessage("open cancer Roi json File fail.");
        return;
    }

    fseek(fp, 0L, SEEK_END);                                            // get the number of char in txt file.
    n_contentSizr = ftell(fp) + 1;

    str_filecontent = new char[n_contentSizr];                          // new char array.
    fseek(fp, 0L, SEEK_SET);

    fgets(str_filecontent, n_contentSizr, fp);                          // read content of txt to char array.

    MyJSParser parser;                              
    parser.setJsonStr(str_filecontent);                                 // parse!
    m_rois_cancer = parser.getRois();                                   // get Rois (二階Vector，最裡面存放cv::Point)
        //最後交由updateView畫出
    MainFrame::showMessage(wxString::Format("Total number of Cancer rois:%d", m_rois_cancer.size()));
    
    //auto to check checlBox
    m_checkBoxCancerRoi->SetValue(true);
    UpdateView();
}
void MainFrame::loadNormalRoi(wxString filePath)
{
    m_rois_normal.clear();
    FILE* fp                = NULL;
    char* str_filecontent   = NULL;
    int   n_contentSizr     = 0;
    fp = fopen(filePath.mb_str(), "r");
    // Is open file success?
    if(fp==NULL)
    {
        MainFrame::showMessage("open normal Roi json File fail.");
        return;
    }

    fseek(fp, 0L, SEEK_END);                                            // get the number of char in txt file.
    n_contentSizr = ftell(fp) + 1;

    str_filecontent = new char[n_contentSizr];                          // new char array.
    fseek(fp, 0L, SEEK_SET);

    fgets(str_filecontent, n_contentSizr, fp);                          // read content of txt to char array.

    MyJSParser parser;                              
    parser.setJsonStr(str_filecontent);                                 // parse!
    m_rois_normal = parser.getRois();                                   // get Rois (二階Vector，最裡面存放cv::Point)
        //最後交由updateView畫出
    MainFrame::showMessage(wxString::Format("Total number of Cancer rois:%d", m_rois_cancer.size()));
    //auto to check checlBox
    m_checkBoxNormalRoi->SetValue(true);
    UpdateView();
}

void MainFrame::OnSliderChangeFilterWidth(wxScrollEvent& event)
{
    m_nFilterWidth = m_sliderFilterWidth->GetValue();
    UpdateView();
}
void MainFrame::drawHistorgamMask()
{
     m_staticTextSlideValue->SetLabel(wxString::Format(wxT("%d"), m_nFilterWidth));
    if(m_nFilterWidth == 0)
        return;
    if(!m_scrollWinHis->m_rgbOutput.data)
        return;
    wxPoint pt = m_wxpt_lastptInScrollWinHis;
    //get size of scrollwin
    wxSize size_scrollWinHis = m_scrollWinHis->GetClientSize();
    //get historgam image(w=512)
    cv::Mat histogram  ;
    cv::resize(getHistorgram(), histogram, cv::Size(size_scrollWinHis.x, size_scrollWinHis.y));
    
    
    int realWidth = m_nFilterWidth*2*histogram.cols/512;
    int half_width = realWidth/2;
    int n_rect_x = 0;
    int n_rect_y = 0;
    int n_rect_w = 0;
    int n_rect_h = 0;
    
    
    n_rect_h = histogram.cols;
    if(pt.x < half_width)
    {
        n_rect_x = 0;
        n_rect_w = half_width+pt.x;
    }
    else if(histogram.cols - pt.x < half_width)
    {
        n_rect_x = pt.x-half_width;
        n_rect_w =  half_width-pt.x+histogram.cols;;
    }
    else
    {
        n_rect_x = pt.x-half_width;
        n_rect_w = half_width*2;
    }
    
    //draw transperent area
    MyUtil::drawTransparentRect(histogram, cv::Rect(n_rect_x, n_rect_y, n_rect_w, n_rect_h), cv::Scalar(0,0,255), 0.3);
    //draw rect
    //cv::rectangle(histogram, cv::Rect(n_rect_x, n_rect_y, n_rect_w, n_rect_h), cv::Scalar(0,0,255));

    m_scrollWinHis->setImage(histogram);
    
    
    //暫時只想做單一通道Orz
    if(getCurrentImg()->getType() != CV_8UC1)
        return;
    
    
    //處理filter在view圖片上的遮罩
    double alpha            = 0.4;
    int middle_point        = pt.x*256/size_scrollWinHis.x;
    int n_maxuma            = middle_point + m_nFilterWidth/2;
    int n_minuma            = middle_point - m_nFilterWidth/2;
    if(n_maxuma > 255)
        n_maxuma = 255;
    if(n_minuma < 0)
        n_minuma = 0;
    
    cv::Mat filterCpy       = getCurrentImg()->getMat().clone();
    cv::Mat mat_drawPoint   = filterCpy.clone();
    cv::cvtColor(mat_drawPoint, mat_drawPoint, CV_GRAY2BGR);
    int n_valueInPt = 0;
    for(int i= 0; i<mat_drawPoint.cols; i++)
    {
        for(int j= 0; j<mat_drawPoint.rows; j++)
        {
            // get gray value 
               // slow
               //n_valueInPt = filterCpy.at<uchar>(j,i);
            //fast
            n_valueInPt = filterCpy.data[j * mat_drawPoint.cols + i];
            
            //check value is in the target 
            if(n_valueInPt >= n_minuma && n_valueInPt <= n_maxuma)
            {
                //draw something to the image
                cv::circle(mat_drawPoint, cv::Point(i, j), 2, cv::Scalar(0, 0, 255), -1);
            }
        }
    }
    
    

    
    // cvt gray img to bgr img for cv::addWeighted use
    cv::cvtColor(filterCpy, filterCpy, CV_GRAY2BGR);
    cv::addWeighted(mat_drawPoint, alpha, filterCpy, 1.0 - alpha , 0.0, filterCpy); 
    cv::putText(    filterCpy, 
                    std::string(wxString::Format("%d~%d", n_minuma, n_maxuma).mb_str()),
                    cv::Point(0,30),
                    cv::FONT_HERSHEY_SIMPLEX,
                    1,
                    cv::Scalar(255,255,255));
    drawAllRois(filterCpy);
    m_scrollWin->setImage(filterCpy);
    //cv::imshow("filter result", filterCpy);
   
}

void MainFrame::OnCheckBoxCheckRoi(wxCommandEvent& event)
{
    UpdateView();
}

void MainFrame::OnUpdateCheckBoxRoiCancer(wxUpdateUIEvent& event)
{
    if(m_rois_cancer.size() > 0)
    {
        event.Enable(true);
    }
    else
    {
        event.Enable(false);
    }
        
    
    
}
void MainFrame::OnUpdateCheckBoxRoiNormal(wxUpdateUIEvent& event)
{
    if(m_rois_normal.size() > 0)
    {
        event.Enable(true);
    }
    else
    {
        event.Enable(false);
    }
}
void MainFrame::OnMouseLeaveScrollWinHis(wxMouseEvent& event)
{
    UpdateView();
}
void MainFrame::OnColorChangeCancer(wxColourPickerEvent& event)
{
    wxColor c = event.GetColour();
    m_c_roi_cancer = cv::Scalar(c.Blue(), c.Green(), c.Red());
    UpdateView();
}
void MainFrame::OnColorChangeNormal(wxColourPickerEvent& event)
{
    wxColor c = event.GetColour();
    m_c_roi_normal = cv::Scalar(c.Blue(), c.Green(), c.Red());
    UpdateView();
}
void MainFrame::drawAllRois(cv::Mat img)
{
    if(m_checkBoxCancerRoi->GetValue())
    {
        MyUtil::drawRois(img, m_rois_cancer, m_c_roi_cancer, m_n_index_ofSelCancerRoi);
    }
    if(m_checkBoxNormalRoi->GetValue())
    {
        MyUtil::drawRois(img, m_rois_normal, m_c_roi_normal, m_n_index_ofSelNormalRoi);
    }
}
cv::Mat MainFrame::getHistorgram()
{
    MyImage* pImg = getCurrentImg();
    cv::Mat histogram;
    if(m_n_index_ofSelCancerRoi > -1)
    {
        histogram = pImg->getContourHistorgam(m_rois_cancer[m_n_index_ofSelCancerRoi]);
    }
    else if(m_n_index_ofSelNormalRoi > -1)
    {
        histogram = pImg->getContourHistorgam(m_rois_normal[m_n_index_ofSelNormalRoi]);
    }
    else
    {
        histogram = pImg->getMatHistogram();
    }
    return histogram;
}

void MainFrame::UpdateUITextRoiCount(wxUpdateUIEvent& event)
{    
    
}
void MainFrame::OnScrollWinHisLineUp(wxScrollWinEvent& event)
{
    if(m_sliderFilterWidth->GetValue() > m_sliderFilterWidth->GetMax())
        return;
    m_sliderFilterWidth->SetValue(m_sliderFilterWidth->GetValue()+5);
    m_nFilterWidth = m_sliderFilterWidth->GetValue();
    drawHistorgamMask();
}
void MainFrame::OnScrollWinHisLineDown(wxScrollWinEvent& event)
{
    if(m_sliderFilterWidth->GetValue()<1)
        return;
    m_sliderFilterWidth->SetValue(m_sliderFilterWidth->GetValue()-5);
    m_nFilterWidth = m_sliderFilterWidth->GetValue();
    drawHistorgamMask();
    
}
void MainFrame::UpdateUISliderText(wxUpdateUIEvent& event)
{
        
}
void MainFrame::OnMouseMotionScrollWinHistorgam(wxMouseEvent& event)
{
        
    //get mouse position
    wxClientDC dc(this);
	wxPoint pt1 = event.GetLogicalPosition(dc);
	m_scrollWinHis->CalcUnscrolledPosition( pt1.x,
                                            pt1.y,
                                            &m_wxpt_lastptInScrollWinHis.x,
                                            &m_wxpt_lastptInScrollWinHis.y
                                            );
    drawHistorgamMask();
}
void MainFrame::OnUpdateUISliderFilterWidth(wxUpdateUIEvent& event)
{
    
    event.Enable(true);
    
}
void MainFrame::OnMenuItemClkRaisArmDetect(wxCommandEvent& event)
{
    cv::VideoCapture cam;
    cv::Mat camMat;
    cv::Mat lastFrame;
    cv::Mat nowFrame;
    cam.open(0);
    cam.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    //cam.set()
    
    int update_counter = 0;
    const int n_framesToUpdate = 2;
    while(cam.isOpened())
    {
        update_counter++;
        cam.grab();
        cam.retrieve(camMat);
        
        if(update_counter != n_framesToUpdate)
        {
            continue;
        }
        update_counter = 0;
        cv::cvtColor(camMat, camMat, CV_BGR2GRAY);
        nowFrame = camMat.clone();
        if(lastFrame.data)
        {
            camMat = camMat - lastFrame;
        }
        lastFrame = nowFrame;
        MyImage img(camMat);
        MyImage* result = img.Threshold(40,false);
        
        cv::imshow("ps", result->getMatRef());
        delete result;
        if(cvWaitKey(20) == 27)//esc pressed.
        {
            cam.release();
            return;
        }
    }

    MainFrame::showMessage("camera open fail.");
    
    
    
    
    
}
void MainFrame::OnMenuItemClkRunAllOralCancer(wxCommandEvent& event)
{
    wxDirDialog dlg(this, "Choose input directory", "",wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    if(dlg.ShowModal() == wxID_OK){
		wxString DirPath = dlg.GetPath();
        openMultiOralCancerDataByDir(DirPath);
	}
    dlg.Destroy();
}
void MainFrame::openMultiOralCancerDataByDir(wxString path)
{
    startTimer();
    wxDir dir_oralDir(path);
    wxArrayString aryStr_SubDirs;
    if(!dir_oralDir.HasSubDirs())
    {
        showMessage("no files discovered..");
        return;
    }
    
    //scan all record dir
    wxString    str_subDir="";
    bool        b_cont = dir_oralDir.GetFirst(&str_subDir, "", wxDIR_DIRS);
    while(b_cont)
    {
#if defined(__WINDOWS__)
        aryStr_SubDirs.Add(wxString::Format("%s\\%s", path, str_subDir));
#else
        aryStr_SubDirs.Add(wxString::Format("%s/%s", path, str_subDir));
#endif
        str_subDir = "";
        b_cont = dir_oralDir.GetNext(&str_subDir);
        
    }
    FILE* fp_cancer = fopen("cancer.csv", "w");
    FILE* fp_normal = fopen("normal.csv", "w");
    for(int i = 0; i< aryStr_SubDirs.size(); i++)
    {
        wxDir dir_recordDir(aryStr_SubDirs[i]);
        //scan all files
        wxString    str_fileName="";
        //just get fileName
        bool        b_cont = dir_recordDir.GetFirst(&str_fileName, "", wxDIR_FILES);
        while(b_cont)
        {
            cv::Mat mat2Save;
            
            if(str_fileName.StartsWith("460nm"))
            {
                wxString str_fileName_375 = str_fileName;
                str_fileName_375.Replace("460nm", "375nm", true);
                wxString str_fileName_460 = str_fileName;
                
                
                //append path
//                str_fileName = wxString::Format("%s/%s", aryStr_SubDirs[i], str_fileName);
//                MainFrame::showMessage(str_fileName_375);
//                MainFrame::showMessage(str_fileName_460);
//                
                int mode_375_c = -1, mode_460_c = -1;
                int mode_375_n = -1, mode_460_n = -1;
#if defined(__WINDOWS__)
                wxString path375 = wxString::Format("%s\\%s", aryStr_SubDirs[i], str_fileName_375);
                wxString path460 = wxString::Format("%s\\%s", aryStr_SubDirs[i], str_fileName_460);
#else
                wxString path375 = wxString::Format("%s/%s", aryStr_SubDirs[i], str_fileName_375);
                wxString path460 = wxString::Format("%s/%s", aryStr_SubDirs[i], str_fileName_460);
#endif                
                //375nm
                this->openFile(path375);
                    // cancer roi's mode
                if(m_rois_cancer.size() > 0)
                {
#if defined(__WINDOWS__)
                    cv::imwrite(path375.AfterLast('\\').append("_c.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_cancer[0]));
#else
                    cv::imwrite(path375.AfterLast('/').append("_c.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_cancer[0]));
#endif
                    mode_375_c = getCurrentImg()->getOralCancerMode();
                
                }
                    //normak roi's mode
                if(m_rois_normal.size() > 0)
                {
#if defined(__WINDOWS__)
                    cv::imwrite(path375.AfterLast('\\').append("_n.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_normal[0]));
#else
                    cv::imwrite(path375.AfterLast('/').append("_n.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_normal[0]));
#endif
                    mode_375_n = getCurrentImg()->getOralCancerMode();
                
                }
                
                //460nm
                this->openFile(path460);
                    //cancer roi's mode
                if(m_rois_cancer.size() > 0)
                {
#if defined(__WINDOWS__)
                    cv::imwrite(path460.AfterLast('\\').append("_c.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_cancer[0]));
#else
                    cv::imwrite(path460.AfterLast('/').append("_c.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_cancer[0]));
#endif
                    mode_460_c = getCurrentImg()->getOralCancerMode();
                
                }
                    //normal roi's mode
                if(m_rois_normal.size() > 0)
                {
#if defined(__WINDOWS__)
                    cv::imwrite(path460.AfterLast('\\').append("_n.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_normal[0]));
#else
                    cv::imwrite(path460.AfterLast('/').append("_n.jpg").mb_str().data(),getCurrentImg()->getContourHistorgam(m_rois_normal[0]));
#endif
                    mode_460_n = getCurrentImg()->getOralCancerMode();
                }
                
                
                
                if(mode_460_c > 0 && mode_375_c > 0)
                {
                    fprintf(fp_cancer, "%d,%d,%s\n", mode_460_c, mode_375_c, path460.mb_str().data());
                    
                }
                if(mode_460_n > 0 && mode_375_n > 0)
                {
                    fprintf(fp_normal, "%d,%d,%s\n", mode_460_n, mode_375_n, path460.mb_str().data());
                    
                }
                
            }
            b_cont = dir_recordDir.GetNext(&str_fileName);
        }
    }
    fclose(fp_cancer);
    fclose(fp_normal);
    stopTimer("Run all orcancer data.");
    
    
    
}

void MainFrame::OnMenuItemScreenShot(wxCommandEvent& event)
{
    m_scrollWin->setImage(getScreenShot());
}

cv::Mat MainFrame::getScreenShot()
{
        
    wxScreenDC dcScreen;


    wxCoord screenWidth, screenHeight;
    dcScreen.GetSize(&screenWidth, &screenHeight);

    wxBitmap screenshot(screenWidth, screenHeight,-1);

    wxMemoryDC memDC;
    memDC.SelectObject(screenshot);
    memDC.Blit(     0, 
                    0, 
                    screenWidth,
                    screenHeight,
                    &dcScreen,
                    0, 
                    0  
            );

    memDC.SelectObject(wxNullBitmap);
    wxImage w_img = screenshot.ConvertToImage();
    
    w_img.ClearAlpha();
    //showMessage(wxString::Format("%d", w_img.HasAlpha()));
    
    cv::Mat img(w_img.GetHeight(),w_img.GetWidth(),  CV_8UC3, w_img.GetData()); 
    cv::cvtColor(img, img, CV_RGB2BGR);
    //cv::Mat img = cv::Mat::zeros(10,10, CV_8UC3);
    return img;
}

void MainFrame::OnMenuItemClickGaborFilter(wxCommandEvent& event)
{
    MyImage* img = getCurrentImg()->clone()->gaborFilter(40);
    if(img)
    {
        addNewImageState(img);
        UpdateView();
    }
    
    return;
}

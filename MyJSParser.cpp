#include "MyJSParser.h"
#include "MainFrame.h"
MyJSParser::MyJSParser()
{

}

MyJSParser::~MyJSParser()
{
    releaseMem();
}
void MyJSParser::setJsonFile(FILE* jsonFp)
{
    //rapidjson::FileStream is(jsonFp);
    //m_doc.ParseStream<0>(is);
}
void MyJSParser::setJsonStr(char *jsonStr)
{
    m_doc.Parse(jsonStr);
    if(m_doc.HasParseError())
    {
        wxString result = "error Code:"+ wxString::Format("%d", m_doc.GetParseError());;
//        switch(m_doc.GetParseError())
//        {
//            case rapidjson::ParseErrorCode.kParseErrorDocumentEmpty:
//                result = "The document is empty".
//                break;
//            case rapidjson::kParseErrorDocumentRootNotSingular:
//                result = "The document root must not follow by other values.".
//                break;
//            case rapidjson::kParseErrorValueInvalid:
//                result = "Invalid value.".
//                break;
//            case rapidjson::kParseErrorObjectMissName:
//                result = "Missing a colon after a name of object member.".
//                break;
//            case rapidjson::kParseErrorObjectMissCommaOrCurlyBracket:
//                result = "Missing a comma or '}' after an object member.".
//                break;
//            case rapidjson::kParseErrorArrayMissCommaOrSquareBracket:
//                result = "Missing a comma or ']' after an array element.".
//                break;
//        }
        MainFrame::showMessage(result);
    }
}
void MyJSParser::releaseMem()
{
    for(int i = 0; i< m_vv_Rois.size(); i++)
    {
        for(int j = 0; j< m_vv_Rois[i].size(); j++)
        {
            delete m_vv_Rois[i][j];
        }
        m_vv_Rois[i].clear();
    }
    
    m_vv_Rois.clear();
}
std::vector<std::vector<cv::Point* > > MyJSParser::getRois()
{
    releaseMem();
    if(m_doc.IsArray())
    {
        //Loop for get Rois
        for(int n_numRois = 0; n_numRois < m_doc.Size(); n_numRois++)
        {
            
            if(m_doc[n_numRois].IsArray())
            {
                //loop for get points in one Roi
                std::vector<cv::Point* > v_pts;
                for(int n_numPts = 0; n_numPts < m_doc[n_numRois].Size(); n_numPts++)
                {
                    int n_ptX = m_doc[n_numRois][n_numPts]["x"].GetInt();
                    int n_ptY = m_doc[n_numRois][n_numPts]["y"].GetInt();
                    cv::Point* pt = new cv::Point(n_ptX, n_ptY);
                    v_pts.push_back(pt);
                }
                 m_vv_Rois.push_back(v_pts);
            }
            else
            {
                MainFrame::showMessage("JSparser fail. 2-nd array is not array.");
            }
        }
        
    }
    else
    {
        MainFrame::showMessage("JSparser fail. 1-st array is not array.");
    }
    return m_vv_Rois;
    
}
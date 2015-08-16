



void drawTransparentRect(cv::Mat input, cv::Rect rect, cv::Scalar color, double alpha)
{
    cv::Mat context;
    input.copyTo(context);
    cv::rectangle(context, rect, color,CV_FILLED, CV_AA, 0);
    cv::addWeighted(context, alpha, input, 1.0 - alpha , 0.0, input); 
}
void drawRois(cv::Mat img, std::vector<std::vector<cv::Point > > rois, cv::Scalar color)
{
    if(rois.size() < 1)
    {
        return;
    }
    if(img.type() == CV_8UC1)
    {        
        cv::cvtColor(img, img, CV_GRAY2BGR);
    }
    
    cv::drawContours(img, rois, -1, color, 2);
    
}
wxString Slice(const wxString& s, size_t from, size_t to) 
      { return s.Mid(from, (to - from) ); }
//Split (Tokenize) string at specified intervals
//s == string to split
//retArray == split up string (out)
//cpszExp == expression to split at
//crnStart == start postion to split 
//crnCount == max number of split of strings
//crbCIComp == true if case insensitive
void Split(  const wxString& s, wxArrayString& retArray,  const wxChar* cpszExp,  
                                const size_t& crnStart = 0,    const size_t& crnCount = (size_t)-1, 
                                const bool& crbCIComp = false)
{
    //sanity checks
    wxASSERT_MSG(cpszExp != NULL, wxT("Invalid value for First Param of wxString::Split (cpszExp)"));
//    wxASSERT_MSG(crnCount >= (size_t)-1, wxT("Invalid value for Third Param of wxString::Split (crnCount)"));
  
    retArray.Clear();

    size_t  nOldPos = crnStart,      //Current start position in this string
            nPos = crnStart;      //Current end position in this string 

    wxString szComp,            //this string as-is (if bCIComp is false) or converted to lowercase
             szExp = cpszExp;   //Expression string, normal or lowercase

    if (crbCIComp)
    {
        szComp = s.Lower();
        szExp.MakeLower();
    }
    else
        szComp = s;

    if(crnCount == (size_t)-1)
    {
    for (; (nPos = szComp.find(szExp, nPos)) != wxString::npos;)//Is there another token in the string 
        {
        retArray.Add(Slice(s, nOldPos, nPos)); //Insert the token in the array
        nOldPos = nPos += szExp.Length();//Move up the start slice position
        }
    
    }
    else
    {
    for (int i = crnCount; 
            (nPos = szComp.find(szExp, nPos)) != wxString::npos &&
            i != 0;
                --i)//Is there another token in the string && have we met nCount?
    {
        retArray.Add(Slice(s, nOldPos, nPos)); //Insert the token in the array
        nOldPos = nPos += szExp.Length();//Move up the start slice position
    }
    }
    if (nOldPos != s.Length())
        retArray.Add( Slice(s, nOldPos, s.Length()) ); //Add remaining characters in string
}
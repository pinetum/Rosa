
/*
 *  This Class require a linrary: rapidJson
 *  GitHub: https://github.com/miloyip/rapidjson
 *  Documention: http://rapidjson.org/zh-cn/md_doc_tutorial_8zh-cn.html
 */

#ifndef MYJSPARSER_H
#define MYJSPARSER_H
#include <opencv2/opencv.hpp>
#include "rapidjson/document.h"
#include "vector"

class MyJSParser
{
public:
    
    MyJSParser();
    ~MyJSParser();
    void                                    setJsonStr(char *jsonStr);
    void                                    setJsonFile(FILE* jsonFp);
    std::vector<std::vector<cv::Point* > >     getRois();
private:
    //
    std::vector<std::vector<cv::Point* > >     m_vv_Rois;
    rapidjson::Document                     m_doc;
    void releaseMem();
};

#endif // MYJSPARSER_H

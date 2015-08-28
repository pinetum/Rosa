##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## win64-Debug
ProjectName            :=Rosa
ConfigurationName      :=win64-Debug
WorkspacePath          := "E:\crownTing\Rosa"
ProjectPath            := "E:\crownTing\Rosa"
IntermediateDirectory  :=./Debug-win64
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Pinetum
Date                   :=28/08/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Rosa.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  $(shell wx-config --libs --debug)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/opencv/build/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)opencv_adas300.dll $(LibrarySwitch)opencv_bgsegm300.dll $(LibrarySwitch)opencv_bioinspired300.dll $(LibrarySwitch)opencv_calib3d300.dll $(LibrarySwitch)opencv_ccalib300.dll $(LibrarySwitch)opencv_core300.dll $(LibrarySwitch)opencv_datasets300.dll $(LibrarySwitch)opencv_face300.dll $(LibrarySwitch)opencv_features2d300.dll $(LibrarySwitch)opencv_flann300.dll $(LibrarySwitch)opencv_hal300 $(LibrarySwitch)opencv_highgui300.dll $(LibrarySwitch)opencv_imgcodecs300.dll $(LibrarySwitch)opencv_imgproc300.dll $(LibrarySwitch)opencv_latentsvm300.dll $(LibrarySwitch)opencv_line_descriptor300.dll $(LibrarySwitch)opencv_ml300.dll $(LibrarySwitch)opencv_objdetect300.dll $(LibrarySwitch)opencv_optflow300.dll $(LibrarySwitch)opencv_photo300.dll $(LibrarySwitch)opencv_reg300.dll $(LibrarySwitch)opencv_rgbd300.dll $(LibrarySwitch)opencv_saliency300.dll $(LibrarySwitch)opencv_shape300.dll $(LibrarySwitch)opencv_stereo300.dll $(LibrarySwitch)opencv_stitching300.dll $(LibrarySwitch)opencv_superres300.dll $(LibrarySwitch)opencv_surface_matching300.dll $(LibrarySwitch)opencv_text300.dll $(LibrarySwitch)opencv_tracking300.dll $(LibrarySwitch)opencv_ts300 $(LibrarySwitch)opencv_video300.dll $(LibrarySwitch)opencv_videoio300.dll $(LibrarySwitch)opencv_videostab300.dll $(LibrarySwitch)opencv_xfeatures2d300.dll $(LibrarySwitch)opencv_ximgproc300.dll $(LibrarySwitch)opencv_xobjdetect300.dll $(LibrarySwitch)opencv_xphoto300.dll 
ArLibs                 :=  "libopencv_adas300.dll.a" "libopencv_bgsegm300.dll.a" "libopencv_bioinspired300.dll.a" "libopencv_calib3d300.dll.a" "libopencv_ccalib300.dll.a" "libopencv_core300.dll.a" "libopencv_datasets300.dll.a" "libopencv_face300.dll.a" "libopencv_features2d300.dll.a" "libopencv_flann300.dll.a" "libopencv_hal300.a" "libopencv_highgui300.dll.a" "libopencv_imgcodecs300.dll.a" "libopencv_imgproc300.dll.a" "libopencv_latentsvm300.dll.a" "libopencv_line_descriptor300.dll.a" "libopencv_ml300.dll.a" "libopencv_objdetect300.dll.a" "libopencv_optflow300.dll.a" "libopencv_photo300.dll.a" "libopencv_reg300.dll.a" "libopencv_rgbd300.dll.a" "libopencv_saliency300.dll.a" "libopencv_shape300.dll.a" "libopencv_stereo300.dll.a" "libopencv_stitching300.dll.a" "libopencv_superres300.dll.a" "libopencv_surface_matching300.dll.a" "libopencv_text300.dll.a" "libopencv_tracking300.dll.a" "libopencv_ts300.a" "libopencv_video300.dll.a" "libopencv_videoio300.dll.a" "libopencv_videostab300.dll.a" "libopencv_xfeatures2d300.dll.a" "libopencv_ximgproc300.dll.a" "libopencv_xobjdetect300.dll.a" "libopencv_xphoto300.dll.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/opencv/build/x64/mingw/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cflags --debug) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix) $(IntermediateDirectory)/highDMeanShift.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug-win64"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug-win64"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix) -MM "MainFrame.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix) "MainFrame.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp $(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix) -MM "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix) "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix) -MM "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix) "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix): CDlgGetValue.cpp $(IntermediateDirectory)/CDlgGetValue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/CDlgGetValue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CDlgGetValue.cpp$(DependSuffix): CDlgGetValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CDlgGetValue.cpp$(DependSuffix) -MM "CDlgGetValue.cpp"

$(IntermediateDirectory)/CDlgGetValue.cpp$(PreprocessSuffix): CDlgGetValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CDlgGetValue.cpp$(PreprocessSuffix) "CDlgGetValue.cpp"

$(IntermediateDirectory)/highDMeanShift.cpp$(ObjectSuffix): highDMeanShift.cpp $(IntermediateDirectory)/highDMeanShift.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/highDMeanShift.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/highDMeanShift.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/highDMeanShift.cpp$(DependSuffix): highDMeanShift.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/highDMeanShift.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/highDMeanShift.cpp$(DependSuffix) -MM "highDMeanShift.cpp"

$(IntermediateDirectory)/highDMeanShift.cpp$(PreprocessSuffix): highDMeanShift.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/highDMeanShift.cpp$(PreprocessSuffix) "highDMeanShift.cpp"

$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix): MyImage.cpp $(IntermediateDirectory)/MyImage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/MyImage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyImage.cpp$(DependSuffix): MyImage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyImage.cpp$(DependSuffix) -MM "MyImage.cpp"

$(IntermediateDirectory)/MyImage.cpp$(PreprocessSuffix): MyImage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyImage.cpp$(PreprocessSuffix) "MyImage.cpp"

$(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix): MyImageWin.cpp $(IntermediateDirectory)/MyImageWin.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/MyImageWin.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyImageWin.cpp$(DependSuffix): MyImageWin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyImageWin.cpp$(DependSuffix) -MM "MyImageWin.cpp"

$(IntermediateDirectory)/MyImageWin.cpp$(PreprocessSuffix): MyImageWin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyImageWin.cpp$(PreprocessSuffix) "MyImageWin.cpp"

$(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix): MyJSParser.cpp $(IntermediateDirectory)/MyJSParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/crownTing/Rosa/MyJSParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyJSParser.cpp$(DependSuffix): MyJSParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyJSParser.cpp$(DependSuffix) -MM "MyJSParser.cpp"

$(IntermediateDirectory)/MyJSParser.cpp$(PreprocessSuffix): MyJSParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyJSParser.cpp$(PreprocessSuffix) "MyJSParser.cpp"

$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "E:/crownTing/Rosa/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)

-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug-win64/



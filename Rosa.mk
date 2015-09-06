##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Rosa
ConfigurationName      :=Debug
WorkspacePath          := "/Users/Pinetum/coding/Rosa"
ProjectPath            := "/Users/Pinetum/coding/Rosa"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=QT Lin
Date                   :=04/09/2015
CodeLitePath           :="/Users/Pinetum/Library/Application Support/codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
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
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell /usr/local/bin/wx-config --libs --debug)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)opencv_calib3d.3.0.0 $(LibrarySwitch)opencv_imgproc.3.0.0 $(LibrarySwitch)opencv_superres.3.0.0 $(LibrarySwitch)opencv_core.3.0.0 $(LibrarySwitch)opencv_ml.3.0.0 $(LibrarySwitch)opencv_video.3.0.0 $(LibrarySwitch)opencv_features2d.3.0.0 $(LibrarySwitch)opencv_objdetect.3.0.0 $(LibrarySwitch)opencv_videoio.3.0.0 $(LibrarySwitch)opencv_flann.3.0.0 $(LibrarySwitch)opencv_photo.3.0.0 $(LibrarySwitch)opencv_videostab.3.0.0 $(LibrarySwitch)opencv_highgui.3.0.0 $(LibrarySwitch)opencv_shape.3.0.0 $(LibrarySwitch)opencv_imgcodecs.3.0.0 $(LibrarySwitch)opencv_stitching.3.0.0 
ArLibs                 :=  "libopencv_calib3d.3.0.0.dylib" "libopencv_imgproc.3.0.0.dylib" "libopencv_superres.3.0.0.dylib" "libopencv_core.3.0.0.dylib" "libopencv_ml.3.0.0.dylib" "libopencv_video.3.0.0.dylib" "libopencv_features2d.3.0.0.dylib" "libopencv_objdetect.3.0.0.dylib" "libopencv_videoio.3.0.0.dylib" "libopencv_flann.3.0.0.dylib" "libopencv_photo.3.0.0.dylib" "libopencv_videostab.3.0.0.dylib" "libopencv_highgui.3.0.0.dylib" "libopencv_shape.3.0.0.dylib" "libopencv_imgcodecs.3.0.0.dylib" "libopencv_stitching.3.0.0.dylib" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 $(shell /usr/local/bin/wx-config --cflags --debug) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Users/Pinetum/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/fams.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyTaskBarIcon.cpp$(ObjectSuffix) \
	



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix) -MM "MainFrame.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix) "MainFrame.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp $(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix) -MM "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix) "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix) -MM "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix) "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix): CDlgGetValue.cpp $(IntermediateDirectory)/CDlgGetValue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/CDlgGetValue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CDlgGetValue.cpp$(DependSuffix): CDlgGetValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CDlgGetValue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CDlgGetValue.cpp$(DependSuffix) -MM "CDlgGetValue.cpp"

$(IntermediateDirectory)/CDlgGetValue.cpp$(PreprocessSuffix): CDlgGetValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CDlgGetValue.cpp$(PreprocessSuffix) "CDlgGetValue.cpp"

$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix): MyImage.cpp $(IntermediateDirectory)/MyImage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/MyImage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyImage.cpp$(DependSuffix): MyImage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyImage.cpp$(DependSuffix) -MM "MyImage.cpp"

$(IntermediateDirectory)/MyImage.cpp$(PreprocessSuffix): MyImage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyImage.cpp$(PreprocessSuffix) "MyImage.cpp"

$(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix): MyImageWin.cpp $(IntermediateDirectory)/MyImageWin.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/MyImageWin.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyImageWin.cpp$(DependSuffix): MyImageWin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyImageWin.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyImageWin.cpp$(DependSuffix) -MM "MyImageWin.cpp"

$(IntermediateDirectory)/MyImageWin.cpp$(PreprocessSuffix): MyImageWin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyImageWin.cpp$(PreprocessSuffix) "MyImageWin.cpp"

$(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix): MyJSParser.cpp $(IntermediateDirectory)/MyJSParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/MyJSParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyJSParser.cpp$(DependSuffix): MyJSParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyJSParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyJSParser.cpp$(DependSuffix) -MM "MyJSParser.cpp"

$(IntermediateDirectory)/MyJSParser.cpp$(PreprocessSuffix): MyJSParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyJSParser.cpp$(PreprocessSuffix) "MyJSParser.cpp"

$(IntermediateDirectory)/fams.cpp$(ObjectSuffix): fams.cpp $(IntermediateDirectory)/fams.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/fams.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fams.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fams.cpp$(DependSuffix): fams.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fams.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/fams.cpp$(DependSuffix) -MM "fams.cpp"

$(IntermediateDirectory)/fams.cpp$(PreprocessSuffix): fams.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fams.cpp$(PreprocessSuffix) "fams.cpp"

$(IntermediateDirectory)/MyTaskBarIcon.cpp$(ObjectSuffix): MyTaskBarIcon.cpp $(IntermediateDirectory)/MyTaskBarIcon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Pinetum/coding/Rosa/MyTaskBarIcon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyTaskBarIcon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyTaskBarIcon.cpp$(DependSuffix): MyTaskBarIcon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyTaskBarIcon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyTaskBarIcon.cpp$(DependSuffix) -MM "MyTaskBarIcon.cpp"

$(IntermediateDirectory)/MyTaskBarIcon.cpp$(PreprocessSuffix): MyTaskBarIcon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyTaskBarIcon.cpp$(PreprocessSuffix) "MyTaskBarIcon.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



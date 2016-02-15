##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ARDELVEmk7013
ConfigurationName      :=Debug
WorkspacePath          := "/Users/calum/Documents/CODElite/Ardelve Test Rev1p0"
ProjectPath            := "/Users/calum/Documents/CODElite/Ardelve Test Rev1p0/ARDELVEmk7013"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Calum MacRae
Date                   :=15/02/2016
CodeLitePath           :="/Users/calum/Library/Application Support/codelite"
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
ObjectsFileList        :="ARDELVEmk7013.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix) $(IntermediateDirectory)/moduleSERVICE1.cpp$(ObjectSuffix) $(IntermediateDirectory)/moduleSEQUENCER.cpp$(ObjectSuffix) $(IntermediateDirectory)/ARDELVEcommands.cpp$(ObjectSuffix) $(IntermediateDirectory)/moduleSERVICE2.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix): ../ARDELVEgusto/MK7013Scripts.cpp $(IntermediateDirectory)/MK7013Scripts.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/calum/Documents/CODElite/Ardelve Test Rev1p0/ARDELVEgusto/MK7013Scripts.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MK7013Scripts.cpp$(DependSuffix): ../ARDELVEgusto/MK7013Scripts.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MK7013Scripts.cpp$(DependSuffix) -MM "../ARDELVEgusto/MK7013Scripts.cpp"

$(IntermediateDirectory)/MK7013Scripts.cpp$(PreprocessSuffix): ../ARDELVEgusto/MK7013Scripts.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MK7013Scripts.cpp$(PreprocessSuffix) "../ARDELVEgusto/MK7013Scripts.cpp"

$(IntermediateDirectory)/moduleSERVICE1.cpp$(ObjectSuffix): ../ARDELVEgusto/moduleSERVICE1.cpp $(IntermediateDirectory)/moduleSERVICE1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/calum/Documents/CODElite/Ardelve Test Rev1p0/ARDELVEgusto/moduleSERVICE1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/moduleSERVICE1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/moduleSERVICE1.cpp$(DependSuffix): ../ARDELVEgusto/moduleSERVICE1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/moduleSERVICE1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/moduleSERVICE1.cpp$(DependSuffix) -MM "../ARDELVEgusto/moduleSERVICE1.cpp"

$(IntermediateDirectory)/moduleSERVICE1.cpp$(PreprocessSuffix): ../ARDELVEgusto/moduleSERVICE1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/moduleSERVICE1.cpp$(PreprocessSuffix) "../ARDELVEgusto/moduleSERVICE1.cpp"

$(IntermediateDirectory)/moduleSEQUENCER.cpp$(ObjectSuffix): ../ARDELVEgusto/moduleSEQUENCER.cpp $(IntermediateDirectory)/moduleSEQUENCER.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/calum/Documents/CODElite/Ardelve Test Rev1p0/ARDELVEgusto/moduleSEQUENCER.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/moduleSEQUENCER.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/moduleSEQUENCER.cpp$(DependSuffix): ../ARDELVEgusto/moduleSEQUENCER.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/moduleSEQUENCER.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/moduleSEQUENCER.cpp$(DependSuffix) -MM "../ARDELVEgusto/moduleSEQUENCER.cpp"

$(IntermediateDirectory)/moduleSEQUENCER.cpp$(PreprocessSuffix): ../ARDELVEgusto/moduleSEQUENCER.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/moduleSEQUENCER.cpp$(PreprocessSuffix) "../ARDELVEgusto/moduleSEQUENCER.cpp"

$(IntermediateDirectory)/ARDELVEcommands.cpp$(ObjectSuffix): ../ARDELVEgusto/ARDELVEcommands.cpp $(IntermediateDirectory)/ARDELVEcommands.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/calum/Documents/CODElite/Ardelve Test Rev1p0/ARDELVEgusto/ARDELVEcommands.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ARDELVEcommands.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ARDELVEcommands.cpp$(DependSuffix): ../ARDELVEgusto/ARDELVEcommands.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ARDELVEcommands.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ARDELVEcommands.cpp$(DependSuffix) -MM "../ARDELVEgusto/ARDELVEcommands.cpp"

$(IntermediateDirectory)/ARDELVEcommands.cpp$(PreprocessSuffix): ../ARDELVEgusto/ARDELVEcommands.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ARDELVEcommands.cpp$(PreprocessSuffix) "../ARDELVEgusto/ARDELVEcommands.cpp"

$(IntermediateDirectory)/moduleSERVICE2.cpp$(ObjectSuffix): ../ARDELVEgusto/moduleSERVICE2.cpp $(IntermediateDirectory)/moduleSERVICE2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/calum/Documents/CODElite/Ardelve Test Rev1p0/ARDELVEgusto/moduleSERVICE2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/moduleSERVICE2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/moduleSERVICE2.cpp$(DependSuffix): ../ARDELVEgusto/moduleSERVICE2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/moduleSERVICE2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/moduleSERVICE2.cpp$(DependSuffix) -MM "../ARDELVEgusto/moduleSERVICE2.cpp"

$(IntermediateDirectory)/moduleSERVICE2.cpp$(PreprocessSuffix): ../ARDELVEgusto/moduleSERVICE2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/moduleSERVICE2.cpp$(PreprocessSuffix) "../ARDELVEgusto/moduleSERVICE2.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



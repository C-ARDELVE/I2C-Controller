##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=hello
ConfigurationName      :=Release
WorkspacePath          := "/Users/Calum/Documents/Ardelve Test"
ProjectPath            := "/Users/Calum/Documents/Ardelve Test/hello"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Calum
Date                   :=23/01/2016
CodeLitePath           :="/Users/Calum/Library/Application Support/codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="hello.txt"
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix) $(IntermediateDirectory)/OTPCommands.cpp$(ObjectSuffix) 



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
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix): MK7013Scripts.cpp $(IntermediateDirectory)/MK7013Scripts.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Calum/Documents/Ardelve Test/hello/MK7013Scripts.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MK7013Scripts.cpp$(DependSuffix): MK7013Scripts.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MK7013Scripts.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MK7013Scripts.cpp$(DependSuffix) -MM "MK7013Scripts.cpp"

$(IntermediateDirectory)/MK7013Scripts.cpp$(PreprocessSuffix): MK7013Scripts.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MK7013Scripts.cpp$(PreprocessSuffix) "MK7013Scripts.cpp"

$(IntermediateDirectory)/OTPCommands.cpp$(ObjectSuffix): OTPCommands.cpp $(IntermediateDirectory)/OTPCommands.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Calum/Documents/Ardelve Test/hello/OTPCommands.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OTPCommands.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OTPCommands.cpp$(DependSuffix): OTPCommands.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OTPCommands.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/OTPCommands.cpp$(DependSuffix) -MM "OTPCommands.cpp"

$(IntermediateDirectory)/OTPCommands.cpp$(PreprocessSuffix): OTPCommands.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OTPCommands.cpp$(PreprocessSuffix) "OTPCommands.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/



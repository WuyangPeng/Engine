// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:37)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateCodeDirectoryImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h" 
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateEngine.h"

using  std::string;
 
AssistTools::GenerateTestingTemplateCodeDirectoryImpl
	::GenerateTestingTemplateCodeDirectoryImpl(const System::String& directory, const string& configurationFileName)
	:ParentType(directory, configurationFileName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

AssistTools::GenerateTestingTemplateCodeDirectoryImpl
	::~GenerateTestingTemplateCodeDirectoryImpl()
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateCodeDirectoryImpl)

void AssistTools::GenerateTestingTemplateCodeDirectoryImpl
	::GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData,const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	GenerateToManager(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT(""), projectCapital, SYSTEM_TEXT(""));
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("MiddleLayer"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_"));
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, newCoreName, projectCapital, CoreNameCapital + SYSTEM_TEXT("_"));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryImpl
	::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& projectCapital, const System::String& managerCapital) const
{
	System::String libFileName = (managerName.empty() ? SYSTEM_TEXT("GameTemplateTestingExeLibCpp.txt") : SYSTEM_TEXT("GameTemplateTestingLibCpp.txt"));

	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, projectCapital, managerCapital, SYSTEM_TEXT(".h"), SYSTEM_TEXT("GameTemplateTestingH.txt"), SYSTEM_TEXT("Testing"));
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, projectCapital, managerCapital, SYSTEM_TEXT(".h"), SYSTEM_TEXT("GameTemplateTestingHelperH.txt"), SYSTEM_TEXT("TestingHelper"));
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, projectCapital, managerCapital, SYSTEM_TEXT(".cpp"), SYSTEM_TEXT("GameTemplateTestingHelperCpp.txt"), SYSTEM_TEXT("TestingHelper"));
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, projectCapital, managerCapital, SYSTEM_TEXT(".cpp"), SYSTEM_TEXT("GameTemplateTestingMainCpp.txt"), SYSTEM_TEXT("TestingMain"));
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, projectCapital, managerCapital, SYSTEM_TEXT(".cpp"),libFileName, SYSTEM_TEXT("TestingLib"));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryImpl
	::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& projectCapital, const System::String& managerCapital, const System::String& extension, const System::String& fileName, const System::String& resultName) const
{
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + managerName + GetTesting());

	GenerateTestingTemplateEngine::Replace replace;
	GenerateTestingTemplateEngine generateTestingTemplateEngine(GetDirectory() + GetForwardSlash() + fileName, extension, replace);
	generateTestingTemplateEngine.GenerateTo(fullDirectory, resultName, copyrightData, newSolutionName, managerName, projectCapital, managerCapital);
}

 

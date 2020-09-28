// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:37)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateEngineDirectoryImpl.h"
#include "System/Helper/UnicodeUsing.h" 
#include "System/FileManager/FileTools.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/CopyFileTools.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateSolution.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateVcxproj.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateVcxprojFilters.h"
#include "AssistTools/GenerateProjects/GenerateTemplateLogJson.h" 

using std::string;
 
AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateTestingTemplateEngineDirectoryImpl(const System::String& directory, const string& configurationFileName)	 
	:ParentType(directory, configurationFileName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
} 

 
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateEngineDirectoryImpl)

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, 
			     const System::String& newIncludeName, const System::String& newTestingIncludeName,
				 const System::String& newDebugLibName, const System::String& newReleaseLibName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	GenerateToSolution(resourceDirectory,newSolutionName,newCoreName);

	GenerateToModule(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, SYSTEM_TEXT(""));
	GenerateToModule(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, SYSTEM_TEXT("MiddleLayer")); 
	GenerateToModule(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, newCoreName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToSolution(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const
{
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplate.txt"));

	const System::String fullDirectory(resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting());

	GenerateTestingTemplateSolution generateTestingTemplateSolution(fileName, GetProjectName(), GetCoreName());
	generateTestingTemplateSolution.GenerateTo(fullDirectory, newSolutionName, newCoreName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToModule(const System::String& resourceDirectory, const System::String& newSolutionName,
	                   const System::String& newIncludeName, const System::String& newTestingIncludeName, const System::String& newDebugLibName, 
					   const System::String& newReleaseLibName, const System::String& moduleName) const
{
	GenerateToModuleVcxproj(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, moduleName);
	GenerateToModuleVcxprojFilters(resourceDirectory, newSolutionName, moduleName);
	GenerateToUpdate(resourceDirectory, newSolutionName, moduleName);
	GenerateToLogJson(resourceDirectory, newSolutionName, moduleName);
	GenerateToTestingJson(resourceDirectory, newSolutionName, moduleName);
	GenerateToEnvironmentVariable(resourceDirectory, newSolutionName, moduleName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToModuleVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newIncludeName, 
	                          const System::String& newTestingIncludeName, const System::String& newDebugLibName, const System::String& newReleaseLibName, 
							  const System::String& moduleName) const
{
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplateVcxproj.txt"));

	const System::String fullDirectory(resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + moduleName + GetTesting());

	GenerateTestingTemplateVcxproj generateTestingTemplateVcxproj(fileName, GetNewProjectName(), GetModuleName(), GetGameIncludeName(), GetTestingIncludeName(), GetDebugLibName(), GetReleaseLibName());
	generateTestingTemplateVcxproj.GenerateTo(fullDirectory, newSolutionName, moduleName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToModuleVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const
{
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplateVcxprojFilters.txt"));

	const System::String fullDirectory(resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + moduleName + GetTesting());

	GenerateTestingTemplateVcxprojFilters generateTestingTemplateVcxprojFilters(fileName, GetProjectName(), GetModuleName());
	generateTestingTemplateVcxprojFilters.GenerateTo(fullDirectory, newSolutionName, moduleName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToUpdate(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const
{
	System::String fullDirectory = resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + moduleName + GetTesting() + GetForwardSlash() + GetResource();

	 [[maybe_unused]] const auto result = System::CreateFileDirectory(fullDirectory, nullptr);

	CoreTools::WriteFileManager manager(fullDirectory + GetForwardSlash() + GetUpdate());
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToLogJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const
{
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLog.txt"));

	const System::String fullDirectory(resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + moduleName + GetTesting() + GetForwardSlash() + GetConfigurationDirectory());

	GenerateTemplateLogJson generateTemplateLogJson(fileName, GetProjectName());

	generateTemplateLogJson.GenerateTo(fullDirectory, newSolutionName, GetLogFileName());
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToTestingJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const
{
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateTestingJson.txt"));

	const System::String fullDirectory(resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + moduleName + GetTesting() + GetForwardSlash() + GetConfigurationDirectory());

	CoreTools::CopyFileTools(fileName, fullDirectory + GetForwardSlash() + SYSTEM_TEXT("Testing.json"));
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl
	::GenerateToEnvironmentVariable(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const
{
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateEnvironmentVariable.txt"));

	const System::String fullDirectory(resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + moduleName + GetTesting() + GetForwardSlash() + GetConfigurationDirectory());

	CoreTools::CopyFileTools(fileName, fullDirectory + GetForwardSlash() + SYSTEM_TEXT("EnvironmentVariable.json"));
}

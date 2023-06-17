///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 13:31)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateEngineDirectoryImpl.h"
#include "System/FileManager/FileTools.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/CopyFileTools.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateLogJson.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateSolution.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateVcxproj.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateVcxprojFilters.h"

using std::string;
using namespace std::literals;

AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateTestingTemplateEngineDirectoryImpl(const System::String& directory, const string& configurationFileName)
    : ParentType{ directory, configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateEngineDirectoryImpl)

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateTo(const System::String& resourceDirectory,
                                                                         const System::String& newSolutionName,
                                                                         const System::String& newCoreName,
                                                                         const System::String& newIncludeName,
                                                                         const System::String& newTestingIncludeName,
                                                                         const System::String& newDebugLibName,
                                                                         const System::String& newReleaseLibName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    GenerateToSolution(resourceDirectory, newSolutionName, newCoreName);

    GenerateToModule(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, SYSTEM_TEXT(""s));
    GenerateToModule(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, SYSTEM_TEXT("MiddleLayer"s));
    GenerateToModule(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, newCoreName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToSolution(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplate.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() };

    GenerateTestingTemplateSolution generateTestingTemplateSolution{ fileName, GetProjectName(), GetCoreName() };
    generateTestingTemplateSolution.GenerateTo(fullDirectory, newSolutionName, newCoreName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToModule(const System::String& resourceDirectory,
                                                                               const System::String& newSolutionName,
                                                                               const System::String& newIncludeName,
                                                                               const System::String& newTestingIncludeName,
                                                                               const System::String& newDebugLibName,
                                                                               const System::String& newReleaseLibName,
                                                                               const System::String& aModuleName) const
{
    GenerateToModuleVcxproj(resourceDirectory, newSolutionName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName, aModuleName);
    GenerateToModuleVcxprojFilters(resourceDirectory, newSolutionName, aModuleName);
    GenerateToIllustrate(resourceDirectory, newSolutionName, aModuleName);
    GenerateToLogJson(resourceDirectory, newSolutionName, aModuleName);
    GenerateToTestingJson(resourceDirectory, newSolutionName, aModuleName);
    GenerateToEnvironmentVariable(resourceDirectory, newSolutionName, aModuleName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToModuleVcxproj(const System::String& resourceDirectory,
                                                                                      const System::String& newSolutionName,
                                                                                      const System::String& newIncludeName,
                                                                                      const System::String& newTestingIncludeName,
                                                                                      const System::String& newDebugLibName,
                                                                                      const System::String& newReleaseLibName,
                                                                                      const System::String& aModuleName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplateVcxproj.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + aModuleName + GetTesting() };

    GenerateTestingTemplateVcxproj generateTestingTemplateVcxproj{ fileName, GetNewProjectName(), GetModuleName(), GetGameIncludeName(), GetTestingIncludeName(), GetDebugLibName(), GetReleaseLibName() };
    generateTestingTemplateVcxproj.GenerateTo(fullDirectory, newSolutionName, aModuleName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToModuleVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplateVcxprojFilters.txt") };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + aModuleName + GetTesting() };

    GenerateTestingTemplateVcxprojFilters generateTestingTemplateVcxprojFilters{ fileName, GetProjectName(), GetModuleName() };
    generateTestingTemplateVcxprojFilters.GenerateTo(fullDirectory, newSolutionName, aModuleName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToIllustrate(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const
{
    auto fullDirectory = resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + aModuleName + GetTesting() + GetForwardSlash() + GetResource();

    auto result = System::CreateFileDirectory(fullDirectory, nullptr);

    CoreTools::WriteFileManager scheduleManager{ fullDirectory + GetForwardSlash() + SYSTEM_TEXT("Schedule.md"s) };
    CoreTools::WriteFileManager readMeManager{ fullDirectory + GetForwardSlash() + SYSTEM_TEXT("ReadMe.md"s) };

    const auto todoDirectory = fullDirectory + GetForwardSlash() + SYSTEM_TEXT("Todo"s);

    result = System::CreateFileDirectory(todoDirectory, nullptr);

    for (auto i = 0; i < 10; ++i)
    {
        CoreTools::WriteFileManager manager{ todoDirectory + GetForwardSlash() + SYSTEM_TEXT("Level "s) + System::ToString(i) + SYSTEM_TEXT(".txt"s) };
    }
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToLogJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLog.txt") };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + aModuleName + GetTesting() + GetForwardSlash() + GetConfigurationDirectory() };

    GenerateTemplateLogJson generateTemplateLogJson{ fileName, GetProjectName() };

    generateTemplateLogJson.GenerateTo(fullDirectory, newSolutionName, GetLogFileName());
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToTestingJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateTestingJson.txt") };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + aModuleName + GetTesting() + GetForwardSlash() + GetConfigurationDirectory() };

    CoreTools::CopyFileTools copyFileTools{ fileName, fullDirectory + GetForwardSlash() + SYSTEM_TEXT("Testing.json"s) };
}

void AssistTools::GenerateTestingTemplateEngineDirectoryImpl::GenerateToEnvironmentVariable(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateEnvironmentVariable.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + aModuleName + GetTesting() + GetForwardSlash() + GetConfigurationDirectory() };

    CoreTools::CopyFileTools copyFileTools{ fileName, fullDirectory + GetForwardSlash() + SYSTEM_TEXT("EnvironmentVariable.json") };
}

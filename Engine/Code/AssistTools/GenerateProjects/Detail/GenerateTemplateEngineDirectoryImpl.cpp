///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 10:55)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateEngineDirectoryImpl.h"
#include "System/FileManager/FileTools.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/CopyFileTools.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateLogJson.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMiddleLayerVcxproj.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMiddleLayerVcxprojFilters.h"
#include "AssistTools/GenerateProjects/GenerateTemplateModuleVcxproj.h"
#include "AssistTools/GenerateProjects/GenerateTemplateModuleVcxprojFilters.h"
#include "AssistTools/GenerateProjects/GenerateTemplateSolution.h"
#include "AssistTools/GenerateProjects/GenerateTemplateVcxproj.h"
#include "AssistTools/GenerateProjects/GenerateTemplateVcxprojFilters.h"

using std::string;
using namespace std::literals;

AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateTemplateEngineDirectoryImpl(const System::String& directory, const string& configurationFileName)
    : ParentType{ directory, configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateEngineDirectoryImpl)

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, const System::String& newIncludeName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    GenerateToSolution(resourceDirectory, newSolutionName, newCoreName);
    GenerateToVcxproj(resourceDirectory, newSolutionName, newIncludeName);
    GenerateToVcxprojFilters(resourceDirectory, newSolutionName);
    GenerateToUpdate(resourceDirectory, newSolutionName, newSolutionName);

    GenerateToModuleVcxproj(resourceDirectory, newSolutionName, newCoreName, newIncludeName);
    GenerateToModuleVcxprojFilters(resourceDirectory, newSolutionName, newCoreName);
    GenerateToUpdate(resourceDirectory, newSolutionName + newCoreName, newSolutionName);
    GenerateToLogJson(resourceDirectory, newSolutionName);

    GenerateToMiddleLayer(resourceDirectory, newSolutionName, SYSTEM_TEXT("MiddleLayer"s), newIncludeName);

    GenerateToEnvironmentVariable(resourceDirectory, newSolutionName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToSolution(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplate.txt") };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName };

    GenerateTemplateSolution generateTemplateSolution{ fileName, GetProjectName(), GetCoreName() };
    generateTemplateSolution.GenerateTo(fullDirectory, newSolutionName, newCoreName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newIncludeName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateVcxproj.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateVcxproj generateTemplateVcxproj{ fileName, GetExeProjectName(), GetIncludeName() };

    generateTemplateVcxproj.GenerateTo(fullDirectory, newSolutionName, newIncludeName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateVcxprojFilters.txt") };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateVcxprojFilters generateTemplateVcxprojFilters{ fileName, GetExeProjectName() };

    generateTemplateVcxprojFilters.GenerateTo(fullDirectory, newSolutionName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToModuleVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, const System::String& newIncludeName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateModuleVcxproj.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + newCoreName };

    GenerateTemplateModuleVcxproj generateTemplateModuleVcxproj{ fileName, GetDllProjectName(), GetModuleName(), GetIncludeName() };

    generateTemplateModuleVcxproj.GenerateTo(fullDirectory, newSolutionName, newCoreName, newIncludeName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToModuleVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateModuleVcxprojFilters.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + newCoreName };

    GenerateTemplateModuleVcxprojFilters generateTemplateModuleVcxprojFilters{ fileName, GetDllProjectName(), GetModuleName() };

    generateTemplateModuleVcxprojFilters.GenerateTo(fullDirectory, newSolutionName, newCoreName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToLogJson(const System::String& resourceDirectory, const System::String& newSolutionName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLog.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + GetForwardSlash() + GetConfigurationDirectory() };

    GenerateTemplateLogJson generateTemplateLogJson{ fileName, GetProjectName() };

    generateTemplateLogJson.GenerateTo(fullDirectory, newSolutionName, GetLogFileName());
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToMiddleLayerVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newManager, const System::String& newIncludeName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMiddleLayerVcxproj.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + newManager };

    GenerateTemplateMiddleLayerVcxproj generateTemplateManagerVcxproj{ fileName, GetDllProjectName(), GetManagerName(), GetIncludeName() };

    generateTemplateManagerVcxproj.GenerateTo(fullDirectory, newSolutionName, newManager, newIncludeName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToMiddleLayerVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newManager) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMiddleLayerVcxprojFilters.txt") };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + newManager };

    GenerateTemplateMiddleLayerVcxprojFilters generateTemplateManagerVcxprojFilters{ fileName, GetDllProjectName(), GetManagerName() };

    generateTemplateManagerVcxprojFilters.GenerateTo(fullDirectory, newSolutionName, newManager);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToMiddleLayer(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newManager, const System::String& newIncludeName) const
{
    GenerateToMiddleLayerVcxproj(resourceDirectory, newSolutionName, newManager, newIncludeName);
    GenerateToMiddleLayerVcxprojFilters(resourceDirectory, newSolutionName, newManager);
    GenerateToUpdate(resourceDirectory, newSolutionName + newManager, newSolutionName);
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToUpdate(const System::String& resourceDirectory, const System::String& newManager, const System::String& newSolutionName) const
{
    auto fullDirectory = resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newManager + GetForwardSlash() + GetResource();

    MAYBE_UNUSED const auto result = System::CreateFileDirectory(fullDirectory, nullptr);

    CoreTools::WriteFileManager manager{ fullDirectory + GetForwardSlash() + GetUpdate() };
}

void AssistTools::GenerateTemplateEngineDirectoryImpl::GenerateToEnvironmentVariable(const System::String& resourceDirectory, const System::String& newSolutionName) const
{
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateEnvironmentVariable.txt"s) };

    const System::String fullDirectory{ resourceDirectory + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + GetForwardSlash() + GetConfigurationDirectory() };

    CoreTools::CopyFileTools copyFileTools{ fileName, fullDirectory + GetForwardSlash() + SYSTEM_TEXT("EnvironmentVariable.json"s) };
}

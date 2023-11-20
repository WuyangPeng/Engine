///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/15 17:21)

#include "AssistTools/AssistToolsExport.h"

#include "WindowsProjectModuleGenerate.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

using namespace std::literals;

AssistTools::WindowsProjectModuleGenerate::WindowsProjectModuleGenerate(const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, GenerateDirectory generateDirectory) noexcept
    : ParentType{ gameParameterAnalysis, codeMappingAnalysis },
      generateDirectory{ std::move(generateDirectory) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, WindowsProjectModuleGenerate)

void AssistTools::WindowsProjectModuleGenerate::GenerateModule(const GameModule& gameModule)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = generateDirectory.GetGenerateDirectory(moduleDescribe, moduleName);
    nextDirectory.CreateFileDirectory();

    ReplaceContainer replace{ Replace{ moduleNameDescribe, moduleName } };

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleSln")), moduleName + SYSTEM_TEXT(".sln"), replace);

    replace.emplace_back(moduleChineseNameDescribe, gameModule.GetChineseName());
    replace.emplace_back(moduleUppercaseDescribe, gameModule.GetUppercaseName());

    GenerateWindowsProjectModuleCore(gameModule, nextDirectory, replace);
    GenerateWindowsProjectModuleMiddleLayer(gameModule, nextDirectory, replace);
    GenerateWindowsProjectModuleExe(gameModule, nextDirectory, replace);
}

void AssistTools::WindowsProjectModuleGenerate::GenerateWindowsProjectTodo(const GenerateDirectory& directory)
{
    const auto nextDirectory = directory.GetGenerateDirectory(todoDescribe);
    nextDirectory.CreateFileDirectory();

    for (auto i = 0; i < maxLevel; ++i)
    {
        const ReplaceContainer replace{ Replace{ SYSTEM_TEXT("LevelIndex"), System::ToString(i) } };

        GenerateFile::GenerateByContent(nextDirectory,
                                        GetContent(nextDirectory.GetInputDirectory(), levelDescribe),
                                        levelDescribe.data() + SYSTEM_TEXT(" "s) + System::ToString(i) + extension.data(),
                                        replace);
    }
}

void AssistTools::WindowsProjectModuleGenerate::GenerateWindowsProjectModuleCore(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(String{ moduleDescribe } + coreDescribe.data(), moduleName + coreDescribe.data());
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreVcxproj")), moduleName + SYSTEM_TEXT("Core.vcxproj"), replace);
    GenerateFile::GenerateByContentUtf8(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreVcxprojFilters"), ProjectGenerationType::Utf8), moduleName + SYSTEM_TEXT("Core.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleResource(gameModule, nextDirectory, replace);
}

void AssistTools::WindowsProjectModuleGenerate::GenerateWindowsProjectModuleMiddleLayer(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(String{ moduleDescribe } + middleLayerDescribe.data(), moduleName + middleLayerDescribe.data());
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerVcxproj")), moduleName + SYSTEM_TEXT("MiddleLayer.vcxproj"), replace);
    GenerateFile::GenerateByContentUtf8(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerVcxprojFilters"), ProjectGenerationType::Utf8), moduleName + SYSTEM_TEXT("MiddleLayer.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleResource(gameModule, nextDirectory, replace);
}

void AssistTools::WindowsProjectModuleGenerate::GenerateWindowsProjectModuleExe(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(moduleDescribe, moduleName);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleVcxproj")), moduleName + SYSTEM_TEXT(".vcxproj"), replace);
    GenerateFile::GenerateByContentUtf8(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleVcxprojFilters"), ProjectGenerationType::Utf8), moduleName + SYSTEM_TEXT(".vcxproj.filters"), replace);

    GenerateWindowsProjectModuleResource(gameModule, nextDirectory, replace);
    GenerateWindowsProjectModuleExeConfiguration(gameModule, nextDirectory, replace);
}

void AssistTools::WindowsProjectModuleGenerate::GenerateWindowsProjectModuleResource(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(resourceDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), readMeMd), readMeMdOriginal, replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), scheduleMd), scheduleMdOriginal, replace);

    GenerateWindowsProjectTodo(nextDirectory);
}

void AssistTools::WindowsProjectModuleGenerate::GenerateWindowsProjectModuleExeConfiguration(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(configurationDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("EnvironmentVariableJson")), SYSTEM_TEXT("EnvironmentVariable.json"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("LogJson")), SYSTEM_TEXT("Log.json"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("RendererJson")), SYSTEM_TEXT("Renderer.json"), replace);
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:58)

#include "AssistTools/AssistToolsExport.h"

#include "WindowsProjectModuleTestingGenerate.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

using namespace std::literals;

AssistTools::WindowsProjectModuleTestingGenerate::WindowsProjectModuleTestingGenerate(const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, GenerateDirectory generateDirectory) noexcept
    : ParentType{ gameParameterAnalysis, codeMappingAnalysis },
      generateDirectory{ std::move(generateDirectory) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, WindowsProjectModuleTestingGenerate)

void AssistTools::WindowsProjectModuleTestingGenerate::GenerateModule(const GameModule& gameModule)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = generateDirectory.GetGenerateDirectory(moduleDescribe, moduleName + SYSTEM_TEXT("Testing"));
    directory.CreateFileDirectory();

    const ReplaceContainer replace{ Replace{ moduleNameDescribe, moduleName },
                                    Replace{ moduleChineseNameDescribe, gameModule.GetChineseName() },
                                    Replace{ moduleUppercaseDescribe, gameModule.GetUppercaseName() } };

    GenerateWindowsProjectModuleCore(gameModule, directory, replace);
    GenerateWindowsProjectModuleMiddleLayer(gameModule, directory, replace);
    GenerateWindowsProjectModuleExe(gameModule, directory, replace);
}

void AssistTools::WindowsProjectModuleTestingGenerate::GenerateWindowsProjectModuleCore(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(moduleCoreDescribe, moduleName + SYSTEM_TEXT("CoreTesting"));
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreVcxproj")), moduleName + SYSTEM_TEXT("CoreTesting.vcxproj"), replace);
    GenerateFile::GenerateByContentUtf8(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreVcxprojFilters"), ProjectGenerationType::Utf8), moduleName + SYSTEM_TEXT("CoreTesting.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleResource(gameModule, nextDirectory, replace);
    GenerateWindowsProjectModuleConfiguration(gameModule, nextDirectory, replace, SYSTEM_TEXT("Core"));
}

void AssistTools::WindowsProjectModuleTestingGenerate::GenerateWindowsProjectModuleMiddleLayer(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(moduleMiddleLayerDescribe, moduleName + SYSTEM_TEXT("MiddleLayerTesting"));
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerVcxproj")), moduleName + SYSTEM_TEXT("MiddleLayerTesting.vcxproj"), replace);
    GenerateFile::GenerateByContentUtf8(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerVcxprojFilters"), ProjectGenerationType::Utf8), moduleName + SYSTEM_TEXT("MiddleLayerTesting.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleResource(gameModule, nextDirectory, replace);
    GenerateWindowsProjectModuleConfiguration(gameModule, nextDirectory, replace, SYSTEM_TEXT("MiddleLayer"));
}

void AssistTools::WindowsProjectModuleTestingGenerate::GenerateWindowsProjectModuleExe(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(moduleDescribe, moduleName + SYSTEM_TEXT("Testing"));
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleVcxproj")), moduleName + SYSTEM_TEXT("Testing.vcxproj"), replace);
    GenerateFile::GenerateByContentUtf8(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleVcxprojFilters"), ProjectGenerationType::Utf8), moduleName + SYSTEM_TEXT("Testing.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleResource(gameModule, nextDirectory, replace);
    GenerateWindowsProjectModuleConfiguration(gameModule, nextDirectory, replace, SYSTEM_TEXT(""));
}

void AssistTools::WindowsProjectModuleTestingGenerate::GenerateWindowsProjectModuleResource(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(resourceDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), readMeMd), readMeMdOriginal, replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), scheduleMd), scheduleMdOriginal, replace);

    GenerateWindowsProjectModuleResourceTodo(nextDirectory);
}

void AssistTools::WindowsProjectModuleTestingGenerate::GenerateWindowsProjectModuleConfiguration(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace, const String& mark)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(configurationDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("EnvironmentVariableJson")), SYSTEM_TEXT("EnvironmentVariable.json"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("LogJson")), SYSTEM_TEXT("Log.json"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("Testing")), SYSTEM_TEXT("Testing.json"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleTestingJson")), moduleName + mark + SYSTEM_TEXT("Testing.json"), replace);
}

void AssistTools::WindowsProjectModuleTestingGenerate::GenerateWindowsProjectModuleResourceTodo(const GenerateDirectory& directory)
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

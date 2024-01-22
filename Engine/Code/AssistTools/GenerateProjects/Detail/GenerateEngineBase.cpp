/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:59)

#include "AssistTools/AssistToolsExport.h"

#include "CodeModuleGenerate.h"
#include "GenerateEngineBase.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

using namespace std::literals;

AssistTools::GenerateEngineBase::GenerateEngineBase(const String& input, const String& output, const std::string& fileName)
    : gameParameterAnalysis{ fileName },
      codeMappingAnalysis{ input + SYSTEM_TEXT("GenerateProjects.json") },
      generateFile{ gameParameterAnalysis, codeMappingAnalysis },
      generateDirectory{ input, output }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateEngineBase)

System::String AssistTools::GenerateEngineBase::GetProjectName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectName);
}

System::String AssistTools::GenerateEngineBase::GetTestingName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameParameterAnalysis.GetGameParameter(GameParameterType::TestingName);
}

void AssistTools::GenerateEngineBase::Generate() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    generateDirectory.CreateFileDirectory();

    GenerateTop();
    GenerateBinary(SYSTEM_TEXT("x64"));
    GenerateBinary(SYSTEM_TEXT("Win32"));
    GenerateRun();
    Generate(doxygenDescribe, doxygenFile, doxygenFileOriginal);
    Generate(docDescribe, overviewMd, overviewMdOriginal);
    Generate(batDescribe, delDoxygenFileBat, delDoxygenFileBatOriginal);
    GenerateCode();
    GenerateWindows();
}

void AssistTools::GenerateEngineBase::Generate(const StringView& describe, const StringView& textName, const StringView& originalName) const
{
    const auto directory = generateDirectory.GetGenerateDirectory(describe);
    directory.CreateFileDirectory();

    generateFile.Generate(directory, textName, originalName);
}

void AssistTools::GenerateEngineBase::GenerateTop() const
{
    generateFile.Generate(generateDirectory, readMeMd, readMeMdOriginal);
    generateFile.Generate(generateDirectory, gitIgnore, gitIgnoreOriginal);
    generateFile.Generate(generateDirectory, clangFormat, clangFormatOriginal);
}

void AssistTools::GenerateEngineBase::GenerateBinary(const String& configuration) const
{
    const auto directory = generateDirectory.GetGenerateDirectory(generateDescribe, configuration);
    directory.CreateFileDirectory();

    const ReplaceContainer replace{ Replace{ configurationDescribe, configuration } };

    generateFile.Generate(directory, readMeMd, readMeMdOriginal, replace);
    generateFile.Generate(directory, gitIgnore, gitIgnoreOriginal);

    GenerateBinaryConfiguration(SYSTEM_TEXT("Debug"), directory);
    GenerateBinaryConfiguration(SYSTEM_TEXT("EngineStaticDebug"), directory);
    GenerateBinaryConfiguration(SYSTEM_TEXT("GameStaticDebug"), directory);
    GenerateBinaryConfiguration(SYSTEM_TEXT("StaticDebug"), directory);
    GenerateBinaryConfiguration(SYSTEM_TEXT("Release"), directory);
    GenerateBinaryConfiguration(SYSTEM_TEXT("EngineStaticRelease"), directory);
    GenerateBinaryConfiguration(SYSTEM_TEXT("GameStaticRelease"), directory);
    GenerateBinaryConfiguration(SYSTEM_TEXT("StaticRelease"), directory);
}

void AssistTools::GenerateEngineBase::GenerateCode() const
{
    const auto directory = generateDirectory.GetGenerateDirectory(codeDescribe);
    directory.CreateFileDirectory();

    generateFile.Generate(directory, readMeMd, readMeMdOriginal);
    generateFile.Generate(directory, gitIgnore, gitIgnoreOriginal);
    GenerateCodeProject(directory);
    GenerateCodeModule(directory);
}

AssistTools::GenerateDirectory AssistTools::GenerateEngineBase::CreateBinaryConfigurationFileDirectory(const String& staticDescribe, const GenerateDirectory& directory)
{
    auto nextDirectory = directory.GetGenerateDirectory(configurationDescribe, staticDescribe + windowsDescribe.data());
    nextDirectory.CreateFileDirectory();

    nextDirectory.AddOutputPathRoute(configurationDescribe);
    nextDirectory.CreateFileDirectory();

    return nextDirectory;
}

void AssistTools::GenerateEngineBase::Generate(const GenerateDirectory& directory, const ReplaceContainer& file) const
{
    for (const auto& element : file)
    {
        generateFile.Generate(directory, element.GetKeyCode(), element.GetParameter());
    }
}

void AssistTools::GenerateEngineBase::Generate(const GenerateDirectory& directory, const ReplaceContainer& file, const ReplaceContainer& replace) const
{
    for (const auto& element : file)
    {
        generateFile.Generate(directory, element.GetKeyCode(), element.GetParameter(), replace);
    }
}

void AssistTools::GenerateEngineBase::Generate(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName, const ReplaceContainer& replace) const
{
    generateFile.Generate(directory, templateName, originalName, replace);
}

void AssistTools::GenerateEngineBase::Generate(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName, ProjectServiceType projectServiceType) const
{
    generateFile.Generate(directory, templateName, originalName, projectServiceType);
}

void AssistTools::GenerateEngineBase::Generate(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName) const
{
    generateFile.Generate(directory, templateName, originalName);
}

void AssistTools::GenerateEngineBase::GenerateUtf8(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName) const
{
    generateFile.GenerateUtf8(directory, templateName, originalName);
}

void AssistTools::GenerateEngineBase::GenerateSln(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName) const
{
    generateFile.GenerateSln(directory, templateName, originalName);
}

AssistTools::GenerateDirectory AssistTools::GenerateEngineBase::GetGenerateDirectory(const StringView& pathRoute) const
{
    return generateDirectory.GetGenerateDirectory(pathRoute);
}

AssistTools::GenerateDirectory AssistTools::GenerateEngineBase::GetGenerateDirectory(const StringView& inputPathRoute, const String& outputPathRoute) const
{
    return generateDirectory.GetGenerateDirectory(inputPathRoute, outputPathRoute);
}

void AssistTools::GenerateEngineBase::GenerateRunBat(const GenerateDirectory& directory) const
{
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        GenerateRunBat(iter->GetModuleName(), directory);
    }
}

void AssistTools::GenerateEngineBase::GenerateWindowsProjectResource(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(resourceDescribe);
    nextDirectory.CreateFileDirectory();

    Generate(nextDirectory, readMeMd, readMeMdOriginal);
    Generate(nextDirectory, scheduleMd, scheduleMdOriginal);

    GenerateWindowsProjectResourceTodo(nextDirectory);
}

void AssistTools::GenerateEngineBase::GenerateWindowsProjectResourceTodo(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(todoDescribe);
    nextDirectory.CreateFileDirectory();

    for (auto i = 0; i < maxLevel; ++i)
    {
        const ReplaceContainer replace{ Replace{ SYSTEM_TEXT("LevelIndex"), System::ToString(i) } };

        Generate(nextDirectory,
                 levelDescribe,
                 levelDescribe.data() + SYSTEM_TEXT(" "s) + System::ToString(i) + extension.data(),
                 replace);
    }
}
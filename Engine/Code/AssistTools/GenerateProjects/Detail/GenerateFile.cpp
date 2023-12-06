///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/14 17:03)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateFile.h"
#include "ProjectGenerationReplace.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

AssistTools::GenerateFile::GenerateFile(GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : gameParameterAnalysis(std::move(gameParameterAnalysis)), codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateFile)

void AssistTools::GenerateFile::Generate(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    Generate(generateDirectory.GetInputDirectory(), templateName, generateDirectory.GetOutputDirectory(), originalName);
}

void AssistTools::GenerateFile::Generate(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName, const ReplaceContainer& replace) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    Generate(generateDirectory.GetInputDirectory(), templateName, generateDirectory.GetOutputDirectory(), originalName, replace);
}

void AssistTools::GenerateFile::Generate(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName, ProjectServiceType projectServiceType) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    Generate(generateDirectory.GetInputDirectory(), templateName, generateDirectory.GetOutputDirectory(), originalName, projectServiceType);
}

void AssistTools::GenerateFile::GenerateUtf8(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    GenerateUtf8(generateDirectory.GetInputDirectory(), templateName, generateDirectory.GetOutputDirectory(), originalName);
}

void AssistTools::GenerateFile::GenerateUtf8(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName, const ReplaceContainer& replace) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    GenerateUtf8(generateDirectory.GetInputDirectory(), templateName, generateDirectory.GetOutputDirectory(), originalName, replace);
}

void AssistTools::GenerateFile::GenerateSln(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    GenerateSln(generateDirectory.GetInputDirectory(), templateName, generateDirectory.GetOutputDirectory(), originalName);
}

void AssistTools::GenerateFile::GenerateByContent(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName, const ReplaceContainer& replace)
{
    GenerateByContent(content, GetOutputFileName(generateDirectory.GetOutputDirectory(), originalName), replace);
}

void AssistTools::GenerateFile::GenerateByContent(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName)
{
    GenerateByContent(content, GetOutputFileName(generateDirectory.GetOutputDirectory(), originalName));
}

void AssistTools::GenerateFile::GenerateByContentUtf8(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName, const ReplaceContainer& replace)
{
    GenerateByContentUtf8(content, GetOutputFileName(generateDirectory.GetOutputDirectory(), originalName), replace);
}

void AssistTools::GenerateFile::GenerateByContentUtf8(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName)
{
    GenerateByContentUtf8(content, GetOutputFileName(generateDirectory.GetOutputDirectory(), originalName));
}

System::String AssistTools::GenerateFile::GetInputFileName(const String& directory, const StringView& name)
{
    return directory + slash.data() + name.data() + extension.data();
}

System::String AssistTools::GenerateFile::GetOutputFileName(const String& directory, const StringView& name)
{
    return directory + slash.data() + name.data();
}

void AssistTools::GenerateFile::Generate(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName) const
{
    Generate(GetInputFileName(inputDirectory, templateName), GetOutputFileName(outputDirectory, originalName));
}

void AssistTools::GenerateFile::Generate(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName, const ReplaceContainer& replace) const
{
    Generate(GetInputFileName(inputDirectory, templateName), GetOutputFileName(outputDirectory, originalName), replace);
}

void AssistTools::GenerateFile::Generate(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName, ProjectServiceType projectServiceType) const
{
    Generate(GetInputFileName(inputDirectory, templateName), GetOutputFileName(outputDirectory, originalName), projectServiceType);
}

void AssistTools::GenerateFile::GenerateUtf8(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName) const
{
    GenerateUtf8(GetInputFileName(inputDirectory, templateName), GetOutputFileName(outputDirectory, originalName));
}

void AssistTools::GenerateFile::GenerateUtf8(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName, const ReplaceContainer& replace) const
{
    GenerateUtf8(GetInputFileName(inputDirectory, templateName), GetOutputFileName(outputDirectory, originalName), replace);
}

void AssistTools::GenerateFile::GenerateSln(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName) const
{
    GenerateSln(GetInputFileName(inputDirectory, templateName), GetOutputFileName(outputDirectory, originalName));
}

void AssistTools::GenerateFile::Generate(const String& inputFileName, const String& outputFileName) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    GenerateByContent(content, outputFileName);
}

void AssistTools::GenerateFile::Generate(const String& inputFileName, const String& outputFileName, const ReplaceContainer& replace) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis,
                                               replace };

    const auto content = projectGeneration.GetContent();

    GenerateByContent(content, outputFileName);
}

void AssistTools::GenerateFile::Generate(const String& inputFileName, const String& outputFileName, ProjectServiceType projectServiceType) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis,
                                               projectServiceType };

    const auto content = projectGeneration.GetContent();

    GenerateByContent(content, outputFileName);
}

void AssistTools::GenerateFile::GenerateUtf8(const String& inputFileName, const String& outputFileName) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Utf8,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    GenerateByContentUtf8(content, outputFileName);
}

void AssistTools::GenerateFile::GenerateSln(const String& inputFileName, const String& outputFileName) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Sln,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    GenerateByContentUtf8(content, outputFileName);
}

void AssistTools::GenerateFile::GenerateUtf8(const String& inputFileName, const String& outputFileName, const ReplaceContainer& replace) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Utf8,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis,
                                               replace };

    const auto content = projectGeneration.GetContent();

    GenerateByContentUtf8(content, outputFileName);
}

void AssistTools::GenerateFile::GenerateByContent(const String& content, const String& outputFileName, const ReplaceContainer& replace)
{
    const auto result = ProjectGenerationReplace::ReplaceParameter(content, replace);

    GenerateByContent(result, outputFileName);
}

void AssistTools::GenerateFile::GenerateByContent(const String& content, const String& outputFileName)
{
    CoreTools::OFStreamManager streamManager{ outputFileName, false };
    streamManager.SetSimplifiedChinese();

    streamManager << content;
}

void AssistTools::GenerateFile::GenerateByContentUtf8(const String& content, const String& outputFileName, const ReplaceContainer& replace)
{
    const auto result = ProjectGenerationReplace::ReplaceParameter(content, replace);

    GenerateByContentUtf8(result, outputFileName);
}

void AssistTools::GenerateFile::GenerateByContentUtf8(const String& content, const String& outputFileName)
{
    CoreTools::OFStreamManager streamManager{ outputFileName, false };

    streamManager << content;
}

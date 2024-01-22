/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:55)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_FILE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_FILE_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateDirectory.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateFile
    {
    public:
        using ClassType = GenerateFile;

        using String = System::String;
        using StringView = System::StringView;
        using ReplaceContainer = std::vector<Replace>;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    public:
        GenerateFile(GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Generate(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName) const;
        void Generate(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName, const ReplaceContainer& replace) const;
        void Generate(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName, ProjectServiceType projectServiceType) const;
        void GenerateUtf8(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName) const;
        void GenerateUtf8(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName, const ReplaceContainer& replace) const;
        void GenerateSln(const GenerateDirectory& generateDirectory, const StringView& templateName, const StringView& originalName) const;
        static void GenerateByContent(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName, const ReplaceContainer& replace);
        static void GenerateByContent(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName);
        static void GenerateByContentUtf8(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName, const ReplaceContainer& replace);
        static void GenerateByContentUtf8(const GenerateDirectory& generateDirectory, const String& content, const StringView& originalName);

    private:
        NODISCARD static String GetInputFileName(const String& directory, const StringView& name);
        NODISCARD static String GetOutputFileName(const String& directory, const StringView& name);

        void Generate(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName) const;
        void Generate(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName, const ReplaceContainer& replace) const;
        void Generate(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName, ProjectServiceType projectServiceType) const;
        void GenerateUtf8(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName) const;
        void GenerateUtf8(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName, const ReplaceContainer& replace) const;
        void GenerateSln(const String& inputDirectory, const StringView& templateName, const String& outputDirectory, const StringView& originalName) const;

        void Generate(const String& inputFileName, const String& outputFileName) const;
        void Generate(const String& inputFileName, const String& outputFileName, const ReplaceContainer& replace) const;
        void Generate(const String& inputFileName, const String& outputFileName, ProjectServiceType projectServiceType) const;
        void GenerateUtf8(const String& inputFileName, const String& outputFileName) const;
        void GenerateUtf8(const String& inputFileName, const String& outputFileName, const ReplaceContainer& replace) const;
        void GenerateSln(const String& inputFileName, const String& outputFileName) const;
        static void GenerateByContent(const String& content, const String& outputFileName, const ReplaceContainer& replace);
        static void GenerateByContent(const String& content, const String& outputFileName);
        static void GenerateByContentUtf8(const String& content, const String& outputFileName, const ReplaceContainer& replace);
        static void GenerateByContentUtf8(const String& content, const String& outputFileName);

    private:
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_FILE_H

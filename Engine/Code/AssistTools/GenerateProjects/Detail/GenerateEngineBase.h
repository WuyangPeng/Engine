/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:55)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_BASE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_BASE_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateDirectory.h"
#include "GenerateFile.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateEngineBase
    {
    public:
        using ClassType = GenerateEngineBase;

        using String = System::String;

    public:
        GenerateEngineBase(const String& input, const String& output, const std::string& fileName);
        virtual ~GenerateEngineBase() noexcept = default;
        GenerateEngineBase(const GenerateEngineBase& rhs) = default;
        GenerateEngineBase& operator=(const GenerateEngineBase& rhs) = default;
        GenerateEngineBase(GenerateEngineBase&& rhs) noexcept = default;
        GenerateEngineBase& operator=(GenerateEngineBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void Generate() const;

    protected:
        using StringView = System::StringView;
        using ReplaceContainer = std::vector<Replace>;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    protected:
        NODISCARD String GetProjectName() const;
        NODISCARD String GetTestingName() const;

        NODISCARD static GenerateDirectory CreateBinaryConfigurationFileDirectory(const String& staticDescribe, const GenerateDirectory& directory);

        void Generate(const GenerateDirectory& directory, const ReplaceContainer& file) const;
        void Generate(const GenerateDirectory& directory, const ReplaceContainer& file, const ReplaceContainer& replace) const;
        void Generate(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName, const ReplaceContainer& replace) const;
        void Generate(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName, ProjectServiceType projectServiceType) const;
        void Generate(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName) const;
        void GenerateUtf8(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName) const;
        void GenerateSln(const GenerateDirectory& directory, const StringView& templateName, const StringView& originalName) const;

        NODISCARD GenerateDirectory GetGenerateDirectory(const StringView& pathRoute) const;
        NODISCARD GenerateDirectory GetGenerateDirectory(const StringView& inputPathRoute, const String& outputPathRoute) const;

        virtual void GenerateRunBat(const GenerateDirectory& directory) const;

        void GenerateWindowsProjectResource(const GenerateDirectory& directory) const;
        void GenerateWindowsProjectResourceTodo(const GenerateDirectory& directory) const;

        template <typename T>
        requires(std::is_base_of_v<ModuleGenerate, T>)
        void ExecuteModuleGenerate(const GenerateDirectory& directory) const;

    private:
        void GenerateTop() const;
        void GenerateBinary(const String& configuration) const;
        void GenerateCode() const;

        void Generate(const StringView& describe, const StringView& textName, const StringView& originalName) const;

        virtual void GenerateRun() const = 0;
        virtual void GenerateWindows() const = 0;

        virtual void GenerateBinaryConfiguration(const String& staticDescribe, const GenerateDirectory& directory) const = 0;
        virtual void GenerateCodeProject(const GenerateDirectory& directory) const = 0;
        virtual void GenerateCodeModule(const GenerateDirectory& directory) const = 0;
        virtual void GenerateRunBat(const String& moduleName, const GenerateDirectory& directory) const = 0;

    private:
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
        GenerateFile generateFile;
        GenerateDirectory generateDirectory;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_BASE_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:54)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_MODULE_GENERATE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_MODULE_GENERATE_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateFile.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"

#include <map>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE ModuleGenerate
    {
    public:
        using ClassType = ModuleGenerate;

        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;
        using MiddleLayerContainerConstIter = GameParameterAnalysis::MiddleLayerContainerConstIter;

    public:
        ModuleGenerate(GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept;
        virtual ~ModuleGenerate() noexcept = default;
        ModuleGenerate(const ModuleGenerate& rhs) = default;
        ModuleGenerate& operator=(const ModuleGenerate& rhs) = default;
        ModuleGenerate(ModuleGenerate&& rhs) noexcept = default;
        ModuleGenerate& operator=(ModuleGenerate&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void Generate();

    protected:
        using String = System::String;
        using StringView = System::StringView;
        using ReplaceContainer = std::vector<Replace>;
        using ContentType = std::map<String, String>;

    protected:
        NODISCARD String GetContent(const String& inputDirectory, const StringView& codeKey, ProjectGenerationType projectGenerationType = ProjectGenerationType::Default);
        NODISCARD String GetOnlyContent(const String& inputDirectory, const StringView& codeKey, ProjectGenerationType projectGenerationType = ProjectGenerationType::Default);

        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerBegin() const noexcept;
        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerEnd() const noexcept;

        NODISCARD String GetProjectName() const;

    private:
        virtual void GenerateModule(const GameModule& gameModule) = 0;

    private:
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
        ContentType content;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_MODULE_GENERATE_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/09 16:42)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"
#include "AssistTools/GenerateProjects/GenerateProjectsInternalFwd.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE ProjectGenerationImpl
    {
    public:
        using ClassType = ProjectGenerationImpl;
        using FactoryType = ProjectGenerationFactory;

        using String = System::String;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    public:
        ProjectGenerationImpl(String fileName, GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept;
        virtual ~ProjectGenerationImpl() noexcept = default;
        ProjectGenerationImpl(const ProjectGenerationImpl& rhs) = default;
        ProjectGenerationImpl& operator=(const ProjectGenerationImpl& rhs) = default;
        ProjectGenerationImpl(ProjectGenerationImpl&& rhs) noexcept = default;
        ProjectGenerationImpl& operator=(ProjectGenerationImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual String GetContent() const = 0;

    protected:
        using StringView = System::StringView;

    protected:
        NODISCARD virtual String GetTemplateContent() const;

        NODISCARD String GetFileName() const;

        NODISCARD GameParameterAnalysis GetGameParameterAnalysis() const noexcept;
        NODISCARD CodeMappingAnalysis GetCodeMappingAnalysis() const noexcept;

    private:
        String fileName;
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_IMPL_H
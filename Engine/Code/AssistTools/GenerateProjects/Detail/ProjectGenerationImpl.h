///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 14:18)

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
        ProjectGenerationImpl(ProjectGenerationImpl&& rhs) = default;
        ProjectGenerationImpl& operator=(ProjectGenerationImpl&& rhs) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual String GetContent() const = 0;

    protected:
        NODISCARD virtual String GetTemplateContent() const;
        NODISCARD String ReplaceCodeMapping(const String& templateContent, const String& codeKey) const;
        NODISCARD String ReplaceModuleCount(const String& templateContent) const;
        NODISCARD String ReplaceModuleDescribe(const String& templateContent) const;
        NODISCARD String ReplaceModuleJson(const String& templateContent) const;
        NODISCARD String ReplaceModuleTestingJson(const String& templateContent) const;
        NODISCARD String ReplaceProjectChineseName(const String& templateContent) const;
        NODISCARD String ReplaceProjectDescribeName(const String& templateContent) const;
        NODISCARD String ReplaceProjectName(const String& templateContent) const;
        NODISCARD String ReplaceTestingName(const String& templateContent) const;
        NODISCARD String ReplaceVersion(const String& templateContent) const;
        NODISCARD String ReplaceVersionNum(const String& templateContent) const;
        NODISCARD String ReplaceParameter(const String& templateContent, const String& codeKey, const String& parameter) const;
        NODISCARD String ReplaceCallRunBat(const String& templateContent, bool isClient) const;
        NODISCARD String CallRunTestingBat(const String& templateContent) const;
        NODISCARD String ReplaceProjectAbbreviation(const String& templateContent) const;
        NODISCARD String ReplaceEndYear(const String& templateContent) const;
        NODISCARD String ReplaceTime(const String& templateContent) const;
        NODISCARD String ReplaceCodeAnalysis(const String& templateContent) const;
        NODISCARD String ReplaceTestingCodeAnalysis(const String& templateContent) const;
        NODISCARD String ReplaceProjectCapital(const String& templateContent) const;
        NODISCARD String ReplaceCopyright(const String& templateContent) const;
        NODISCARD String ReplaceCoreName(const String& templateContent) const;
        NODISCARD String ReplaceCoreCapital(const String& templateContent) const;
        NODISCARD String ReplaceMiddleLayerInclude(const String& templateContent) const;
        NODISCARD String ReplaceMiddleLayerFwdInclude(const String& templateContent) const;

        NODISCARD String GetFileName() const;

    private:
        String fileName;
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_IMPL_H
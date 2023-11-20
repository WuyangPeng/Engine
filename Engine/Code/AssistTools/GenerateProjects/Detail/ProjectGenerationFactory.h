///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/09 16:41)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_FACTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_FACTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CharacterStringFwd.h"
#include "AssistTools/GenerateProjects/GenerateProjectsInternalFwd.h"

#include <memory>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE ProjectGenerationFactory
    {
    public:
        using ClassType = ProjectGenerationFactory;

        using String = System::String;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;
        using ReplaceContainer = std::vector<Replace>;
        using ProjectGenerationSharedPtr = std::shared_ptr<ProjectGenerationImpl>;

    public:
        ProjectGenerationFactory() noexcept = delete;

        NODISCARD static ProjectGenerationSharedPtr Create(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);
        NODISCARD static ProjectGenerationSharedPtr Create(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, ProjectServiceType projectServiceType);
        NODISCARD static ProjectGenerationSharedPtr Create(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, const ReplaceContainer& replace);
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_FACTORY_H
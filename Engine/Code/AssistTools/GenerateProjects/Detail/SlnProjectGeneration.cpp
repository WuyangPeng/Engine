///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.1 (2023/11/23 22:08)

#include "AssistTools/AssistToolsExport.h"

#include "ProjectGenerationReplace.h"
#include "SlnProjectGeneration.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::SlnProjectGeneration::SlnProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, SlnProjectGeneration)

System::String AssistTools::SlnProjectGeneration::GetContent() const
{
    ProjectGenerationReplace projectGenerationReplace{ ParentType::GetContent(), GetGameParameterAnalysis(), GetCodeMappingAnalysis() };

    projectGenerationReplace.ReplaceToolDirectory();
    projectGenerationReplace.ReplaceToolProject();
    projectGenerationReplace.ReplaceTestingToolProject();
    projectGenerationReplace.ReplaceToolNestedProjects();

    return projectGenerationReplace.GetReplaceResult();
}
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/09 16:49)

#include "AssistTools/AssistToolsExport.h"

#include "ClientProjectGeneration.h"
#include "ProjectGenerationReplace.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::ClientProjectGeneration::ClientProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, ProjectServiceType projectServiceType)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis }, projectServiceType{ projectServiceType }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ClientProjectGeneration)

AssistTools::ClientProjectGeneration::String AssistTools::ClientProjectGeneration::GetContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ProjectGenerationReplace projectGenerationReplace{ ParentType::GetContent(), GetGameParameterAnalysis(), GetCodeMappingAnalysis() };

    projectGenerationReplace.ReplaceCallRunBat(projectServiceType);

    return projectGenerationReplace.GetReplaceResult();
}
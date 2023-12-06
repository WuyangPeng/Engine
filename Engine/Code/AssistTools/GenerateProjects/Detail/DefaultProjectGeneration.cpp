/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 22:15)

#include "AssistTools/AssistToolsExport.h"

#include "DefaultProjectGeneration.h"
#include "ProjectGenerationReplace.h"
#include "System/Helper/EnumOperator.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"

using System::operator++;

AssistTools::DefaultProjectGeneration::DefaultProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, DefaultProjectGeneration)

System::String AssistTools::DefaultProjectGeneration::GetContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ProjectGenerationReplace projectGenerationReplace{ GetTemplateContent(), GetGameParameterAnalysis(), GetCodeMappingAnalysis() };

    if (projectGenerationReplace.IsEmpty())
    {
        return projectGenerationReplace.GetReplaceResult();
    }

    projectGenerationReplace.ReplaceCopyright();
    projectGenerationReplace.ReplaceTime();

    projectGenerationReplace.ReplaceModuleCount();
    projectGenerationReplace.ReplaceModuleDescribe();
    projectGenerationReplace.ReplaceModuleJson();
    projectGenerationReplace.ReplaceModuleTestingJson();

    projectGenerationReplace.ReplaceCodeAnalysis();
    projectGenerationReplace.ReplaceTestingCodeAnalysis();

    projectGenerationReplace.ReplaceMiddleLayerInclude();
    projectGenerationReplace.ReplaceMiddleLayerFwdInclude();

    projectGenerationReplace.ReplaceCallRunTestingBat();

    for (auto gameParameterType = GameParameterType::Begin; gameParameterType < GameParameterType::Count; ++gameParameterType)
    {
        projectGenerationReplace.ReplaceGameParameter(gameParameterType);
    }

    return projectGenerationReplace.GetReplaceResult();
}

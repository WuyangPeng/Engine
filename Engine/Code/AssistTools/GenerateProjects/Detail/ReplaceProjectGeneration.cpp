/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:58)

#include "AssistTools/AssistToolsExport.h"

#include "ProjectGenerationReplace.h"
#include "ReplaceProjectGeneration.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::ReplaceProjectGeneration::ReplaceProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, ReplaceContainer replace)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis }, replace{ std::move(replace) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ReplaceProjectGeneration)

AssistTools::ProjectGenerationImpl::String AssistTools::ReplaceProjectGeneration::GetContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ProjectGenerationReplace::ReplaceParameter(ParentType::GetContent(), replace);
}

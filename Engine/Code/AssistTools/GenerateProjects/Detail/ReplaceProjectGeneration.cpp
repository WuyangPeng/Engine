﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 15:25)

#include "AssistTools/AssistToolsExport.h"

#include "ReplaceProjectGeneration.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::ReplaceProjectGeneration::ReplaceProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, ReplaceType replace)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis }, replace{ std::move(replace) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ReplaceProjectGeneration)

AssistTools::ProjectGenerationImpl::String AssistTools::ReplaceProjectGeneration::GetContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = ParentType::GetContent();

    for (const auto& element : replace)
    {
        boost::algorithm::replace_all(content, SYSTEM_TEXT("$") + element.first + SYSTEM_TEXT("$"), element.second);
    }

    return content;
}

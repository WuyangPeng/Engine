///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 15:25)

#include "AssistTools/AssistToolsExport.h"

#include "ClientProjectGeneration.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::ClientProjectGeneration::ClientProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, bool isClient)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis }, isClient{ isClient }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ClientProjectGeneration)

AssistTools::ClientProjectGeneration::String AssistTools::ClientProjectGeneration::GetContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = ParentType::GetContent();

    content = ReplaceCallRunBat(content, isClient);

    return content;
}

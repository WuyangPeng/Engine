///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/24 13:34)

#include "AssistTools/AssistToolsExport.h"

#include "Utf8ReplaceProjectGeneration.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::Utf8ReplaceProjectGeneration::Utf8ReplaceProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis, ReplaceType{} }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

AssistTools::Utf8ReplaceProjectGeneration::Utf8ReplaceProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, const ReplaceType& replace)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, Utf8ReplaceProjectGeneration)

AssistTools::ProjectGenerationImpl::String AssistTools::Utf8ReplaceProjectGeneration::GetTemplateContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    const CoreTools::IFStreamManager streamManager{ GetFileName() };

    return streamManager.GetFileContent();
}

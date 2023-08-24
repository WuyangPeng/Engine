///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 15:25)

#include "AssistTools/AssistToolsExport.h"

#include "DefaultProjectGeneration.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::DefaultProjectGeneration::DefaultProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ fileName, gameParameterAnalysis, codeMappingAnalysis }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, DefaultProjectGeneration)

AssistTools::ProjectGenerationImpl::String AssistTools::DefaultProjectGeneration::GetContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GetTemplateContent();

    content = ReplaceCopyright(content);
    content = ReplaceProjectName(content);
    content = ReplaceProjectChineseName(content);
    content = ReplaceProjectDescribeName(content);
    content = ReplaceModuleCount(content);
    content = ReplaceModuleDescribe(content);
    content = ReplaceModuleJson(content);
    content = ReplaceProjectAbbreviation(content);
    content = ReplaceVersion(content);
    content = ReplaceVersionNum(content);
    content = ReplaceEndYear(content);
    content = ReplaceTime(content);
    content = ReplaceCodeAnalysis(content);
    content = ReplaceProjectCapital(content);
    content = ReplaceCoreName(content);
    content = ReplaceCoreCapital(content);
    content = ReplaceMiddleLayerInclude(content);
    content = ReplaceMiddleLayerFwdInclude(content);

    return content;
}

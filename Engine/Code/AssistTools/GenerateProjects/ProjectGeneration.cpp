///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 14:20)

#include "AssistTools/AssistToolsExport.h"

#include "ProjectGeneration.h"
#include "Detail/ProjectGenerationFactory.h"
#include "Detail/ProjectGenerationImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::ProjectGeneration::ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
    : impl{ CoreTools::ImplCreateUseFactory::Default, projectGenerationType, fileName, gameParameterAnalysis, codeMappingAnalysis }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

AssistTools::ProjectGeneration::ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, bool isClient)
    : impl{ CoreTools::ImplCreateUseFactory::Default, projectGenerationType, fileName, gameParameterAnalysis, codeMappingAnalysis, isClient }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

AssistTools::ProjectGeneration::ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, const ReplaceType& replace)
    : impl{ CoreTools::ImplCreateUseFactory::Default, projectGenerationType, fileName, gameParameterAnalysis, codeMappingAnalysis, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ProjectGeneration)

System::String AssistTools::ProjectGeneration::GetContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetContent();
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 14:26)

#include "AssistTools/AssistToolsExport.h"

#include "ClientProjectGeneration.h"
#include "DefaultProjectGeneration.h"
#include "ProjectGenerationFactory.h"
#include "ReplaceProjectGeneration.h"
#include "Utf8ReplaceProjectGeneration.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"

AssistTools::ProjectGenerationFactory::ProjectGenerationFactory() noexcept
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ProjectGenerationFactory)

AssistTools::ProjectGenerationFactory::ProjectGenerationSharedPtr AssistTools::ProjectGenerationFactory::Create(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis)
{
    switch (projectGenerationType)
    {
        case ProjectGenerationType::Default:
        {
            return std::make_shared<DefaultProjectGeneration>(fileName, gameParameterAnalysis, codeMappingAnalysis);
        }
        case ProjectGenerationType::Utf8:
        {
            return std::make_shared<Utf8ReplaceProjectGeneration>(fileName, gameParameterAnalysis, codeMappingAnalysis);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("ProjectGenerationType 无效"))
        }
    }
}

AssistTools::ProjectGenerationFactory::ProjectGenerationSharedPtr AssistTools::ProjectGenerationFactory::Create(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, bool isClient)
{
    switch (projectGenerationType)
    {
        case ProjectGenerationType::Default:
        {
            return std::make_shared<ClientProjectGeneration>(fileName, gameParameterAnalysis, codeMappingAnalysis, isClient);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("ProjectGenerationType 无效"))
        }
    }
}

AssistTools::ProjectGenerationFactory::ProjectGenerationSharedPtr AssistTools::ProjectGenerationFactory::Create(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, const ReplaceType& replace)
{
    switch (projectGenerationType)
    {
        case ProjectGenerationType::Default:
        {
            return std::make_shared<ReplaceProjectGeneration>(fileName, gameParameterAnalysis, codeMappingAnalysis, replace);
        }
        case ProjectGenerationType::Utf8:
        {
            return std::make_shared<Utf8ReplaceProjectGeneration>(fileName, gameParameterAnalysis, codeMappingAnalysis, replace);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("ProjectGenerationType 无效"))
        }
    }
}

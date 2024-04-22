/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:58)

#include "AssistTools/AssistToolsExport.h"

#include "ProjectGenerationImpl.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/GameModule.h"

AssistTools::ProjectGenerationImpl::ProjectGenerationImpl(String fileName, GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : fileName{ std::move(fileName) }, gameParameterAnalysis{ std::move(gameParameterAnalysis) }, codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ProjectGenerationImpl)

System::String AssistTools::ProjectGenerationImpl::GetFileName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return fileName;
}

AssistTools::GameParameterAnalysis AssistTools::ProjectGenerationImpl::GetGameParameterAnalysis() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameParameterAnalysis;
}

CoreTools::CodeMappingAnalysis AssistTools::ProjectGenerationImpl::GetCodeMappingAnalysis() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return codeMappingAnalysis;
}

System::String AssistTools::ProjectGenerationImpl::GetTemplateContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    CoreTools::IFileStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    return streamManager.GetFileContent();
}

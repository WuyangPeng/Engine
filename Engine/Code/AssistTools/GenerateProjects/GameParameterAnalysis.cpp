///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:56)

#include "AssistTools/AssistToolsExport.h"

#include "GameParameterAnalysis.h"
#include "Detail/GameParameterAnalysisImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GameParameterAnalysis::GameParameterAnalysis(const std::string& fileName)
    : impl{ fileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GameParameterAnalysis)

int AssistTools::GameParameterAnalysis::GetModuleCount() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetModuleCount();
}

AssistTools::GameParameterAnalysis::GameModuleContainerConstIter AssistTools::GameParameterAnalysis::GetModuleBegin() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetModuleBegin();
}

AssistTools::GameParameterAnalysis::GameModuleContainerConstIter AssistTools::GameParameterAnalysis::GetModuleEnd() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetModuleEnd();
}

AssistTools::GameParameterAnalysis::MiddleLayerContainerConstIter AssistTools::GameParameterAnalysis::GetMiddleLayerBegin() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetMiddleLayerBegin();
}

AssistTools::GameParameterAnalysis::MiddleLayerContainerConstIter AssistTools::GameParameterAnalysis::GetMiddleLayerEnd() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetMiddleLayerEnd();
}

bool AssistTools::GameParameterAnalysis::HasTools() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasTools();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetGameParameter(GameParameterType gameParameterType) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetGameParameter(gameParameterType);
}

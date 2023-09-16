///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 11:03)

#include "AssistTools/AssistToolsExport.h"

#include "GameParameterAnalysis.h"
#include "Detail/GameParameterAnalysisImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(AssistTools, GameParameterAnalysis)

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

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetCoreName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCoreName();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetCoreCapital() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCoreCapital();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetProjectChineseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectChineseName();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetProjectDescribeName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectDescribeName();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetProjectName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectName();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetProjectCapital() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectCapital();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetProjectAbbreviation() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectAbbreviation();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetEndYear() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEndYear();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetVersion() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVersion();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetVersionNum() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVersionNum();
}

AssistTools::GameParameterAnalysis::String AssistTools::GameParameterAnalysis::GetTestingName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetTestingName();
}

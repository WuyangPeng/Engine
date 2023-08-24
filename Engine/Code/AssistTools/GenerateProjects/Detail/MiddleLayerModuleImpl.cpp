///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/21 10:08)

#include "AssistTools/AssistToolsExport.h"

#include "MiddleLayerModuleImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::MiddleLayerModuleImpl::MiddleLayerModuleImpl(String middleLayerName, String uppercaseName, bool isManager) noexcept
    : middleLayerName{ std::move(middleLayerName) }, uppercaseName{ std::move(uppercaseName) }, isManager{ isManager }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, MiddleLayerModuleImpl)

System::String AssistTools::MiddleLayerModuleImpl::GetMiddleLayerName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return middleLayerName;
}

System::String AssistTools::MiddleLayerModuleImpl::GetUppercaseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return uppercaseName;
}

bool AssistTools::MiddleLayerModuleImpl::IsManager() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return isManager;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:40)

#include "AssistTools/AssistToolsExport.h"

#include "MiddleLayerModule.h"
#include "Detail/MiddleLayerModuleImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::MiddleLayerModule::MiddleLayerModule(const String& middleLayerName, const String& uppercaseName, bool isManager)
    : impl{ middleLayerName, uppercaseName, isManager }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, MiddleLayerModule)

AssistTools::MiddleLayerModule::String AssistTools::MiddleLayerModule::GetMiddleLayerName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetMiddleLayerName();
}

AssistTools::MiddleLayerModule::String AssistTools::MiddleLayerModule::GetUppercaseName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetUppercaseName();
}

bool AssistTools::MiddleLayerModule::IsManager() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsManager();
}

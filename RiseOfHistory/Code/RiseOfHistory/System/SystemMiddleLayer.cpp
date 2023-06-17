///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.9.0.12 (2023/06/17 12:41)

#include "RiseOfHistory/Helper/RiseOfHistoryClassInvariantMacro.h"
#include "RiseOfHistory/Resource/ResourceMiddleLayer.h"
#include "SystemMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/ExceptionMacro.h"

RiseOfHistory::SystemMiddleLayer::SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    RISE_OF_HISTORY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RiseOfHistory, SystemMiddleLayer)

void RiseOfHistory::SystemMiddleLayer::Execute(int select)
{
    RISE_OF_HISTORY_CLASS_IS_VALID_1;

    auto resource = boost::polymorphic_pointer_downcast<ResourceMiddleLayer>(GetResourceManager());

    if (resource->IsSelectValid(select))
    {
        const auto engineeringName = resource->GetEngineeringName(select);

        resource->PrintEngineering(engineeringName);

        if (!System::CreateSystemProcess(engineeringName))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("打开进程"s) + engineeringName + SYSTEM_TEXT("失败！"s));
        }
    }
}

int RiseOfHistory::SystemMiddleLayer::GetContainerPrintWidth() const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_1;

    auto resource = boost::polymorphic_pointer_downcast<const ResourceMiddleLayer>(GetResourceManager());

    return resource->GetContainerPrintWidth();
}

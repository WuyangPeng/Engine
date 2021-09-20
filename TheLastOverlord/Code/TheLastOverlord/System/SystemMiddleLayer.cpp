///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	最后的霸王版本：0.7.0.1 (2021/02/18 15:02)

#include "SystemMiddleLayer.h"
#include "TheLastOverlord/Helper/TheLastOverlordClassInvariantMacro.h"
#include "TheLastOverlord/Resource/ResourceMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/ExceptionMacro.h"

TheLastOverlord::SystemMiddleLayer::SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    THE_LAST_OVERLORD_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlord, SystemMiddleLayer)

void TheLastOverlord::SystemMiddleLayer::Execute(int select)
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_1;

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

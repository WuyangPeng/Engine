///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 14:00)

#include "SystemMiddleLayer.h"
#include "ThreadingCoreRenderEngineAssist/Helper/AssistClassInvariantMacro.h"
#include "ThreadingCoreRenderEngineAssist/Resource/ResourceMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/ExceptionMacro.h"

ThreadingCoreRenderEngineAssist::SystemMiddleLayer::SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    ASSIST_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineAssist, SystemMiddleLayer)

void ThreadingCoreRenderEngineAssist::SystemMiddleLayer::Execute(int select)
{
    ASSIST_CLASS_IS_VALID_1;

    auto resource = boost::polymorphic_pointer_downcast<ResourceMiddleLayer>(GetResourceManager());

    const auto engineeringName = resource->GetEngineeringNameOrEmpty(select);

    if (!engineeringName.empty())
    {
        resource->PrintEngineering(engineeringName);

        if (!System::CreateSystemProcess(engineeringName))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("打开进程"s) + engineeringName + SYSTEM_TEXT("失败！"s));
        }
    }
}

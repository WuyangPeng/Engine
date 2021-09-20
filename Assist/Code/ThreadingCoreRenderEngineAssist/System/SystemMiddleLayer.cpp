///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 10:47)

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
            THROW_EXCEPTION(SYSTEM_TEXT("�򿪽���"s) + engineeringName + SYSTEM_TEXT("ʧ�ܣ�"s));
        }
    }
}

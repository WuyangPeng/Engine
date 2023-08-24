///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 16:10)

#include "Framework/FrameworkExport.h"

#include "ResourceProjectManager.h"
#include "SystemProjectManager.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::SystemProjectManager::SystemProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SystemProjectManager)

void Framework::SystemProjectManager::Execute(int select)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (const auto resource = GetResourceManager<ResourceProjectManager>();
        resource->IsSelectValid(select))
    {
        const auto engineeringName = resource->GetEngineeringName(select);

        resource->PrintEngineering(engineeringName);

        if (!System::CreateSystemProcess(engineeringName))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("打开进程"s) + engineeringName + SYSTEM_TEXT("失败！"s))
        }
    }
}

int Framework::SystemProjectManager::GetContainerPrintWidth() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    const auto resource = GetResourceManager<ResourceProjectManager>();

    return resource->GetContainerPrintWidth();
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 16:10)

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
            THROW_EXCEPTION(SYSTEM_TEXT("�򿪽���"s) + engineeringName + SYSTEM_TEXT("ʧ�ܣ�"s))
        }
    }
}

int Framework::SystemProjectManager::GetContainerPrintWidth() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    const auto resource = GetResourceManager<ResourceProjectManager>();

    return resource->GetContainerPrintWidth();
}

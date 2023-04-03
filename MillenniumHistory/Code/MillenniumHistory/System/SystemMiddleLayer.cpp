///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:27)

#include "MillenniumHistory/Helper/MillenniumHistoryClassInvariantMacro.h"
#include "MillenniumHistory/Resource/ResourceMiddleLayer.h"
#include "SystemMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/ExceptionMacro.h"

MillenniumHistory::SystemMiddleLayer::SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MillenniumHistory, SystemMiddleLayer)

void MillenniumHistory::SystemMiddleLayer::Execute(int select)
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    if (const auto resource = boost::polymorphic_pointer_downcast<ResourceMiddleLayer>(GetResourceManager());
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

int MillenniumHistory::SystemMiddleLayer::GetContainerPrintWidth() const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1;

    const auto resource = boost::polymorphic_pointer_downcast<const ResourceMiddleLayer>(GetResourceManager());

    return resource->GetContainerPrintWidth();
}

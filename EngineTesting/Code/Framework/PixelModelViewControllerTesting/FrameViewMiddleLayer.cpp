///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:33)

#include "FrameViewMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"

#include <iostream>

PixelModelViewController::FrameViewMiddleLayer::FrameViewMiddleLayer(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, timeDelta{ timerInterval }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(PixelModelViewController, FrameViewMiddleLayer)

bool PixelModelViewController::FrameViewMiddleLayer::Idle(int64_t aTimeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Idle(aTimeDelta))
    {
        PrintFrameRateMessage(aTimeDelta);

        return true;
    }
    else
    {
        return false;
    }
}

// private
void PixelModelViewController::FrameViewMiddleLayer::PrintFrameRateMessage(int64_t aTimeDelta)
{
    timeDelta -= aTimeDelta;
    if (timeDelta <= 0)
    {
        auto modelMiddleLayer = boost::polymorphic_pointer_downcast<Framework::ModelMiddleLayer>(this->GetModelMiddleLayer());

        if (modelMiddleLayer)
        {
            std::cout << modelMiddleLayer->GetFrameRateMessage() << '\n';
        }

        timeDelta = timerInterval;
    }
}

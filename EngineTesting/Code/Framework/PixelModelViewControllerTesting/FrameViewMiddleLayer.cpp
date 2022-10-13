///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 17:07)

#include "FrameViewMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"

#include <iostream>

using std::cout;

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
            cout << modelMiddleLayer->GetFrameRateMessage() << '\n';
        }

        timeDelta = timerInterval;
    }
}

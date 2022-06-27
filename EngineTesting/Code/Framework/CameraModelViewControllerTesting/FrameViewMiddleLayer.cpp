///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/23 17:21)

#include "FrameViewMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"

#include <iostream>

using std::cout;

CameraModelViewController::FrameViewMiddleLayer::FrameViewMiddleLayer(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, timeDelta{ timerInterval }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CameraModelViewController, FrameViewMiddleLayer)

bool CameraModelViewController::FrameViewMiddleLayer::Idle(int64_t aTimeDelta)
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
void CameraModelViewController::FrameViewMiddleLayer::PrintFrameRateMessage(int64_t aTimeDelta)
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

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 17:08)

#ifndef PIXEL_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H
#define PIXEL_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

#include "System/Time/Using/DeltaTimeUsing.h"
#include "Framework/MiddleLayer/PixelViewMiddleLayer.h"

namespace PixelModelViewController
{
    class FrameViewMiddleLayer : public Framework::PixelViewMiddleLayer
    {
    public:
        using ClassType = FrameViewMiddleLayer;
        using ParentType = PixelViewMiddleLayer;

    public:
        explicit FrameViewMiddleLayer(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool Idle(int64_t timeDelta) override;

    private:
        void PrintFrameRateMessage(int64_t timeDelta);

    private:
        static constexpr int timerInterval = System::g_Microseconds;

        int64_t timeDelta;
    };
}

#endif  // PIXEL_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

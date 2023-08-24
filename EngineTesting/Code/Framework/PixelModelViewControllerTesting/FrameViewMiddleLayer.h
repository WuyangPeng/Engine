///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 11:02)

#ifndef PIXEL_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H
#define PIXEL_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

#include "System/Time/Using/DeltaTimeUsing.h"
#include "Framework/MiddleLayer/PixelViewMiddleLayer.h"

namespace PixelModelViewController
{
    class FrameViewMiddleLayer final : public Framework::PixelViewMiddleLayer
    {
    public:
        using ClassType = FrameViewMiddleLayer;
        using ParentType = PixelViewMiddleLayer;

    public:
        FrameViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool Idle(int64_t timeDelta) override;

    private:
        void PrintFrameRateMessage(int64_t timeDelta);

    private:
        static constexpr int timerInterval = System::gMicroseconds;

        int64_t timeDelta;
    };
}

#endif  // PIXEL_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

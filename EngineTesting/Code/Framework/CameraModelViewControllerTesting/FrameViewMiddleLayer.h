///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/23 17:22)

#ifndef CAMERA_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H
#define CAMERA_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

#include "System/Time/Using/DeltaTimeUsing.h"
#include "Framework/MiddleLayer/CameraViewMiddleLayer.h"

namespace CameraModelViewController
{
    class FrameViewMiddleLayer : public Framework::CameraViewMiddleLayer
    {
    public:
        using ClassType = FrameViewMiddleLayer;
        using ParentType = CameraViewMiddleLayer;

    public:
        explicit FrameViewMiddleLayer(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool Idle(int64_t timeDelta) override;

    private:
        void PrintFrameRateMessage(int64_t aTimeDelta);

    private:
        static constexpr int timerInterval = System::g_Microseconds;

        int64_t timeDelta;
    };
}

#endif  // CAMERA_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

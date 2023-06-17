///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 18:05)

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
        explicit FrameViewMiddleLayer(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool Idle(int64_t timeDelta) override;

    private:
        void PrintFrameRateMessage(int64_t aTimeDelta);

    private:
        static constexpr int timerInterval = System::gMicroseconds;

        int64_t timeDelta;
    };
}

#endif  // CAMERA_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

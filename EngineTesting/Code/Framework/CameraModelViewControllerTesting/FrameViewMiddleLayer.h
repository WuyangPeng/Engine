// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 17:35)

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
        void PrintFrameRateMessage(int64_t timeDelta);

    private:
        static constexpr int sm_TimerInterval = System::g_Microseconds;

        int64_t m_TimeDelta;
    };
}

#endif  // CAMERA_MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

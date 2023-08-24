///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MODEL_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MODEL_MIDDLE_LAYER_TESTING_H

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class CameraModelMiddleLayerTesting final : public CameraMiddleLayerTesting
    {
    public:
        using ClassType = CameraModelMiddleLayerTesting;
        using ParentType = CameraMiddleLayerTesting;

    public:
        explicit CameraModelMiddleLayerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void MiddleLayerTest();
        void FrameRateTest();
        void CameraMotionSpeedTest(); 
        void MoveObjectTest();
        void TrackBallDownTest();
        void RotateTrackBallTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MODEL_MIDDLE_LAYER_TESTING_H
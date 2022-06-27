///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 10:25)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayer.h"

namespace Framework
{
    class CameraControllerMiddleLayerTesting final : public CameraMiddleLayerTesting
    {
    public:
        using ClassType = CameraControllerMiddleLayerTesting;
        using ParentType = CameraMiddleLayerTesting;

    public:
        explicit CameraControllerMiddleLayerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void MiddleLayerTest();
        void KeyDownTest();
        void CameraMotionMoveTest() noexcept;
        void MoveObjectTest() noexcept;
        void TrackBallDownTest();
        void RotateTrackBallTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H
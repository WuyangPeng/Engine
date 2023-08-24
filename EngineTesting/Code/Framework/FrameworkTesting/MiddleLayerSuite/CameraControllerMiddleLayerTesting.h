///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/12 15:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

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
        void DoRunUnitTest() override;

        void MainTest();

        void MiddleLayerTest();
        void KeyDownTest();
        void TrackBallDownTest();
        void RotateTrackBallTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H
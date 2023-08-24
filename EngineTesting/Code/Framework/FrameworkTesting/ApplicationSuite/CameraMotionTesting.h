///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 20:33)

#ifndef FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/SceneGraph/Camera.h"

namespace Framework
{
    class CameraMotionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CameraMotionTesting;
        using ParentType = UnitTest;

        using Camera = Rendering::Camera;
        using CameraSharedPtr = Rendering::CameraSharedPtr;

    public:
        explicit CameraMotionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void BaseTest();
        void SpeedTest();
        void MoveTest();

        void AssertCamera(const Camera& lhs, const Camera& rhs);
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H

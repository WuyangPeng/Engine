///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:15)

#ifndef FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Rendering/SceneGraph/Camera.h"

namespace Framework
{
    class CameraMotionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CameraMotionTesting;
        using ParentType = UnitTest;
        using CameraSmartPointer = Rendering::CameraSharedPtr;

    public:
        explicit CameraMotionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void BaseTest();
        void SpeedTest();
        void MoveTest();

        void AssertCamera(const CameraSmartPointer& lhs, const CameraSmartPointer& rhs);
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H

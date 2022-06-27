///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 10:24)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_SYSTEMS_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_SYSTEMS_MANAGER_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class CameraSystemsManagerInterfaceTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = CameraSystemsManagerInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit CameraSystemsManagerInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void MiddleLayerTest();
        void SetMiddleLayerTest();

        void SetNetworkManagerExceptionTest();
        void SetInputManagerExceptionTest();
        void SetObjectLogicManagerExceptionTest();
        void SetPhysicalModellingManagerExceptionTest();
        void SetMessageManagerExceptionTest();
        void SetEventManagerExceptionTest();
        void SetSystemManagerTest();
        void SetResourceManagerExceptionTest();
        void SetAudioManagerExceptionTest();
        void SetCameraSystemsManagerExceptionTest();
        void SetRenderingManagerTest();
        void SetGUIManagerTest();

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_SYSTEMS_MANAGER_INTERFACE_TESTING_H
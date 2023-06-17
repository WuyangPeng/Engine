///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:03)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_INPUT_MANAGER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_INPUT_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class InputManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = InputManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit InputManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void MiddleLayerTest();
        void SetMiddleLayerTest();

        void SetNetworkManagerTest();
        void SetInputManagerExceptionTest();
        void SetObjectLogicManagerTest();
        void SetPhysicalModellingManagerExceptionTest();
        void SetMessageManagerExceptionTest();
        void SetEventManagerExceptionTest();
        void SetSystemManagerTest();
        void SetResourceManagerExceptionTest();
        void SetAudioManagerExceptionTest();
        void SetCameraSystemsManagerTest();
        void SetRenderingManagerExceptionTest();
        void SetGUIManagerExceptionTest();

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_INPUT_MANAGER_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/12 15:25)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_PHYSICAL_MODELLING_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_PHYSICAL_MODELLING_MANAGER_INTERFACE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class PhysicalModellingManagerInterfaceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PhysicalModellingManagerInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit PhysicalModellingManagerInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void MiddleLayerTest();
        void SetMiddleLayerTest();

        void SetNetworkManagerExceptionTest();
        void SetInputManagerExceptionTest();
        void SetObjectLogicManagerTest();
        void SetPhysicalModellingManagerExceptionTest();
        void SetMessageManagerExceptionTest();
        void SetEventManagerExceptionTest();
        void SetSystemManagerExceptionTest();
        void SetResourceManagerExceptionTest();
        void SetAudioManagerExceptionTest();
        void SetCameraSystemsManagerExceptionTest();
        void SetRenderingManagerExceptionTest();
        void SetGUIManagerExceptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_PHYSICAL_MODELLING_MANAGER_INTERFACE_TESTING_H
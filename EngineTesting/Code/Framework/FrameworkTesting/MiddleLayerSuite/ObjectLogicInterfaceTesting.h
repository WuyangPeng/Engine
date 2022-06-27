///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 10:23)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_OBJECT_LOGIC_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_OBJECT_LOGIC_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class ObjectLogicInterfaceTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ObjectLogicInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectLogicInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void MiddleLayerTest();
        void SetMiddleLayerTest();

        void SetNetworkManagerTest();
        void SetInputManagerTest();
        void SetObjectLogicManagerExceptionTest();
        void SetPhysicalModellingManagerTest();
        void SetMessageManagerTest();
        void SetEventManagerExceptionTest();
        void SetSystemManagerTest();
        void SetResourceManagerExceptionTest();
        void SetAudioManagerExceptionTest();
        void SetCameraSystemsManagerExceptionTest();
        void SetRenderingManagerExceptionTest();
        void SetGUIManagerExceptionTest();

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_OBJECT_LOGIC_INTERFACE_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:25)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_OBJECT_LOGIC_MANAGER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_OBJECT_LOGIC_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class ObjectLogicManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ObjectLogicManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectLogicManagerTesting(const OStreamShared& stream);

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

        void DoRunUnitTest() override;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H
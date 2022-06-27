///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 10:20)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_SYSTEM_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_SYSTEM_MANAGER_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class SystemManagerInterfaceTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SystemManagerInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit SystemManagerInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void MiddleLayerTest();
        void SetMiddleLayerTest();

        void SetNetworkManagerExceptionTest();
        void SetInputManagerTest();
        void SetObjectLogicManagerTest();
        void SetPhysicalModellingManagerExceptionTest();
        void SetMessageManagerTest();
        void SetEventManagerTest();
        void SetSystemManagerExceptionTest();
        void SetResourceManagerTest();
        void SetAudioManagerTest();
        void SetCameraSystemsManagerTest();
        void SetRenderingManagerTest();
        void SetGUIManagerExceptionTest();
        void SetEngineManagerTest();

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_SYSTEM_MANAGER_INTERFACE_TESTING_H
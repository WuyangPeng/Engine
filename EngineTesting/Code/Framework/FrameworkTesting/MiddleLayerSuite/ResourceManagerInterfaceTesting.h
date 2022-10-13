///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/02 13:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_RESOURCE_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_RESOURCE_MANAGER_INTERFACE_TESTING_H

#include "MiddleLayerInterfaceTestingBase.h"

namespace Framework
{
    class ResourceManagerInterfaceTesting : public MiddleLayerInterfaceTestingBase
    {
    public:
        using ClassType = ResourceManagerInterfaceTesting;
        using ParentType = MiddleLayerInterfaceTestingBase;

    public:
        explicit ResourceManagerInterfaceTesting(const OStreamShared& stream);

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
        void SetAudioManagerTest();
        void SetCameraSystemsManagerExceptionTest();
        void SetRenderingManagerTest();
        void SetGUIManagerTest();

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_RESOURCE_MANAGER_INTERFACE_TESTING_H
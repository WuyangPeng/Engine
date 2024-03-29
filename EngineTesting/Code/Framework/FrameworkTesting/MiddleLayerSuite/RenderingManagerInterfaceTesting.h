///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:26)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MANAGER_INTERFACE_TESTING_H

#include "MiddleLayerInterfaceTestingBase.h"

namespace Framework
{
    class RenderingManagerInterfaceTesting final : public MiddleLayerInterfaceTestingBase
    {
    public:
        using ClassType = RenderingManagerInterfaceTesting;
        using ParentType = MiddleLayerInterfaceTestingBase;

    public:
        explicit RenderingManagerInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void MiddleLayerTest();
        void MiddleLayerExceptionTest();

        void SetMiddleLayerTest();
        void SetSystemManagerTest();

        void GetMiddleLayerTest();
        void GetConstMiddleLayerTest();
        void GetSystemManagerTest();

        void RendererTest();
        void RendererExceptionTest();
        void ConstRendererExceptionTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MANAGER_INTERFACE_TESTING_H
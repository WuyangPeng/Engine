///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:04)

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
        void DoRunUnitTest() final;

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
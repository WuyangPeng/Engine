///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:03)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H

#include "MiddleLayerInterfaceTestingBase.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

namespace Framework
{
    class EngineMiddleLayerInterfaceTesting final : public MiddleLayerInterfaceTestingBase
    {
    public:
        using ClassType = EngineMiddleLayerInterfaceTesting;
        using ParentType = MiddleLayerInterfaceTestingBase;

    public:
        explicit EngineMiddleLayerInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void SetMiddleLayerTest();
        void GetMiddleLayerTest();
        void GetConstMiddleLayerTest();
        void GetNullMiddleLayerTest();
        void GetConstNullMiddleLayerTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H
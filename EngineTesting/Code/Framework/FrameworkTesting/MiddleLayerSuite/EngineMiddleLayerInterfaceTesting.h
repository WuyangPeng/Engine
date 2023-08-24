///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:22)

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
        void DoRunUnitTest() override;

        void MainTest();

        void SetMiddleLayerTest();
        void GetMiddleLayerTest();
        void GetConstMiddleLayerTest();
        void GetNullMiddleLayerTest();
        void GetConstNullMiddleLayerTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H
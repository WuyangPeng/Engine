///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/08/30 17:19)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_H

#include "MiddleLayerInterfaceTestingBase.h"

namespace Framework
{
    class MiddleLayerInterfaceTesting final : public MiddleLayerInterfaceTestingBase
    {
    public:
        using ClassType = MiddleLayerInterfaceTesting;
        using ParentType = MiddleLayerInterfaceTestingBase;

    public:
        explicit MiddleLayerInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/08/30 17:19)

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
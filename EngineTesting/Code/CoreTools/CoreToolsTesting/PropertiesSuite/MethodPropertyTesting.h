///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:24)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MethodPropertyTesting final : public UnitTest
    {
    public:
        using ClassType = MethodPropertyTesting;
        using ParentType = UnitTest;

    public:
        explicit MethodPropertyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void GetTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_TESTING_H

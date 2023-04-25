///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:26)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SimplePropertyExternalTesting final : public UnitTest
    {
    public:
        using ClassType = SimplePropertyExternalTesting;
        using ParentType = UnitTest;

    public:
        explicit SimplePropertyExternalTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void GetSetTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_TESTING_H

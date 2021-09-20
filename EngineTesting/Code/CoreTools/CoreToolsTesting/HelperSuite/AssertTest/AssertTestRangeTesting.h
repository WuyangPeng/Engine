///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/02 19:33)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_RANGE_TESTINGG_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_RANGE_TESTINGG_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestRangeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AssertTestRangeTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestRangeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AssertRangeTest();
        void AssertRangeMessageTest();
        void AssertRangeFailureThrowTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_RANGE_TESTINGG_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 21:30)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_RANGE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_RANGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestRangeTesting final : public UnitTest
    {
    public:
        using ClassType = AssertTestRangeTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestRangeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertRangeTest();
        void AssertRangeMessageTest();
        void AssertRangeFailureThrowTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_RANGE_TESTING_H
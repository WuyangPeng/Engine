///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/06 11:40)

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
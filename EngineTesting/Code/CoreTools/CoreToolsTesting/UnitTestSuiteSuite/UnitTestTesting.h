///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 14:01)

#ifndef CONCURRENT_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_TESTING_H
#define CONCURRENT_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UnitTestTesting : public UnitTest
    {
    public:
        using ClassType = UnitTestTesting;
        using ParentType = UnitTest;

    public:
        explicit UnitTestTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void NameTest();
        void StreamTest() noexcept;
        void AssertTestTest();
        void ErrorTestTest();
        void AssertEqualTest();
        void AssertCompareTest();
        void AssertNotThrowTest();
        void AssertThrowTest();
        void TestResultTest();

        void NotThrowException() noexcept;
        void NotThrowExceptionWithParameter(int parameter) noexcept;
        void NotThrowExceptionWithTwoParameter(int parameter1, float parameter2) noexcept;
        void ThrowException();
        void ThrowExceptionWithParameter(int parameter);
        void ThrowExceptionWithTwoParameter(int parameter1, float parameter2);

        void DoRunUnitTest() override;

    private:
        int passNumber;
        int failNumber;
        int errorNumber;
    };

    NODISCARD bool Approximate(double lhs, double rhs, double epsilon) noexcept;
}

#endif  // CONCURRENT_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_TESTING_H
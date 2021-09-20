// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:18)

#ifndef CONCURRENT_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_TESTING_H
#define CONCURRENT_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class UnitTestTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(UnitTestTesting);

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
        int m_PassNumber;
        int m_FailNumber;
        int m_ErrorNumber;
    };

    bool Approximate(double lhs, double rhs, double epsilon) noexcept;
}

#endif  // CONCURRENT_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_TESTING_H
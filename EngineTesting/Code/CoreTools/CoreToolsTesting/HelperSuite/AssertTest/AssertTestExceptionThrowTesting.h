/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 21:30)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_EXCEPTION_THROW_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_EXCEPTION_THROW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestExceptionThrowTesting final : public UnitTest
    {
    public:
        using ClassType = AssertTestExceptionThrowTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestExceptionThrowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertTrueFailureThrowExceptionTest();
        void AssertFalseFailureThrowExceptionTest();

        void AssertEqualFailureThrowExceptionTest();
        void AssertEqualDoNotUseMessageFailureThrowExceptionTest();
        void AssertEnumEqualFailureThrowExceptionTest();
        void AssertSignedEnumEqualFailureThrowExceptionTest();
        void AssertThreeEqualFailureThrowExceptionTest();
        void AssertFloatingPointCompleteEqualFailureThrowExceptionTest();

        void AssertUnequalFailureThrowExceptionTest();
        void AssertUnequalDoNotUseMessageFailureThrowExceptionTest();
        void AssertEnumUnequalFailureThrowExceptionTest();
        void AssertSignedEnumUnequalFailureThrowExceptionTest();
        void AssertFloatingPointCompleteUnequalFailureThrowExceptionTest();

        void AssertApproximateFailureThrowExceptionTest();
        void AssertApproximateUseFunctionFailureThrowExceptionTest();
        void AssertApproximateFloatZeroFailureThrowExceptionTest();
        void AssertApproximateDoubleZeroFailureThrowExceptionTest();

        void AssertLessFailureThrowExceptionTest();
        void AssertEnumLessFailureThrowExceptionTest();
        void AssertSignedEnumLessFailureThrowExceptionTest();

        void AssertLessEqualFailureThrowExceptionTest();
        void AssertEnumLessEqualFailureThrowExceptionTest();
        void AssertSignedEnumLessEqualFailureThrowExceptionTest();

        void AssertGreaterFailureThrowExceptionTest();
        void AssertEnumGreaterFailureThrowExceptionTest();
        void AssertSignedEnumGreaterFailureThrowExceptionTest();

        void AssertGreaterEqualFailureThrowExceptionTest();
        void AssertEnumGreaterEqualFailureThrowExceptionTest();
        void AssertSignedEnumGreaterEqualFailureThrowExceptionTest();

        void AssertEqualNullptrFailureThrowExceptionTest();
        void AssertUnequalNullptrFailureThrowExceptionTest();

        void AssertRangeFailureThrowExceptionTest();

        void TestEnd();

        NODISCARD static bool Approximate(float lhs, float rhs, float epsilon) noexcept;

    private:
        int failedNumber;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_EXCEPTION_THROW_TESTING_H
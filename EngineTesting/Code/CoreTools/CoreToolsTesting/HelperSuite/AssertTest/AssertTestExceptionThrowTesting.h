///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/02 16:37)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_EXCEPTION_THROW_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_EXCEPTION_THROW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestExceptionThrowTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AssertTestExceptionThrowTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestExceptionThrowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AssertTrueFailureThrowExceptionTest();
        void AssertFalseFailureThrowExceptionTest();
        void AssertEqualFailureThrowExceptionTest();
        void AssertEqualDoNotUseMessageFailureThrowExceptionTest();
        void AssertEnumEqualFailureThrowExceptionTest();
        void AssertSignedEqualFailureThrowExceptionTest();
        void AssertThreeEqualFailureThrowExceptionTest();
        void AssertFloatingPointCompleteEquallFailureThrowExceptionTest();
        void AssertUnequalFailureThrowExceptionTest();
        void AssertUnequalDoNotUseMessageFailureThrowExceptionTest();
        void AssertEnumUnequalFailureThrowExceptionTest();
        void AssertSignedUnequalFailureThrowExceptionTest();
        void AssertFloatingPointCompleteUnequalFailureThrowExceptionTest();
        void AssertApproximateFailureThrowExceptionTest();
        void AssertApproximateUseFunctionFailureThrowExceptionTest();
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
        void AssertEnumLessGreaterEqualFailureThrowExceptionTest();
        void AssertSignedEnumGreaterEqualFailureThrowExceptionTest();
        void AssertEqualNullptrFailureThrowExceptionTest();
        void AssertUnequalNullptrFailureThrowExceptionTest();
        void AssertRangeFailureThrowExceptionTest();

        NODISCARD static bool Approximate(float lhs, float rhs, float epsilon) noexcept;

    private:
        int failedNumber;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_EXCEPTION_THROW_TESTING_H
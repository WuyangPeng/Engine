///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:12)

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
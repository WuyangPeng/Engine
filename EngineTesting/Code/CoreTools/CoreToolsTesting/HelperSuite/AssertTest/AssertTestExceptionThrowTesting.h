///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:51)

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
        void AssertFloatingPointCompleteEquallFailureThrowExceptionTest();

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
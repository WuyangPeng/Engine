///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/06 11:32)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_APPROXIMATE_TESTINGG_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_APPROXIMATE_TESTINGG_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestApproximateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AssertTestApproximateTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestApproximateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AssertApproximateTest();
        void AssertApproximateMessageTest();
        void AssertApproximateFailureThrowTest();
        void AssertApproximateFloatZeroTest();
        void AssertApproximateDoubleZeroTest();

        NODISCARD static bool Approximate(float lhs, float rhs, float epsilon) noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_APPROXIMATE_TESTINGG_H
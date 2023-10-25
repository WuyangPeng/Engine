///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:29)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_APPROXIMATE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_APPROXIMATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestApproximateTesting final : public UnitTest
    {
    public:
        using ClassType = AssertTestApproximateTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestApproximateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertApproximateTest();
        void AssertApproximateMessageTest();
        void AssertApproximateFailureThrowTest();
        void AssertApproximateFloatZeroTest();
        void AssertApproximateDoubleZeroTest();

        NODISCARD static bool Approximate(float lhs, float rhs, float epsilon) noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_APPROXIMATE_TESTING_H
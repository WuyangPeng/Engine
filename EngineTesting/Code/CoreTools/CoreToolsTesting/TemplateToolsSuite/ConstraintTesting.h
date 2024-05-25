/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 11:05)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_CONSTRAINT_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_CONSTRAINT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConstraintTesting final : public UnitTest
    {
    public:
        using ClassType = ConstraintTesting;
        using ParentType = UnitTest;

    public:
        explicit ConstraintTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MustBePodTest() noexcept;
        void MustBeSameSizeTest() noexcept;
        void MustBeSubscriptableTest() noexcept;
        void MustHaveBaseTest() noexcept;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_CONSTRAINT_TESTING_H

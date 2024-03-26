/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 10:55)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_ANDABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_ANDABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief 枚举&运算符测试
    class EnumAndableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumAndableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumAndableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SignedOperatorTest();
        void SignedConstexprOperatorTest() const noexcept;
        void UnsignedOperatorTest();
        void UnsignedConstexprOperatorTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_ANDABLE_TESTING_H

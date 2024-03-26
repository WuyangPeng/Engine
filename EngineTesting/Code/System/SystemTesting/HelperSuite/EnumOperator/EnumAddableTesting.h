/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 10:47)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_ADDABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_ADDABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief 枚举加法测试。
    class EnumAddableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumAddableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumAddableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SignedOperatorTest();
        void SignedConstexprOperator0Test() const noexcept;
        void SignedConstexprOperator1Test() const noexcept;
        void UnsignedOperatorTest();
        void UnsignedConstexprOperator0Test() const noexcept;
        void UnsignedConstexprOperator1Test() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_ADDABLE_TESTING_H

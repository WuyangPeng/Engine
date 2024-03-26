/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 11:00)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @Brief 枚举取反测试
    class EnumNegateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumNegateTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumNegateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SignedConstexprOperatorTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H

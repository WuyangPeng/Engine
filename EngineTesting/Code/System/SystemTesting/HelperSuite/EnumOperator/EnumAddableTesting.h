///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 19:25)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_ADDABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_ADDABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumAddableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumAddableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumAddableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SignedOperatorTest();
        void SignedConstexprOperator0Test() noexcept;
        void SignedConstexprOperator1Test() noexcept;
        void UnsignedOperatorTest();
        void UnsignedConstexprOperator0Test() noexcept;
        void UnsignedConstexprOperator1Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_ADDABLE_TESTING_H

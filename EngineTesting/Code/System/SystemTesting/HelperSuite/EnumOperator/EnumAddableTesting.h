///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:28)

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
        void DoRunUnitTest() override;
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

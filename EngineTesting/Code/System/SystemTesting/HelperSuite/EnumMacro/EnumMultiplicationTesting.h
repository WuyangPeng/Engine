///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/17 14:22)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_MULTIPLICATION_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_MULTIPLICATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumMultiplicationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumMultiplicationTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumMultiplicationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SignedConstexprOperator0Test() noexcept;
        void SignedConstexprOperator1Test() noexcept;
        void UnsignedConstexprOperator0Test() noexcept;
        void UnsignedConstexprOperator1Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_MULTIPLICATION_TESTING_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:27)

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
        void DoRunUnitTest() override;
        void MainTest();

        void SignedConstexprOperator0Test() noexcept;
        void SignedConstexprOperator1Test() noexcept;
        void UnsignedConstexprOperator0Test() noexcept;
        void UnsignedConstexprOperator1Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_MULTIPLICATION_TESTING_H

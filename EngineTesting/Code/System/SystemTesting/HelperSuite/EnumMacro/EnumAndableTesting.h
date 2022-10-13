///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/25 19:58)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_ANDABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_ANDABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumAndableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumAndableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumAndableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SignedOperatorTest();
        void SignedConstexprOperatorTest() noexcept;
        void UnsignedOperatorTest();
        void UnsignedConstexprOperatorTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_ANDABLE_TESTING_H

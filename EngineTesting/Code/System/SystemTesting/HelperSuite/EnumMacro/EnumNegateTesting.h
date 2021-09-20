///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/17 13:47)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumNegateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumNegateTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumNegateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SignedConstexprOperatorTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H

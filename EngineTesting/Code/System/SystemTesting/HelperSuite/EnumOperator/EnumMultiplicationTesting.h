/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 10:59)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_MULTIPLICATION_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_MULTIPLICATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ö�ٳ˷�����
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

        void SignedConstexprOperator0Test() const noexcept;
        void SignedConstexprOperator1Test() const noexcept;
        void UnsignedConstexprOperator0Test() const noexcept;
        void UnsignedConstexprOperator1Test() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_MULTIPLICATION_TESTING_H

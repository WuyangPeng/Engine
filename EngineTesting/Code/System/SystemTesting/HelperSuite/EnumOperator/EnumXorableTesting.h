/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 11:03)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_XORABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_XORABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ö��������������
    class EnumXorableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumXorableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumXorableTesting(const OStreamShared& stream);

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

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_XORABLE_TESTING_H

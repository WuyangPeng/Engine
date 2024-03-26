/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 11:02)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_SUBTRACTABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_SUBTRACTABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ö�ټ�������
    class EnumSubtractableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumSubtractableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumSubtractableTesting(const OStreamShared& stream);

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

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_SUBTRACTABLE_TESTING_H

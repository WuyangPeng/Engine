/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 11:01)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_SHIFTABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_SHIFTABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ö��<<��>>���������
    class EnumShiftableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumShiftableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumShiftableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ShiftableTest() const;

        void PrintTipsMessage() override;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_SHIFTABLE_TESTING_H

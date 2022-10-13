///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/25 19:59)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_SHIFTABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_SHIFTABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumShiftableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumShiftableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumShiftableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ShiftableTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_SHIFTABLE_TESTING_H

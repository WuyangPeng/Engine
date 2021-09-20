///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/17 16:16)

#ifndef SYSTEM_TIME_SUITE_DELTA_TIME_OF_DAY_DATA_TESTING_H
#define SYSTEM_TIME_SUITE_DELTA_TIME_OF_DAY_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class TimeOfDayDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = TimeOfDayDataTesting;
        using ParentType = UnitTest;

    public:
        explicit TimeOfDayDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CurrentTimeTest();
    };
}

#endif  // SYSTEM_TIME_SUITE_DELTA_TIME_OF_DAY_DATA_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/17 16:35)

#ifndef SYSTEM_TIME_SUITE_DELTA_TIME_VALUE_DATA_TESTING_H
#define SYSTEM_TIME_SUITE_DELTA_TIME_VALUE_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DeltaTimeValueDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DeltaTimeValueDataTesting;
        using ParentType = UnitTest;

    public:
        explicit DeltaTimeValueDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DataTest();
        void TimerSubTest();
        void CorrectionTest();
    };
}

#endif  // SYSTEM_TIME_SUITE_DELTA_TIME_VALUE_DATA_TESTING_H
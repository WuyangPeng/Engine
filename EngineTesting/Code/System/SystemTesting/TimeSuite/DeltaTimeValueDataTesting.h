///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:38)

#ifndef SYSTEM_TIME_SUITE_DELTA_TIME_VALUE_DATA_TESTING_H
#define SYSTEM_TIME_SUITE_DELTA_TIME_VALUE_DATA_TESTING_H

#include "System/Time/Using/DeltaTimeUsing.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void DataTest();

        void TimerSubTest();
        void CorrectionTest();

        void DataZeroTest();
        NODISCARD DeltaTimeValue DataNonZeroTest();
        void DataCopyTest(const DeltaTimeValue& deltaTimeValue);
    };
}

#endif  // SYSTEM_TIME_SUITE_DELTA_TIME_VALUE_DATA_TESTING_H
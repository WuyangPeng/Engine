/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/04 19:37)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H

#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Time/MillisecondTimer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MillisecondTimerTesting final : public UnitTest
    {
    public:
        using ClassType = MillisecondTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit MillisecondTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        static constexpr int32_t epsilon{ 10 };
        static constexpr int64_t microseconds{ System::gMillisecond };
        static constexpr int64_t twoMicroseconds{ microseconds * 2 };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TimeTest();

        void TimeBaseTest(const MillisecondTimer& millisecondTimer);
        void Sleep0Test(const MillisecondTimer& millisecondTimer);
        void ReTimingTest(MillisecondTimer& millisecondTimer);
        void Sleep1Test(const MillisecondTimer& millisecondTimer);
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H
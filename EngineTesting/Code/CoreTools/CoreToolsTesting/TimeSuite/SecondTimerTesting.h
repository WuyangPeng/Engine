/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/04 19:42)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_SECOND_TIMER_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_SECOND_TIMER_TESTING_H

#include "CoreTools/Time/SecondTimer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SecondTimerTesting final : public UnitTest
    {
    public:
        using ClassType = SecondTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit SecondTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        static constexpr int64_t seconds{ 2 };
        static constexpr int32_t epsilon{ 1 };
        static constexpr auto fourSeconds = seconds * 2;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TimeTest();

        void TimeBaseTest(const SecondTimer& secondTimer);
        void Sleep0Test(const SecondTimer& secondTimer);
        void ReTimingTest(SecondTimer& secondTimer);
        void Sleep1Test(const SecondTimer& secondTimer);
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_SECOND_TIMER_TESTING_H
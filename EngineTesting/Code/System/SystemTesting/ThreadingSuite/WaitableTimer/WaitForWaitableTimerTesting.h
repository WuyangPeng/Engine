///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/08 14:11)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_WAITABLE_TIMER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
    class WaitForWaitableTimerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForWaitableTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        static constexpr auto base = 10000000LL;

        void CreateSynchronizationTest();

        void WaitForWaitableTimer0Test(WindowsHandle waitableTimerHandle);
        void WaitForWaitableTimer1Test(WindowsHandle waitableTimerHandle);
        void WaitForWaitableTimer2Test(WindowsHandle waitableTimerHandle);
        void WaitForWaitableTimer3Test(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_WAITABLE_TIMER_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:40)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_WAITABLE_TIMER_TESTING_H

#include "WaitableTimerTestingBase.h"

namespace System
{
    class WaitForWaitableTimerTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = WaitForWaitableTimerTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit WaitForWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void CreateSynchronizationTest();

        void WaitForWaitableTimer0Test(WindowsHandle waitableTimerHandle);
        void WaitForWaitableTimer1Test(WindowsHandle waitableTimerHandle);
        void WaitForWaitableTimer2Test(WindowsHandle waitableTimerHandle);
        void WaitForWaitableTimer3Test(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);

        void DoCreateSynchronizationTest(WindowsHandle waitableTimerHandle);
        void CreateThread(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_WAITABLE_TIMER_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:11)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_WAITABLE_TIMER_TESTING_H

#include "WaitableTimerTestingBase.h"

#include <vector>

namespace System
{
    class WaitForMultipleWaitableTimerTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = WaitForMultipleWaitableTimerTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit WaitForMultipleWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        using Container = std::vector<WindowsHandle>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void CreateSynchronizationTest();

        void WaitForWaitableTimer0Test(const Container& waitableTimerHandles);
        void WaitForWaitableTimer1Test(const Container& waitableTimerHandles);
        void WaitForWaitableTimer2Test(const Container& waitableTimerHandles);

        void ResetSystemWaitableTimer(const Container& waitableTimerHandles);
        void CreateWaitableTimerTest(Container& waitableTimerHandles);
        void CreateThread(const Container& waitableTimerHandles);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_WAITABLE_TIMER_TESTING_H
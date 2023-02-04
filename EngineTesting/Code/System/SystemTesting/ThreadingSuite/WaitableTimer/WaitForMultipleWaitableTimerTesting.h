///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 23:12)

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
        void DoRunUnitTest() final;
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
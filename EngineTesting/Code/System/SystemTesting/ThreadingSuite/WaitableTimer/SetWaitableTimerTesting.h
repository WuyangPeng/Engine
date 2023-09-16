///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:40)

#ifndef SYSTEM_THREADING_SUITE_SET_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_SET_WAITABLE_TIMER_TESTING_H

#include "WaitableTimerTestingBase.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
    class SetWaitableTimerTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = SetWaitableTimerTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit SetWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AsynchronousTest();
        void AsynchronousUseTolerableDelayTest();

        void DoAsynchronousTest(WindowsHandle waitableTimerHandle);
        void DoAsynchronousUseTolerableDelayTest(WindowsHandle waitableTimerHandle);
        static void SYSTEM_WINAPI TimerAPCProcedure(WindowsVoidPtr argToCompletionRoutine, WindowsDWord timerLowValue, WindowsDWord timerHighValue);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SET_WAITABLE_TIMER_TESTING_H
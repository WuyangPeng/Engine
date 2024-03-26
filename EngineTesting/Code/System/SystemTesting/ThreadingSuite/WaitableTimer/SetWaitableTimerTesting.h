/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:10)

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
        static void SYSTEM_WIN_API TimerApcProcedure(WindowsVoidPtr argToCompletionRoutine, WindowsDWord timerLowValue, WindowsDWord timerHighValue);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SET_WAITABLE_TIMER_TESTING_H
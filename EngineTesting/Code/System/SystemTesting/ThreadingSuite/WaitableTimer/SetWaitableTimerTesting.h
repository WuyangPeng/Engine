///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/23 0:03)

#ifndef SYSTEM_THREADING_SUITE_SET_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_SET_WAITABLE_TIMER_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SetWaitableTimerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SetWaitableTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit SetWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AsynchronousTest();
        void AsynchronousUseTolerableDelayTest();

        static void SYSTEM_WINAPI TimerAPCProcedure(WindowsVoidPtr argToCompletionRoutine, WindowsDWord timerLowValue, WindowsDWord timerHighValue);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SET_WAITABLE_TIMER_TESTING_H
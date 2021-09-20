///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/08 17:25)

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
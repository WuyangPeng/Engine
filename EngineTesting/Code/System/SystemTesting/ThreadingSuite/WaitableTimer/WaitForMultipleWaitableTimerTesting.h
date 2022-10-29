///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/23 0:03)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_WAITABLE_TIMER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace System
{
    class WaitForMultipleWaitableTimerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForMultipleWaitableTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForMultipleWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Container = std::vector<WindowsHandle>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        static constexpr auto base = 10000000LL;

        void CreateSynchronizationTest();

        void WaitForWaitableTimer0Test(const Container& waitableTimerHandle);
        void WaitForWaitableTimer1Test(const Container& waitableTimerHandle);
        void WaitForWaitableTimer2Test(const Container& waitableTimerHandle);

        void ResetSystemWaitableTimer(const Container& waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_WAITABLE_TIMER_TESTING_H
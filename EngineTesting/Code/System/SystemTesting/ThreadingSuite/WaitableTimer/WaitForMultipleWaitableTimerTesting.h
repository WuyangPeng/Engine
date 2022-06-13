///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:40)

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
        void DoRunUnitTest() final;
        void MainTest();

    private:
        static constexpr auto base = 10000000LL;

        void CreateSynchronizationTest();

        void WaitForWaitableTimer0Test(const std::vector<WindowsHandle>& waitableTimerHandle);
        void WaitForWaitableTimer1Test(const std::vector<WindowsHandle>& waitableTimerHandle);
        void WaitForWaitableTimer2Test(const std::vector<WindowsHandle>& waitableTimerHandle);

        void ResetSystemWaitableTimer(const std::vector<WindowsHandle>& waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_WAITABLE_TIMER_TESTING_H
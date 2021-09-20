///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/07 13:21)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateWaitableTimerSynchronizationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateWaitableTimerSynchronizationTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateWaitableTimerSynchronizationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        static constexpr auto base = 10000000LL;

        void CreateSynchronizationTest();

        void WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_TESTING_H
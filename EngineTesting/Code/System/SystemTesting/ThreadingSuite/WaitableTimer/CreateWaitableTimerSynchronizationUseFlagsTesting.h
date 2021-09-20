///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/08 11:49)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CreateWaitableTimerSynchronizationUseFlagsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateWaitableTimerSynchronizationUseFlagsTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateWaitableTimerSynchronizationUseFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        static constexpr auto base = 10000000LL;

        void CreateManualTest();

        void WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);

    private:
        using WaitableTimerStandardAccessFlagsCollection = std::vector<MutexStandardAccess>;

    private:
        WaitableTimerStandardAccessFlagsCollection waitableTimerStandardAccessFlags;
        WaitableTimerSpecificAccess waitableTimerSpecificAccess;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H
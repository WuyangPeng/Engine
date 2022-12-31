///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/23 0:03)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
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
        using WaitableTimerStandardAccessFlagsContainer = std::vector<MutexStandardAccess>;

    private:
        WaitableTimerStandardAccessFlagsContainer waitableTimerStandardAccessFlags;
        WaitableTimerSpecificAccess waitableTimerSpecificAccess;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H
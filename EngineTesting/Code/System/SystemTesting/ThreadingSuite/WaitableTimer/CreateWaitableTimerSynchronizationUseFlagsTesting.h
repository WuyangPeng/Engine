///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 21:11)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H

#include "WaitableTimerTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <vector>

namespace System
{
    class CreateWaitableTimerSynchronizationUseFlagsTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = CreateWaitableTimerSynchronizationUseFlagsTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit CreateWaitableTimerSynchronizationUseFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void CreateManualTest();

        void WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);
        void DoCreateManualTest(MutexStandardAccess waitableTimerStandardAccess);
        void ResultTest(WindowsHandle waitableTimerHandle);
        void CreateThread(WindowsHandle waitableTimerHandle);

    private:
        using WaitableTimerStandardAccessContainer = std::vector<MutexStandardAccess>;

    private:
        WaitableTimerStandardAccessContainer waitableTimerStandardAccesses;
        WaitableTimerSpecificAccess waitableTimerSpecificAccess;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_USE_FLAGS_TESTING_H
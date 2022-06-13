///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:39)

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
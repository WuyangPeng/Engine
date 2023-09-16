///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:40)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_TESTING_H

#include "WaitableTimerTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class CreateWaitableTimerSynchronizationTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = CreateWaitableTimerSynchronizationTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit CreateWaitableTimerSynchronizationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void CreateSynchronizationTest();

        void WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);
        void DoCreateSynchronizationTest(WindowsHandle waitableTimerHandle);
        void CreateThreadTest(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_SYNCHRONIZATION_TESTING_H
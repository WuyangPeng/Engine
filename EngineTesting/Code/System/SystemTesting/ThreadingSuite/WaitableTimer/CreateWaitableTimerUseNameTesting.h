/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:10)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_USE_NAME_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_USE_NAME_TESTING_H

#include "WaitableTimerTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class CreateWaitableTimerUseNameTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = CreateWaitableTimerUseNameTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit CreateWaitableTimerUseNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateSynchronizationTest();
        void WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);
        void DoCreateSynchronizationTest(WindowsHandle waitableTimerHandle);
        void CreateThread(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_USE_NAME_TESTING_H
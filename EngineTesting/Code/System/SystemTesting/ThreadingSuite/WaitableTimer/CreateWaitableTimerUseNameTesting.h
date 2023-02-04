///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 22:40)

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
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void CreateSynchronizationTest();

        void WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle);
        void ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle);
        void DoCreateSynchronizationTest(WindowsHandle waitableTimerHandle);
        void CreateThread(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_USE_NAME_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/23 0:03)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_USE_NAME_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_USE_NAME_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateWaitableTimerUseNameTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateWaitableTimerUseNameTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateWaitableTimerUseNameTesting(const OStreamShared& stream);

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

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_USE_NAME_TESTING_H
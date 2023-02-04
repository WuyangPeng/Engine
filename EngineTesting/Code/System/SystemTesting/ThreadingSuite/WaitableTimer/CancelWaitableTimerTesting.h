///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 20:38)

#ifndef SYSTEM_THREADING_SUITE_CANCEL_WAITABLE_TIMER_MANUAL_TESTING_H
#define SYSTEM_THREADING_SUITE_CANCEL_WAITABLE_TIMER_MANUAL_TESTING_H

#include "WaitableTimerTestingBase.h"

namespace System
{
    class CancelWaitableTimerTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = CancelWaitableTimerTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit CancelWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CancelTest();

        void DoCancelTest(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CANCEL_WAITABLE_TIMER_MANUAL_TESTING_H
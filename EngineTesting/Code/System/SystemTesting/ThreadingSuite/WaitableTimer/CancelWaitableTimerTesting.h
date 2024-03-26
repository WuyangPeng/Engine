/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:09)

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
        void DoRunUnitTest() override;
        void MainTest();

        void CancelTest();
        void DoCancelTest(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CANCEL_WAITABLE_TIMER_MANUAL_TESTING_H
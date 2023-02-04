///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 20:38)

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
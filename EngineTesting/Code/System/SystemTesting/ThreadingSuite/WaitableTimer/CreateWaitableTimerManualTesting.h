/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:09)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_TESTING_H

#include "WaitableTimerTestingBase.h"

namespace System
{
    class CreateWaitableTimerManualTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = CreateWaitableTimerManualTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit CreateWaitableTimerManualTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateManualTest();
        void DoCreateManualTest(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_TESTING_H
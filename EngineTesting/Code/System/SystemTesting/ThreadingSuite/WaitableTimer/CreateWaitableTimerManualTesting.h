///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/07 13:21)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateWaitableTimerManualTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateWaitableTimerManualTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateWaitableTimerManualTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateManualTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_TESTING_H
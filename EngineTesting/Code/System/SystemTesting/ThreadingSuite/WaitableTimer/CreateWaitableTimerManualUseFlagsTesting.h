///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/08 11:43)

#ifndef SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_USE_FLAGS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_USE_FLAGS_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CreateWaitableTimerManualUseFlagsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateWaitableTimerManualUseFlagsTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateWaitableTimerManualUseFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateManualTest();

    private:
        using WaitableTimerStandardAccessFlagsCollection = std::vector<MutexStandardAccess>;

    private:
        WaitableTimerStandardAccessFlagsCollection waitableTimerStandardAccessFlags;
        WaitableTimerSpecificAccess waitableTimerSpecificAccess;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_WAITABLE_TIMER_MANUAL_USE_FLAGS_TESTING_H
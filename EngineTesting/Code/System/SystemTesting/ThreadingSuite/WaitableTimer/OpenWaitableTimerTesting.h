///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/23 0:03)

#ifndef SYSTEM_THREADING_SUITE_OPEN_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_WAITABLE_TIMER_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class OpenWaitableTimerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenWaitableTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();
        void WaitForWaitableTimerTest(const String& waitableTimerName);

    private:
        using WaitableTimerStandardAccessFlagsContainer = std::vector<MutexStandardAccess>;
        using WaitableTimerSpecificAccessFlagsContainer = std::vector<WaitableTimerSpecificAccess>;

    private:
        WaitableTimerStandardAccessFlagsContainer waitableTimerStandardAccessFlags;
        WaitableTimerSpecificAccessFlagsContainer waitableTimerSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_WAITABLE_TIMER_TESTING_H
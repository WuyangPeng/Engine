///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:40)

#ifndef SYSTEM_THREADING_SUITE_OPEN_WAITABLE_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_WAITABLE_TIMER_TESTING_H

#include "WaitableTimerTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class OpenWaitableTimerTesting final : public WaitableTimerTestingBase
    {
    public:
        using ClassType = OpenWaitableTimerTesting;
        using ParentType = WaitableTimerTestingBase;

    public:
        explicit OpenWaitableTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

        void WaitForWaitableTimerTest(const String& waitableTimerName);
        void CreateThread(const String& waitableTimerName);
        void DoWaitForWaitableTimerTest(size_t index, const String& waitableTimerName);

    private:
        using WaitableTimerStandardAccessContainer = std::vector<MutexStandardAccess>;
        using WaitableTimerSpecificAccessContainer = std::vector<WaitableTimerSpecificAccess>;

    private:
        WaitableTimerStandardAccessContainer waitableTimerStandardAccesses;
        WaitableTimerSpecificAccessContainer waitableTimerSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_WAITABLE_TIMER_TESTING_H
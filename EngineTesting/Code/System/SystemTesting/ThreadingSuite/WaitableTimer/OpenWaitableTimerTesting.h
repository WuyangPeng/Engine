/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:10)

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
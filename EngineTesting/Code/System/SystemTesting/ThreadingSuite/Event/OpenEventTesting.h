///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:29)

#ifndef SYSTEM_THREADING_SUITE_OPEN_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_EVENT_TESTING_H

#include "EventTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class OpenEventTesting final : public EventTestingBase
    {
    public:
        using ClassType = OpenEventTesting;
        using ParentType = EventTestingBase;

    public:
        explicit OpenEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();
        void WaitForEventTest(const String& eventName);
        void DoThreadTest(WindowsHandle eventHandle, const String& eventName);
        void DoWaitForEventTest(size_t index, const String& eventName);

    private:
        using EventStandardAccessContainer = std::vector<MutexStandardAccess>;
        using EventSpecificAccessContainer = std::vector<EventSpecificAccess>;

    private:
        EventStandardAccessContainer eventStandardAccesses;
        EventSpecificAccessContainer eventSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_EVENT_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/31 17:23)

#ifndef SYSTEM_THREADING_SUITE_CREATE_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_EVENT_TESTING_H

#include "EventTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class CreateEventTesting final : public EventTestingBase
    {
    public:
        using ClassType = CreateEventTesting;
        using ParentType = EventTestingBase;

    public:
        explicit CreateEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateEventTest();

        void DoCreateEventTest(size_t index);

    private:
        using CreateEventTypeContainer = std::vector<CreateEventType>;
        using EventSpecificAccessContainer = std::vector<EventSpecificAccess>;
        using EventStandardAccessContainer = std::vector<MutexStandardAccess>;

    private:
        EventStandardAccessContainer eventStandardAccesses;
        EventSpecificAccessContainer eventSpecificAccesses;
        CreateEventTypeContainer createEvents;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_EVENT_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:11)

#ifndef SYSTEM_THREADING_SUITE_CREATE_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_EVENT_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class CreateEventTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateEventTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateEventTest();

    private:
        using CreateEventFlagsCollection = std::vector<CreateEventType>;
        using EventSpecificAccessFlagsCollection = std::vector<EventSpecificAccess>;
        using EventStandardAccessFlagsCollection = std::vector<MutexStandardAccess>;

    private:
        EventStandardAccessFlagsCollection eventStandardAccessFlags;
        EventSpecificAccessFlagsCollection eventSpecificAccessFlags;
        CreateEventFlagsCollection createEventFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_EVENT_TESTING_H
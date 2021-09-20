///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/27 15:52)

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
        EventStandardAccessFlagsCollection m_EventStandardAccessFlags;
        EventSpecificAccessFlagsCollection m_EventSpecificAccessFlags;
        CreateEventFlagsCollection m_CreateEventFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_EVENT_TESTING_H
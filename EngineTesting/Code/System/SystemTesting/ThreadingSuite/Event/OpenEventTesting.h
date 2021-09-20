///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/27 19:31)

#ifndef SYSTEM_THREADING_SUITE_OPEN_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_EVENT_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class OpenEventTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenEventTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();
        void WaitForEventTest(const String& eventName);

    private:
        using EventStandardAccessFlagsCollection = std::vector<MutexStandardAccess>;
        using EventSpecificAccessFlagsCollection = std::vector<EventSpecificAccess>;

    private:
        EventStandardAccessFlagsCollection eventStandardAccessFlags;
        EventSpecificAccessFlagsCollection eventSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_EVENT_TESTING_H
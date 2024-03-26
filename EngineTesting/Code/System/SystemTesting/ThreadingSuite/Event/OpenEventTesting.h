/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 17:58)

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
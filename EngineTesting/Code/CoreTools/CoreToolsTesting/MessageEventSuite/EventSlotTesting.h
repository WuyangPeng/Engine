/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 22:48)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_TESTING_H

#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/MessageEvent/MessageEventFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EventSlotTesting final : public UnitTest
    {
    public:
        using ClassType = EventSlotTesting;
        using ParentType = UnitTest;

    public:
        explicit EventSlotTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto value = 5;
        static constexpr auto eventPriority = EventPriority::High;

        using TestingType = EventSlot<EventSubclass, EventPriority>;
        using UInt64TestingType = EventSlot<EventSubclass, uint64_t>;
        using EventSubclassSharedPtr = std::shared_ptr<EventSubclass>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SlotTest();
        void OperatorTest();
        void UInt64PriorityTest();

        NODISCARD EventSubclassSharedPtr GetEventSubclass();
        void DoSlotTest(EventSubclassSharedPtr& eventSubclass, TestingType& eventSlot);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_TESTING_H
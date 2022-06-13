///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 17:03)

#include "EventSlotTesting.h"
#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventSlotDetail.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EventSlotTesting)

namespace CoreTools
{
    using TestingType = EventSlot<EventSubclass, EventPriority>;
}

void CoreTools::EventSlotTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SlotTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UInt64PriorityTest);
}

void CoreTools::EventSlotTesting::SlotTest()
{
    constexpr auto value = 5;

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr EventPriority eventPriority{ EventPriority::High };

    TestingType eventSlot{ eventSubclass, eventPriority, &EventInterface::EventFunction };

    CallbackParameters callbackParameters{ 0 };

    callbackParameters.SetValue(0, value);

    ASSERT_TRUE(eventSlot(callbackParameters));

    ASSERT_EQUAL(eventSubclass->GetValue(), value + value);

    ASSERT_ENUM_EQUAL(eventSlot.GetPriority(), eventPriority);

    eventSubclass.reset();
    ASSERT_EQUAL_NULL_PTR(eventSubclass);
}

void CoreTools::EventSlotTesting::OperatorTest()
{
    constexpr auto value = 5;

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr EventPriority highEventPriority{ EventPriority::High };
    constexpr EventPriority lowEventPriority{ EventPriority::Low };

    TestingType firstEventSlot{ eventSubclass, highEventPriority, &EventInterface::EventFunction };
    TestingType secondEventSlot{ eventSubclass, lowEventPriority, &EventInterface::EventFunction };

    ASSERT_LESS(secondEventSlot, firstEventSlot);
}

void CoreTools::EventSlotTesting::UInt64PriorityTest()
{
    using UInt64TestingType = EventSlot<EventSubclass, uint64_t>;

    constexpr auto value = 5;

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    UInt64TestingType firstEventSlot{ eventSubclass, 2, &EventInterface::EventFunction };
    UInt64TestingType secondEventSlot{ eventSubclass, 1, &EventInterface::EventFunction };

    ASSERT_LESS(secondEventSlot, firstEventSlot);
}

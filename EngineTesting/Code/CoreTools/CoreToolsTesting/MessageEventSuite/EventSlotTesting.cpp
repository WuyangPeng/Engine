// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:02)

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

void CoreTools::EventSlotTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SlotTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UInt64PriorityTest);
}

void CoreTools::EventSlotTesting ::SlotTest()
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

void CoreTools::EventSlotTesting ::OperatorTest()
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

void CoreTools::EventSlotTesting ::UInt64PriorityTest()
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

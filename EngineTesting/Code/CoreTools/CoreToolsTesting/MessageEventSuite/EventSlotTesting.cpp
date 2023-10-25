///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 15:30)

#include "EventSlotTesting.h"
#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventSlotDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::EventSlotTesting::EventSlotTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EventSlotTesting)

void CoreTools::EventSlotTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr auto eventPriority = EventPriority::High;

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

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr auto highEventPriority = EventPriority::High;
    constexpr auto lowEventPriority = EventPriority::Low;

    const TestingType eventSlot0{ eventSubclass, highEventPriority, &EventInterface::EventFunction };
    const TestingType eventSlot1{ eventSubclass, lowEventPriority, &EventInterface::EventFunction };

    ASSERT_LESS(eventSlot1, eventSlot0);
}

void CoreTools::EventSlotTesting::UInt64PriorityTest()
{
    using UInt64TestingType = EventSlot<EventSubclass, uint64_t>;

    constexpr auto value = 5;

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    const UInt64TestingType eventSlot0{ eventSubclass, 2, &EventInterface::EventFunction };
    const UInt64TestingType eventSlot1{ eventSubclass, 1, &EventInterface::EventFunction };

    ASSERT_LESS(eventSlot1, eventSlot0);
}

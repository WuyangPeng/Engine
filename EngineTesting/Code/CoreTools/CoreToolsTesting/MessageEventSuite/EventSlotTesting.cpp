/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 22:48)

#include "EventSlotTesting.h"
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

void CoreTools::EventSlotTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SlotTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UInt64PriorityTest);
}

void CoreTools::EventSlotTesting::SlotTest()
{
    auto eventSubclass = GetEventSubclass();

    TestingType eventSlot{ eventSubclass, eventPriority, &EventInterface::EventFunction };

    ASSERT_NOT_THROW_EXCEPTION_2(DoSlotTest, eventSubclass, eventSlot);
}

void CoreTools::EventSlotTesting::DoSlotTest(EventSubclassSharedPtr& eventSubclass, TestingType& eventSlot)
{
    CallbackParameters callbackParameters{ 0 };

    callbackParameters.SetValue(0, value);

    ASSERT_TRUE(eventSlot(callbackParameters));

    ASSERT_EQUAL(eventSubclass->GetValue(), value + value);

    ASSERT_EQUAL(eventSlot.GetPriority(), eventPriority);

    eventSubclass.reset();
    ASSERT_EQUAL_NULL_PTR(eventSubclass);
}

CoreTools::EventSlotTesting::EventSubclassSharedPtr CoreTools::EventSlotTesting::GetEventSubclass()
{
    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    return eventSubclass;
}

void CoreTools::EventSlotTesting::OperatorTest()
{
    const auto eventSubclass = GetEventSubclass();

    constexpr auto highEventPriority = EventPriority::High;
    constexpr auto lowEventPriority = EventPriority::Low;

    const TestingType eventSlot0{ eventSubclass, highEventPriority, &EventInterface::EventFunction };
    const TestingType eventSlot1{ eventSubclass, lowEventPriority, &EventInterface::EventFunction };

    ASSERT_LESS(eventSlot1, eventSlot0);
}

void CoreTools::EventSlotTesting::UInt64PriorityTest()
{
    const auto eventSubclass = GetEventSubclass();

    constexpr auto highEventPriority = 2;
    constexpr auto lowEventPriority = 1;

    const UInt64TestingType eventSlot0{ eventSubclass, highEventPriority, &EventInterface::EventFunction };
    const UInt64TestingType eventSlot1{ eventSubclass, lowEventPriority, &EventInterface::EventFunction };

    ASSERT_LESS(eventSlot1, eventSlot0);
}

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:02)

#include "MessageManagerTesting.h"
#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventSlotDetail.h"
#include "CoreTools/MessageEvent/EventSlotManagerDetail.h"
#include "CoreTools/MessageEvent/MessageManagerDetail.h"

using std::make_shared;

namespace CoreTools
{
    using EventSlotType = EventSlot<EventSubclass, EventPriority>;
    using TestingType = MessageManager<EventSlotType>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MessageManagerTesting)

void CoreTools::MessageManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SuccessTest);
    ASSERT_THROW_EXCEPTION_0(UnregisteredExceptionTest);
}

void CoreTools::MessageManagerTesting ::SuccessTest()
{
    constexpr auto value = 5;

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr EventPriority eventPriority{ EventPriority::High };

    TestingType messageManager;

    const uint64_t index = messageManager.Registered(1, eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    CallbackParameters callbackParameters{ 0 };

    callbackParameters.SetValue(0, value);

    messageManager.CallEvent(1, callbackParameters);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 2);

    messageManager.CallEventUnordered(1, callbackParameters);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 3);

    messageManager.DelayCallEvent(1, callbackParameters, 3);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 3);

    messageManager.DispatchDelayEvent(1);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 3);

    messageManager.DispatchDelayEvent(3);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 4);

    messageManager.DelayCallEventUnordered(1, callbackParameters, 2);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 4);

    messageManager.DispatchDelayEvent(1);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 4);

    messageManager.DispatchDelayEvent(3);

    ASSERT_EQUAL(eventSubclass->GetValue(), value * 5);

    messageManager.Unregistered(1, index);
}

void CoreTools::MessageManagerTesting ::UnregisteredExceptionTest()
{
    constexpr auto value = 5;

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr EventPriority eventPriority{ EventPriority::High };

    TestingType messageManager;

    const auto index = messageManager.Registered(1, eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    messageManager.Unregistered(1, index);
    messageManager.Unregistered(1, index);
}

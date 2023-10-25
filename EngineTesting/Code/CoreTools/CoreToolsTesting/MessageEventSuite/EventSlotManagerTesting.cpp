///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 15:30)

#include "EventSlotManagerTesting.h"
#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventSlotDetail.h"
#include "CoreTools/MessageEvent/EventSlotManagerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace CoreTools
{
    using EventSlotType = EventSlot<EventSubclass, EventPriority>;
    using TestingType = EventSlotManager<EventSlotType>;
}

CoreTools::EventSlotManagerTesting::EventSlotManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EventSlotManagerTesting)

void CoreTools::EventSlotManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EventSlotManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SuccessTest);
    ASSERT_THROW_EXCEPTION_0(UnregisteredExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayTest);
}

void CoreTools::EventSlotManagerTesting::SuccessTest()
{
    constexpr auto value = 5;

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr auto eventPriority = EventPriority::High;

    TestingType messageManager;

    const auto index = messageManager.Registered(eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    CallbackParameters callbackParameters{ 0 };

    callbackParameters.SetValue(0, value);

    messageManager.CallEvent(callbackParameters);

    ASSERT_EQUAL(eventSubclass->GetValue(), value + value);

    messageManager.CallEventUnordered(callbackParameters);

    ASSERT_EQUAL(eventSubclass->GetValue(), value + value + value);

    messageManager.Unregistered(index);
}

void CoreTools::EventSlotManagerTesting::UnregisteredExceptionTest()
{
    constexpr auto value = 5;

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr auto eventPriority = EventPriority::High;

    TestingType messageManager{};

    const auto index = messageManager.Registered(eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    messageManager.Unregistered(index);
    messageManager.Unregistered(index);
}

void CoreTools::EventSlotManagerTesting::DelayTest()
{
    constexpr auto value = 5;

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr auto eventPriority = EventPriority::High;

    TestingType messageManager;

    const auto index = messageManager.Registered(eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    CallbackParameters callbackParameters{ 0 };

    callbackParameters.SetValue(0, value);

    messageManager.DelayCallEvent(callbackParameters, 100);

    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    messageManager.DelayCallEventUnordered(callbackParameters, 100);

    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    messageManager.DispatchDelayEvent(200);

    ASSERT_EQUAL(eventSubclass->GetValue(), value + value + value);

    messageManager.Unregistered(index);
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 15:06)

#include "MessageManagerTesting.h"
#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventSlotDetail.h"
#include "CoreTools/MessageEvent/EventSlotManagerDetail.h"
#include "CoreTools/MessageEvent/MessageManagerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace CoreTools
{
    using EventSlotType = EventSlot<EventSubclass, EventPriority>;
    using TestingType = MessageManager<EventSlotType>;
}

CoreTools::MessageManagerTesting::MessageManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MessageManagerTesting)

void CoreTools::MessageManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MessageManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SuccessTest);
    ASSERT_THROW_EXCEPTION_0(UnregisteredExceptionTest);
}

void CoreTools::MessageManagerTesting::SuccessTest()
{
    constexpr auto value = 5;

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr auto eventPriority = EventPriority::High;

    TestingType messageManager{};

    const auto index = messageManager.Registered(1, eventSubclass, eventPriority, &EventInterface::EventFunction);

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

void CoreTools::MessageManagerTesting::UnregisteredExceptionTest()
{
    constexpr auto value = 5;

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr auto eventPriority = EventPriority::High;

    TestingType messageManager{};

    const auto index = messageManager.Registered(1, eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    messageManager.Unregistered(1, index);
    messageManager.Unregistered(1, index);
}

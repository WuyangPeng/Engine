/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:02)

#include "MessageManagerTesting.h"
#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventSlotDetail.h"
#include "CoreTools/MessageEvent/EventSlotManagerDetail.h"
#include "CoreTools/MessageEvent/MessageManagerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    const auto eventSubclass = GetEventSubclass();

    TestingType messageManager{};

    const auto index = RegisteredTest(eventSubclass, messageManager);

    CallbackParameters callbackParameters{ 0 };

    callbackParameters.SetValue(0, value);

    ASSERT_NOT_THROW_EXCEPTION_3(CallEventTest, *eventSubclass, messageManager, callbackParameters);
    ASSERT_NOT_THROW_EXCEPTION_3(DelayCallEventTest, *eventSubclass, messageManager, callbackParameters);
    ASSERT_NOT_THROW_EXCEPTION_3(DispatchDelayEventTest, *eventSubclass, messageManager, callbackParameters);

    messageManager.Unregistered(1, index);
}

void CoreTools::MessageManagerTesting::CallEventTest(const EventSubclass& eventSubclass, TestingType& messageManager, const CallbackParameters& callbackParameters)
{
    messageManager.CallEvent(1, callbackParameters);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 2);

    messageManager.CallEventUnordered(1, callbackParameters);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 3);
}

void CoreTools::MessageManagerTesting::DelayCallEventTest(const EventSubclass& eventSubclass, TestingType& messageManager, const CallbackParameters& callbackParameters)
{
    messageManager.DelayCallEvent(1, callbackParameters, 3);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 3);
}

void CoreTools::MessageManagerTesting::DispatchDelayEventTest(const EventSubclass& eventSubclass, TestingType& messageManager, const CallbackParameters& callbackParameters)
{
    messageManager.DispatchDelayEvent(1);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 3);

    messageManager.DispatchDelayEvent(3);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 4);

    messageManager.DelayCallEventUnordered(1, callbackParameters, 2);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 4);

    messageManager.DispatchDelayEvent(1);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 4);

    messageManager.DispatchDelayEvent(3);

    ASSERT_EQUAL(eventSubclass.GetValue(), value * 5);
}

CoreTools::MessageManagerTesting::EventSubclassSharedPtr CoreTools::MessageManagerTesting::GetEventSubclass()
{
    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    return eventSubclass;
}

int64_t CoreTools::MessageManagerTesting::RegisteredTest(const EventSubclassSharedPtr& eventSubclass, TestingType& messageManager)
{
    constexpr auto eventPriority = EventPriority::High;

    const auto index = messageManager.Registered(1, eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    return index;
}

void CoreTools::MessageManagerTesting::UnregisteredExceptionTest()
{
    const auto eventSubclass = GetEventSubclass();

    TestingType messageManager{};

    const auto index = RegisteredTest(eventSubclass, messageManager);

    messageManager.Unregistered(1, index);
    messageManager.Unregistered(1, index);
}

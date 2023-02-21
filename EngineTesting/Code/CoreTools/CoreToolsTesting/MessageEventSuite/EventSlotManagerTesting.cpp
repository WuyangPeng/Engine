///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 17:03)

#include "EventSlotManagerTesting.h"
#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventSlotDetail.h"
#include "CoreTools/MessageEvent/EventSlotManagerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;

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
}

void CoreTools::EventSlotManagerTesting::SuccessTest()
{
    constexpr auto value = 5;

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr EventPriority eventPriority{ EventPriority::High };

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

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);
    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    constexpr EventPriority eventPriority{ EventPriority::High };

    TestingType messageManager;

    const auto index = messageManager.Registered(eventSubclass, eventPriority, &EventInterface::EventFunction);

    ASSERT_LESS(0, index);

    messageManager.Unregistered(index);
    messageManager.Unregistered(index);
}

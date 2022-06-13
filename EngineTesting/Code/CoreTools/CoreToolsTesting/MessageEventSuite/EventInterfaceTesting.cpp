///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 17:03)

#include "EventInterfaceTesting.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, EventInterface)

void CoreTools::EventInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EventSubclassTest);
}

void CoreTools::EventInterfaceTesting::EventSubclassTest()
{
    constexpr auto value = 5;

    EventInterfaceSharedPtr baseSmartPointer{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(baseSmartPointer);

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);

    ASSERT_EQUAL(eventSubclass->GetValue(), value);
}

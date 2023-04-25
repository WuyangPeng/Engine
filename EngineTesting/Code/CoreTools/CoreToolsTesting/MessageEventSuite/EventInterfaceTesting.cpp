///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 13:15)

#include "EventInterfaceTesting.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::EventInterfaceTesting::EventInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EventInterfaceTesting)

void CoreTools::EventInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EventInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EventSubclassTest);
}

void CoreTools::EventInterfaceTesting::EventSubclassTest()
{
    constexpr auto value = 5;

    const EventInterfaceSharedPtr basePointer{ std::make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(basePointer);

    const auto eventSubclass = std::make_shared<EventSubclass>(value);

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);

    ASSERT_EQUAL(eventSubclass->GetValue(), value);

    CallbackParameters callbackParameters{ 1 };
    callbackParameters.SetValue(0, 100);
    ASSERT_TRUE(eventSubclass->EventFunction(callbackParameters));

    ASSERT_EQUAL(eventSubclass->GetValue(), value + 100);
}

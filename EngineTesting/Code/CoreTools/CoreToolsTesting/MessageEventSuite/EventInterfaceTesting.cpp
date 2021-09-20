// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:02)

#include "EventInterfaceTesting.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, EventInterface)

void CoreTools::EventInterfaceTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EventSubclassTest);
}

void CoreTools::EventInterfaceTesting ::EventSubclassTest()
{
    constexpr auto value = 5;

    EventInterfaceSharedPtr baseSmartPointer{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(baseSmartPointer);

    EventSubclassSharedPtr eventSubclass{ make_shared<EventSubclass>(value) };

    ASSERT_UNEQUAL_NULL_PTR(eventSubclass);

    ASSERT_EQUAL(eventSubclass->GetValue(), value);
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 19:30)

#include "CreateEventTesting.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateEventTesting::CreateEventTesting(const OStreamShared& stream)
    : ParentType{ stream },
      eventStandardAccesses{ MutexStandardAccess::Delete,
                             MutexStandardAccess::ReadControl,
                             MutexStandardAccess::WriteDac,
                             MutexStandardAccess::WriteOwner,
                             MutexStandardAccess::Synchronize },
      eventSpecificAccesses{ EventSpecificAccess::Default,
                             EventSpecificAccess::ModifyState,
                             EventSpecificAccess::AllAccess },
      createEvents{ CreateEventType::Default,
                    CreateEventType::InitialSet,
                    CreateEventType::ManualReset,
                    CreateEventType::All },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement({ eventStandardAccesses.size(), eventSpecificAccesses.size(), createEvents.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateEventTesting)

void System::CreateEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleFlags);
}

bool System::CreateEventTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(eventStandardAccesses, randomEngine);
    std::ranges::shuffle(eventSpecificAccesses, randomEngine);
    std::ranges::shuffle(createEvents, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateEventTest);

    return true;
}

void System::CreateEventTesting::CreateEventTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateEventTest, index);
    }
}

void System::CreateEventTesting::DoCreateEventTest(size_t index)
{
    const auto eventStandardAccess = eventStandardAccesses.at(index % eventStandardAccesses.size());
    const auto eventSpecificAccess = eventSpecificAccesses.at(index % eventSpecificAccesses.size());
    const auto createEvent = createEvents.at(index % createEvents.size());

    const auto eventHandle = CreateSystemEvent(nullptr, nullptr, createEvent, eventStandardAccess, eventSpecificAccess);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

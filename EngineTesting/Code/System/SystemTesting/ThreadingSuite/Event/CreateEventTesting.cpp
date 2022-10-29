///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:23)

#include "CreateEventTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateEventTesting::CreateEventTesting(const OStreamShared& stream)
    : ParentType{ stream },
      eventStandardAccessFlags{ MutexStandardAccess::Delete,
                                MutexStandardAccess::ReadControl,
                                MutexStandardAccess::WriteDac,
                                MutexStandardAccess::WriteOwner,
                                MutexStandardAccess::Synchronize },
      eventSpecificAccessFlags{ EventSpecificAccess::Default,
                                EventSpecificAccess::ModifyState,
                                EventSpecificAccess::AllAccess },
      createEventFlags{ CreateEventType::Default,
                        CreateEventType::InitalSet,
                        CreateEventType::ManualReset,
                        CreateEventType::All },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement<size_t>({ eventStandardAccessFlags.size(), eventSpecificAccessFlags.size(), createEventFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    shuffle(eventStandardAccessFlags.begin(), eventStandardAccessFlags.end(), randomEngine);
    shuffle(eventSpecificAccessFlags.begin(), eventSpecificAccessFlags.end(), randomEngine);
    shuffle(createEventFlags.begin(), createEventFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateEventTest);

    return true;
}

void System::CreateEventTesting::CreateEventTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto eventStandardAccess = eventStandardAccessFlags.at(index % eventStandardAccessFlags.size());
        auto eventSpecificAccess = eventSpecificAccessFlags.at(index % eventSpecificAccessFlags.size());
        auto createEvent = createEventFlags.at(index % createEventFlags.size());

        auto eventHandle = CreateSystemEvent(nullptr, nullptr, createEvent, eventStandardAccess, eventSpecificAccess);
        ASSERT_TRUE(IsSystemEventValid(eventHandle));

        ASSERT_TRUE(CloseSystemEvent(eventHandle));
    }
}

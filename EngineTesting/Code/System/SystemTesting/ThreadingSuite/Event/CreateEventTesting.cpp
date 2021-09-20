///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/27 15:53)

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
      m_EventStandardAccessFlags{ MutexStandardAccess::Delete,
                                  MutexStandardAccess::ReadControl,
                                  MutexStandardAccess::WriteDac,
                                  MutexStandardAccess::WriteOwner,
                                  MutexStandardAccess::Synchronize },
      m_EventSpecificAccessFlags{ EventSpecificAccess::Default,
                                  EventSpecificAccess::ModifyState,
                                  EventSpecificAccess::AllAccess },
      m_CreateEventFlags{ CreateEventType::Default,
                          CreateEventType::InitalSet,
                          CreateEventType::ManualReset,
                          CreateEventType::All },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement<size_t>({ m_EventStandardAccessFlags.size(), m_EventSpecificAccessFlags.size(), m_CreateEventFlags.size() }) }
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
    shuffle(m_EventStandardAccessFlags.begin(), m_EventStandardAccessFlags.end(), randomEngine);
    shuffle(m_EventSpecificAccessFlags.begin(), m_EventSpecificAccessFlags.end(), randomEngine);
    shuffle(m_CreateEventFlags.begin(), m_CreateEventFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateEventTest);

    return true;
}

void System::CreateEventTesting::CreateEventTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto eventStandardAccess = m_EventStandardAccessFlags.at(index % m_EventStandardAccessFlags.size());
        auto eventSpecificAccess = m_EventSpecificAccessFlags.at(index % m_EventSpecificAccessFlags.size());
        auto createEvent = m_CreateEventFlags.at(index % m_CreateEventFlags.size());

        auto eventHandle = CreateSystemEvent(nullptr, nullptr, createEvent, eventStandardAccess, eventSpecificAccess);
        ASSERT_TRUE(IsSystemEventValid(eventHandle));

        ASSERT_TRUE(CloseSystemEvent(eventHandle));
    }
}

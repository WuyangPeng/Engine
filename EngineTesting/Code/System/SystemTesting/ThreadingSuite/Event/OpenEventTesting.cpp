///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:00)

#include "OpenEventTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenEventTesting::OpenEventTesting(const OStreamShared& stream)
    : ParentType{ stream },
      eventStandardAccesses{ MutexStandardAccess::Delete,
                             MutexStandardAccess::ReadControl,
                             MutexStandardAccess::WriteDac,
                             MutexStandardAccess::WriteOwner,
                             MutexStandardAccess::Synchronize },
      eventSpecificAccesses{ EventSpecificAccess::Default,
                             EventSpecificAccess::ModifyState,
                             EventSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(eventStandardAccesses.size(), eventSpecificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenEventTesting)

void System::OpenEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenEventTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenEventTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(eventStandardAccesses, randomEngine);
    std::ranges::shuffle(eventSpecificAccesses, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenEventTesting::ThreadTest()
{
    const auto eventName = System::ToString(GetTimeInMicroseconds());

    const auto eventHandle = CreateSystemEvent(nullptr, true, true, eventName.c_str());
    ASSERT_NOT_THROW_EXCEPTION_2(DoThreadTest, eventHandle, eventName);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::OpenEventTesting::WaitForEventTest(const String& eventName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoWaitForEventTest, index, eventName);
    }
}

void System::OpenEventTesting::DoThreadTest(WindowsHandle eventHandle, const String& eventName)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, eventName]() {
            this->WaitForEventTest(eventName);
        });
    }

    threadGroup.join_all();
}

void System::OpenEventTesting::DoWaitForEventTest(size_t index, const String& eventName)
{
    const auto eventStandardAccess = eventStandardAccesses.at(index % eventStandardAccesses.size());
    const auto eventSpecificAccess = eventSpecificAccesses.at(index % eventSpecificAccesses.size());

    const auto eventHandle = OpenSystemEvent(eventStandardAccess, eventSpecificAccess, true, eventName.c_str());
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

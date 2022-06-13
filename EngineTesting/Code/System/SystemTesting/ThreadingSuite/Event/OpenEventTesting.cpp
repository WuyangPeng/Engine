///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:45)

#include "OpenEventTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;

System::OpenEventTesting::OpenEventTesting(const OStreamShared& stream)
    : ParentType{ stream },
      eventStandardAccessFlags{ MutexStandardAccess::Delete, MutexStandardAccess::ReadControl, MutexStandardAccess::WriteDac, MutexStandardAccess::WriteOwner, MutexStandardAccess::Synchronize },
      eventSpecificAccessFlags{ EventSpecificAccess::Default, EventSpecificAccess::ModifyState, EventSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(eventStandardAccessFlags.size(), eventSpecificAccessFlags.size()) }
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
    shuffle(eventStandardAccessFlags.begin(), eventStandardAccessFlags.end(), randomEngine);
    shuffle(eventSpecificAccessFlags.begin(), eventSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenEventTesting::ThreadTest()
{
    constexpr auto threadCount = 12;
    auto eventName = System::ToString(GetTimeInMicroseconds());

    auto eventHandle = CreateSystemEvent(nullptr, true, true, eventName.c_str());
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForEventTest, this, eventName));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::OpenEventTesting::WaitForEventTest(const String& eventName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto eventStandardAccess = eventStandardAccessFlags.at(index % eventStandardAccessFlags.size());
        auto eventSpecificAccess = eventSpecificAccessFlags.at(index % eventSpecificAccessFlags.size());

        auto eventHandle = OpenSystemEvent(eventStandardAccess, eventSpecificAccess, true, eventName.c_str());
        ASSERT_TRUE(IsSystemEventValid(eventHandle));

        ASSERT_TRUE(CloseSystemEvent(eventHandle));
    }
}

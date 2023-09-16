///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:30)

#include "OpenWaitableTimerTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/WaitableTimerFlags.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenWaitableTimerTesting::OpenWaitableTimerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      waitableTimerStandardAccesses{ MutexStandardAccess::Delete,
                                     MutexStandardAccess::ReadControl,
                                     MutexStandardAccess::WriteDac,
                                     MutexStandardAccess::WriteOwner,
                                     MutexStandardAccess::Synchronize },
      waitableTimerSpecificAccesses{ WaitableTimerSpecificAccess::Default,
                                     WaitableTimerSpecificAccess::ModifyState,
                                     WaitableTimerSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(waitableTimerStandardAccesses.size(), waitableTimerSpecificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenWaitableTimerTesting)

void System::OpenWaitableTimerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenWaitableTimerTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenWaitableTimerTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(waitableTimerStandardAccesses, randomEngine);
    std::ranges::shuffle(waitableTimerSpecificAccesses, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenWaitableTimerTesting::ThreadTest()
{
    const auto waitableTimerName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, waitableTimerName.c_str());
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, waitableTimerName);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

void System::OpenWaitableTimerTesting::WaitForWaitableTimerTest(const String& waitableTimerName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoWaitForWaitableTimerTest, index, waitableTimerName);
    }
}

void System::OpenWaitableTimerTesting::CreateThread(const String& waitableTimerName)
{
    constexpr auto threadCount = 12;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, waitableTimerName]() {
            this->WaitForWaitableTimerTest(waitableTimerName);
        });
    }

    threadGroup.join_all();
}

void System::OpenWaitableTimerTesting::DoWaitForWaitableTimerTest(size_t index, const String& waitableTimerName)
{
    const auto waitableTimerStandardAccess = waitableTimerStandardAccesses.at(index % waitableTimerStandardAccesses.size());
    const auto waitableTimerSpecificAccess = waitableTimerSpecificAccesses.at(index % waitableTimerSpecificAccesses.size());

    const auto waitableTimerHandle = OpenSystemWaitableTimer(waitableTimerStandardAccess, waitableTimerSpecificAccess, true, waitableTimerName.c_str());
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

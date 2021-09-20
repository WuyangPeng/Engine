// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.1 (2020/01/13 15:16)

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

using std::max;

System::OpenWaitableTimerTesting::OpenWaitableTimerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      waitableTimerStandardAccessFlags{ MutexStandardAccess::Delete,
                                        MutexStandardAccess::ReadControl,
                                        MutexStandardAccess::WriteDac,
                                        MutexStandardAccess::WriteOwner,
                                        MutexStandardAccess::Synchronize },
      waitableTimerSpecificAccessFlags{ WaitableTimerSpecificAccess::Default,
                                        WaitableTimerSpecificAccess::ModifyState,
                                        WaitableTimerSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(waitableTimerStandardAccessFlags.size(), waitableTimerSpecificAccessFlags.size()) }
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
    shuffle(waitableTimerStandardAccessFlags.begin(), waitableTimerStandardAccessFlags.end(), randomEngine);
    shuffle(waitableTimerSpecificAccessFlags.begin(), waitableTimerSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenWaitableTimerTesting::ThreadTest()
{
    constexpr auto threadCount = 12;
    auto waitableTimerName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, waitableTimerName.c_str());
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForWaitableTimerTest, this, waitableTimerName));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
}

void System::OpenWaitableTimerTesting::WaitForWaitableTimerTest(const String& waitableTimerName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto waitableTimerStandardAccess = waitableTimerStandardAccessFlags.at(index % waitableTimerStandardAccessFlags.size());
        auto waitableTimerSpecificAccess = waitableTimerSpecificAccessFlags.at(index % waitableTimerSpecificAccessFlags.size());

        auto waitableTimerHandle = OpenSystemWaitableTimer(waitableTimerStandardAccess, waitableTimerSpecificAccess, true, waitableTimerName.c_str());
        ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

        ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
    }
}

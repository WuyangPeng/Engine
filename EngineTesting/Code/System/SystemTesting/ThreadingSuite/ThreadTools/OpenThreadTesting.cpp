///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/11 11:44)

#include "OpenThreadTesting.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/Thread.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;

System::OpenThreadTesting::OpenThreadTesting(const OStreamShared& stream)
    : ParentType{ stream },
      threadStandardAccessFlags{ ThreadStandardAccess::Default,
                                 ThreadStandardAccess::Delete,
                                 ThreadStandardAccess::ReadControl,
                                 ThreadStandardAccess::WriteDac,
                                 ThreadStandardAccess::WriteOwner,
                                 ThreadStandardAccess::Synchronize },
      threadSpecificAccessFlags{ ThreadSpecificAccess::QueryInformation,
                                 ThreadSpecificAccess::QueryLimitedInformation,
                                 ThreadSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(threadStandardAccessFlags.size(), threadSpecificAccessFlags.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenThreadTesting)

void System::OpenThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenThreadTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenThreadTesting::RandomShuffleFlags()
{
    shuffle(threadStandardAccessFlags.begin(), threadStandardAccessFlags.end(), randomEngine);
    shuffle(threadSpecificAccessFlags.begin(), threadSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenThreadTesting::ThreadTest()
{
    auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto threadStandardAccess = threadStandardAccessFlags.at(index % threadStandardAccessFlags.size());
        auto threadSpecificAccess = threadSpecificAccessFlags.at(index % threadSpecificAccessFlags.size());

        ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

        DoThreadTest(mutexHandle, threadStandardAccess, threadSpecificAccess);
    }

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}

void System::OpenThreadTesting::DoThreadTest(WindowsHandle mutexHandle, ThreadStandardAccess threadStandardAccess, ThreadSpecificAccess threadSpecificAccess)
{
    WindowsDWord threadID{ 0 };
    auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, mutexHandle, ThreadCreation::Default, &threadID);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadID);

    auto openThreadHandle = OpenSystemThread(threadStandardAccess, threadSpecificAccess, false, threadID);
    ASSERT_TRUE(IsThreadHandleValid(openThreadHandle));

    const auto openThreadID = GetSystemThreadID(openThreadHandle);
    ASSERT_EQUAL(openThreadID, threadID);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));

    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    WindowsDWord exitCode{ 0 };
    ASSERT_TRUE(GetThreadExitCode(openThreadHandle, &exitCode));
    ASSERT_EQUAL(exitCode, 1u);

    ASSERT_TRUE(CloseSystemThread(openThreadHandle));
    ASSERT_TRUE(CloseSystemThread(threadHandle));
}

System::WindowsDWord System::OpenThreadTesting::ThreadStartRoutine(void* threadParameter) noexcept
{
    MAYBE_UNUSED const auto waitResult = WaitForSystemMutex(threadParameter);

    MAYBE_UNUSED const auto releaseResult = ReleaseSystemMutex(threadParameter);

    return 1u;
}
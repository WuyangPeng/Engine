///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:28)

#include "OpenThreadTesting.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/Thread.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenThreadTesting::OpenThreadTesting(const OStreamShared& stream)
    : ParentType{ stream },
      threadStandardAccesses{ ThreadStandardAccess::Default,
                              ThreadStandardAccess::Delete,
                              ThreadStandardAccess::ReadControl,
                              ThreadStandardAccess::WriteDac,
                              ThreadStandardAccess::WriteOwner,
                              ThreadStandardAccess::Synchronize },
      threadSpecificAccesses{ ThreadSpecificAccess::QueryInformation,
                              ThreadSpecificAccess::QueryLimitedInformation,
                              ThreadSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(threadStandardAccesses.size(), threadSpecificAccesses.size()) }
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
    std::ranges::shuffle(threadStandardAccesses, randomEngine);
    std::ranges::shuffle(threadSpecificAccesses, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenThreadTesting::ThreadTest()
{
    const auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(WaitForSystemMutexTest, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}

void System::OpenThreadTesting::WaitForSystemMutexTest(WindowsHandle mutexHandle)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoWaitForSystemMutexTest, index, mutexHandle);
    }
}

void System::OpenThreadTesting::DoWaitForSystemMutexTest(size_t index, WindowsHandle mutexHandle)
{
    const auto threadStandardAccess = threadStandardAccesses.at(index % threadStandardAccesses.size());
    const auto threadSpecificAccess = threadSpecificAccesses.at(index % threadSpecificAccesses.size());

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_3(DoThreadTest, mutexHandle, threadStandardAccess, threadSpecificAccess);
}

void System::OpenThreadTesting::DoThreadTest(WindowsHandle mutexHandle, ThreadStandardAccess threadStandardAccess, ThreadSpecificAccess threadSpecificAccess)
{
    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, mutexHandle, ThreadCreation::Default, &threadId);

    ThreadResultTest(threadHandle, threadId, threadStandardAccess, threadSpecificAccess, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

void System::OpenThreadTesting::ThreadResultTest(WindowsHandle threadHandle, WindowsDWord threadId, ThreadStandardAccess threadStandardAccess, ThreadSpecificAccess threadSpecificAccess, WindowsHandle mutexHandle)
{
    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    const auto openThreadHandle = OpenSystemThread(threadStandardAccess, threadSpecificAccess, false, threadId);

    OpenThreadTest(openThreadHandle, threadId, mutexHandle, threadHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, openThreadHandle);
}

void System::OpenThreadTesting::OpenThreadTest(WindowsHandle openThreadHandle, WindowsDWord threadId, WindowsHandle mutexHandle, WindowsHandle threadHandle)
{
    ASSERT_TRUE(IsThreadHandleValid(openThreadHandle));

    const auto openThreadId = GetSystemThreadId(openThreadHandle);
    ASSERT_EQUAL(openThreadId, threadId);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));

    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    WindowsDWord exitCode{ 0 };
    ASSERT_TRUE(GetThreadExitCode(openThreadHandle, &exitCode));
    ASSERT_EQUAL(exitCode, exitFunctionCode);
}

System::WindowsDWord System::OpenThreadTesting::ThreadStartRoutine(void* threadParameter) noexcept
{
    MAYBE_UNUSED const auto waitResult = WaitForSystemMutex(threadParameter);

    MAYBE_UNUSED const auto releaseResult = ReleaseSystemMutex(threadParameter);

    return exitFunctionCode;
}
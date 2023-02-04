///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 10:38)

#include "ThreadMutexTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ThreadMutexTesting::ThreadMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, threadSum{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ThreadMutexTesting)

void System::ThreadMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ThreadMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrylockTest);
}

void System::ThreadMutexTesting::ThreadTest()
{
    const auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(DoThreadTest, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}

void System::ThreadMutexTesting::DoThreadTest(WindowsHandle mutexHandle)
{
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    threadSum = 0;

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, mutexHandle);

    ASSERT_EQUAL(threadSum, threadCount);
}

void System::ThreadMutexTesting::TrylockTest()
{
    const auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    DoTrylockTest(mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}

void System::ThreadMutexTesting::WaitForMutexTest(WindowsHandle mutexHandle)
{
    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    --threadSum;
    --threadSum;
    threadSum += 3;

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

void System::ThreadMutexTesting::TrylockTimeoutTest(WindowsHandle mutexHandle)
{
    ASSERT_ENUM_EQUAL(WaitForSystemMutex(mutexHandle, 0), MutexWaitReturn::Timeout);
}

void System::ThreadMutexTesting::TrylockSuccessTest(WindowsHandle mutexHandle)
{
    ASSERT_ENUM_EQUAL(WaitForSystemMutex(mutexHandle, 0), MutexWaitReturn::Object0);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

void System::ThreadMutexTesting::CreateThread(WindowsHandle mutexHandle)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest, this, mutexHandle));
    }

    threadGroup.join_all();
}

void System::ThreadMutexTesting::DoTrylockTest(WindowsHandle mutexHandle)
{
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    threadSum = 0;

    ASSERT_NOT_THROW_EXCEPTION_1(TrylockSuccessThreadTest, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(TrylockTimeoutThreadTest, mutexHandle);
}

void System::ThreadMutexTesting::TrylockSuccessThreadTest(WindowsHandle mutexHandle)
{
    boost::thread thread{ boost::bind(&ClassType::TrylockSuccessTest, this, mutexHandle) };

    thread.join();

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));
}

void System::ThreadMutexTesting::TrylockTimeoutThreadTest(WindowsHandle mutexHandle)
{
    boost::thread thread{ boost::bind(&ClassType::TrylockTimeoutTest, this, mutexHandle) };

    thread.join();

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

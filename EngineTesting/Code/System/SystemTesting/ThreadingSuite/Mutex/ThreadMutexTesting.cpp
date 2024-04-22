/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:29)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ThreadMutexTesting)

void System::ThreadMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ThreadMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockTest);
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

void System::ThreadMutexTesting::TryLockTest()
{
    const auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    DoTryLockTest(mutexHandle);

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

void System::ThreadMutexTesting::TryLockTimeoutTest(WindowsHandle mutexHandle)
{
    ASSERT_EQUAL(WaitForSystemMutex(mutexHandle, 0), MutexWaitReturn::Timeout);
}

void System::ThreadMutexTesting::TryLockSuccessTest(WindowsHandle mutexHandle)
{
    ASSERT_EQUAL(WaitForSystemMutex(mutexHandle, 0), MutexWaitReturn::Object0);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

void System::ThreadMutexTesting::CreateThread(WindowsHandle mutexHandle)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, mutexHandle]() {
            this->WaitForMutexTest(mutexHandle);
        });
    }

    threadGroup.join_all();
}

void System::ThreadMutexTesting::DoTryLockTest(WindowsHandle mutexHandle)
{
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    threadSum = 0;

    ASSERT_NOT_THROW_EXCEPTION_1(TryLockSuccessThreadTest, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(TryLockTimeoutThreadTest, mutexHandle);
}

void System::ThreadMutexTesting::TryLockSuccessThreadTest(WindowsHandle mutexHandle)
{
    boost::thread thread{ [this, mutexHandle]() {
        this->TryLockSuccessTest(mutexHandle);
    } };

    thread.join();

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));
}

void System::ThreadMutexTesting::TryLockTimeoutThreadTest(WindowsHandle mutexHandle)
{
    boost::thread thread{ [this, mutexHandle]() {
        this->TryLockTimeoutTest(mutexHandle);
    } };

    thread.join();

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

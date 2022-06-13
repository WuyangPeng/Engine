///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:50)

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
    constexpr auto threadCount = 12;

    auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    threadSum = 0;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest, this, mutexHandle));
    }

    threadGroup.join_all();

    ASSERT_EQUAL(threadSum, threadCount);

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}

void System::ThreadMutexTesting::TrylockTest()
{
    auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    threadSum = 0;

    boost::thread thread0{ boost::bind(&ClassType::TrylockSuccessTest, this, mutexHandle) };

    thread0.join();

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    boost::thread thread1{ boost::bind(&ClassType::TrylockTimeoutTest, this, mutexHandle) };

    thread1.join();

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
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

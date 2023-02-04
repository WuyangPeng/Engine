///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 15:52)

#include "WaitSemaphoreTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitSemaphoreTesting::WaitSemaphoreTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitSemaphoreTesting)

void System::WaitSemaphoreTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitSemaphoreTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::WaitSemaphoreTesting::ThreadTest()
{
    constexpr WindowsLong maxSemphoreCount{ 5 };

    const auto semaphoreHandle = CreateSystemSemaphore(maxSemphoreCount, maxSemphoreCount);
    ASSERT_TRUE(IsSystemSemaphoreValid(semaphoreHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, semaphoreHandle);

    ASSERT_TRUE(CloseSystemSemaphore(semaphoreHandle));
}

void System::WaitSemaphoreTesting::WaitForSemaphoreTest0(WindowsHandle semaphoreHandle)
{
    const auto result = WaitForSystemSemaphore(semaphoreHandle);
    ASSERT_TRUE(result);

    if (result)
    {
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, nullptr));
    }
}

void System::WaitSemaphoreTesting::WaitForSemaphoreTest1(WindowsHandle semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(semaphoreHandle, EnumCastUnderlying(MutexWait::Infinite));

    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    if (flag == MutexWaitReturn::Object0)
    {
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, nullptr));
    }
}

void System::WaitSemaphoreTesting::WaitForSemaphoreTest2(WindowsHandle semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(semaphoreHandle, EnumCastUnderlying(MutexWait::Infinite), true);

    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    if (flag == MutexWaitReturn::Object0)
    {
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, nullptr));
    }
}

void System::WaitSemaphoreTesting::WaitForSemaphoreTest3(WindowsHandle semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(semaphoreHandle, EnumCastUnderlying(MutexWait::Infinite), false);

    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    if (flag == MutexWaitReturn::Object0)
    {
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, nullptr));
    }
}

void System::WaitSemaphoreTesting::CreateThread(WindowsHandle semaphoreHandle)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest0, this, semaphoreHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest1, this, semaphoreHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest2, this, semaphoreHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest3, this, semaphoreHandle));
    }

    threadGroup.join_all();
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:19)

#include "WaitMultipleSemaphoreTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitMultipleSemaphoreTesting::WaitMultipleSemaphoreTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitMultipleSemaphoreTesting)

void System::WaitMultipleSemaphoreTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitMultipleSemaphoreTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::WaitMultipleSemaphoreTesting::ThreadTest()
{
    Container semaphoreHandles{};

    ASSERT_NOT_THROW_EXCEPTION_1(CreateSemaphoreTest, semaphoreHandles);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, semaphoreHandles);

    for (auto semaphoreHandle : semaphoreHandles)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CloseSemaphoreTest, semaphoreHandle);
    }
}

void System::WaitMultipleSemaphoreTesting::WaitForSemaphoreTest0(const Container& semaphoreHandles)
{
    const auto flag = WaitForSystemSemaphore(boost::numeric_cast<WindowsDWord>(semaphoreHandles.size()), semaphoreHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    if (flag != MutexWaitReturn::Failed)
    {
        for (const auto handle : semaphoreHandles)
        {
            ASSERT_TRUE(ReleaseSystemSemaphore(handle, 1, nullptr));
        }
    }
}

void System::WaitMultipleSemaphoreTesting::WaitForSemaphoreTest1(const Container& semaphoreHandles)
{
    const auto flag = WaitForSystemSemaphore(boost::numeric_cast<WindowsDWord>(semaphoreHandles.size()), semaphoreHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    if (flag != MutexWaitReturn::Failed)
    {
        for (const auto handle : semaphoreHandles)
        {
            ASSERT_TRUE(ReleaseSystemSemaphore(handle, 1, nullptr));
        }
    }
}

void System::WaitMultipleSemaphoreTesting::WaitForSemaphoreTest2(const Container& semaphoreHandles)
{
    const auto flag = WaitForSystemSemaphore(boost::numeric_cast<WindowsDWord>(semaphoreHandles.size()), semaphoreHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    if (flag != MutexWaitReturn::Failed)
    {
        for (const auto handle : semaphoreHandles)
        {
            ASSERT_TRUE(ReleaseSystemSemaphore(handle, 1, nullptr));
        }
    }
}

void System::WaitMultipleSemaphoreTesting::CreateSemaphoreTest(Container& semaphoreHandles)
{
    constexpr WindowsLong maxSemaphoreCount{ 5 };
    constexpr auto semaphoreSize = 5;

    for (auto i = 0; i < semaphoreSize; ++i)
    {
        const auto handle = CreateSystemSemaphore(maxSemaphoreCount, maxSemaphoreCount);
        ASSERT_TRUE(IsSystemSemaphoreValid(handle));

        semaphoreHandles.emplace_back(handle);
    }
}

void System::WaitMultipleSemaphoreTesting::CreateThread(const Container& semaphoreHandles)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, semaphoreHandles]() {
            this->WaitForSemaphoreTest0(semaphoreHandles);
        });

        threadGroup.create_thread([this, semaphoreHandles]() {
            this->WaitForSemaphoreTest1(semaphoreHandles);
        });

        threadGroup.create_thread([this, semaphoreHandles]() {
            this->WaitForSemaphoreTest2(semaphoreHandles);
        });
    }

    threadGroup.join_all();
}

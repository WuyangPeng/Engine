///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:54)

#include "WaitMultipleSemaphoreTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

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
    constexpr WindowsLong maxSemphoreCount{ 5 };
    constexpr auto threadCount = 12;
    constexpr auto semaphoreSize = 5;
    vector<WindowsHandle> semaphoreHandle{};

    for (auto i = 0; i < semaphoreSize; ++i)
    {
        auto handle = CreateSystemSemaphore(maxSemphoreCount, maxSemphoreCount);
        ASSERT_TRUE(IsSystemSemaphoreValid(handle));

        semaphoreHandle.emplace_back(handle);
    }

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest0, this, semaphoreHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest1, this, semaphoreHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest2, this, semaphoreHandle));
    }

    threadGroup.join_all();

    for (auto handle : semaphoreHandle)
    {
        ASSERT_TRUE(CloseSystemSemaphore(handle));
    }
}

void System::WaitMultipleSemaphoreTesting::WaitForSemaphoreTest0(const std::vector<WindowsHandle>& semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(boost::numeric_cast<WindowsDWord>(semaphoreHandle.size()), semaphoreHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    if (flag != MutexWaitReturn::Failed)
    {
        for (auto handle : semaphoreHandle)
        {
            ASSERT_TRUE(ReleaseSystemSemaphore(handle, 1, nullptr));
        }
    }
}

void System::WaitMultipleSemaphoreTesting::WaitForSemaphoreTest1(const std::vector<WindowsHandle>& semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(boost::numeric_cast<WindowsDWord>(semaphoreHandle.size()), semaphoreHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    if (flag != MutexWaitReturn::Failed)
    {
        for (auto handle : semaphoreHandle)
        {
            ASSERT_TRUE(ReleaseSystemSemaphore(handle, 1, nullptr));
        }
    }
}

void System::WaitMultipleSemaphoreTesting::WaitForSemaphoreTest2(const std::vector<WindowsHandle>& semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(boost::numeric_cast<WindowsDWord>(semaphoreHandle.size()), semaphoreHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    if (flag != MutexWaitReturn::Failed)
    {
        for (auto handle : semaphoreHandle)
        {
            ASSERT_TRUE(ReleaseSystemSemaphore(handle, 1, nullptr));
        }
    }
}

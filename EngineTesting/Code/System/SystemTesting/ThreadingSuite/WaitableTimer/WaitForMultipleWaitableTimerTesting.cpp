///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/23 0:05)

#include "WaitForMultipleWaitableTimerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/WaitableTimer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::vector;

System::WaitForMultipleWaitableTimerTesting::WaitForMultipleWaitableTimerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForMultipleWaitableTimerTesting)

void System::WaitForMultipleWaitableTimerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForMultipleWaitableTimerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateSynchronizationTest);
}

void System::WaitForMultipleWaitableTimerTesting::CreateSynchronizationTest()
{
    constexpr auto mutexSize = 5;
    Container waitableTimerHandle{};

    for (auto i = 0; i < mutexSize; ++i)
    {
        auto handle = CreateSystemWaitableTimer(nullptr, false, nullptr);
        ASSERT_TRUE(IsWaitableTimerValid(handle));

        waitableTimerHandle.emplace_back(handle);
    }

    ResetSystemWaitableTimer(waitableTimerHandle);

    constexpr auto threadCount = 4;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForWaitableTimer0Test, this, waitableTimerHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForWaitableTimer1Test, this, waitableTimerHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForWaitableTimer2Test, this, waitableTimerHandle));
    }

    GetStream() << "等待" << (threadCount * 3) / 2 << "秒钟。\n";

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);

    threadGroup.join_all();

    GetStream() << "等待结束。\n";

    for (auto handle : waitableTimerHandle)
    {
        ASSERT_TRUE(CloseSystemWaitableTimer(handle));
    }
}

void System::WaitForMultipleWaitableTimerTesting::WaitForWaitableTimer0Test(const Container& waitableTimerHandle)
{
    const auto flag = WaitForSystemWaitableTimer(boost::numeric_cast<WindowsDWord>(waitableTimerHandle.size()), waitableTimerHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ResetSystemWaitableTimer(waitableTimerHandle);
}

void System::WaitForMultipleWaitableTimerTesting::WaitForWaitableTimer1Test(const Container& waitableTimerHandle)
{
    const auto flag = WaitForSystemWaitableTimer(boost::numeric_cast<WindowsDWord>(waitableTimerHandle.size()), waitableTimerHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ResetSystemWaitableTimer(waitableTimerHandle);
}

void System::WaitForMultipleWaitableTimerTesting::WaitForWaitableTimer2Test(const Container& waitableTimerHandle)
{
    const auto flag = WaitForSystemWaitableTimer(boost::numeric_cast<WindowsDWord>(waitableTimerHandle.size()), waitableTimerHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ResetSystemWaitableTimer(waitableTimerHandle);
}

void System::WaitForMultipleWaitableTimerTesting::ResetSystemWaitableTimer(const Container& waitableTimerHandle)
{
    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base / 2;

    for (auto handle : waitableTimerHandle)
    {
        ASSERT_TRUE(SetSystemWaitableTimer(handle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));
    }
}

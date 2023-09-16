///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:31)

#include "WaitForMultipleWaitableTimerTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    Container waitableTimerHandles{};

    ASSERT_NOT_THROW_EXCEPTION_1(CreateWaitableTimerTest, waitableTimerHandles);

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandles);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, waitableTimerHandles);

    GetStream() << "等待结束。\n";

    for (auto waitableTimerHandle : waitableTimerHandles)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
    }
}

void System::WaitForMultipleWaitableTimerTesting::WaitForWaitableTimer0Test(const Container& waitableTimerHandles)
{
    const auto flag = WaitForSystemWaitableTimer(boost::numeric_cast<WindowsDWord>(waitableTimerHandles.size()), waitableTimerHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ResetSystemWaitableTimer(waitableTimerHandles);
}

void System::WaitForMultipleWaitableTimerTesting::WaitForWaitableTimer1Test(const Container& waitableTimerHandles)
{
    const auto flag = WaitForSystemWaitableTimer(boost::numeric_cast<WindowsDWord>(waitableTimerHandles.size()), waitableTimerHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ResetSystemWaitableTimer(waitableTimerHandles);
}

void System::WaitForMultipleWaitableTimerTesting::WaitForWaitableTimer2Test(const Container& waitableTimerHandles)
{
    const auto flag = WaitForSystemWaitableTimer(boost::numeric_cast<WindowsDWord>(waitableTimerHandles.size()), waitableTimerHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ResetSystemWaitableTimer(waitableTimerHandles);
}

void System::WaitForMultipleWaitableTimerTesting::ResetSystemWaitableTimer(const Container& waitableTimerHandles)
{
    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base / 2;

    for (const auto handle : waitableTimerHandles)
    {
        ASSERT_TRUE(SetSystemWaitableTimer(handle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));
    }
}

void System::WaitForMultipleWaitableTimerTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待。\n";

    SystemPause();
}

void System::WaitForMultipleWaitableTimerTesting::CreateWaitableTimerTest(Container& waitableTimerHandles)
{
    constexpr auto mutexSize = 5;
    for (auto i = 0; i < mutexSize; ++i)
    {
        const auto handle = CreateSystemWaitableTimer(nullptr, false, nullptr);
        ASSERT_TRUE(IsWaitableTimerValid(handle));

        waitableTimerHandles.emplace_back(handle);
    }
}

void System::WaitForMultipleWaitableTimerTesting::CreateThread(const Container& waitableTimerHandles)
{
    constexpr auto threadCount = 4;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, waitableTimerHandles]() {
            this->WaitForWaitableTimer0Test(waitableTimerHandles);
        });
        threadGroup.create_thread([this, waitableTimerHandles]() {
            this->WaitForWaitableTimer1Test(waitableTimerHandles);
        });
        threadGroup.create_thread([this, waitableTimerHandles]() {
            this->WaitForWaitableTimer2Test(waitableTimerHandles);
        });
    }

    GetStream() << "等待" << (threadCount * 3) / 2 << "秒钟。\n";

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandles);

    threadGroup.join_all();
}

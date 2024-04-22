/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:16)

#include "WaitForWaitableTimerTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForWaitableTimerTesting::WaitForWaitableTimerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForWaitableTimerTesting)

void System::WaitForWaitableTimerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForWaitableTimerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateSynchronizationTest);
}

void System::WaitForWaitableTimerTesting::CreateSynchronizationTest()
{
    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, false, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(DoCreateSynchronizationTest, waitableTimerHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

void System::WaitForWaitableTimerTesting::WaitForWaitableTimer0Test(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::WaitForWaitableTimerTesting::WaitForWaitableTimer1Test(WindowsHandle waitableTimerHandle)
{
    ASSERT_EQUAL(WaitForSystemWaitableTimer(waitableTimerHandle, EnumCastUnderlying(MutexWait::Infinite)), MutexWaitReturn::Object0);

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::WaitForWaitableTimerTesting::WaitForWaitableTimer2Test(WindowsHandle waitableTimerHandle)
{
    ASSERT_EQUAL(WaitForSystemWaitableTimer(waitableTimerHandle, EnumCastUnderlying(MutexWait::Infinite), true), MutexWaitReturn::Object0);

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::WaitForWaitableTimerTesting::WaitForWaitableTimer3Test(WindowsHandle waitableTimerHandle)
{
    ASSERT_EQUAL(WaitForSystemWaitableTimer(waitableTimerHandle, EnumCastUnderlying(MutexWait::Infinite), false), MutexWaitReturn::Object0);

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::WaitForWaitableTimerTesting::ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle)
{
    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base / 2;

    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));
}

void System::WaitForWaitableTimerTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待。\n";

    SystemPause();
}

void System::WaitForWaitableTimerTesting::DoCreateSynchronizationTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, waitableTimerHandle);

    GetStream() << "等待结束。\n";
}

void System::WaitForWaitableTimerTesting::CreateThread(WindowsHandle waitableTimerHandle)
{
    constexpr auto threadCount = 3;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, waitableTimerHandle]() {
            this->WaitForWaitableTimer0Test(waitableTimerHandle);
        });
        threadGroup.create_thread([this, waitableTimerHandle]() {
            this->WaitForWaitableTimer1Test(waitableTimerHandle);
        });
        threadGroup.create_thread([this, waitableTimerHandle]() {
            this->WaitForWaitableTimer2Test(waitableTimerHandle);
        });
        threadGroup.create_thread([this, waitableTimerHandle]() {
            this->WaitForWaitableTimer3Test(waitableTimerHandle);
        });
    }

    GetStream() << "等待" << (threadCount * 4) / 2 << "秒钟。\n";

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);

    threadGroup.join_all();
}

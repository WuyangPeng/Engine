/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:17)

#include "CreateWaitableTimerSynchronizationTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateWaitableTimerSynchronizationTesting::CreateWaitableTimerSynchronizationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateWaitableTimerSynchronizationTesting)

void System::CreateWaitableTimerSynchronizationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateWaitableTimerSynchronizationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateSynchronizationTest);
}

void System::CreateWaitableTimerSynchronizationTesting::CreateSynchronizationTest()
{
    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, false, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(DoCreateSynchronizationTest, waitableTimerHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

void System::CreateWaitableTimerSynchronizationTesting::WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::CreateWaitableTimerSynchronizationTesting::ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle)
{
    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base;
    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));
}

void System::CreateWaitableTimerSynchronizationTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待6秒钟。\n";

    SystemPause();
}

void System::CreateWaitableTimerSynchronizationTesting::DoCreateSynchronizationTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThreadTest, waitableTimerHandle);

    GetStream() << "等待结束。\n";
}

void System::CreateWaitableTimerSynchronizationTesting::CreateThreadTest(WindowsHandle waitableTimerHandle)
{
    constexpr auto threadCount = 5;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, waitableTimerHandle]() {
            this->WaitForWaitableTimerTest(waitableTimerHandle);
        });
    }

    GetStream() << "等待" << (threadCount + 1) << "秒钟。\n";

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);

    threadGroup.join_all();
}

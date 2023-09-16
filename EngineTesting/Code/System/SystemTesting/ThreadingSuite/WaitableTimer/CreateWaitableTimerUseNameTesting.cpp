///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:30)

#include "CreateWaitableTimerUseNameTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateWaitableTimerUseNameTesting::CreateWaitableTimerUseNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateWaitableTimerUseNameTesting)

void System::CreateWaitableTimerUseNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateWaitableTimerUseNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateSynchronizationTest);
}

void System::CreateWaitableTimerUseNameTesting::CreateSynchronizationTest()
{
    const auto waitableTimerName = System::ToString(GetTimeInMicroseconds());

    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, false, waitableTimerName.c_str());

    ASSERT_NOT_THROW_EXCEPTION_1(DoCreateSynchronizationTest, waitableTimerHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

void System::CreateWaitableTimerUseNameTesting::WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::CreateWaitableTimerUseNameTesting::ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle)
{
    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base;
    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));
}

void System::CreateWaitableTimerUseNameTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待6秒钟。\n";

    SystemPause();
}

void System::CreateWaitableTimerUseNameTesting::DoCreateSynchronizationTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, waitableTimerHandle);

    GetStream() << "等待结束。\n";
}

void System::CreateWaitableTimerUseNameTesting::CreateThread(WindowsHandle waitableTimerHandle)
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

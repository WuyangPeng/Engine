/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:17)

#include "CreateWaitableTimerManualUseFlagsTesting.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/WaitableTimerFlags.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateWaitableTimerManualUseFlagsTesting::CreateWaitableTimerManualUseFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream },
      waitableTimerStandardAccesses{ MutexStandardAccess::Delete,
                                     MutexStandardAccess::ReadControl,
                                     MutexStandardAccess::WriteDac,
                                     MutexStandardAccess::WriteOwner,
                                     MutexStandardAccess::Synchronize },
      waitableTimerSpecificAccess{ WaitableTimerSpecificAccess::AllAccess }

{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateWaitableTimerManualUseFlagsTesting)

void System::CreateWaitableTimerManualUseFlagsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateWaitableTimerManualUseFlagsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateManualTest);
}

void System::CreateWaitableTimerManualUseFlagsTesting::CreateManualTest()
{
    for (const auto waitableTimerStandardAccess : waitableTimerStandardAccesses)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateManualTest, waitableTimerStandardAccess);
    }
}

void System::CreateWaitableTimerManualUseFlagsTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待。\n";

    SystemPause();
}

void System::CreateWaitableTimerManualUseFlagsTesting::DoCreateManualTest(MutexStandardAccess waitableTimerStandardAccess)
{
    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, nullptr, CreateWaitableTimerReset::ManualReset, waitableTimerStandardAccess, waitableTimerSpecificAccess);

    ASSERT_NOT_THROW_EXCEPTION_1(ResultTest, waitableTimerHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

void System::CreateWaitableTimerManualUseFlagsTesting::ResultTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base;
    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));

    GetStream() << "等待" << -waitableTimerLargeInteger.QuadPart / base << "秒钟。\n";

    ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));
    ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));

    GetStream() << "等待结束。\n";
}

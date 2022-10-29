///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/23 0:05)

#include "CreateWaitableTimerSynchronizationUseFlagsTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/WaitableTimerFlags.h"
#include "System/Threading/WaitableTimer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateWaitableTimerSynchronizationUseFlagsTesting::CreateWaitableTimerSynchronizationUseFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream },
      waitableTimerStandardAccessFlags{ MutexStandardAccess::Delete,
                                        MutexStandardAccess::ReadControl,
                                        MutexStandardAccess::WriteDac,
                                        MutexStandardAccess::WriteOwner,
                                        MutexStandardAccess::Synchronize },
      waitableTimerSpecificAccess{ WaitableTimerSpecificAccess::AllAccess }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateWaitableTimerSynchronizationUseFlagsTesting)

void System::CreateWaitableTimerSynchronizationUseFlagsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateWaitableTimerSynchronizationUseFlagsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateManualTest);
}

void System::CreateWaitableTimerSynchronizationUseFlagsTesting::CreateManualTest()
{
    for (const auto waitableTimerStandardAccess : waitableTimerStandardAccessFlags)
    {
        auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, nullptr, CreateWaitableTimerReset::Default, waitableTimerStandardAccess, waitableTimerSpecificAccess);

        ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

        constexpr auto threadCount = 4;

        boost::thread_group threadGroup{};
        for (auto i = 0; i < threadCount; ++i)
        {
            threadGroup.create_thread(boost::bind(&ClassType::WaitForWaitableTimerTest, this, waitableTimerHandle));
        }

        ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);

        GetStream() << "等待" << (threadCount + 1) << "秒钟。\n";

        threadGroup.join_all();

        GetStream() << "等待结束。\n";

        ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
    }
}

void System::CreateWaitableTimerSynchronizationUseFlagsTesting::WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::CreateWaitableTimerSynchronizationUseFlagsTesting::ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle)
{
    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base;
    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));
}

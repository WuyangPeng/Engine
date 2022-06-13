///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:59)

#include "CreateWaitableTimerManualUseFlagsTesting.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/WaitableTimerFlags.h"
#include "System/Threading/WaitableTimer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateWaitableTimerManualUseFlagsTesting::CreateWaitableTimerManualUseFlagsTesting(const OStreamShared& stream)
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
    for (const auto waitableTimerStandardAccess : waitableTimerStandardAccessFlags)
    {
        auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, nullptr, CreateWaitableTimerReset::ManualReset, waitableTimerStandardAccess, waitableTimerSpecificAccess);

        ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

        constexpr auto base = 10000000LL;

        WindowsLargeInteger waitableTimerLargeInteger{};
        waitableTimerLargeInteger.QuadPart = -base;
        ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));

        GetStream() << "�ȴ�" << -waitableTimerLargeInteger.QuadPart / base << "���ӡ�\n";

        ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));
        ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));

        GetStream() << "�ȴ�������\n";

        ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
    }
}

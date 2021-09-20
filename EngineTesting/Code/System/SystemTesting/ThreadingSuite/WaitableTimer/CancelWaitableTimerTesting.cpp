///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/08 17:20)

#include "CancelWaitableTimerTesting.h"
#include "System/Threading/WaitableTimer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CancelWaitableTimerTesting::CancelWaitableTimerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CancelWaitableTimerTesting)

void System::CancelWaitableTimerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CancelWaitableTimerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CancelTest);
}

void System::CancelWaitableTimerTesting::CancelTest()
{
    auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, nullptr);
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    constexpr auto base = 10000000LL;

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -5 * base;
    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));

    ASSERT_TRUE(CancelSystemWaitableTimer(waitableTimerHandle));

    ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
}

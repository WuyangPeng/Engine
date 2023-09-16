///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 15:31)

#include "SetWaitableTimerTesting.h"
#include "System/Helper/Tools.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/SyncToolsFlags.h"
#include "System/Threading/SyncTools.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SetWaitableTimerTesting::SetWaitableTimerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SetWaitableTimerTesting)

void System::SetWaitableTimerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SetWaitableTimerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousUseTolerableDelayTest);
}

void System::SetWaitableTimerTesting::AsynchronousTest()
{
    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(DoAsynchronousTest, waitableTimerHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

void System::SetWaitableTimerTesting::DoAsynchronousTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -5 * base;
    constexpr WindowsLong period{ 5000 };

    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, period, ClassType::TimerAPCProcedure, this, false));

    GetStream() << "�ȴ�" << -waitableTimerLargeInteger.QuadPart / base << "���ӡ�\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    GetStream() << "�ȴ�" << period / 1000 << "���ӡ�\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);
}

void System::SetWaitableTimerTesting::AsynchronousUseTolerableDelayTest()
{
    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(DoAsynchronousUseTolerableDelayTest, waitableTimerHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);
}

void System::SetWaitableTimerTesting::DoAsynchronousUseTolerableDelayTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -5 * base;
    constexpr WindowsLong period{ 5000 };
    constexpr WindowsULong tolerableDelay{ 1000 };

    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, period, ClassType::TimerAPCProcedure, this, nullptr, tolerableDelay));

    GetStream() << "�ȴ�" << -waitableTimerLargeInteger.QuadPart / base << "���ӡ�\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    GetStream() << "�ȴ�" << period / 1000 << "���ӡ�\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);
}

void System::SetWaitableTimerTesting::TimerAPCProcedure(WindowsVoidPtr argToCompletionRoutine, WindowsDWord timerLowValue, WindowsDWord timerHighValue)
{
    UnusedFunction(timerLowValue, timerHighValue);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    const auto classType = reinterpret_cast<ClassType*>(argToCompletionRoutine);

#include SYSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "��������˻ص������ĵ��á�\n";
    }
}

void System::SetWaitableTimerTesting::PrintTipsMessage()
{
    GetStream() << "���������Ҫ�ȴ���\n";

    SystemPause();
}

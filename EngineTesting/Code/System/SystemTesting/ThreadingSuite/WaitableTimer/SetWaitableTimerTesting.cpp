/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:16)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
#ifdef SYSTEM_PLATFORM_WIN32

    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -5 * base;
    constexpr WindowsLong period{ 5000 };

    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, period, ClassType::TimerApcProcedure, this, false));

    GetStream() << "等待" << -waitableTimerLargeInteger.QuadPart / base << "秒钟。\n";

    ASSERT_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    GetStream() << "等待" << period / 1000 << "秒钟。\n";

    ASSERT_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

#endif  // !SYSTEM_PLATFORM_WIN32
}

void System::SetWaitableTimerTesting::AsynchronousUseTolerableDelayTest()
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(DoAsynchronousUseTolerableDelayTest, waitableTimerHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseWaitableTimerTest, waitableTimerHandle);

#endif  // !SYSTEM_PLATFORM_WIN32
}

void System::SetWaitableTimerTesting::DoAsynchronousUseTolerableDelayTest(WindowsHandle waitableTimerHandle)
{
#ifdef SYSTEM_PLATFORM_WIN32

    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -5 * base;
    constexpr WindowsLong period{ 5000 };
    constexpr WindowsULong tolerableDelay{ 1000 };

    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, period, ClassType::TimerApcProcedure, this, nullptr, tolerableDelay));

    GetStream() << "等待" << -waitableTimerLargeInteger.QuadPart / base << "秒钟。\n";

    ASSERT_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    GetStream() << "等待" << period / 1000 << "秒钟。\n";

    ASSERT_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

#endif  // !SYSTEM_PLATFORM_WIN32
}

void System::SetWaitableTimerTesting::TimerApcProcedure(WindowsVoidPtr argToCompletionRoutine, WindowsDWord timerLowValue, WindowsDWord timerHighValue)
{
    UnusedFunction(timerLowValue, timerHighValue);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    const auto classType = reinterpret_cast<ClassType*>(argToCompletionRoutine);

#include SYSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }
}

void System::SetWaitableTimerTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待。\n";

    SystemPause();
}

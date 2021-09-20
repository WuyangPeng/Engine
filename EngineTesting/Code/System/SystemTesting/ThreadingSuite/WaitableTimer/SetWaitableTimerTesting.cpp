///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/08 17:25)

#include "SetWaitableTimerTesting.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/SyncToolsFlags.h"
#include "System/Threading/SyncTools.h"
#include "System/Threading/WaitableTimer.h"
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
    static constexpr auto base = 10000000LL;

    auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, nullptr);
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -5 * base;
    constexpr WindowsLong period{ 5000 };

    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, period, ClassType::TimerAPCProcedure, this, false));

    GetStream() << "等待" << -waitableTimerLargeInteger.QuadPart / base << "秒钟。\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    GetStream() << "等待" << period / 1000 << "秒钟。\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
}

void System::SetWaitableTimerTesting::AsynchronousUseTolerableDelayTest()
{
    static constexpr auto base = 10000000LL;

    auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, true, nullptr);
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -5 * base;
    constexpr WindowsLong period{ 5000 };
    constexpr WindowsULong tolerableDelay{ 1000 };

    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, period, ClassType::TimerAPCProcedure, this, nullptr, tolerableDelay));

    GetStream() << "等待" << -waitableTimerLargeInteger.QuadPart / base << "秒钟。\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    GetStream() << "等待" << period / 1000 << "秒钟。\n";

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
}

void System::SetWaitableTimerTesting::TimerAPCProcedure(WindowsVoidPtr argToCompletionRoutine, MAYBE_UNUSED WindowsDWord timerLowValue, MAYBE_UNUSED WindowsDWord timerHighValue)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    auto classType = reinterpret_cast<ClassType*>(argToCompletionRoutine);

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

#include STSTEM_WARNING_POP
}

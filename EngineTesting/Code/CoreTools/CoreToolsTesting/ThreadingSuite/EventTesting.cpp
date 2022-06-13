///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:03)

#include "EventTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/Threading/ThreadGuardDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::EventTesting::EventTesting(const OStreamShared& stream)
    : ParentType{ stream }, manualResetTrueEvent{ true, false }, manualResetFlaseEvent{ false, true }, testValue{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EventTesting)

void CoreTools::EventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EventTesting::MainTest()
{
    // 测试两次
    ASSERT_NOT_THROW_EXCEPTION_0(ManualResetTrueCreateThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ManualResetTrueCreateThreadTest);

    ASSERT_NOT_THROW_EXCEPTION_0(ManualResetFalseCreateThreadTest);
}

void CoreTools::EventTesting::ManualResetTrueCreateThreadTest()
{
    {
        auto thread = ThreadGroup::Create();

        thread.AddThread(&ClassType::Thread0, this);
        thread.AddThread(&ClassType::Thread1, this);
        thread.AddThread(&ClassType::Thread2, this);
    }

    ThreadGuard threadGuard{ &ClassType::Thread3, this };
}

void CoreTools::EventTesting::Thread0()
{
    ASSERT_EQUAL(testValue, 0);

    ++testValue;

    manualResetTrueEvent.SetEvent();
}

void CoreTools::EventTesting::Thread1()
{
    manualResetTrueEvent.Wait();

    ASSERT_TRUE(testValue == 1 || testValue == 3);

    ++testValue;

    manualResetTrueEvent.SetEvent();
}

void CoreTools::EventTesting::Thread2()
{
    manualResetTrueEvent.Wait();

    ASSERT_TRUE(testValue == 1 || testValue == 2);

    testValue += 2;

    manualResetTrueEvent.SetEvent();
}

void CoreTools::EventTesting::Thread3()
{
    ASSERT_EQUAL(testValue, 4);

    testValue = 0;

    manualResetTrueEvent.ResetEvent();
}

void CoreTools::EventTesting::ManualResetFalseCreateThreadTest()
{
    {
        auto thread = ThreadGroup::Create();

        thread.AddThread(&ClassType::Thread4, this);
        thread.AddThread(&ClassType::Thread5, this);
        thread.AddThread(&ClassType::Thread4, this);
    }

    ThreadGuard threadGuard{ &ClassType::Thread6, this };
}

void CoreTools::EventTesting::Thread4()
{
    manualResetFlaseEvent.Wait();

    manualResetFlaseEvent.SetEvent();
}

void CoreTools::EventTesting::Thread5()
{
    manualResetFlaseEvent.Wait();

    manualResetFlaseEvent.SetEvent();
}

void CoreTools::EventTesting::Thread6()
{
    manualResetFlaseEvent.ResetEvent();
}

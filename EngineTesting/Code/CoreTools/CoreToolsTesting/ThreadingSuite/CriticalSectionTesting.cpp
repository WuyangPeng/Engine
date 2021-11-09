///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/02 14:13)

#include "CriticalSectionTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CriticalSectionTesting::CriticalSectionTesting(const OStreamShared& stream)
    : ParentType{ stream }, criticalSection0{ MutexCreate::UseCriticalSection }, criticalSection1{ MutexCreate::UseCriticalSection }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CriticalSectionTesting)

void CoreTools::CriticalSectionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CriticalSectionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// 递归测试
void CoreTools::CriticalSectionTesting::RecursionTest()
{
    criticalSection0.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);

    criticalSection0.Delete();
}

void CoreTools::CriticalSectionTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ criticalSection0 };
    TryScopedMutex holder2{ criticalSection0 };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ criticalSection0 };
}

// 多线程锁成功测试
void CoreTools::CriticalSectionTesting::MultithreadingLockingSuccessTest()
{
    criticalSection0.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);

    criticalSection0.Delete();
}

void CoreTools::CriticalSectionTesting::CreateLockingSuccessThread()
{
    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, &ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::CriticalSectionTesting::CreateThread(Function function)
{
    ThreadGroup thread{ DisableNotThrow::Disable };

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::CriticalSectionTesting::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::CriticalSectionTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ criticalSection0 };

    constexpr auto original = 0;
    static auto testValue = original;

    const auto loopCount = GetTestLoopCount();

    for (auto outerLoop = 0; outerLoop < loopCount; ++outerLoop)
    {
        for (auto innerLoop = 0; innerLoop < loopCount; ++innerLoop)
        {
            testValue = outerLoop + innerLoop;
            ASSERT_EQUAL(testValue, outerLoop + innerLoop);

            testValue = outerLoop - innerLoop;
            ASSERT_EQUAL(testValue, outerLoop - innerLoop);

            testValue = outerLoop * innerLoop;
            ASSERT_EQUAL(testValue, outerLoop * innerLoop);
        }
    }

    testValue = original;
    ASSERT_EQUAL(testValue, original);
}

// 多线程锁失败测试
void CoreTools::CriticalSectionTesting::MultithreadingLockingFailureTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);
}

void CoreTools::CriticalSectionTesting::CreateLockingFailureThread()
{
    ScopedMutex holder(criticalSection1);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, &ClassType::MultithreadingFailureCallBack);
}

void CoreTools::CriticalSectionTesting::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::CriticalSectionTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::CriticalSectionTesting::TryLockFailureTest()
{
    TryScopedMutex holder(criticalSection1);

    ASSERT_FALSE(holder.IsSuccess());
}

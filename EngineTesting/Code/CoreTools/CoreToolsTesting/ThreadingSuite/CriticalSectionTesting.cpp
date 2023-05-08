///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:34)

#include "CriticalSectionTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CriticalSectionTesting::CriticalSectionTesting(const OStreamShared& stream)
    : ParentType{ stream }, dllCriticalSection{ MutexCreate::UseCriticalSection }, criticalSection{ MutexCreate::UseCriticalSection }
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
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingFailureTest);
}

// 递归测试
void CoreTools::CriticalSectionTesting::RecursionTest()
{
    dllCriticalSection.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);

    dllCriticalSection.Delete();
}

void CoreTools::CriticalSectionTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ dllCriticalSection };
    const TryScopedMutex holder2{ dllCriticalSection };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ dllCriticalSection };
}

// 多线程锁成功测试
void CoreTools::CriticalSectionTesting::MultiThreadingLockingSuccessTest()
{
    dllCriticalSection.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);

    dllCriticalSection.Delete();
}

void CoreTools::CriticalSectionTesting::CreateLockingSuccessThread()
{
    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, &ClassType::MultiThreadingSuccessCallBack);
}

void CoreTools::CriticalSectionTesting::CreateThread(Function function)
{
    auto thread = ThreadGroup::Create();

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::CriticalSectionTesting::MultiThreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::CriticalSectionTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ dllCriticalSection };

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
void CoreTools::CriticalSectionTesting::MultiThreadingLockingFailureTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);
}

void CoreTools::CriticalSectionTesting::CreateLockingFailureThread()
{
    ScopedMutex holder(criticalSection);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, &ClassType::MultiThreadingFailureCallBack);
}

void CoreTools::CriticalSectionTesting::MultiThreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::CriticalSectionTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::CriticalSectionTesting::TryLockFailureTest()
{
    const TryScopedMutex holder(criticalSection);

    ASSERT_FALSE(holder.IsSuccess());
}

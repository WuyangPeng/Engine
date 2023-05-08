///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:33)

#include "BoostMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::BoostMutexTesting::BoostMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, boostMutex{ MutexCreate::UseBoost }, boostDllMutex{ MutexCreate::UseBoost }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BoostMutexTesting)

void CoreTools::BoostMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BoostMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingFailureTest);
}

// 递归测试
void CoreTools::BoostMutexTesting::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::BoostMutexTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ boostMutex };
    const TryScopedMutex holder2{ boostMutex };

    ASSERT_FALSE(holder2.IsSuccess());
}

// 多线程锁成功测试
void CoreTools::BoostMutexTesting::MultiThreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::BoostMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultiThreadingSuccessCallBack);
}

void CoreTools::BoostMutexTesting::CreateThread(Function function)
{
    auto thread = ThreadGroup::Create();

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::BoostMutexTesting::MultiThreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::BoostMutexTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ boostMutex };

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
void CoreTools::BoostMutexTesting::MultiThreadingLockingFailureTest()
{
    boostDllMutex.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    boostDllMutex.Delete();
}

void CoreTools::BoostMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ boostDllMutex };

    CreateThread(&ClassType::MultiThreadingFailureCallBack);
}

void CoreTools::BoostMutexTesting::MultiThreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::BoostMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::BoostMutexTesting::TryLockFailureTest()
{
    const TryScopedMutex holder{ boostDllMutex };

    ASSERT_FALSE(holder.IsSuccess());
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/02 14:10)

#include "BoostMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::BoostMutexTesting::BoostMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, boostMutex0{ MutexCreate::UseBoost }, boostMutex1{ MutexCreate::UseBoost }
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
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// 递归测试
void CoreTools::BoostMutexTesting::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::BoostMutexTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ boostMutex0 };
    TryScopedMutex holder2{ boostMutex0 };

    ASSERT_FALSE(holder2.IsSuccess());
}

// 多线程锁成功测试
void CoreTools::BoostMutexTesting::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::BoostMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultithreadingSuccessCallBack);
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

void CoreTools::BoostMutexTesting::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::BoostMutexTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ boostMutex0 };

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
void CoreTools::BoostMutexTesting::MultithreadingLockingFailureTest()
{
    boostMutex1.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    boostMutex1.Delete();
}

void CoreTools::BoostMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ boostMutex1 };

    CreateThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::BoostMutexTesting::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::BoostMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::BoostMutexTesting::TryLockFailureTest()
{
    TryScopedMutex holder{ boostMutex1 };

    ASSERT_FALSE(holder.IsSuccess());
}

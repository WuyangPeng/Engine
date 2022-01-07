///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/02 14:51)

#include "StdRecursiveMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StdRecursiveMutexTesting::StdRecursiveMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, stdMutex0{ MutexCreate::UseStdRecursive }, stdMutex1{ MutexCreate::UseStdRecursive }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdRecursiveMutexTesting)

void CoreTools::StdRecursiveMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StdRecursiveMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// 递归测试
void CoreTools::StdRecursiveMutexTesting::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::StdRecursiveMutexTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ stdMutex0 };
    TryScopedMutex holder2{ stdMutex0 };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ stdMutex0 };
}

// 多线程锁成功测试
void CoreTools::StdRecursiveMutexTesting::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::StdRecursiveMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::StdRecursiveMutexTesting::CreateThread(Function function)
{
    auto thread = ThreadGroup::Create();

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::StdRecursiveMutexTesting::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::StdRecursiveMutexTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ stdMutex0 };

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
void CoreTools::StdRecursiveMutexTesting::MultithreadingLockingFailureTest()
{
    stdMutex1.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    stdMutex1.Delete();
}

void CoreTools::StdRecursiveMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ stdMutex1 };

    CreateThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::StdRecursiveMutexTesting::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::StdRecursiveMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::StdRecursiveMutexTesting::TryLockFailureTest()
{
    TryScopedMutex holder{ stdMutex1 };

    ASSERT_FALSE(holder.IsSuccess());
}

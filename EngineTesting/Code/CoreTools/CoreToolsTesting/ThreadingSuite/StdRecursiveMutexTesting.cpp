///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:35)

#include "StdRecursiveMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StdRecursiveMutexTesting::StdRecursiveMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, stdMutex{ MutexCreate::UseStdRecursive }, stdDllMutex{ MutexCreate::UseStdRecursive }
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
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingFailureTest);
}

// 递归测试
void CoreTools::StdRecursiveMutexTesting::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::StdRecursiveMutexTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ stdMutex };
    const TryScopedMutex holder2{ stdMutex };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ stdMutex };
}

// 多线程锁成功测试
void CoreTools::StdRecursiveMutexTesting::MultiThreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::StdRecursiveMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultiThreadingSuccessCallBack);
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

void CoreTools::StdRecursiveMutexTesting::MultiThreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::StdRecursiveMutexTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ stdMutex };

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
void CoreTools::StdRecursiveMutexTesting::MultiThreadingLockingFailureTest()
{
    stdDllMutex.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    stdDllMutex.Delete();
}

void CoreTools::StdRecursiveMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ stdDllMutex };

    CreateThread(&ClassType::MultiThreadingFailureCallBack);
}

void CoreTools::StdRecursiveMutexTesting::MultiThreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::StdRecursiveMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::StdRecursiveMutexTesting::TryLockFailureTest()
{
    const TryScopedMutex holder{ stdDllMutex };

    ASSERT_FALSE(holder.IsSuccess());
}

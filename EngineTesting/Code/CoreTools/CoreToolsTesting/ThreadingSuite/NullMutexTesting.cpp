///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/02 09:12)

#include "NullMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::NullMutexTesting::NullMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, nullMutex{ MutexCreate::UseNull }, nullDllMutex{ MutexCreate::UseNull }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullMutexTesting)

void CoreTools::NullMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NullMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiThreadingLockingFailureTest);
}

// 递归测试
void CoreTools::NullMutexTesting::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::NullMutexTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ nullMutex };
    const TryScopedMutex holder2{ nullMutex };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ nullMutex };
}

// 多线程锁成功测试
void CoreTools::NullMutexTesting::MultiThreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::NullMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultiThreadingSuccessCallBack);
}

void CoreTools::NullMutexTesting::CreateThread(Function function)
{
    auto thread = ThreadGroup::Create();

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::NullMutexTesting::MultiThreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::NullMutexTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ nullMutex };

    constexpr auto original = 0;
    static auto testValue = original;

    const auto loopCount = GetTestLoopCount();

    for (auto outerLoop = 0; outerLoop < loopCount; ++outerLoop)
    {
        for (auto innerLoop = 0; innerLoop < loopCount; ++innerLoop)
        {
            testValue = outerLoop + innerLoop;

            testValue = outerLoop - innerLoop;

            testValue = outerLoop * innerLoop;
        }
    }

    testValue = original;
}

// 多线程锁失败测试
void CoreTools::NullMutexTesting::MultiThreadingLockingFailureTest()
{
    nullDllMutex.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    nullDllMutex.Delete();
}

void CoreTools::NullMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ nullDllMutex };

    CreateThread(&ClassType::MultiThreadingFailureCallBack);
}

void CoreTools::NullMutexTesting::MultiThreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::NullMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockTest);
}

void CoreTools::NullMutexTesting::TryLockTest()
{
    const TryScopedMutex holder{ nullDllMutex };

    ASSERT_TRUE(holder.IsSuccess());
}

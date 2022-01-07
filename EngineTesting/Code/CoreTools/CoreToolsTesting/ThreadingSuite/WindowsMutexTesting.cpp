///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/02 14:56)

#include "WindowsMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::WindowsMutexTesting::WindowsMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, windowsMutex0{ MutexCreate::UseDefault }, windowsMutex1{ MutexCreate::UseDefault }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsMutexTesting)

void CoreTools::WindowsMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WindowsMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// 递归测试
void CoreTools::WindowsMutexTesting::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::WindowsMutexTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ windowsMutex0 };
    TryScopedMutex holder2{ windowsMutex0 };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ windowsMutex0 };
}

// 多线程锁成功测试
void CoreTools::WindowsMutexTesting::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::WindowsMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::WindowsMutexTesting::CreateThread(Function function)
{
    auto thread = ThreadGroup::Create();

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::WindowsMutexTesting::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::WindowsMutexTesting::StaticValueTest()
{
    ScopedMutex holderFirst{ windowsMutex0 };

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
void CoreTools::WindowsMutexTesting::MultithreadingLockingFailureTest()
{
    windowsMutex1.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    windowsMutex1.Delete();
}

void CoreTools::WindowsMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ windowsMutex1 };

    CreateThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::WindowsMutexTesting::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::WindowsMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::WindowsMutexTesting::TryLockFailureTest()
{
    TryScopedMutex holder{ windowsMutex1 };

    ASSERT_FALSE(holder.IsSuccess());
}

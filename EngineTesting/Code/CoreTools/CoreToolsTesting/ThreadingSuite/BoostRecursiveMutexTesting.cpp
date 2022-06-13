///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:02)

#include "BoostRecursiveMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::BoostRecursiveMutexTesting::BoostRecursiveMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, boostMutex0{ MutexCreate::UseBoostRecursive }, boostMutex1{ MutexCreate::UseBoostRecursive }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BoostRecursiveMutexTesting)

void CoreTools::BoostRecursiveMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BoostRecursiveMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// �ݹ����
void CoreTools::BoostRecursiveMutexTesting::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::BoostRecursiveMutexTesting::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ boostMutex0 };
    TryScopedMutex holder2{ boostMutex0 };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ boostMutex0 };
}

// ���߳����ɹ�����
void CoreTools::BoostRecursiveMutexTesting::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::BoostRecursiveMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::BoostRecursiveMutexTesting::CreateThread(Function function)
{
    auto thread = ThreadGroup::Create();

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::BoostRecursiveMutexTesting::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::BoostRecursiveMutexTesting::StaticValueTest()
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

// ���߳���ʧ�ܲ���
void CoreTools::BoostRecursiveMutexTesting::MultithreadingLockingFailureTest()
{
    boostMutex1.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    boostMutex1.Delete();
}

void CoreTools::BoostRecursiveMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ boostMutex1 };

    CreateThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::BoostRecursiveMutexTesting::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::BoostRecursiveMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::BoostRecursiveMutexTesting::TryLockFailureTest()
{
    TryScopedMutex holder{ boostMutex1 };

    ASSERT_FALSE(holder.IsSuccess());
}

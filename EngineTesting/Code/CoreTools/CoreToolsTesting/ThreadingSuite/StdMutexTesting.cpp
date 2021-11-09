///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/02 14:47)

#include "StdMutexTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StdMutexTesting::StdMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, stdMutex0{ MutexCreate::UseStd }, stdMutex1{ MutexCreate::UseStd }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdMutexTesting)

void CoreTools::StdMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StdMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// �ݹ����
void CoreTools::StdMutexTesting::RecursionTest()
{
    ASSERT_THROW_EXCEPTION_0(CreateRecursionTestFailureHolder);
}

void CoreTools::StdMutexTesting::CreateRecursionTestFailureHolder()
{
    ScopedMutex holder1{ stdMutex0 };
    TryScopedMutex holder2{ stdMutex0 };

    ASSERT_FALSE(holder2.IsSuccess());

    ScopedMutex holder3{ stdMutex0 };
}

// ���߳����ɹ�����
void CoreTools::StdMutexTesting::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::StdMutexTesting::CreateLockingSuccessThread()
{
    CreateThread(&ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::StdMutexTesting::CreateThread(Function function)
{
    ThreadGroup thread{ DisableNotThrow::Disable };

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::StdMutexTesting::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::StdMutexTesting::StaticValueTest()
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

// ���߳���ʧ�ܲ���
void CoreTools::StdMutexTesting::MultithreadingLockingFailureTest()
{
    stdMutex1.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    stdMutex1.Delete();
}

void CoreTools::StdMutexTesting::CreateLockingFailureThread()
{
    ScopedMutex holder{ stdMutex1 };

    CreateThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::StdMutexTesting::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::StdMutexTesting::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::StdMutexTesting::TryLockFailureTest()
{
    TryScopedMutex holder{ stdMutex1 };

    ASSERT_FALSE(holder.IsSuccess());
}

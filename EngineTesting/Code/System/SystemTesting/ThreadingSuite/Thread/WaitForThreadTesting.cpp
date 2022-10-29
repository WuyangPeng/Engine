///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 23:47)

#include "WaitForThreadTesting.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForThreadTesting::WaitForThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForThreadTesting)

void System::WaitForThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForThreadTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(WaitThreadTest);
}

bool System::WaitForThreadTesting::WaitThreadTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread3Test);

    return true;
}

void System::WaitForThreadTesting::WaitThread0Test()
{
    WindowsDWord threadId{ 0 };
    auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    ASSERT_TRUE(CloseSystemThread(threadHandle));
}

void System::WaitForThreadTesting::WaitThread1Test()
{
    WindowsDWord threadId{ 0 };
    auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    const auto flag = WaitForSystemThread(threadHandle, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(CloseSystemThread(threadHandle));
}

void System::WaitForThreadTesting::WaitThread2Test()
{
    WindowsDWord threadId{ 0 };
    auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    const auto flag = WaitForSystemThread(threadHandle, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(CloseSystemThread(threadHandle));
}

void System::WaitForThreadTesting::WaitThread3Test()
{
    WindowsDWord threadId{ 0 };
    auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    const auto flag = WaitForSystemThread(threadHandle, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(CloseSystemThread(threadHandle));
}

System::WindowsDWord System::WaitForThreadTesting::ThreadStartRoutine(void* threadParameter)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include STSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

    return 0;
}
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:21)

#include "WaitForThreadTesting.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForThreadTesting::WaitForThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForThreadTesting)

void System::WaitForThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThreadTest);
}

void System::WaitForThreadTesting::WaitThreadTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitThread3Test);
}

void System::WaitForThreadTesting::WaitThread0Test()
{
    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

void System::WaitForThreadTesting::WaitThread1Test()
{
    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    const auto flag = WaitForSystemThread(threadHandle, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

void System::WaitForThreadTesting::WaitThread2Test()
{
    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    const auto flag = WaitForSystemThread(threadHandle, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

void System::WaitForThreadTesting::WaitThread3Test()
{
    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    const auto flag = WaitForSystemThread(threadHandle, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

System::WindowsDWord System::WaitForThreadTesting::ThreadStartRoutine(void* threadParameter)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    const auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include SYSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

    return 0;
}
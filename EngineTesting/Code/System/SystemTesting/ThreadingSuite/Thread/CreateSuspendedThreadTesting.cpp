/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:21)

#include "CreateSuspendedThreadTesting.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSuspendedThreadTesting::CreateSuspendedThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSuspendedThreadTesting)

void System::CreateSuspendedThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateSuspendedThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::CreateSuspendedThreadTesting::ThreadTest()
{
    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, this, ThreadCreation::CreateSuspended, &threadId);

    ASSERT_NOT_THROW_EXCEPTION_2(DoThreadTest, threadHandle, threadId);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

System::WindowsDWord System::CreateSuspendedThreadTesting::ThreadStartRoutine(void* threadParameter)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    const auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include SYSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

    return ExitSystemThread(0);
}

void System::CreateSuspendedThreadTesting::DoThreadTest(ThreadHandle threadHandle, WindowsDWord threadId)
{
    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    /// 返回先前的暂停计数。
    ASSERT_EQUAL(SuspendSystemThread(threadHandle), 1u);
    ASSERT_EQUAL(ResumeSystemThread(threadHandle), 2u);
    ASSERT_EQUAL(ResumeSystemThread(threadHandle), 1u);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));
}

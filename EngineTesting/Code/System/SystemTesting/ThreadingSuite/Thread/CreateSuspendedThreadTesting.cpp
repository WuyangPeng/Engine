///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 23:46)

#include "CreateSuspendedThreadTesting.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSuspendedThreadTesting::CreateSuspendedThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSuspendedThreadTesting)

void System::CreateSuspendedThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateSuspendedThreadTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ThreadTest);
}

bool System::CreateSuspendedThreadTesting::ThreadTest()
{
    WindowsDWord threadId{ 0 };
    auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, this, ThreadCreation::CreateSuspended, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    // 返回先前的暂停计数。
    ASSERT_EQUAL(SuspendSystemThread(threadHandle), 1u);
    ASSERT_EQUAL(ResumeSystemThread(threadHandle), 2u);
    ASSERT_EQUAL(ResumeSystemThread(threadHandle), 1u);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    ASSERT_TRUE(CloseSystemThread(threadHandle));

    return true;
}

System::WindowsDWord System::CreateSuspendedThreadTesting::ThreadStartRoutine(void* threadParameter)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include STSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

    return ExitSystemThread(0);
}

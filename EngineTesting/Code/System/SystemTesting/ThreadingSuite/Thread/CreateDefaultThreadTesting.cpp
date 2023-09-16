///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:25)

#include "CreateDefaultThreadTesting.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateDefaultThreadTesting::CreateDefaultThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateDefaultThreadTesting)

void System::CreateDefaultThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateDefaultThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::CreateDefaultThreadTesting::ThreadTest()
{
    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

    ASSERT_NOT_THROW_EXCEPTION_2(DoThreadTest, threadHandle, threadId);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

System::WindowsDWord System::CreateDefaultThreadTesting::ThreadStartRoutine(void* threadParameter)
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

void System::CreateDefaultThreadTesting::DoThreadTest(ThreadHandle threadHandle, WindowsDWord threadId)
{
    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));
}

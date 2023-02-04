///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:12)

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include STSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "��������˻ص������ĵ��á�\n";
    }

    return ExitSystemThread(0);
}

void System::CreateSuspendedThreadTesting::DoThreadTest(ThreadHandle threadHandle, WindowsDWord threadId)
{
    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    // ������ǰ����ͣ������
    ASSERT_EQUAL(SuspendSystemThread(threadHandle), 1u);
    ASSERT_EQUAL(ResumeSystemThread(threadHandle), 2u);
    ASSERT_EQUAL(ResumeSystemThread(threadHandle), 1u);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));
}

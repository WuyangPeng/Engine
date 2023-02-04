///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:01)

#include "CreateCThreadTesting.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateCThreadTesting::CreateCThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateCThreadTesting)

void System::CreateCThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateCThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BeginThreadExTest);
}

void System::CreateCThreadTesting::BeginThreadExTest()
{
    unsigned int threadId{ 0 };
    const auto threadHandle = BeginSystemThread(nullptr, 0, ClassType::ThreadStartRoutineEx, this, 0, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    ASSERT_TRUE(CloseSystemThread(threadHandle));
}

unsigned int System::CreateCThreadTesting::ThreadStartRoutineEx(void* threadParameter)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include STSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "��������˻ص������ĵ��á�\n";
    }

    EndSystemThread(0);

    return 0u;
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:21)

#include "CreateCThreadTesting.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateCThreadTesting::CreateCThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    const auto threadHandle = BeginSystemThread(nullptr, 0, ThreadStartRoutineEx, this, 0, &threadId);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    ASSERT_TRUE(CloseSystemThread(threadHandle));
}

unsigned int System::CreateCThreadTesting::ThreadStartRoutineEx(void* threadParameter)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    const auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include SYSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

    EndSystemThread(0);

    return 0u;
}

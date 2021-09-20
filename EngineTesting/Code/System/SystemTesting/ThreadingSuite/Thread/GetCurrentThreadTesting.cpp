///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/10 16:31)

#include "GetCurrentThreadTesting.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetCurrentThreadTesting::GetCurrentThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetCurrentThreadTesting)

void System::GetCurrentThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetCurrentThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadPriorityTest);
}

void System::GetCurrentThreadTesting::ThreadPriorityTest()
{
    auto threadHandle = GetCurrentSystemThread();
    ASSERT_TRUE(IsThreadHandleValid(threadHandle));

    const auto threadId = GetCurrentSystemThreadID();
    ASSERT_LESS(0u, threadId);
}

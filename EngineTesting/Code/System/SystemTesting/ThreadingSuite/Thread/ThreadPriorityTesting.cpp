///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:23)

#include "ThreadPriorityTesting.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ThreadPriorityTesting::ThreadPriorityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ThreadPriorityTesting)

void System::ThreadPriorityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ThreadPriorityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadPriorityTest);
}

void System::ThreadPriorityTesting::ThreadPriorityTest()
{
    const auto threadHandle = GetCurrentSystemThread();
    ASSERT_TRUE(IsThreadHandleValid(threadHandle));

    const auto originalPrority = GetSystemThreadPriority(threadHandle);

    ASSERT_TRUE(SetSystemThreadPriority(threadHandle, EnumCastUnderlying(ThreadPriority::Highest)));

    const auto prority = GetSystemThreadPriority(threadHandle);
    ASSERT_EQUAL(EnumCastUnderlying(ThreadPriority::Highest), prority);

    ASSERT_TRUE(SetSystemThreadPriority(threadHandle, originalPrority));
}

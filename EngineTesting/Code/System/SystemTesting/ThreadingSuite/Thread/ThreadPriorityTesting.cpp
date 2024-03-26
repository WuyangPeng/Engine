/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:21)

#include "ThreadPriorityTesting.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ThreadPriorityTesting::ThreadPriorityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    const auto originalPriority = GetSystemThreadPriority(threadHandle);

    ASSERT_TRUE(SetSystemThreadPriority(threadHandle, EnumCastUnderlying(ThreadPriority::Highest)));

    const auto priority = GetSystemThreadPriority(threadHandle);
    ASSERT_EQUAL(EnumCastUnderlying(ThreadPriority::Highest), priority);

    ASSERT_TRUE(SetSystemThreadPriority(threadHandle, originalPriority));
}

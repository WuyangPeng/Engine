///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/11 13:51)

#include "PriorityBoostTesting.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/Thread.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::PriorityBoostTesting::PriorityBoostTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PriorityBoostTesting)

void System::PriorityBoostTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PriorityBoostTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::PriorityBoostTesting::ThreadTest()
{
    auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    WindowsDWord threadID{ 0 };
    auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, mutexHandle, ThreadCreation::Default, &threadID);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadID);

    auto disablePriorityBoost = true;
    ASSERT_TRUE(GetSystemThreadPriorityBoost(threadHandle, &disablePriorityBoost));
    ASSERT_EQUAL(disablePriorityBoost, false);

    ASSERT_TRUE(SetSystemThreadPriorityBoost(threadHandle, true));
    ASSERT_TRUE(GetSystemThreadPriorityBoost(threadHandle, &disablePriorityBoost));
    ASSERT_EQUAL(disablePriorityBoost, true);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    ASSERT_TRUE(CloseSystemThread(threadHandle));
    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}

System::WindowsDWord System::PriorityBoostTesting::ThreadStartRoutine(void* threadParameter) noexcept
{
    MAYBE_UNUSED const auto waitResult = WaitForSystemMutex(threadParameter);

    MAYBE_UNUSED const auto releaseResult = ReleaseSystemMutex(threadParameter);

    return 1u;
}

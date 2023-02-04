///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 20:07)

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
    const auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(DoThreadTest, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}

System::WindowsDWord System::PriorityBoostTesting::ThreadStartRoutine(void* threadParameter) noexcept
{
    MAYBE_UNUSED const auto waitResult = WaitForSystemMutex(threadParameter);

    MAYBE_UNUSED const auto releaseResult = ReleaseSystemMutex(threadParameter);

    return exitFunctionCode;
}

void System::PriorityBoostTesting::DoThreadTest(WindowsHandle mutexHandle)
{
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    WindowsDWord threadID{ 0 };
    const auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, mutexHandle, ThreadCreation::Default, &threadID);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest, threadHandle, threadID, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

void System::PriorityBoostTesting::ResultTest(WindowsHandle threadHandle, WindowsDWord threadID, WindowsHandle mutexHandle)
{
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
}

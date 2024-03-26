/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:20)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    std::ignore = WaitForSystemMutex(threadParameter);

    std::ignore = ReleaseSystemMutex(threadParameter);

    return exitFunctionCode;
}

void System::PriorityBoostTesting::DoThreadTest(WindowsHandle mutexHandle)
{
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, mutexHandle, ThreadCreation::Default, &threadId);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest, threadHandle, threadId, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);
}

void System::PriorityBoostTesting::ResultTest(WindowsHandle threadHandle, WindowsDWord threadId, WindowsHandle mutexHandle)
{
    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    auto disablePriorityBoost = true;
    ASSERT_TRUE(GetSystemThreadPriorityBoost(threadHandle, &disablePriorityBoost));
    ASSERT_EQUAL(disablePriorityBoost, false);

    ASSERT_TRUE(SetSystemThreadPriorityBoost(threadHandle, true));
    ASSERT_TRUE(GetSystemThreadPriorityBoost(threadHandle, &disablePriorityBoost));
    ASSERT_EQUAL(disablePriorityBoost, true);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
    ASSERT_TRUE(WaitForSystemThread(threadHandle));
}

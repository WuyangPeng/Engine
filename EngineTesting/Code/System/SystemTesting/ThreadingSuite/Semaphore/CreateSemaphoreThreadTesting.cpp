///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 15:15)

#include "CreateSemaphoreThreadTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSemaphoreThreadTesting::CreateSemaphoreThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSemaphoreThreadTesting)

void System::CreateSemaphoreThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateSemaphoreThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::CreateSemaphoreThreadTesting::ThreadTest()
{
    constexpr WindowsLong maxSemphoreCount{ 5 };

    const auto semaphoreHandle = CreateSystemSemaphore(maxSemphoreCount, maxSemphoreCount);
    ASSERT_TRUE(IsSystemSemaphoreValid(semaphoreHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, semaphoreHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSemaphoreTest, semaphoreHandle);
}

void System::CreateSemaphoreThreadTesting::WaitForSemaphoreTest(WindowsHandle semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(semaphoreHandle, EnumCastUnderlying(MutexWait::Infinite));

    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    if (flag == MutexWaitReturn::Object0)
    {
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, nullptr));
    }
}

void System::CreateSemaphoreThreadTesting::CreateThread(WindowsHandle semaphoreHandle)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest, this, semaphoreHandle));
    }

    threadGroup.join_all();
}

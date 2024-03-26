/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:23)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    constexpr WindowsLong maxSemaphoreCount{ 5 };

    const auto semaphoreHandle = CreateSystemSemaphore(maxSemaphoreCount, maxSemaphoreCount);
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
        threadGroup.create_thread([this, semaphoreHandle]() {
            this->WaitForSemaphoreTest(semaphoreHandle);
        });
    }

    threadGroup.join_all();
}

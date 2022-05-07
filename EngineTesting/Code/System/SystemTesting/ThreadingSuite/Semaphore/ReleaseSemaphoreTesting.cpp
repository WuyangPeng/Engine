///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/27 14:03)

#include "ReleaseSemaphoreTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ReleaseSemaphoreTesting::ReleaseSemaphoreTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReleaseSemaphoreTesting)

void System::ReleaseSemaphoreTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReleaseSemaphoreTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitReleaseTest);
}

void System::ReleaseSemaphoreTesting::InitReleaseTest()
{
    constexpr WindowsLong maxSemphoreCount{ 10 };
    constexpr auto threadCount = 12;

    auto semaphoreHandle = CreateSystemSemaphore(0, maxSemphoreCount);
    ASSERT_TRUE(IsSystemSemaphoreValid(semaphoreHandle));

    for (WindowsLong index{ 0 }; index < maxSemphoreCount; ++index)
    {
        WindowsLong previousCount{ 0 };
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, &previousCount));

        ASSERT_EQUAL(previousCount, index);
    }

    boost::thread_group threadGroup;
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest, this, semaphoreHandle));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemSemaphore(semaphoreHandle));
}

void System::ReleaseSemaphoreTesting::WaitForSemaphoreTest(WindowsHandle semaphoreHandle)
{
    const auto flag = WaitForSystemSemaphore(semaphoreHandle, EnumCastUnderlying(MutexWait::Infinite));

    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    if (flag == MutexWaitReturn::Object0)
    {
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, nullptr));
    }
}
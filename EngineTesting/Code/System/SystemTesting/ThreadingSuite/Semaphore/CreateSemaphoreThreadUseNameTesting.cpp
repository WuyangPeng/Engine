///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:53)

#include "CreateSemaphoreThreadUseNameTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSemaphoreThreadUseNameTesting::CreateSemaphoreThreadUseNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSemaphoreThreadUseNameTesting)

void System::CreateSemaphoreThreadUseNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateSemaphoreThreadUseNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::CreateSemaphoreThreadUseNameTesting::ThreadTest()
{
    constexpr WindowsLong maxSemphoreCount{ 5 };
    constexpr auto threadCount = 12;

    auto semaphoreName = System::ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto semaphoreHandle = CreateSystemSemaphore(nullptr, maxSemphoreCount, maxSemphoreCount, semaphoreName.c_str());
    ASSERT_TRUE(IsSystemSemaphoreValid(semaphoreHandle));

    boost::thread_group threadGroup;
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest, this, semaphoreHandle));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemSemaphore(semaphoreHandle));
}

void System::CreateSemaphoreThreadUseNameTesting::WaitForSemaphoreTest(WindowsHandle semaphoreHandle)
{
    const auto result = WaitForSystemSemaphore(semaphoreHandle);
    ASSERT_TRUE(result);

    if (result)
    {
        ASSERT_TRUE(ReleaseSystemSemaphore(semaphoreHandle, 1, nullptr));
    }
}

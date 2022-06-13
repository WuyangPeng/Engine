///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:59)

#include "CreateWaitableTimerUseNameTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/WaitableTimer.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateWaitableTimerUseNameTesting::CreateWaitableTimerUseNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateWaitableTimerUseNameTesting)

void System::CreateWaitableTimerUseNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateWaitableTimerUseNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateSynchronizationTest);
}

void System::CreateWaitableTimerUseNameTesting::CreateSynchronizationTest()
{
    auto waitableTimerName = System::ToString(GetTimeInMicroseconds());

    auto waitableTimerHandle = CreateSystemWaitableTimer(nullptr, false, waitableTimerName.c_str());
    ASSERT_TRUE(IsWaitableTimerValid(waitableTimerHandle));

    constexpr auto threadCount = 5;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForWaitableTimerTest, this, waitableTimerHandle));
    }

    GetStream() << "�ȴ�" << (threadCount + 1) << "���ӡ�\n";

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);

    threadGroup.join_all();

    GetStream() << "�ȴ�������\n";

    ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
}

void System::CreateWaitableTimerUseNameTesting::WaitForWaitableTimerTest(WindowsHandle waitableTimerHandle)
{
    ASSERT_TRUE(WaitForSystemWaitableTimer(waitableTimerHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(ResetSystemWaitableTimer, waitableTimerHandle);
}

void System::CreateWaitableTimerUseNameTesting::ResetSystemWaitableTimer(WindowsHandle waitableTimerHandle)
{
    WindowsLargeInteger waitableTimerLargeInteger{};
    waitableTimerLargeInteger.QuadPart = -base;
    ASSERT_TRUE(SetSystemWaitableTimer(waitableTimerHandle, &waitableTimerLargeInteger, 0, nullptr, nullptr, false));
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/31 23:25)

#include "ManualEventThreadTesting.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ManualEventThreadTesting::ManualEventThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ManualEventThreadTesting)

void System::ManualEventThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ManualEventThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ManualEventThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ManualResetEventThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllEventThreadTest);
}

void System::ManualEventThreadTesting::ManualEventThreadTest()
{
    const auto eventHandle = CreateSystemEvent(true, false);

    ASSERT_NOT_THROW_EXCEPTION_1(DoManualEventThreadTest, eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::ManualEventThreadTesting::DoManualEventThreadTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, threadGroup, eventHandle);

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();
}

void System::ManualEventThreadTesting::ManualResetEventThreadTest()
{
    const auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::ManualReset, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);

    ASSERT_NOT_THROW_EXCEPTION_1(DoManualResetEventThreadTest, eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::ManualEventThreadTesting::DoManualResetEventThreadTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, threadGroup, eventHandle);

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();
}

void System::ManualEventThreadTesting::AllEventThreadTest()
{
    const auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::All, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);
    DoAllEventThreadTest(eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::ManualEventThreadTesting::WaitForManualEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));
}

void System::ManualEventThreadTesting::CreateThread(boost::thread_group& threadGroup, WindowsHandle eventHandle)
{
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForManualEventTest, this, eventHandle));
    }
}

void System::ManualEventThreadTesting::DoAllEventThreadTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, threadGroup, eventHandle);

    threadGroup.join_all();
}

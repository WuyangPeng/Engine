///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:24)

#include "ManualEventThreadTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
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
    constexpr auto threadCount = 12;

    auto eventHandle = CreateSystemEvent(true, false);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForManualEventTest, this, eventHandle));
    }

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::ManualEventThreadTesting::ManualResetEventThreadTest()
{
    constexpr auto threadCount = 12;

    auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::ManualReset, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForManualEventTest, this, eventHandle));
    }

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::ManualEventThreadTesting::AllEventThreadTest()
{
    constexpr auto threadCount = 12;

    auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::All, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForManualEventTest, this, eventHandle));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::ManualEventThreadTesting::WaitForManualEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));
}

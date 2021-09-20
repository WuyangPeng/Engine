///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/27 15:53)

#include "AutoEventThreadTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AutoEventThreadTesting::AutoEventThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AutoEventThreadTesting)

void System::AutoEventThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AutoEventThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AutoEventThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultEventThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InitalSetEventThreadTest);
}

void System::AutoEventThreadTesting::AutoEventThreadTest()
{
    constexpr auto threadCount = 12;

    auto eventHandle = CreateSystemEvent(false, true);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForAutoEventTest, this, eventHandle));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::AutoEventThreadTesting::DefaultEventThreadTest()
{
    constexpr auto threadCount = 12;

    auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::Default, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForAutoEventTest, this, eventHandle));
    }

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::AutoEventThreadTesting::InitalSetEventThreadTest()
{
    constexpr auto threadCount = 12;

    auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::InitalSet, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForAutoEventTest, this, eventHandle));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::AutoEventThreadTesting::WaitForAutoEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:57)

#include "AutoEventThreadTesting.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(InitialSetEventThreadTest);
}

void System::AutoEventThreadTesting::AutoEventThreadTest()
{
    const auto eventHandle = CreateSystemEvent(false, true);

    ASSERT_NOT_THROW_EXCEPTION_1(DoAutoEventThreadTest, eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::AutoEventThreadTesting::DoAutoEventThreadTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, threadGroup, eventHandle);

    threadGroup.join_all();
}

void System::AutoEventThreadTesting::DefaultEventThreadTest()
{
    const auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::Default, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);

    ASSERT_NOT_THROW_EXCEPTION_1(DoDefaultEventThreadTest, eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::AutoEventThreadTesting::DoDefaultEventThreadTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, threadGroup, eventHandle);

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();
}

void System::AutoEventThreadTesting::InitialSetEventThreadTest()
{
    const auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::InitialSet, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);

    ASSERT_NOT_THROW_EXCEPTION_1(DoInitialSetEventThreadTest, eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::AutoEventThreadTesting::DoInitialSetEventThreadTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, threadGroup, eventHandle);

    threadGroup.join_all();
}

void System::AutoEventThreadTesting::CreateThread(boost::thread_group& threadGroup, WindowsHandle eventHandle)
{
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, eventHandle]() {
            this->WaitForAutoEventTest(eventHandle);
        });
    }
}

void System::AutoEventThreadTesting::WaitForAutoEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

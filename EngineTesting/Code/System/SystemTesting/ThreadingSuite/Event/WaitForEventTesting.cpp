/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 19:29)

#include "WaitForEventTesting.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForEventTesting::WaitForEventTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForEventTesting)

void System::WaitForEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitEventTest);
}

void System::WaitForEventTesting::WaitEventTest()
{
    const auto eventHandle = CreateSystemEvent(false, false);

    ASSERT_NOT_THROW_EXCEPTION_1(DoWaitEventTest, eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::WaitForEventTesting::WaitForAutoEventTest0(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

void System::WaitForEventTesting::WaitForAutoEventTest1(WindowsHandle eventHandle)
{
    const auto flag = WaitForSystemEvent(eventHandle, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

void System::WaitForEventTesting::WaitForAutoEventTest2(WindowsHandle eventHandle)
{
    const auto flag = WaitForSystemEvent(eventHandle, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

void System::WaitForEventTesting::WaitForAutoEventTest3(WindowsHandle eventHandle)
{
    const auto flag = WaitForSystemEvent(eventHandle, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

void System::WaitForEventTesting::DoWaitEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, eventHandle, threadGroup);
    }

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();
}

void System::WaitForEventTesting::CreateThread(WindowsHandle eventHandle, boost::thread_group& threadGroup)
{
    threadGroup.create_thread([this, eventHandle]() {
        this->WaitForAutoEventTest0(eventHandle);
    });

    threadGroup.create_thread([this, eventHandle]() {
        this->WaitForAutoEventTest1(eventHandle);
    });

    threadGroup.create_thread([this, eventHandle]() {
        this->WaitForAutoEventTest2(eventHandle);
    });

    threadGroup.create_thread([this, eventHandle]() {
        this->WaitForAutoEventTest3(eventHandle);
    });
}
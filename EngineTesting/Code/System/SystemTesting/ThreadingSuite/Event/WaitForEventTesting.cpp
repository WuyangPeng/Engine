///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 0:03)

#include "WaitForEventTesting.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForEventTesting::WaitForEventTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

void System::WaitForEventTesting::WaitForAutoEventTest2(WindowsHandle eventHandle)
{
    const auto flag = WaitForSystemEvent(eventHandle, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

void System::WaitForEventTesting::WaitForAutoEventTest3(WindowsHandle eventHandle)
{
    const auto flag = WaitForSystemEvent(eventHandle, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(SetSystemEvent(eventHandle));
}

void System::WaitForEventTesting::DoWaitEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForAutoEventTest0, this, eventHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForAutoEventTest1, this, eventHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForAutoEventTest2, this, eventHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForAutoEventTest3, this, eventHandle));
    }

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();
}

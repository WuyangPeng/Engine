/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 19:29)

#include "WaitForMultipleEventTesting.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForMultipleEventTesting::WaitForMultipleEventTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForMultipleEventTesting)

void System::WaitForMultipleEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForMultipleEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjectsTest);
}

void System::WaitForMultipleEventTesting::WaitMultipleObjectsTest()
{
    const auto eventHandles = GetEventHandle();

    ASSERT_NOT_THROW_EXCEPTION_1(WaitForManualEventTest, eventHandles);

    for (auto eventHandle : eventHandles)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
    }
}

void System::WaitForMultipleEventTesting::WaitForManualEventTest0(const Container& eventHandle)
{
    const auto flag = WaitForSystemEvent(boost::numeric_cast<WindowsDWord>(eventHandle.size()), eventHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_UNEQUAL(flag, MutexWaitReturn::Failed);
}

void System::WaitForMultipleEventTesting::WaitForManualEventTest1(const Container& eventHandle)
{
    const auto flag = WaitForSystemEvent(boost::numeric_cast<WindowsDWord>(eventHandle.size()), eventHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_UNEQUAL(flag, MutexWaitReturn::Failed);
}

void System::WaitForMultipleEventTesting::WaitForManualEventTest2(const Container& eventHandle)
{
    const auto flag = WaitForSystemEvent(boost::numeric_cast<WindowsDWord>(eventHandle.size()), eventHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_UNEQUAL(flag, MutexWaitReturn::Failed);
}

System::WaitForMultipleEventTesting::Container System::WaitForMultipleEventTesting::GetEventHandle()
{
    constexpr auto eventSize = 5;

    Container eventHandle{};

    for (auto i = 0; i < eventSize; ++i)
    {
        const auto handle = CreateSystemEvent(true, true);
        ASSERT_TRUE(IsSystemEventValid(handle));

        eventHandle.emplace_back(handle);
    }

    return eventHandle;
}

void System::WaitForMultipleEventTesting::WaitForManualEventTest(const Container& eventHandles)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, eventHandles, threadGroup);
    }

    threadGroup.join_all();
}

void System::WaitForMultipleEventTesting::CreateThread(const Container& eventHandles, boost::thread_group& threadGroup)
{
    threadGroup.create_thread([this, eventHandles]() {
        this->WaitForManualEventTest0(eventHandles);
    });

    threadGroup.create_thread([this, eventHandles]() {
        this->WaitForManualEventTest1(eventHandles);
    });

    threadGroup.create_thread([this, eventHandles]() {
        this->WaitForManualEventTest2(eventHandles);
    });
}
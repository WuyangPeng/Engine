///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:01)

#include "ResetEventTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Event.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ResetEventTesting::ResetEventTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ResetEventTesting)

void System::ResetEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ResetEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EventThreadTest);
}

void System::ResetEventTesting::EventThreadTest()
{
    const auto eventHandle = CreateSystemEvent(true, true);

    ASSERT_NOT_THROW_EXCEPTION_1(DoEventThreadTest, eventHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

void System::ResetEventTesting::WaitForEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));
}

void System::ResetEventTesting::DoEventThreadTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    ASSERT_TRUE(ResetSystemEvent(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, eventHandle]() {
            this->WaitForEventTest(eventHandle);
        });
    }

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();
}

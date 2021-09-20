///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/27 17:09)

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
    constexpr auto threadCount = 12;

    auto eventHandle = CreateSystemEvent(true, true);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    ASSERT_TRUE(ResetSystemEvent(eventHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForEventTest, this, eventHandle));
    }

    ASSERT_TRUE(SetSystemEvent(eventHandle));

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::ResetEventTesting::WaitForEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 19:30)

#include "CreateEventUseNameTesting.h"
#include "System/Threading/Event.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateEventUseNameTesting::CreateEventUseNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateEventUseNameTesting)

void System::CreateEventUseNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateEventUseNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(CreateEventTest, true, true);
    ASSERT_NOT_THROW_EXCEPTION_2(CreateEventTest, true, false);
    ASSERT_NOT_THROW_EXCEPTION_2(CreateEventTest, false, true);
    ASSERT_NOT_THROW_EXCEPTION_2(CreateEventTest, false, false);
}

void System::CreateEventUseNameTesting::CreateEventTest(bool manualReset, bool initialState)
{
    const auto eventName = System::ToString(GetTimeInMicroseconds());

    const auto eventHandle = CreateSystemEvent(nullptr, manualReset, initialState, eventName.c_str());
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSystemEventTest, eventHandle);
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 14:20)

#include "CustomTimeTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/CustomTime.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CustomTimeTesting)

void CoreTools::CustomTimeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DescribeTest);
}

void CoreTools::CustomTimeTesting::TimeTest()
{
    CustomTime time{};

    ASSERT_APPROXIMATE(time.GetThisElapsedTime(), 0.0, 1e-10);
    ASSERT_APPROXIMATE(time.GetNowTime(), 0.0, 1e-10);

    System::SystemSleep(5);

    const auto elapsedTime = time.GetThisElapsedTime();

    System::SystemSleep(5);

    const auto nowTime = time.GetNowTime();

    ASSERT_TRUE(elapsedTime <= nowTime);
    ASSERT_TRUE(0 <= elapsedTime);
    ASSERT_TRUE(0 <= nowTime);

    time.ResetCustomTime();

    ASSERT_APPROXIMATE(time.GetThisElapsedTime(), 0.0, 1e-10);
    ASSERT_APPROXIMATE(time.GetNowTime(), 0.0, 1e-10);

    System::SystemSleep(5);

    const auto elapsedMillisecondTime = time.GetThisElapsedMillisecondTime();

    System::SystemSleep(5);

    const auto nowMillisecondTime = time.GetNowMillisecondTime();

    ASSERT_TRUE(elapsedMillisecondTime <= nowMillisecondTime);
    ASSERT_TRUE(0 <= elapsedMillisecondTime);
    ASSERT_TRUE(0 <= nowMillisecondTime);

    time.ResetCustomTime();

    ASSERT_RANGE(time.GetThisElapsedMillisecondTime(), 0.0, 1.0);
    ASSERT_RANGE(time.GetNowMillisecondTime(), 0.0, 1.0);
}

void CoreTools::CustomTimeTesting::DescribeTest()
{
    auto describe = CustomTime::GetSystemTimeDescribe();

    ASSERT_FALSE(describe.empty());

    describe = CustomTime::GetSystemTimeDescribe(SYSTEM_TEXT("%1%-%2%.%3%"));

    ASSERT_FALSE(describe.empty());
}

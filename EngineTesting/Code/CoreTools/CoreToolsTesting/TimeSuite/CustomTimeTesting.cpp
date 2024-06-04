/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/04 10:51)

#include "CustomTimeTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CustomTimeTesting::CustomTimeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CustomTimeTesting)

void CoreTools::CustomTimeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CustomTimeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DescribeTest);
}

void CoreTools::CustomTimeTesting::TimeTest()
{
    CustomTime time{};

    ASSERT_NOT_THROW_EXCEPTION_1(Time0Test, time);
    ASSERT_NOT_THROW_EXCEPTION_1(Time1Test, time);
    ASSERT_NOT_THROW_EXCEPTION_1(Time2Test, time);
}

void CoreTools::CustomTimeTesting::Time0Test(CustomTime& time)
{
    ASSERT_APPROXIMATE(time.GetThisElapsedTime(), 0.0, 1e-10);
    ASSERT_APPROXIMATE(time.GetNowTime(), 0.0, 1e-10);

    System::SystemSleep(5);

    const auto elapsedTime = time.GetThisElapsedTime();

    System::SystemSleep(5);

    const auto nowTime = time.GetNowTime();

    ASSERT_TRUE(elapsedTime <= nowTime);
    ASSERT_TRUE(0 <= elapsedTime);
    ASSERT_TRUE(0 <= nowTime);
}

void CoreTools::CustomTimeTesting::Time1Test(CustomTime& time)
{
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
}

void CoreTools::CustomTimeTesting::Time2Test(CustomTime& time)
{
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

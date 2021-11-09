// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:39)

#include "CustomTimeTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/CustomTime.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CustomTimeTesting)

void CoreTools::CustomTimeTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DescribeTest);
}

void CoreTools::CustomTimeTesting ::TimeTest()
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

void CoreTools::CustomTimeTesting ::DescribeTest()
{
    auto describe = CustomTime::GetSystemTimeDescribe();

    ASSERT_FALSE(describe.empty());

    describe = CustomTime::GetSystemTimeDescribe(SYSTEM_TEXT("%1%-%2%.%3%"));

    ASSERT_FALSE(describe.empty());
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:15)

#include "SecondTimerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Time/SecondTimer.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SecondTimerTesting::SecondTimerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SecondTimerTesting)

void CoreTools::SecondTimerTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待。\n";

    System::SystemPause();
}

void CoreTools::SecondTimerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SecondTimerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
}

void CoreTools::SecondTimerTesting::TimeTest()
{
    SecondTimer secondTimer{ seconds };

    ASSERT_NOT_THROW_EXCEPTION_1(TimeBaseTest, secondTimer);
    ASSERT_NOT_THROW_EXCEPTION_1(Sleep0Test, secondTimer);
    ASSERT_NOT_THROW_EXCEPTION_1(ReTimingTest, secondTimer);
    ASSERT_NOT_THROW_EXCEPTION_1(Sleep1Test, secondTimer);
}

void CoreTools::SecondTimerTesting::TimeBaseTest(const SecondTimer& secondTimer)
{
    ASSERT_RANGE(secondTimer.GetRemain(), seconds - epsilon, seconds);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), 0, epsilon);
    ASSERT_FALSE(secondTimer.IsElapsed());
}

void CoreTools::SecondTimerTesting::Sleep0Test(const SecondTimer& secondTimer)
{
    const auto nowTime = secondTimer.GetNowTime();
    ASSERT_LESS(0, nowTime);

    System::SystemSleep(boost::numeric_cast<uint32_t>(seconds * System::gMillisecond));

    ASSERT_RANGE(secondTimer.GetRemain(), 0, epsilon);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), seconds, seconds + epsilon);
    ASSERT_TRUE(secondTimer.IsElapsed());
}

void CoreTools::SecondTimerTesting::ReTimingTest(SecondTimer& secondTimer)
{
    secondTimer.ReTiming(fourSeconds);

    ASSERT_RANGE(secondTimer.GetRemain(), fourSeconds - epsilon, fourSeconds);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), 0, epsilon);
    ASSERT_FALSE(secondTimer.IsElapsed());
}

void CoreTools::SecondTimerTesting::Sleep1Test(const SecondTimer& secondTimer)
{
    System::SystemSleep(boost::numeric_cast<uint32_t>(fourSeconds * System::gMillisecond));

    ASSERT_RANGE(secondTimer.GetRemain(), 0, epsilon);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), fourSeconds, fourSeconds + epsilon);
    ASSERT_TRUE(secondTimer.IsElapsed());
}

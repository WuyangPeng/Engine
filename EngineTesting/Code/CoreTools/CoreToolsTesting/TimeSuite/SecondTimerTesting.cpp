///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 14:21)

#include "SecondTimerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/SecondTimer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
CoreTools::SecondTimerTesting::SecondTimerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SecondTimerTesting)

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
    constexpr int64_t seconds{ 2 };
    SecondTimer secondTimer{ seconds };
    constexpr int32_t epsilon{ 1 };

    ASSERT_RANGE(secondTimer.GetRemain(), seconds - epsilon, seconds);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), 0, epsilon);
    ASSERT_FALSE(secondTimer.IsElapsed());

    const auto nowTime = secondTimer.GetNowTime();
    ASSERT_LESS(0, nowTime);

    System::SystemSleep(boost::numeric_cast<uint32_t>(seconds * System::gMillisecond));

    ASSERT_RANGE(secondTimer.GetRemain(), 0, epsilon);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), seconds, seconds + epsilon);
    ASSERT_TRUE(secondTimer.IsElapsed());

    constexpr int64_t fourSeconds{ seconds * 2 };
    secondTimer.ReTiming(fourSeconds);

    ASSERT_RANGE(secondTimer.GetRemain(), fourSeconds - epsilon, fourSeconds);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), 0, epsilon);
    ASSERT_FALSE(secondTimer.IsElapsed());

    System::SystemSleep(boost::numeric_cast<uint32_t>(fourSeconds * System::gMillisecond));

    ASSERT_RANGE(secondTimer.GetRemain(), 0, epsilon);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), fourSeconds, fourSeconds + epsilon);
    ASSERT_TRUE(secondTimer.IsElapsed());
}

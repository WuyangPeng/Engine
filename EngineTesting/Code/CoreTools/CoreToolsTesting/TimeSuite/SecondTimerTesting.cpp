// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:40)

#include "SecondTimerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/SecondTimer.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SecondTimerTesting)

void CoreTools::SecondTimerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
}

void CoreTools::SecondTimerTesting ::TimeTest()
{
    constexpr uint64_t seconds{ 2 };
    SecondTimer secondTimer{ seconds };
    constexpr uint32_t epsilon{ 1 };

    ASSERT_RANGE(secondTimer.GetRemain(), seconds - epsilon, seconds);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), 0u, epsilon);
    ASSERT_FALSE(secondTimer.IsElapsed());

    const auto nowTime = secondTimer.GetNowTime();
    ASSERT_LESS(0, nowTime);

    System::SystemSleep(boost::numeric_cast<uint32_t>(seconds * System::g_Millisecond));

    ASSERT_RANGE(secondTimer.GetRemain(), 0u, epsilon);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), seconds, seconds + epsilon);
    ASSERT_TRUE(secondTimer.IsElapsed());

    constexpr uint64_t fourSeconds{ seconds * 2 };
    secondTimer.ReTiming(fourSeconds);

    ASSERT_RANGE(secondTimer.GetRemain(), fourSeconds - epsilon, fourSeconds);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), 0u, epsilon);
    ASSERT_FALSE(secondTimer.IsElapsed());

    System::SystemSleep(boost::numeric_cast<uint32_t>(fourSeconds * System::g_Millisecond));

    ASSERT_RANGE(secondTimer.GetRemain(), 0u, epsilon);
    ASSERT_RANGE(secondTimer.GetElapsedTime(), fourSeconds, fourSeconds + epsilon);
    ASSERT_TRUE(secondTimer.IsElapsed());
}

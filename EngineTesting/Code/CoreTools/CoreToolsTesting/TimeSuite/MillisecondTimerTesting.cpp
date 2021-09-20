// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:40)

#include "MillisecondTimerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/MillisecondTimer.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MillisecondTimerTesting)

void CoreTools::MillisecondTimerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
}

void CoreTools::MillisecondTimerTesting ::TimeTest()
{
    constexpr uint64_t microseconds{ System::g_Millisecond * 1 };
    MillisecondTimer millisecondTimer{ microseconds };
    constexpr uint32_t epsilon{ 10 };

    ASSERT_RANGE(millisecondTimer.GetRemain(), microseconds - epsilon, microseconds);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), 0u, epsilon);
    ASSERT_FALSE(millisecondTimer.IsElapsed());

    const auto nowTime = millisecondTimer.GetNowTime();
    ASSERT_LESS(0, nowTime);

    System::SystemSleep(boost::numeric_cast<uint32_t>(microseconds));

    ASSERT_RANGE(millisecondTimer.GetRemain(), 0u, epsilon);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), microseconds, microseconds + epsilon);
    ASSERT_TRUE(millisecondTimer.IsElapsed());

    constexpr uint64_t twoMicroseconds{ microseconds * 2 };
    millisecondTimer.ReTiming(twoMicroseconds);

    ASSERT_RANGE(millisecondTimer.GetRemain(), twoMicroseconds - epsilon, twoMicroseconds);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), 0u, epsilon);
    ASSERT_FALSE(millisecondTimer.IsElapsed());

    System::SystemSleep(boost::numeric_cast<uint32_t>(twoMicroseconds));

    ASSERT_RANGE(millisecondTimer.GetRemain(), 0u, epsilon);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), twoMicroseconds, twoMicroseconds + epsilon);
    ASSERT_TRUE(millisecondTimer.IsElapsed());
}

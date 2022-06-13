///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 14:21)

#include "SecondTimerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/SecondTimer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SecondTimerTesting)

void CoreTools::SecondTimerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
}

void CoreTools::SecondTimerTesting::TimeTest()
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

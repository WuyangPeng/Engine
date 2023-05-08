///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:37)

#include "MillisecondTimerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Time/MillisecondTimer.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MillisecondTimerTesting::MillisecondTimerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MillisecondTimerTesting)

void CoreTools::MillisecondTimerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MillisecondTimerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
}

void CoreTools::MillisecondTimerTesting::TimeTest()
{
    constexpr int64_t microseconds{ System::gMillisecond };
    MillisecondTimer millisecondTimer{ microseconds };
    constexpr int32_t epsilon{ 10 };

    ASSERT_RANGE(millisecondTimer.GetRemain(), microseconds - epsilon, microseconds);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), 0, epsilon);
    ASSERT_FALSE(millisecondTimer.IsElapsed());

    const auto nowTime = millisecondTimer.GetNowTime();
    ASSERT_LESS(0, nowTime);

    System::SystemSleep(boost::numeric_cast<uint32_t>(microseconds));

    ASSERT_RANGE(millisecondTimer.GetRemain(), 0, epsilon);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), microseconds, microseconds + epsilon);
    ASSERT_TRUE(millisecondTimer.IsElapsed());

    constexpr int64_t twoMicroseconds{ microseconds * 2 };
    millisecondTimer.ReTiming(twoMicroseconds);

    ASSERT_RANGE(millisecondTimer.GetRemain(), twoMicroseconds - epsilon, twoMicroseconds);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), 0, epsilon);
    ASSERT_FALSE(millisecondTimer.IsElapsed());

    System::SystemSleep(boost::numeric_cast<uint32_t>(twoMicroseconds));

    ASSERT_RANGE(millisecondTimer.GetRemain(), 0, epsilon);
    ASSERT_RANGE(millisecondTimer.GetElapsedTime(), twoMicroseconds, twoMicroseconds + epsilon);
    ASSERT_TRUE(millisecondTimer.IsElapsed());
}

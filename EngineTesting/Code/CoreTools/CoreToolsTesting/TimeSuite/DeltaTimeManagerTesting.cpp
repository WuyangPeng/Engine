// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:39)

#include "DeltaTimeManagerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/DeltaTimeManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DeltaTimeManagerTesting)

void CoreTools::DeltaTimeManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
}

void CoreTools::DeltaTimeManagerTesting ::TimeTest()
{
    auto time = DeltaTimeManager::Create();

    ASSERT_APPROXIMATE(time.GetElapsedTimeInSeconds(), 0.0, 1e-10);
    ASSERT_LESS(0, time.GetNowTimeInSeconds());
    ASSERT_LESS(0, time.GetNowTimeInMicroseconds());
    ASSERT_EQUAL(time.GetNowTimeInSeconds(), time.GetNowTimeInMicroseconds() / System::g_Microseconds);

    System::SystemSleep(5);

    const auto elapsedTime = time.GetElapsedTimeInSeconds();

    ASSERT_TRUE(0 <= elapsedTime);

    time.ResetCurrentTime();

    ASSERT_APPROXIMATE(time.GetElapsedTimeInSeconds(), 0.0, 1e-10);

    System::SystemSleep(5);

    const auto elapsedMillisecondTime = time.GetElapsedTimeInMicroseconds();

    ASSERT_TRUE(0 <= elapsedMillisecondTime);

    time.ResetCurrentTime();

    ASSERT_APPROXIMATE(time.GetElapsedTimeInMicroseconds(), 0.0, 1e-10);
}

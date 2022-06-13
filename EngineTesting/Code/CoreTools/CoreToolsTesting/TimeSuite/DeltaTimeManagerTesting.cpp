///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 14:20)

#include "DeltaTimeManagerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Time/DeltaTimeManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DeltaTimeManagerTesting)

void CoreTools::DeltaTimeManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimeTest);
}

void CoreTools::DeltaTimeManagerTesting::TimeTest()
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

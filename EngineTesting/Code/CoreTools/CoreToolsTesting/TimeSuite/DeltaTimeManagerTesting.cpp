///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:37)

#include "DeltaTimeManagerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Time/DeltaTimeManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <Mathematics/Base/Math.h>

CoreTools::DeltaTimeManagerTesting::DeltaTimeManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DeltaTimeManagerTesting)

void CoreTools::DeltaTimeManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
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
    ASSERT_EQUAL(time.GetNowTimeInSeconds(), time.GetNowTimeInMicroseconds() / System::gMicroseconds);

    System::SystemSleep(5);

    const auto elapsedTime = time.GetElapsedTimeInSeconds();

    ASSERT_TRUE(0 <= elapsedTime);

    time.ResetCurrentTime();

    ASSERT_APPROXIMATE(time.GetElapsedTimeInSeconds(), 0.0, 1e-10);

    System::SystemSleep(5);

    const auto elapsedMillisecondTime = time.GetElapsedTimeInMicroseconds();

    ASSERT_TRUE(0 <= elapsedMillisecondTime);

    time.ResetCurrentTime();

    ASSERT_APPROXIMATE(time.GetElapsedTimeInMicroseconds(), 0.0, Mathematics::MathD::GetZeroTolerance());
}

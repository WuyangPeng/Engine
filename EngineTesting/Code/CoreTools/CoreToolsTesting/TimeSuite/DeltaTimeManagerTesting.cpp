/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:13)

#include "DeltaTimeManagerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Time/DeltaTimeManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

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

    ASSERT_TRUE(5 <= time.GetElapsedTimeInMicroseconds());

    time.ResetCurrentTime();

    ASSERT_TRUE(0 <= time.GetElapsedTimeInMicroseconds());

    System::SystemSleep(5);

    ASSERT_TRUE(5 <= time.GetElapsedTimeInMicroseconds());

    time.ResetCurrentTime();

    ASSERT_TRUE(0 <= time.GetElapsedTimeInMicroseconds());
}

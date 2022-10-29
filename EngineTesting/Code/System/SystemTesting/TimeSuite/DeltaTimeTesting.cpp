///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/29 0:00)

#include "DeltaTimeTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DeltaTimeTesting::DeltaTimeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DeltaTimeTesting)

void System::DeltaTimeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DeltaTimeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MicrosecondsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SecondsTest);
}

void System::DeltaTimeTesting::MicrosecondsTest()
{
    const auto elapsedTime0 = GetTimeInMicroseconds();

    constexpr auto sleepTime = 2000;

    SystemSleep(sleepTime);

    const auto elapsedTime1 = GetTimeInMicroseconds();

    ASSERT_LESS(0, elapsedTime0);
    ASSERT_LESS(0, elapsedTime1);
    ASSERT_LESS(elapsedTime0, elapsedTime1);

    ASSERT_TRUE(sleepTime * gMillisecond - gMicroseconds <= elapsedTime1 - elapsedTime0);
    ASSERT_TRUE(elapsedTime1 - elapsedTime0 <= sleepTime * gMillisecond + gMicroseconds);

    constexpr auto second = 1000;
    constexpr auto microsecond = 800;
    const DeltaTimeValueData deltaTime{ second, microsecond };
    const auto elapsedTime2 = GetTimeInMicroseconds(deltaTime);
    ASSERT_EQUAL(elapsedTime2, second * gMicroseconds + microsecond);
}

void System::DeltaTimeTesting::SecondsTest()
{
    const auto elapsedTime0 = GetTimeInSeconds();

    constexpr auto sleepTime = 2000;

    SystemSleep(sleepTime);

    const auto elapsedTime1 = GetTimeInSeconds();

    ASSERT_LESS(0, elapsedTime0);
    ASSERT_LESS(0, elapsedTime1);
    ASSERT_LESS(elapsedTime0, elapsedTime1);

    ASSERT_TRUE(1 <= elapsedTime1 - elapsedTime0);
    ASSERT_TRUE(elapsedTime1 - elapsedTime0 <= 3);

    constexpr auto second = 1000;
    constexpr auto microsecond = 800;
    const DeltaTimeValueData deltaTime{ second, microsecond };
    const auto elapsedTime2 = GetTimeInSeconds(deltaTime);
    ASSERT_EQUAL(elapsedTime2, second);
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/17 16:20)

#include "TimeOfDayDataTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Data/CurrentDeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::TimeOfDayDataTesting::TimeOfDayDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TimeOfDayDataTesting)

void System::TimeOfDayDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::TimeOfDayDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CurrentTimeTest);
}

void System::TimeOfDayDataTesting::CurrentTimeTest()
{
    const CurrentDeltaTime timeOfDayData0{};

    const auto data0 = timeOfDayData0.GetDeltaTimeValueData();

    const auto second0 = data0.GetSecond();
    const auto microsecond0 = data0.GetMicrosecond();

    ASSERT_LESS(0, second0);
    ASSERT_LESS(0, microsecond0);

    constexpr auto deltaTime = 2;

    SystemSleep(deltaTime * 1000);

    const CurrentDeltaTime timeOfDayData1{};

    const auto data1 = timeOfDayData1.GetDeltaTimeValueData();

    const auto second1 = data1.GetSecond();

    ASSERT_LESS(second0, second1);
    ASSERT_RANGE(second1 - second0, deltaTime - 1, deltaTime + 1);
}

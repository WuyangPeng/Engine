///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 10:49)

#include "CurrentDeltaTimeTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Data/CurrentDeltaTime.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CurrentDeltaTimeTesting::CurrentDeltaTimeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CurrentDeltaTimeTesting)

void System::CurrentDeltaTimeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CurrentDeltaTimeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CurrentTimeTest);
}

void System::CurrentDeltaTimeTesting::CurrentTimeTest()
{
    const auto second0 = GetCurrentSecond();

    ASSERT_NOT_THROW_EXCEPTION_0(SystemSleepTest);

    const auto second1 = GetNextSecond();

    ASSERT_NOT_THROW_EXCEPTION_2(ResultTests, second0, second1);
}

int64_t System::CurrentDeltaTimeTesting::GetCurrentSecond()
{
    const CurrentDeltaTime timeOfDayData0{};

    const auto data = timeOfDayData0.GetDeltaTimeValueData();

    const auto second = data.GetSecond();
    const auto microsecond = data.GetMicrosecond();

    ASSERT_LESS(0, second);
    ASSERT_LESS(0, microsecond);

    return second;
}

void System::CurrentDeltaTimeTesting::ResultTests(int64_t lhsSecond, int64_t rhsSecond)
{
    ASSERT_LESS(lhsSecond, rhsSecond);
    ASSERT_RANGE(rhsSecond - lhsSecond, deltaTime - 1, deltaTime + 1);
}

int64_t System::CurrentDeltaTimeTesting::GetNextSecond() noexcept
{
    const CurrentDeltaTime timeOfDayData{};

    const auto data = timeOfDayData.GetDeltaTimeValueData();

    const auto second = data.GetSecond();

    return second;
}

void System::CurrentDeltaTimeTesting::SystemSleepTest() noexcept
{
    SystemSleep(deltaTime * 1000);
}

void System::CurrentDeltaTimeTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待。\n";

    SystemPause();
}
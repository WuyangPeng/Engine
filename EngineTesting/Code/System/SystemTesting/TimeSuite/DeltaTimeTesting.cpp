/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 19:49)

#include "DeltaTimeTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DeltaTimeTesting::DeltaTimeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    SystemSleep(sleepTime);

    const auto elapsedTime1 = GetTimeInMicroseconds();

    ASSERT_NOT_THROW_EXCEPTION_2(MicrosecondsTestResultTest, elapsedTime0, elapsedTime1);
}

void System::DeltaTimeTesting::SecondsTest()
{
    const auto elapsedTime0 = GetTimeInSeconds();

    SystemSleep(sleepTime);

    const auto elapsedTime1 = GetTimeInSeconds();

    ASSERT_NOT_THROW_EXCEPTION_2(SecondsResultTest, elapsedTime0, elapsedTime1);
}

void System::DeltaTimeTesting::MicrosecondsTestResultTest(int64_t lhsElapsedTime, int64_t rhsElapsedTime)
{
    ASSERT_LESS(0, lhsElapsedTime);
    ASSERT_LESS(0, rhsElapsedTime);
    ASSERT_LESS(lhsElapsedTime, rhsElapsedTime);

    ASSERT_TRUE(sleepTime * gMillisecond - gMicroseconds <= rhsElapsedTime - lhsElapsedTime);
    ASSERT_TRUE(rhsElapsedTime - lhsElapsedTime <= sleepTime * gMillisecond + gMicroseconds);

    const DeltaTimeValueData deltaTime{ second, microsecond };
    const auto elapsedTime = GetTimeInMicroseconds(deltaTime);
    ASSERT_EQUAL(elapsedTime, second * gMicroseconds + microsecond);
}

void System::DeltaTimeTesting::SecondsResultTest(int64_t lhsElapsedTime, int64_t rhsElapsedTime)
{
    ASSERT_LESS(0, lhsElapsedTime);
    ASSERT_LESS(0, rhsElapsedTime);
    ASSERT_LESS(lhsElapsedTime, rhsElapsedTime);

    ASSERT_TRUE(1 <= rhsElapsedTime - lhsElapsedTime);
    ASSERT_TRUE(rhsElapsedTime - lhsElapsedTime <= 3);

    const DeltaTimeValueData deltaTime{ second, microsecond };
    const auto elapsedTime = GetTimeInSeconds(deltaTime);
    ASSERT_EQUAL(elapsedTime, second);
}

void System::DeltaTimeTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待。\n";

    SystemPause();
}

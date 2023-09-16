///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:38)

#include "DeltaTimeValueDataTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Data/DeltaTimeValueData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DeltaTimeValueDataTesting::DeltaTimeValueDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DeltaTimeValueDataTesting)

void System::DeltaTimeValueDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DeltaTimeValueDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TimerSubTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CorrectionTest);
}

void System::DeltaTimeValueDataTesting::DataTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataZeroTest);

    const auto deltaTimeValue = DataNonZeroTest();

    ASSERT_NOT_THROW_EXCEPTION_1(DataCopyTest, deltaTimeValue);
}

void System::DeltaTimeValueDataTesting::TimerSubTest()
{
    const DeltaTimeValueData deltaTimeValueData0{ 100, 45 };
    const DeltaTimeValueData deltaTimeValueData1{ 10, 45 };
    const DeltaTimeValueData deltaTimeValueData2{ 8, 60 };

    const auto deltaTimeValueData3 = deltaTimeValueData0 - deltaTimeValueData1;

    ASSERT_EQUAL(deltaTimeValueData3.GetSecond(), deltaTimeValueData0.GetSecond() - deltaTimeValueData1.GetSecond());
    ASSERT_EQUAL(deltaTimeValueData3.GetMicrosecond(), deltaTimeValueData0.GetMicrosecond() - deltaTimeValueData1.GetMicrosecond());

    const auto deltaTimeValueData4 = deltaTimeValueData1 - deltaTimeValueData2;

    ASSERT_EQUAL(deltaTimeValueData4.GetSecond(), deltaTimeValueData1.GetSecond() - deltaTimeValueData2.GetSecond() - 1);
    ASSERT_EQUAL(deltaTimeValueData4.GetMicrosecond(), deltaTimeValueData1.GetMicrosecond() - deltaTimeValueData2.GetMicrosecond() + gMicroseconds);
}

void System::DeltaTimeValueDataTesting::CorrectionTest()
{
    DeltaTimeValueData deltaTimeValueData{ 100, -45 };

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 100);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), -45);

    deltaTimeValueData.Correction();

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 99);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), -45 + gMicroseconds);
}

void System::DeltaTimeValueDataTesting::DataZeroTest()
{
    constexpr DeltaTimeValueData deltaTimeValueData{};

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 0);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), 0);

    const auto deltaTimeValue = deltaTimeValueData.GetDeltaTimeValue();

    ASSERT_EQUAL(deltaTimeValue.tv_sec, 0);
    ASSERT_EQUAL(deltaTimeValue.tv_usec, 0);
}

System::DeltaTimeValue System::DeltaTimeValueDataTesting::DataNonZeroTest()
{
    const DeltaTimeValueData deltaTimeValueData{ 10, 45 };

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 10);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), 45);

    auto deltaTimeValue = deltaTimeValueData.GetDeltaTimeValue();

    ASSERT_EQUAL(deltaTimeValue.tv_sec, 10);
    ASSERT_EQUAL(deltaTimeValue.tv_usec, 45);

    deltaTimeValue.tv_sec = 20;
    deltaTimeValue.tv_usec = 50;

    return deltaTimeValue;
}

void System::DeltaTimeValueDataTesting::DataCopyTest(const DeltaTimeValue& deltaTimeValue)
{
    DeltaTimeValueData deltaTimeValueData{ deltaTimeValue };

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 20);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), 50);

    auto result = deltaTimeValueData.GetDeltaTimeValue();

    ASSERT_EQUAL(result.tv_sec, 20);
    ASSERT_EQUAL(result.tv_usec, 50);

    deltaTimeValueData.SetValue(4, 5);

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 4);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), 5);

    result = deltaTimeValueData.GetDeltaTimeValue();

    ASSERT_EQUAL(result.tv_sec, 4);
    ASSERT_EQUAL(result.tv_usec, 5);
}

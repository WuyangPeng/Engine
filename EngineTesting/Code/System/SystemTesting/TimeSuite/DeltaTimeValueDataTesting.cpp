///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 16:49)

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
    const DeltaTimeValueData deltaTimeValueData0{};

    ASSERT_EQUAL(deltaTimeValueData0.GetSecond(), 0);
    ASSERT_EQUAL(deltaTimeValueData0.GetMicrosecond(), 0);

    const auto deltaTimeValue0 = deltaTimeValueData0.GetDeltaTimeValue();

    ASSERT_EQUAL(deltaTimeValue0.tv_sec, 0);
    ASSERT_EQUAL(deltaTimeValue0.tv_usec, 0);

    const DeltaTimeValueData deltaTimeValueData1{ 10, 45 };

    ASSERT_EQUAL(deltaTimeValueData1.GetSecond(), 10);
    ASSERT_EQUAL(deltaTimeValueData1.GetMicrosecond(), 45);

    auto deltaTimeValue1 = deltaTimeValueData1.GetDeltaTimeValue();

    ASSERT_EQUAL(deltaTimeValue1.tv_sec, 10);
    ASSERT_EQUAL(deltaTimeValue1.tv_usec, 45);

    deltaTimeValue1.tv_sec = 20;
    deltaTimeValue1.tv_usec = 50;

    DeltaTimeValueData deltaTimeValueData2{ deltaTimeValue1 };

    ASSERT_EQUAL(deltaTimeValueData2.GetSecond(), 20);
    ASSERT_EQUAL(deltaTimeValueData2.GetMicrosecond(), 50);

    auto deltaTimeValue2 = deltaTimeValueData2.GetDeltaTimeValue();

    ASSERT_EQUAL(deltaTimeValue2.tv_sec, 20);
    ASSERT_EQUAL(deltaTimeValue2.tv_usec, 50);

    deltaTimeValueData2.SetValue(4, 5);

    ASSERT_EQUAL(deltaTimeValueData2.GetSecond(), 4);
    ASSERT_EQUAL(deltaTimeValueData2.GetMicrosecond(), 5);

    deltaTimeValue2 = deltaTimeValueData2.GetDeltaTimeValue();

    ASSERT_EQUAL(deltaTimeValue2.tv_sec, 4);
    ASSERT_EQUAL(deltaTimeValue2.tv_usec, 5);
}

void System::DeltaTimeValueDataTesting::TimerSubTest()
{
    const DeltaTimeValueData deltaTimeValueData0{ 100, 45 };
    const DeltaTimeValueData deltaTimeValueData1{ 10, 45 };
    const DeltaTimeValueData deltaTimeValueData2{ 8, 60 };

    auto deltaTimeValueData3 = deltaTimeValueData0 - deltaTimeValueData1;

    ASSERT_EQUAL(deltaTimeValueData3.GetSecond(), deltaTimeValueData0.GetSecond() - deltaTimeValueData1.GetSecond());
    ASSERT_EQUAL(deltaTimeValueData3.GetMicrosecond(), deltaTimeValueData0.GetMicrosecond() - deltaTimeValueData1.GetMicrosecond());

    deltaTimeValueData3 = deltaTimeValueData1 - deltaTimeValueData2;

    ASSERT_EQUAL(deltaTimeValueData3.GetSecond(), deltaTimeValueData1.GetSecond() - deltaTimeValueData2.GetSecond() - 1);
    ASSERT_EQUAL(deltaTimeValueData3.GetMicrosecond(), deltaTimeValueData1.GetMicrosecond() - deltaTimeValueData2.GetMicrosecond() + g_Microseconds);
}

void System::DeltaTimeValueDataTesting::CorrectionTest()
{
    DeltaTimeValueData deltaTimeValueData{ 100, -45 };

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 100);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), -45);

    deltaTimeValueData.Correction();

    ASSERT_EQUAL(deltaTimeValueData.GetSecond(), 99);
    ASSERT_EQUAL(deltaTimeValueData.GetMicrosecond(), -45 + g_Microseconds);
}

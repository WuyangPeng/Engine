// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 19:04)

#include "MinHeapRecordTesting.h"
#include "CoreTools/DataTypes/MinHeapRecordDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MinHeapRecordTesting)

void CoreTools::MinHeapRecordTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTest);
}

void CoreTools::MinHeapRecordTesting ::FloatTest()
{
    MinHeapRecord<int, float> minHeapRecord{};

    minHeapRecord.SetGenerator(5);
    minHeapRecord.SetValue(1.0f);
    minHeapRecord.SetUniqueIndex(0);

    ASSERT_EQUAL(minHeapRecord.GetGenerator(), 5);
    ASSERT_APPROXIMATE(minHeapRecord.GetValue(), 1.0f, 1.0e-8f);
    ASSERT_EQUAL(minHeapRecord.GetUniqueIndex(), 0);
}

void CoreTools::MinHeapRecordTesting ::IntegerTest()
{
    const MinHeapRecord<double, int> minHeapRecord{ 1, 5 };

    ASSERT_EQUAL(minHeapRecord.GetValue(), 5);
    ASSERT_EQUAL(minHeapRecord.GetUniqueIndex(), 1);
    ASSERT_EQUAL(minHeapRecord.GetGenerator(), 0);
}

void CoreTools::MinHeapRecordTesting ::DoubleTest()
{
    const MinHeapRecord<int, double> minHeapRecord{ 1, 2, 5.0 };

    ASSERT_APPROXIMATE(minHeapRecord.GetValue(), 5.0, 1.0e-10);
    ASSERT_EQUAL(minHeapRecord.GetUniqueIndex(), 1);
    ASSERT_EQUAL(minHeapRecord.GetGenerator(), 2);
}

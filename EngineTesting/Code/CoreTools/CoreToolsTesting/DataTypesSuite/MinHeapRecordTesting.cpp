/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 17:18)

#include "MinHeapRecordTesting.h"
#include "Detail/VertexTest.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::MinHeapRecordTesting::MinHeapRecordTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MinHeapRecordTesting)

void CoreTools::MinHeapRecordTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MinHeapRecordTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MinHeapRecordTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMinHeapRecordTest);
}

void CoreTools::MinHeapRecordTesting::DefaultTest()
{
    const MinHeapRecord<VertexTest, double> minHeapRecord{};

    const auto handle = minHeapRecord.GetHandle();

    ASSERT_EQUAL(minHeapRecord.GetIndex(), -1);
    ASSERT_EQUAL(handle.GetCurrent(), 0);
    ASSERT_EQUAL(handle.GetNext(), 0);
    ASSERT_EQUAL(handle.GetPrevious(), 0);
    ASSERT_APPROXIMATE_DOUBLE_ZERO(minHeapRecord.GetWeight());
}

void CoreTools::MinHeapRecordTesting::MinHeapRecordTest()
{
    const VertexTest vertexTest{ 0, 1, 2 };
    const MinHeapRecord minHeapRecord{ 0, vertexTest, 1.0 };

    const auto handle = minHeapRecord.GetHandle();

    ASSERT_EQUAL(minHeapRecord.GetIndex(), 0);
    ASSERT_EQUAL(handle.GetCurrent(), vertexTest.GetCurrent());
    ASSERT_EQUAL(handle.GetNext(), vertexTest.GetNext());
    ASSERT_EQUAL(handle.GetPrevious(), vertexTest.GetPrevious());
    ASSERT_APPROXIMATE(minHeapRecord.GetWeight(), 1.0, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::MinHeapRecordTesting::SetMinHeapRecordTest()
{
    TestingType minHeapRecord{};

    ASSERT_NOT_THROW_EXCEPTION_1(IndexTest, minHeapRecord);
    ASSERT_NOT_THROW_EXCEPTION_1(HandleZeroTest, minHeapRecord);
    ASSERT_NOT_THROW_EXCEPTION_1(HandleEqualTest, minHeapRecord);
    ASSERT_NOT_THROW_EXCEPTION_1(WeightTest, minHeapRecord);
    ASSERT_NOT_THROW_EXCEPTION_1(RecordTest, minHeapRecord);
}

void CoreTools::MinHeapRecordTesting::IndexTest(TestingType& minHeapRecord)
{
    ASSERT_EQUAL(minHeapRecord.GetIndex(), -1);

    minHeapRecord.SetIndex(1);
    ASSERT_EQUAL(minHeapRecord.GetIndex(), 1);
}

void CoreTools::MinHeapRecordTesting::HandleZeroTest(const TestingType& minHeapRecord)
{
    ASSERT_EQUAL(minHeapRecord.GetHandle().GetCurrent(), 0);
    ASSERT_EQUAL(minHeapRecord.GetHandle().GetNext(), 0);
    ASSERT_EQUAL(minHeapRecord.GetHandle().GetPrevious(), 0);
}

void CoreTools::MinHeapRecordTesting::HandleEqualTest(TestingType& minHeapRecord)
{
    const VertexTest vertexTest{ 0, 1, 2 };
    minHeapRecord.SetHandle(vertexTest);

    const auto handle0 = minHeapRecord.GetHandle();
    ASSERT_EQUAL(handle0.GetCurrent(), vertexTest.GetCurrent());
    ASSERT_EQUAL(handle0.GetNext(), vertexTest.GetNext());
    ASSERT_EQUAL(handle0.GetPrevious(), vertexTest.GetPrevious());
}

void CoreTools::MinHeapRecordTesting::WeightTest(TestingType& minHeapRecord)
{
    ASSERT_APPROXIMATE_DOUBLE_ZERO(minHeapRecord.GetWeight());

    minHeapRecord.SetWeight(2.0);
    ASSERT_APPROXIMATE(minHeapRecord.GetWeight(), 2.0, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::MinHeapRecordTesting::RecordTest(TestingType& minHeapRecord)
{
    const VertexTest vertexTest{ 1, 2, 3 };

    minHeapRecord.SetRecord(3, vertexTest, 5.0);

    const auto handle1 = minHeapRecord.GetHandle();
    ASSERT_EQUAL(minHeapRecord.GetIndex(), 3);
    ASSERT_EQUAL(handle1.GetCurrent(), vertexTest.GetCurrent());
    ASSERT_EQUAL(handle1.GetNext(), vertexTest.GetNext());
    ASSERT_EQUAL(handle1.GetPrevious(), vertexTest.GetPrevious());
    ASSERT_APPROXIMATE(minHeapRecord.GetWeight(), 5.0, Mathematics::MathD::GetZeroTolerance());
}

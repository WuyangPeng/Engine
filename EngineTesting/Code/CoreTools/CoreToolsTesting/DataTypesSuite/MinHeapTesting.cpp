/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 17:19)

#include "MinHeapTesting.h"
#include "Detail/VertexTest.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::MinHeapTesting::MinHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MinHeapTesting)

void CoreTools::MinHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MinHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VertexBaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HandleTest);
}

void CoreTools::MinHeapTesting::IntegerTest()
{
    IntegerTestingType minHeap{ numMinHeap };

    ASSERT_NOT_THROW_EXCEPTION_1(BaseNumElementsTest, minHeap);
    ASSERT_NOT_THROW_EXCEPTION_1(BaseRemoveTest, minHeap);
}

void CoreTools::MinHeapTesting::BaseNumElementsTest(IntegerTestingType& minHeap)
{
    ASSERT_NOT_THROW_EXCEPTION_2(IntegerNumElementsTest, minHeap, 0);

    ASSERT_EQUAL(minHeap.Insert(2, 3), 0);

    ASSERT_NOT_THROW_EXCEPTION_2(IntegerNumElementsTest, minHeap, 1);
}

void CoreTools::MinHeapTesting::BaseRemoveTest(IntegerTestingType& minHeap)
{
    minHeap.Update(0, 5);

    const auto minHeapRecord = minHeap.Remove();

    ASSERT_EQUAL(minHeapRecord.GetHandle(), 2);
    ASSERT_EQUAL(minHeapRecord.GetWeight(), 5);

    ASSERT_NOT_THROW_EXCEPTION_2(IntegerNumElementsTest, minHeap, 0);
}

void CoreTools::MinHeapTesting::IntegerNumElementsTest(const IntegerTestingType& minHeap, int numElements)
{
    ASSERT_EQUAL(minHeap.GetMaxElements(), numMinHeap);
    ASSERT_EQUAL(minHeap.GetNumElements(), numElements);
}

void CoreTools::MinHeapTesting::VertexBaseTest()
{
    TestingType minHeap{ numMinHeap };

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, 0);

    const auto records = CreateRecords(minHeap);

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, numVertices);

    minHeap.Reset(numResetMinHeap);

    ASSERT_EQUAL(minHeap.GetMaxElements(), numResetMinHeap);
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);
}

CoreTools::MinHeapTesting::RecordsType CoreTools::MinHeapTesting::CreateRecords(TestingType& minHeap)
{
    RecordsType records{};

    for (auto i = 0; i < numVertices; ++i)
    {
        const VertexTest vertex{ (i + numVertices - 1) % numVertices, i, (i + 1) % numVertices };

        records.emplace_back(minHeap.Insert(vertex, vertex.GetWeight()));
    }

    return records;
}

void CoreTools::MinHeapTesting::RemoveTest()
{
    TestingType minHeap{ numMinHeap };

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, 0);

    const auto records = CreateRecords(minHeap);

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, numVertices);

    auto weight = 0.0;
    for (auto i = 0; i < numVertices; ++i)
    {
        weight = GetLastWeight(minHeap, weight);
    }
}

double CoreTools::MinHeapTesting::GetLastWeight(TestingType& minHeap, double weight)
{
    const auto minimum = minHeap.GetMinimum();

    const auto minHeapRecord = minHeap.Remove();

    ASSERT_APPROXIMATE(minimum.GetWeight(), minHeapRecord.GetWeight(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_EQUAL(minimum.GetIndex(), minHeapRecord.GetIndex());
    ASSERT_EQUAL(minimum.GetHandle().GetCurrent(), minHeapRecord.GetHandle().GetCurrent());
    ASSERT_EQUAL(minimum.GetHandle().GetPrevious(), minHeapRecord.GetHandle().GetPrevious());
    ASSERT_EQUAL(minimum.GetHandle().GetNext(), minHeapRecord.GetHandle().GetNext());

    ASSERT_LESS_EQUAL(weight, minHeapRecord.GetWeight());

    return minHeapRecord.GetWeight();
}

void CoreTools::MinHeapTesting::UpdateTest()
{
    TestingType minHeap{ numMinHeap };

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, 0);

    const auto records = CreateRecords(minHeap);

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, numVertices);

    for (const auto index : records)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(WeightUpdateTest, minHeap, index);
    }
}

void CoreTools::MinHeapTesting::WeightUpdateTest(TestingType& minHeap, int index)
{
    const auto oldWeight = minHeap.GetWeight(index);
    const auto newWeight = oldWeight * 2.0;
    minHeap.Update(index, newWeight);

    ASSERT_APPROXIMATE(minHeap.GetWeight(index), newWeight, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::MinHeapTesting::NumElementsTest(const TestingType& minHeap, int numElements)
{
    ASSERT_EQUAL(minHeap.GetMaxElements(), numMinHeap);
    ASSERT_EQUAL(minHeap.GetNumElements(), numElements);
}

void CoreTools::MinHeapTesting::HandleTest()
{
    TestingType minHeap{ numMinHeap };

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, 0);

    const auto records = CreateRecords(minHeap);

    ASSERT_NOT_THROW_EXCEPTION_2(NumElementsTest, minHeap, numVertices);

    for (const auto index : records)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(RecordTest, minHeap, index);
    }
}

void CoreTools::MinHeapTesting::RecordTest(const TestingType& minHeap, int index)
{
    const auto handle = minHeap.GetHandle(index);

    ASSERT_EQUAL(handle.GetPrevious(), (index + numVertices - 1) % numVertices);
    ASSERT_EQUAL(handle.GetCurrent(), index);
    ASSERT_EQUAL(handle.GetNext(), (index + 1) % numVertices);

    const auto record = minHeap.GetRecord(index);

    ASSERT_APPROXIMATE(record.GetWeight(), minHeap.GetWeight(index), Mathematics::MathD::GetZeroTolerance());

    ASSERT_EQUAL(handle.GetPrevious(), record.GetHandle().GetPrevious());
    ASSERT_EQUAL(handle.GetCurrent(), record.GetHandle().GetCurrent());
    ASSERT_EQUAL(handle.GetNext(), record.GetHandle().GetNext());
}
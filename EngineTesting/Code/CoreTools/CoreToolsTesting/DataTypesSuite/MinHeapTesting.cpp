/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 15:18)

#include "MinHeapTesting.h"
#include "Detail/VertexTest.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <Mathematics/Base/Math.h>

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
    MinHeap<int, int> minHeap{ 10 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 10);
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);

    ASSERT_EQUAL(minHeap.Insert(2, 3), 0);

    ASSERT_EQUAL(minHeap.GetNumElements(), 1);

    minHeap.Update(0, 5);

    const auto minHeapRecord = minHeap.Remove();

    ASSERT_EQUAL(minHeapRecord.GetHandle(), 2);
    ASSERT_EQUAL(minHeapRecord.GetWeight(), 5);

    ASSERT_EQUAL(minHeap.GetNumElements(), 0);
}

void CoreTools::MinHeapTesting::VertexBaseTest()
{
    MinHeap<VertexTest, double> minHeap{ 100 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);

    constexpr auto numVertices = 30;

    std::vector<int> records(numVertices);
    for (auto i = 0; i < numVertices; ++i)
    {
        const VertexTest vertex{ (i + numVertices - 1) % numVertices, i, (i + 1) % numVertices };

        records.at(i) = minHeap.Insert(vertex, vertex.GetWeight());
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), numVertices);

    minHeap.Reset(80);

    ASSERT_EQUAL(minHeap.GetMaxElements(), 80);
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);
}

void CoreTools::MinHeapTesting::RemoveTest()
{
    MinHeap<VertexTest, double> minHeap{ 100 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);

    constexpr auto numVertices = 30;

    std::vector<int> records(numVertices);
    for (auto i = 0; i < numVertices; ++i)
    {
        const VertexTest vertex{ (i + numVertices - 1) % numVertices, i, (i + 1) % numVertices };

        records.at(i) = minHeap.Insert(vertex, vertex.GetWeight());
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), numVertices);

    auto weight = 0.0;
    for (auto i = 0; i < numVertices; ++i)
    {
        const auto minimum = minHeap.GetMinimum();

        const auto minHeapRecord = minHeap.Remove();

        ASSERT_APPROXIMATE(minimum.GetWeight(), minHeapRecord.GetWeight(), Mathematics::MathD::GetZeroTolerance());
        ASSERT_EQUAL(minimum.GetIndex(), minHeapRecord.GetIndex());
        ASSERT_EQUAL(minimum.GetHandle().GetCurrent(), minHeapRecord.GetHandle().GetCurrent());
        ASSERT_EQUAL(minimum.GetHandle().GetPrevious(), minHeapRecord.GetHandle().GetPrevious());
        ASSERT_EQUAL(minimum.GetHandle().GetNext(), minHeapRecord.GetHandle().GetNext());

        ASSERT_LESS_EQUAL(weight, minHeapRecord.GetWeight());

        weight = minHeapRecord.GetWeight();
    }
}

void CoreTools::MinHeapTesting::UpdateTest()
{
    MinHeap<VertexTest, double> minHeap{ 100 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);

    constexpr auto numVertices = 30;

    std::vector<int> records(numVertices);
    for (auto i = 0; i < numVertices; ++i)
    {
        const VertexTest vertex{ (i + numVertices - 1) % numVertices, i, (i + 1) % numVertices };

        records.at(i) = minHeap.Insert(vertex, vertex.GetWeight());
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), numVertices);

    for (const auto index : records)
    {
        const auto oldWeight = minHeap.GetWeight(index);
        minHeap.Update(index, oldWeight * 2.0);

        ASSERT_APPROXIMATE(minHeap.GetWeight(index), oldWeight * 2.0, Mathematics::MathD::GetZeroTolerance());
    }
}

void CoreTools::MinHeapTesting::HandleTest()
{
    MinHeap<VertexTest, double> minHeap{ 100 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);

    constexpr auto numVertices = 30;

    std::vector<int> records(numVertices);
    for (auto i = 0; i < numVertices; ++i)
    {
        const VertexTest vertex{ (i + numVertices - 1) % numVertices, i, (i + 1) % numVertices };

        records.at(i) = minHeap.Insert(vertex, vertex.GetWeight());
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 100);
    ASSERT_EQUAL(minHeap.GetNumElements(), numVertices);

    for (const auto index : records)
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
}

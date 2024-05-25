/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 15:18)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_TESTING_H

#include "Detail/VertexTest.h"
#include "CoreTools/DataTypes/MinHeap.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MinHeapTesting final : public UnitTest
    {
    public:
        using ClassType = MinHeapTesting;
        using ParentType = UnitTest;

    public:
        explicit MinHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TestingType = MinHeap<VertexTest, double>;
        using IntegerTestingType = MinHeap<int, int>;
        using RecordsType = std::vector<int>;

        static constexpr auto numVertices = 30;
        static constexpr auto numMinHeap = 100;
        static constexpr auto numResetMinHeap = 80;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void IntegerTest();
        void VertexBaseTest();
        void RemoveTest();
        void UpdateTest();
        void HandleTest();

        void BaseNumElementsTest(IntegerTestingType& minHeap);
        void BaseRemoveTest(IntegerTestingType& minHeap);
        void IntegerNumElementsTest(const IntegerTestingType& minHeap, int numElements);

        void RecordTest(const TestingType& minHeap, int index);
        NODISCARD static RecordsType CreateRecords(TestingType& minHeap);
        NODISCARD double GetLastWeight(TestingType& minHeap, double weight);
        void WeightUpdateTest(TestingType& minHeap, int index);
        void NumElementsTest(const TestingType& minHeap, int numElements);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 14:46)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_TESTING_H

#include "Detail/VertexTest.h"
#include "CoreTools/DataTypes/MinHeapRecord.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MinHeapRecordTesting final : public UnitTest
    {
    public:
        using ClassType = MinHeapRecordTesting;
        using ParentType = UnitTest;

    public:
        explicit MinHeapRecordTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TestingType = MinHeapRecord<VertexTest, double>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultTest();
        void MinHeapRecordTest();
        void SetMinHeapRecordTest();

        void IndexTest(TestingType& minHeapRecord);
        void HandleZeroTest(const TestingType& minHeapRecord);
        void HandleEqualTest(TestingType& minHeapRecord);
        void WeightTest(TestingType& minHeapRecord);
        void RecordTest(TestingType& minHeapRecord);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_TESTING_H
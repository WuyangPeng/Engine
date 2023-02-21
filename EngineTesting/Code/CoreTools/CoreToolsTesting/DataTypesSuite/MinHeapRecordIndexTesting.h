///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 13:43)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_INDEX_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_INDEX_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MinHeapRecordIndexTesting : public UnitTest
    {
    public:
        using ClassType = MinHeapRecordIndexTesting;
        using ParentType = UnitTest;

    public:
        explicit MinHeapRecordIndexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void IndexTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_INDEX_TESTING_H
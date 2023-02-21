///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 13:43)

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
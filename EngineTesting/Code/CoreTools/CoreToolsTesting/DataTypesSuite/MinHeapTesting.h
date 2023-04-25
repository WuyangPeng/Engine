///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 18:04)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_TESTING_H

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
        void MainTest();
        void IntegerTest();
        void FloatTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_TESTING_H
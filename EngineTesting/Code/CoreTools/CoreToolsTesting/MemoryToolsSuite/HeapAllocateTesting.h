///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 13:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class HeapAllocateTesting final : public UnitTest
    {
    public:
        using ClassType = HeapAllocateTesting;
        using ParentType = UnitTest;

    public:
        explicit HeapAllocateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void CharTest();
        void DoubleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H

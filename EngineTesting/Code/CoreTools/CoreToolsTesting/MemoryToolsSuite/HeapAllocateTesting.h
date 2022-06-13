///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 18:20)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class HeapAllocateTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(HeapAllocateTesting);

    private:
        void MainTest();
        void CharTest();
        void DoubleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H

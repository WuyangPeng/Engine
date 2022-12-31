///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/21 22:43)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_COMPACT_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_COMPACT_HEAP_TESTING_H

#include "HeapTestingBase.h"

namespace System
{
    class CompactHeapTesting final : public HeapTestingBase
    {
    public:
        using ClassType = CompactHeapTesting;
        using ParentType = HeapTestingBase;

    public:
        explicit CompactHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CompactHeapTest();
        void CompactTest(HeapCreate flag);
        void DoCompactTest(WindowsHandle handle, HeapCreate flag);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_COMPACT_HEAP_TESTING_H
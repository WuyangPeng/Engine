///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/16 19:35)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_COMPACT_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_COMPACT_HEAP_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CompactHeapTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CompactHeapTesting;
        using ParentType = UnitTest;

    public:
        explicit CompactHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CompactTest(HeapCreate flag);
        void DoCompactTest(WindowsHandle handle, HeapCreate flag);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_COMPACT_HEAP_TESTING_H
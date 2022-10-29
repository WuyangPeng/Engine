///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/16 19:35)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_HEAP_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class AllocateHeapTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AllocateHeapTesting;
        using ParentType = UnitTest;

    public:
        explicit AllocateHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AllocateDefaultHeapSucceedTest();
        void DoAllocateDefaultHeapSucceedTest(WindowsHandle handle, HeapCreate flag);

        void AllocateDefaultHeapFailureTest();

        void DoAllocateDefaultHeapFailureTest(WindowsHandle handle, HeapCreate flag);

        void AllocateIntegerTest();

    private:
        using HeapCreateFlagsContainer = std::vector<HeapCreate>;

    private:
        HeapCreateFlagsContainer heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_HEAP_TESTING_H
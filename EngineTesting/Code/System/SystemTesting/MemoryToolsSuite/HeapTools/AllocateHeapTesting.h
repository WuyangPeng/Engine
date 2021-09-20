///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/20 13:39)

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
        using HeapCreateFlagsCollection = std::vector<HeapCreate>;

    private:
        HeapCreateFlagsCollection heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_HEAP_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/16 19:34)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_RE_ALLOCATE_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_RE_ALLOCATE_HEAP_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class ReAllocateHeapTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReAllocateHeapTesting;
        using ParentType = UnitTest;

    public:
        explicit ReAllocateHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ReAllocateProcessHeapSucceedTest();
        void DoReAllocateProcessHeapSucceedTest(WindowsHandle handle, HeapCreate flag);

        void ReAllocateProcessHeapFailureTest();
        void DoReAllocateProcessHeapFailureTest(WindowsHandle handle, HeapCreate flag);

    private:
        using HeapCreateFlagsContainer = std::vector<HeapCreate>;

        static constexpr WindowsSize windowSize{ 50 };

    private:
        HeapCreateFlagsContainer heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_RE_ALLOCATE_HEAP_TESTING_H
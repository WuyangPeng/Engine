///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:49)

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
        using HeapCreateFlagsCollection = std::vector<HeapCreate>;

        static constexpr WindowsSize windowSize{ 50 };

    private:
        HeapCreateFlagsCollection heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_RE_ALLOCATE_HEAP_TESTING_H
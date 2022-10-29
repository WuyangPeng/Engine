///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/16 19:34)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CreateHeapTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateHeapTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateHeapSucceedTest();
        void DoCreateHeapSucceedTest(HeapCreate flag);

        void CreateHeapFailureTest();
        void DoCreateHeapFailureTest(HeapCreate flag);

    private:
        using HeapCreateFlagsContainer = std::vector<HeapCreate>;

    private:
        HeapCreateFlagsContainer heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H
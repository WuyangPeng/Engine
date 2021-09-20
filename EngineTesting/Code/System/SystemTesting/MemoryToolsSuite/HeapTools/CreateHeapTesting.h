///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/20 13:32)

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
        using HeapCreateFlagsCollection = std::vector<HeapCreate>;

    private:
        HeapCreateFlagsCollection heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H
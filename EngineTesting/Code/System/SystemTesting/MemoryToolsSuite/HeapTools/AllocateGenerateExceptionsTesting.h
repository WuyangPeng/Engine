///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/16 19:35)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class AllocateGenerateExceptionsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AllocateGenerateExceptionsTesting;
        using ParentType = UnitTest;

    public:
        explicit AllocateGenerateExceptionsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AllocateGenerateExceptionsHeapSucceedTest();
        void DoAllocateGenerateExceptionsHeapSucceedTest(WindowsHandle handle, HeapCreate flag);

        void AllocateGenerateExceptionsHeapFailureTest();
        void DoAllocateGenerateExceptionsHeapFailureTest(WindowsHandle handle, HeapCreate flag);

    private:
        using HeapCreateFlagsContainer = std::vector<HeapCreate>;

    private:
        HeapCreateFlagsContainer heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:49)

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
        using HeapCreateFlagsCollection = std::vector<HeapCreate>;

    private:
        HeapCreateFlagsCollection heapCreateFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:50)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_ALLOC_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_ALLOC_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class LocalMemoryAllocTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LocalMemoryAllocTesting;
        using ParentType = UnitTest;

    public:
        explicit LocalMemoryAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LocalMemoryAllocTest();

    private:
        using LocalMemoryCollection = std::vector<LocalMemory>;

    private:
        LocalMemoryCollection localMemoryCollection;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_ALLOC_TESTING_H
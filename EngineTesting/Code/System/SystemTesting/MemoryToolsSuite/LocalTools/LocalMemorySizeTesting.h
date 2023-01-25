///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/04 21:13)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_SIZE_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_SIZE_TESTING_H

#include "LocalMemoryTestingBase.h"

namespace System
{
    class LocalMemorySizeTesting final : public LocalMemoryTestingBase
    {
    public:
        using ClassType = LocalMemorySizeTesting;
        using ParentType = LocalMemoryTestingBase;

    public:
        explicit LocalMemorySizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LocalMemorySizeTest();
        void DoLocalMemorySizeTest(LocalMemory localMemory);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_SIZE_TESTING_H
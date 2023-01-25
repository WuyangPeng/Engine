///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/04 21:01)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_ALLOC_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_ALLOC_TESTING_H

#include "LocalMemoryTestingBase.h"

namespace System
{
    class LocalMemoryAllocTesting final : public LocalMemoryTestingBase
    {
    public:
        using ClassType = LocalMemoryAllocTesting;
        using ParentType = LocalMemoryTestingBase;

    public:
        explicit LocalMemoryAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LocalMemoryAllocTest();
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_ALLOC_TESTING_H
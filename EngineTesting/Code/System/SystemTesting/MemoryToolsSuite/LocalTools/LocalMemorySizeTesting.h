/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 10:12)

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
        void DoRunUnitTest() override;
        void MainTest();

        void LocalMemorySizeTest();
        void DoLocalMemorySizeTest(LocalMemory localMemory);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_SIZE_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:12)

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
        static constexpr WindowsSize localSize{ 256 * sizeof(TChar) };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LocalMemoryAllocTest();
        void DoLocalMemoryAllocTest(LocalMemory localMemory);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_ALLOC_TESTING_H
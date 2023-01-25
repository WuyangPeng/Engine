///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/06 21:29)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H

#include "VirtualToolsTestingBase.h"

namespace System
{
    class AllocateVirtualSeparationTesting final : public VirtualToolsTestingBase
    {
    public:
        using ClassType = AllocateVirtualSeparationTesting;
        using ParentType = VirtualToolsTestingBase;

    public:
        explicit AllocateVirtualSeparationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool AllocateVirtualTest();

        void AllocateVirtualSeparationTest();
        void DoAllocateVirtualSeparationTest(size_t index);
        void DoAllocateVirtualSeparationUseProcessTest(size_t index);
        void ReadWriteTest(MemoryProtect memoryProtect, char* basePage) noexcept;

        void AllocateVirtualOnePageTest(char* baseVirtual, size_t index);
        void AllocateVirtualOnePageUseProcessTest(char* baseVirtual, size_t index);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:14)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool AllocateVirtualTest();

        void AllocateVirtualSeparationTest(size_t index);
        void AllocateVirtualSeparationTestLoop();
        void DoAllocateVirtualSeparationTest(size_t index);
        void DoAllocateVirtualSeparationUseProcessTest(size_t index);
        void DoAllocateVirtualOnePageUseProcessTest(MemoryProtect memoryProtect, char*& nextVirtual);
        void ReadWriteTest(MemoryProtect memoryProtect, char* basePage) const noexcept;

        void AllocateVirtualOnePageTest(char* baseVirtual, size_t index);
        void AllocateVirtualOnePageUseProcessTest(char* baseVirtual, size_t index);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H
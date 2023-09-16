///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:02)

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

        void AllocateVirtualSeparationTest();
        void DoAllocateVirtualSeparationTest(size_t index);
        void DoAllocateVirtualSeparationUseProcessTest(size_t index);
        void ReadWriteTest(MemoryProtect memoryProtect, char* basePage) noexcept;

        void AllocateVirtualOnePageTest(char* baseVirtual, size_t index);
        void AllocateVirtualOnePageUseProcessTest(char* baseVirtual, size_t index);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H
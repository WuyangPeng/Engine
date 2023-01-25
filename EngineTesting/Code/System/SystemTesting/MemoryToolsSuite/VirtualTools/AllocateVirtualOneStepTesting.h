///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/06 20:53)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H

#include "VirtualToolsTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class AllocateVirtualOneStepTesting final : public VirtualToolsTestingBase
    {
    public:
        using ClassType = AllocateVirtualOneStepTesting;
        using ParentType = VirtualToolsTestingBase;

    public:
        explicit AllocateVirtualOneStepTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool AllocateVirtualTest();

        void AllocateVirtualOneStepTest();
        void DoAllocateVirtualOneStepTest(size_t index);
        void DoAllocateVirtualOneStepUseProcessTest(size_t index);
        void ReadWriteTest(MemoryProtect memoryProtect, char* basePage) noexcept;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H
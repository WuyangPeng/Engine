/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:13)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H

#include "VirtualToolsTestingBase.h"

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool AllocateVirtualTest();

        void AllocateVirtualOneStepTest(size_t index);
        void AllocateVirtualOneStepTestLoop();
        void DoAllocateVirtualOneStepTest(size_t index);
        void DoAllocateVirtualOneStepUseProcessTest(size_t index);
        void ReadWriteTest(MemoryProtect memoryProtect, char* basePage) const noexcept;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H
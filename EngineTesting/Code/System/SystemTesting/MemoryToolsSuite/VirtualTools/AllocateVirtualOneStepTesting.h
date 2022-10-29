///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/16 19:32)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class AllocateVirtualOneStepTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AllocateVirtualOneStepTesting;
        using ParentType = UnitTest;

    public:
        explicit AllocateVirtualOneStepTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void AllocateVirtualOneStepTest();
        void DoAllocateVirtualOneStepTest(const WindowsSystemInfo& systemInfo, size_t index);
        void DoAllocateVirtualOneStepUseProcessTest(const WindowsSystemInfo& systemInfo, size_t index);
        void ReadWriteTest(const WindowsSystemInfo& systemInfo, MemoryProtect memoryProtect, char* basePage) noexcept;
        void DoReadWriteTest(MemoryProtect memoryProtect, char& basePage) noexcept;

    private:
        using MemoryAllocationFlagsContainer = std::vector<MemoryAllocation>;
        using MemoryProtectFlagsContainer = std::vector<MemoryProtect>;

    private:
        static constexpr auto pageLimit = 80;

    private:
        MemoryAllocationFlagsContainer memoryAllocationFlags;
        MemoryProtectFlagsContainer memoryProtectFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_ONE_STEP_TESTING_H
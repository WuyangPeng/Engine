///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/20 18:21)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class AllocateVirtualSeparationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AllocateVirtualSeparationTesting;
        using ParentType = UnitTest;

    public:
        explicit AllocateVirtualSeparationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void AllocateVirtualSeparationTest();
        void DoAllocateVirtualSeparationTest(const WindowsSystemInfo& systemInfo, size_t index);
        void DoAllocateVirtualSeparationUseProcessTest(const WindowsSystemInfo& systemInfo, size_t index);
        void ReadWriteTest(const WindowsSystemInfo& systemInfo, MemoryProtect memoryProtect, char* basePage) noexcept;
        void DoReadWriteTest(MemoryProtect memoryProtect, char& basePage) noexcept;

    private:
        using MemoryAllocationFlagsCollection = std::vector<MemoryAllocation>;
        using MemoryProtectFlagsCollection = std::vector<MemoryProtect>;

    private:
        static constexpr auto pageLimit = 80;

    private:
        MemoryAllocationFlagsCollection memoryAllocationFlags;
        MemoryProtectFlagsCollection memoryProtectFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_VIRTUAL_SEPARATION_TESTING_H
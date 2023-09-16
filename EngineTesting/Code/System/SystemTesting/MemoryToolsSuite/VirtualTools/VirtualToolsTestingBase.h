///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:03)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_TOOLS_TESTING_BASE_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_TOOLS_TESTING_BASE_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class VirtualToolsTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = VirtualToolsTestingBase;
        using ParentType = UnitTest;

    public:
        explicit VirtualToolsTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD void RandomShuffle();

    protected:
        using MemoryAllocationContainer = std::vector<MemoryAllocation>;
        using MemoryProtectContainer = std::vector<MemoryProtect>;

    protected:
        NODISCARD size_t GetMaxSize() const noexcept;
        NODISCARD MemoryAllocation GetMemoryAllocation(size_t index) const;
        NODISCARD MemoryProtect GetMemoryProtect(size_t index) const;
        NODISCARD WindowsDWord GetPageSize() const noexcept;
        NODISCARD WindowsDWord GetOnePageSize() const noexcept;
        void FreeVirtualTest(WindowsVoidPtr baseVirtual);
        void FreeVirtualUseProcessTest(WindowsHandle process, WindowsVoidPtr baseVirtual);
        void DoReadWriteTest(MemoryProtect memoryProtect, char& basePage) noexcept;

    protected:
        static constexpr auto pageLimit = 80;

    private:
        MemoryAllocationContainer memoryAllocations;
        MemoryProtectContainer memoryProtects;
        size_t maxSize;
        std::default_random_engine randomEngine;
        WindowsSystemInfo windowsSystemInfo;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_TOOLS_TESTING_BASE_H
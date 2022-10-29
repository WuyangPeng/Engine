///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/16 19:31)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_PROTECT_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_PROTECT_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class VirtualProtectTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VirtualProtectTesting;
        using ParentType = UnitTest;

    public:
        explicit VirtualProtectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void ProtectTest();

        void DoProtectTest(size_t index, const WindowsSystemInfo& systemInfo);
        void DoProtectUseProcessTest(size_t index, const WindowsSystemInfo& systemInfo);

    private:
        using MemoryProtectFlagsContainer = std::vector<MemoryProtect>;

    private:
        static constexpr auto pageLimit = 80;

    private:
        MemoryProtectFlagsContainer memoryProtectFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_PROTECT_TESTING_H
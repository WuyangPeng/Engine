///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/16 19:30)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class VirtualQueryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VirtualQueryTesting;
        using ParentType = UnitTest;

    public:
        explicit VirtualQueryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void QueryTest();

        void DoQueryTest(size_t index, const WindowsSystemInfo& systemInfo);
        void DoQueryUseProcessTest(size_t index, const WindowsSystemInfo& systemInfo);

    private:
        using MemoryProtectFlagsContainer = std::vector<MemoryProtect>;

    private:
        static constexpr auto pageLimit = 80;

    private:
        MemoryProtectFlagsContainer memoryProtectFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H
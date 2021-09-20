///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/22 11:36)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
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
        using MemoryProtectFlagsCollection = std::vector<MemoryProtect>;

    private:
        static constexpr auto pageLimit = 80;

    private:
        MemoryProtectFlagsCollection memoryProtectFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H
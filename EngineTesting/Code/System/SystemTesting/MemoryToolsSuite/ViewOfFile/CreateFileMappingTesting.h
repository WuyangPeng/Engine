///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/16 19:33)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_CREATE_FILE_MAPPING_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_CREATE_FILE_MAPPING_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>
#include <random>
#include <vector>

namespace System
{
    class CreateFileMappingTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateFileMappingTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateFileMappingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void CreateFileMappingTest();
        void DoCreateFileMappingTest(size_t index);

    private:
        using MemoryProtectFlagsContainer = std::vector<MemoryProtect>;
        using FileMapProtectionFlagsContainer = std::vector<FileMapProtection>;
        using MappingType = std::map<MemoryProtect, FileHandleDesiredAccess>;

    private:
        MemoryProtectFlagsContainer memoryProtectFlags;
        FileMapProtectionFlagsContainer fileMapProtectionFlags;
        MappingType mapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_CREATE_FILE_MAPPING_TESTING_H
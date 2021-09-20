///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/22 19:38)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_OPEN_FILE_MAPPING_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_OPEN_FILE_MAPPING_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>
#include <random>
#include <vector>

namespace System
{
    class OpenFileMappingTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenFileMappingTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenFileMappingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void OpenFileMappingTest();
        void DoOpenFileMappingTest(size_t index);

    private:
        using MemoryProtectFlagsCollection = std::vector<MemoryProtect>;
        using FileMapProtectionFlagsCollection = std::vector<FileMapProtection>;
        using FileMapDesiredAccessFlagsCollection = std::vector<FileMapDesiredAccess>;
        using MappingType = std::map<MemoryProtect, FileHandleDesiredAccess>;

    private:
        MemoryProtectFlagsCollection memoryProtectFlags;
        FileMapProtectionFlagsCollection fileMapProtectionFlags;
        FileMapDesiredAccessFlagsCollection fileMapDesiredAccessFlags;
        MappingType mapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_OPEN_FILE_MAPPING_TESTING_H
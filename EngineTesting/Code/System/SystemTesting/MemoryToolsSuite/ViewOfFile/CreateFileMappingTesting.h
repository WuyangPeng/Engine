///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/22 17:12)

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
        using MemoryProtectFlagsCollection = std::vector<MemoryProtect>;
        using FileMapProtectionFlagsCollection = std::vector<FileMapProtection>;
        using MappingType = std::map<MemoryProtect, FileHandleDesiredAccess>;

    private:
        MemoryProtectFlagsCollection memoryProtectFlags;
        FileMapProtectionFlagsCollection fileMapProtectionFlags;
        MappingType mapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_CREATE_FILE_MAPPING_TESTING_H
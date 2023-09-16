///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:01)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_FILE_MAPPING_TESTING_BASE_H
#define SYSTEM_MEMORY_TOOLS_SUITE_FILE_MAPPING_TESTING_BASE_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>
#include <random>
#include <vector>

namespace System
{
    class FileMappingTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = FileMappingTestingBase;
        using ParentType = UnitTest;

    public:
        explicit FileMappingTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD void RandomShuffle();
        NODISCARD size_t GetMaxSize() const noexcept;
        NODISCARD MemoryProtect GetMemoryProtect(size_t index) const;
        NODISCARD FileMapProtection GetFileMapProtection(size_t index) const;
        NODISCARD FileMapDesiredAccess GetFileMapDesiredAccess(size_t index) const;
        NODISCARD FileHandleDesiredAccess GetMapping(MemoryProtect memoryProtect);
        NODISCARD String GetFileMappingName() const;
        NODISCARD String GetLoopTestFileName() const;
        void CloseFileTest(WindowsHandle fileHandle);
        void CloseFileMappingTest(WindowsHandle fileHandle);

        constexpr static WindowsDWord GetMaximumSizeLow() noexcept
        {
            return 0xFFFFu;
        }

    private:
        using MemoryProtectContainer = std::vector<MemoryProtect>;
        using FileMapProtectionContainer = std::vector<FileMapProtection>;
        using FileMapDesiredAccessContainer = std::vector<FileMapDesiredAccess>;
        using MappingType = std::map<MemoryProtect, FileHandleDesiredAccess>;

    private:
        MemoryProtectContainer memoryProtects;
        FileMapProtectionContainer fileMapProtections;
        FileMapDesiredAccessContainer fileMapDesiredAccesses;
        MappingType mapping;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_FILE_MAPPING_TESTING_BASE_H
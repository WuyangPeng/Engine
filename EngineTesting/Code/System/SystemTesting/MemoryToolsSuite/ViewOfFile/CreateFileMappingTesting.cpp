///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:55)

#include "CreateFileMappingTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/MemoryTools/Flags/ViewOfFileFlags.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/ViewOfFile.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileMappingTesting::CreateFileMappingTesting(const OStreamShared& stream)
    : ParentType{ stream },
      memoryProtectFlags{ MemoryProtect::WriteCopy,
                          MemoryProtect::ReadOnly,
                          MemoryProtect::ReadWrite,
                          MemoryProtect::ExecuteWriteCopy,
                          MemoryProtect::ExecuteRead,
                          MemoryProtect::ExecuteReadWrite },
      fileMapProtectionFlags{ FileMapProtection::Default,
                              FileMapProtection::Commit,
                              FileMapProtection::Reserve },
      mapping{ { MemoryProtect::WriteCopy, FileHandleDesiredAccess::ReadWrite },
               { MemoryProtect::ReadOnly, FileHandleDesiredAccess::ReadWrite },
               { MemoryProtect::ReadWrite, FileHandleDesiredAccess::ReadWrite },
               { MemoryProtect::ExecuteWriteCopy, FileHandleDesiredAccess::Read | FileHandleDesiredAccess::Execute },
               { MemoryProtect::ExecuteRead, FileHandleDesiredAccess::Read | FileHandleDesiredAccess::Execute },
               { MemoryProtect::ExecuteReadWrite, FileHandleDesiredAccess::ReadWrite | FileHandleDesiredAccess::Execute } },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileMappingTesting)

void System::CreateFileMappingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileMappingTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateFileMappingTesting::RandomShuffleFlags()
{
    shuffle(memoryProtectFlags.begin(), memoryProtectFlags.end(), randomEngine);
    shuffle(fileMapProtectionFlags.begin(), fileMapProtectionFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileMappingTest);

    return true;
}

void System::CreateFileMappingTesting::CreateFileMappingTest()
{
    for (auto index = 0u; index < memoryProtectFlags.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateFileMappingTest, index);
    }
}

void System::CreateFileMappingTesting::DoCreateFileMappingTest(size_t index)
{
    constexpr WindowsDWord maximumSizeLow{ 0xFFFF };
    const auto fileMapName = L"FileMappingTestingFileMap"s;
    const auto fileMappingName = SYSTEM_TEXT("Resource/FileMappingTesting/FileMappingTest.txt"s);

    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());
    auto fileMapProtection = fileMapProtectionFlags.at(index % fileMapProtectionFlags.size());

    const auto iter = mapping.find(memoryProtect);
    ASSERT_UNEQUAL_FAILURE_THROW(iter, mapping.end(), "");

    auto fileHandle = CreateSystemFile(fileMappingName.c_str(),
                                       iter->second,
                                       FileHandleShareMode::Prevents,
                                       FileHandleCreationDisposition::OpenAlways);
    ASSERT_TRUE_FAILURE_THROW(IsFileHandleValid(fileHandle), "CreateSystemFile 失败");

    auto loopTestFileName = fileMapName + System::ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto isExists = false;
    auto fileMappingHandle = CreateSystemFileMapping(fileHandle, memoryProtect, fileMapProtection, 0, maximumSizeLow, loopTestFileName.c_str(), &isExists);

    ASSERT_UNEQUAL_NULL_PTR(fileMappingHandle);
    ASSERT_FALSE(isExists);

    auto againFileMappingHandle = CreateSystemFileMapping(fileHandle, memoryProtect, fileMapProtection, 0, maximumSizeLow, loopTestFileName.c_str(), &isExists);
    ASSERT_UNEQUAL_NULL_PTR(againFileMappingHandle);
    ASSERT_TRUE(isExists);

    ASSERT_TRUE(CloseFileMapping(fileMappingHandle));
    ASSERT_TRUE(CloseFileMapping(againFileMappingHandle));
    ASSERT_TRUE(CloseSystemFile(fileHandle));
}

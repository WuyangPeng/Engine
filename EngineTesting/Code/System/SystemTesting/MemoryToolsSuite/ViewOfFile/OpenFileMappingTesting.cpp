///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/22 19:39)

#include "OpenFileMappingTesting.h"
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

System::OpenFileMappingTesting::OpenFileMappingTesting(const OStreamShared& stream)
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
      fileMapDesiredAccessFlags{ FileMapDesiredAccess::Write,
                                 FileMapDesiredAccess::Read,
                                 FileMapDesiredAccess::AllAccess,
                                 FileMapDesiredAccess::Execute },
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenFileMappingTesting)

void System::OpenFileMappingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenFileMappingTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenFileMappingTesting::RandomShuffleFlags()
{
    shuffle(memoryProtectFlags.begin(), memoryProtectFlags.end(), randomEngine);
    shuffle(fileMapProtectionFlags.begin(), fileMapProtectionFlags.end(), randomEngine);
    shuffle(fileMapDesiredAccessFlags.begin(), fileMapDesiredAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(OpenFileMappingTest);

    return true;
}

void System::OpenFileMappingTesting::OpenFileMappingTest()
{
    for (auto index = 0u; index < fileMapDesiredAccessFlags.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoOpenFileMappingTest, index);
    }
}

void System::OpenFileMappingTesting::DoOpenFileMappingTest(size_t index)
{
    constexpr WindowsDWord maximumSizeLow{ 0xFFFF };
    const auto fileMapName = L"FileMappingTestingFileMap"s;
    const auto fileMappingName = SYSTEM_TEXT("Resource/FileMappingTesting/FileMappingTest.txt"s);

    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());
    auto fileMapProtection = fileMapProtectionFlags.at(index % fileMapProtectionFlags.size());
    auto fileMapDesiredAccess = fileMapDesiredAccessFlags.at(index % fileMapDesiredAccessFlags.size());

    const auto iter = mapping.find(memoryProtect);
    ASSERT_UNEQUAL_DO_NOT_USE_MESSAGE_FAILURE_THROW(iter, mapping.end());

    auto fileHandle = CreateSystemFile(fileMappingName.c_str(),
                                       iter->second,
                                       FileHandleShareMode::Prevents,
                                       FileHandleCreationDisposition::OpenAlways);
    ASSERT_TRUE_FAILURE_THROW(IsFileHandleValid(fileHandle), "CreateSystemFile 失败");

    auto loopTestFileName = fileMapName + System::ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto fileMappingHandle = CreateSystemFileMapping(fileHandle, memoryProtect, fileMapProtection, 0, maximumSizeLow, loopTestFileName.c_str(), nullptr);
    ASSERT_UNEQUAL_NULL_PTR(fileMappingHandle);

    auto openFileMappingHandle = OpenSystemFileMapping(fileMapDesiredAccess, true, loopTestFileName.c_str());
    ASSERT_UNEQUAL_NULL_PTR(openFileMappingHandle);

    ASSERT_TRUE(CloseFileMapping(fileMappingHandle));
    ASSERT_TRUE(CloseFileMapping(openFileMappingHandle));
    ASSERT_TRUE(CloseSystemFile(fileHandle));
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:26)

#include "CreateFileWithSecurityFlagsTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileWithSecurityFlagsTesting::CreateFileWithSecurityFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileWithSecurityFlagsTesting)

void System::CreateFileWithSecurityFlagsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileWithSecurityFlagsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateFileWithSecurityFlagsTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomFileHandleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileTest);

    return true;
}

void System::CreateFileWithSecurityFlagsTesting::CreateFileTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateFileTest, index);
    }
}

void System::CreateFileWithSecurityFlagsTesting::DoCreateFileTest(size_t index)
{
    if (const auto fileHandleCreationDisposition = GetFileHandleCreationDisposition(index);
        fileHandleCreationDisposition == FileHandleCreationDisposition::CreateNew)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CreateNewTest, index, fileHandleCreationDisposition);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(ExistingFileTest, index, fileHandleCreationDisposition);
    }
}

void System::CreateFileWithSecurityFlagsTesting::CreateNewTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto createFileName = GetCreateFileName(index);

    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index);
    const auto fileHandleShareMode = GetFileHandleShareMode(index);
    const auto fileHandleSecurityFlag = GetFileHandleSecurity(index);

    const auto fileHandle = CreateSystemFile(createFileName,
                                             fileHandleDesiredAccess,
                                             fileHandleShareMode,
                                             fileHandleCreationDisposition,
                                             FileHandleAttribute::Normal,
                                             FileHandleOther::SequentialScan,
                                             fileHandleSecurityFlag);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);

    if (fileHandleCreationDisposition == FileHandleCreationDisposition::CreateNew)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(RemoveFile, createFileName);
    }
}

void System::CreateFileWithSecurityFlagsTesting::ExistingFileTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto createFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    const auto fileHandleShareMode = GetFileHandleShareMode(index);
    const auto fileHandleSecurityFlag = GetFileHandleSecurity(index);
    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index, fileHandleCreationDisposition);

    const auto fileHandle = CreateSystemFile(createFileName,
                                             fileHandleDesiredAccess,
                                             fileHandleShareMode,
                                             fileHandleCreationDisposition,
                                             FileHandleAttribute::Normal,
                                             FileHandleOther::SequentialScan,
                                             fileHandleSecurityFlag);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);
}

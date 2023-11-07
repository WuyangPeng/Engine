///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:20)

#include "CreateFileWithOtherFlagsTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileWithOtherFlagsTesting::CreateFileWithOtherFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileWithOtherFlagsTesting)

void System::CreateFileWithOtherFlagsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileWithOtherFlagsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateFileWithOtherFlagsTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomFileHandleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileTest);

    return true;
}

void System::CreateFileWithOtherFlagsTesting::CreateFileTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateFileTest, index);
    }
}

void System::CreateFileWithOtherFlagsTesting::DoCreateFileTest(size_t index)
{
    const auto fileHandleCreationDisposition = GetFileHandleCreationDisposition(index);
    const auto fileHandleOther = GetFileHandleOther(index);

    if (fileHandleCreationDisposition == FileHandleCreationDisposition::CreateNew ||
        ((fileHandleOther & FileHandleOther::DeleteOnClose) == FileHandleOther::DeleteOnClose))
    {
        CreateNewTest(index, FileHandleCreationDisposition::CreateNew);
    }
    else
    {
        ExistingFileTest(index, fileHandleCreationDisposition);
    }
}

void System::CreateFileWithOtherFlagsTesting::CreateNewTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto createFileName = GetCreateFileName(index);

    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index);
    const auto fileHandleShareMode = GetFileHandleShareMode(index);
    const auto fileHandleOther = GetFileHandleOther(index);

    const auto fileHandle = CreateSystemFile(createFileName,
                                             fileHandleDesiredAccess,
                                             fileHandleShareMode,
                                             fileHandleCreationDisposition,
                                             FileHandleAttributes::Normal,
                                             fileHandleOther,
                                             FileHandleSecurity::Default);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);

    if (fileHandleCreationDisposition == FileHandleCreationDisposition::CreateNew &&
        fileHandleOther != FileHandleOther::DeleteOnClose)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(RemoveFile, createFileName);
    }
}

void System::CreateFileWithOtherFlagsTesting::ExistingFileTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto createFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    const auto fileHandleShareMode = GetFileHandleShareMode(index);
    const auto fileHandleOther = GetFileHandleOther(index);
    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index, fileHandleCreationDisposition);

    const auto fileHandle = CreateSystemFile(createFileName,
                                             fileHandleDesiredAccess,
                                             fileHandleShareMode,
                                             fileHandleCreationDisposition,
                                             FileHandleAttributes::Normal,
                                             fileHandleOther,
                                             FileHandleSecurity::Default);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);
}

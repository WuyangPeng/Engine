///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/13 10:42)

#include "CreateFileWithAttributesTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileWithAttributesTesting::CreateFileWithAttributesTesting(const OStreamShared& stream)
    : ParentType{ stream }, onlyReadFile{ SYSTEM_TEXT("Resource/FileTesting/CreateOnlyReadFile.txt"s) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileWithAttributesTesting)

void System::CreateFileWithAttributesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileWithAttributesTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateFileWithAttributesTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomFileHandleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileTest);

    return true;
}

void System::CreateFileWithAttributesTesting::CreateFileTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateFileTest, index);
    }
}

void System::CreateFileWithAttributesTesting::DoCreateFileTest(size_t index)
{
    const auto fileHandleAttribute = GetFileHandleAttributes(index);
    if (fileHandleAttribute == FileHandleAttributes::ReadOnly)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ReadOnlyTest, fileHandleAttribute);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CommonTest, index, fileHandleAttribute);
    }
}

void System::CreateFileWithAttributesTesting::ReadOnlyTest(FileHandleAttributes fileHandleAttribute)
{
    constexpr auto fileHandleDesiredAccess = FileHandleDesiredAccess::Read;
    constexpr auto fileHandleShareMode = FileHandleShareMode::ShareRead;
    constexpr auto fileHandleCreationDisposition = FileHandleCreationDisposition::OpenAlways;
    constexpr auto fileHandleOther = FileHandleOther::SequentialScan;
    constexpr auto fileHandleSecurity = FileHandleSecurity::Default;

    const auto fileHandle = CreateSystemFile(onlyReadFile,
                                             fileHandleDesiredAccess,
                                             fileHandleShareMode,
                                             nullptr,
                                             fileHandleCreationDisposition,
                                             fileHandleAttribute,
                                             fileHandleOther,
                                             fileHandleSecurity,
                                             nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);
}

void System::CreateFileWithAttributesTesting::CommonTest(size_t index, FileHandleAttributes fileHandleAttribute)
{
    const auto fileHandleCreationDisposition = GetFileHandleCreationDisposition(index);

    if (fileHandleCreationDisposition == FileHandleCreationDisposition::OpenExisting ||
        fileHandleCreationDisposition == FileHandleCreationDisposition::TruncateExisting)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(ExistingTest, index, fileHandleAttribute, fileHandleCreationDisposition);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_3(NonExistentTest, index, fileHandleAttribute, fileHandleCreationDisposition);
    }
}

void System::CreateFileWithAttributesTesting::ExistingTest(size_t index, FileHandleAttributes fileHandleAttribute, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto fileHandleOther = GetFileHandleOther(index);

    if (fileHandleOther == FileHandleOther::DeleteOnClose)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(NonExistentTest, index, fileHandleAttribute, FileHandleCreationDisposition::CreateNew);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoExistingTest, index, fileHandleAttribute, fileHandleCreationDisposition);
    }
}

void System::CreateFileWithAttributesTesting::DoExistingTest(size_t index, FileHandleAttributes fileHandleAttribute, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto fileHandleShareMode = GetFileHandleShareMode(index);
    const auto fileHandleOther = GetFileHandleOther(index);
    const auto fileHandleSecurity = GetFileHandleSecurity(index);
    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index, fileHandleCreationDisposition);

    const auto fileHandle = CreateSystemFile(onlyReadFile,
                                             fileHandleDesiredAccess,
                                             fileHandleShareMode,
                                             nullptr,
                                             fileHandleCreationDisposition,
                                             fileHandleAttribute,
                                             fileHandleOther,
                                             fileHandleSecurity,
                                             nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);
}

void System::CreateFileWithAttributesTesting::NonExistentTest(size_t index, FileHandleAttributes fileHandleAttribute, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto createFileName = GetCreateFileName(index);

    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index);
    const auto fileHandleShareMode = GetFileHandleShareMode(index);
    const auto fileHandleOther = GetFileHandleOther(index);
    const auto fileHandleSecurity = GetFileHandleSecurity(index);

    const auto fileHandle = CreateSystemFile(createFileName,
                                             fileHandleDesiredAccess,
                                             fileHandleShareMode,
                                             nullptr,
                                             fileHandleCreationDisposition,
                                             fileHandleAttribute,
                                             fileHandleOther,
                                             fileHandleSecurity,
                                             nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);

    if (fileHandleOther != FileHandleOther::DeleteOnClose)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(RemoveFile, createFileName);
    }
}

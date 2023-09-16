///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:20)

#include "CreateFileWithDefaultAttributesTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileWithDefaultAttributesTesting::CreateFileWithDefaultAttributesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileWithDefaultAttributesTesting)

void System::CreateFileWithDefaultAttributesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileWithDefaultAttributesTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateFileWithDefaultAttributesTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomFileHandleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileTest);

    return true;
}

void System::CreateFileWithDefaultAttributesTesting::CreateFileTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateFileTest, index);
    }
}

void System::CreateFileWithDefaultAttributesTesting::DoCreateFileTest(size_t index)
{
    if (const auto fileHandleCreationDisposition = GetFileHandleCreationDisposition(index);
        fileHandleCreationDisposition != FileHandleCreationDisposition::OpenExisting &&
        fileHandleCreationDisposition != FileHandleCreationDisposition::TruncateExisting)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(NonExistentTest, index, fileHandleCreationDisposition);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(ExistingTest, index, fileHandleCreationDisposition);
    }
}

void System::CreateFileWithDefaultAttributesTesting::ExistingTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto createFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    const auto fileHandleShareMode = GetFileHandleShareMode(index);

    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index, fileHandleCreationDisposition);

    const auto fileHandle = CreateSystemFile(createFileName, fileHandleDesiredAccess, fileHandleShareMode, fileHandleCreationDisposition);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);
}

void System::CreateFileWithDefaultAttributesTesting::NonExistentTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition)
{
    const auto createFileName = GetCreateFileName(index);

    const auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index);
    const auto fileHandleShareMode = GetFileHandleShareMode(index);

    const auto fileHandle = CreateSystemFile(createFileName, fileHandleDesiredAccess, fileHandleShareMode, fileHandleCreationDisposition);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(RemoveFile, createFileName);
}

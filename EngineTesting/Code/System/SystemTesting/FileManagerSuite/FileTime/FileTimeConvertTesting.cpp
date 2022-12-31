///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 22:08)

#include "FileTimeConvertTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/FileTime.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/FileManager/Flags/FileTimeFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::FileTimeConvertTesting::FileTimeConvertTesting(const OStreamShared& stream)
    : ParentType{ stream }, existingFileName{ SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileTimeConvertTesting)

void System::FileTimeConvertTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileTimeConvertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileTimeTest);
}

void System::FileTimeConvertTesting::FileTimeTest()
{
    auto handle = CreateSystemFile(existingFileName, FileHandleDesiredAccess::Write, FileHandleShareMode::ShareWrite, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(DoFileTimeTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::FileTimeConvertTesting::DoFileTimeTest(WindowsHandle handle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    FileTime creationTime{};
    FileTime lastAccessTime{};
    FileTime lastWriteTime{};
    ASSERT_TRUE(GetSystemFileTime(handle, &creationTime, &lastAccessTime, &lastWriteTime));

    FileTime localFileTime{};
    ASSERT_TRUE(FileTimeConvertLocalFileTime(&creationTime, &localFileTime));

    FileTime fileTime{};
    ASSERT_TRUE(LocalFileTimeConvertFileTime(&localFileTime, &fileTime));

    ASSERT_NOT_THROW_EXCEPTION_2(ResultTest, creationTime, fileTime);
}

void System::FileTimeConvertTesting::ResultTest(const FileTime& creationTime, const FileTime& fileTime)
{
    ASSERT_EQUAL(creationTime.dwLowDateTime, fileTime.dwLowDateTime);
    ASSERT_EQUAL(creationTime.dwHighDateTime, fileTime.dwHighDateTime);
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/15 22:12)

#include "FileTimeTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/FileTime.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/FileManager/Flags/FileTimeFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::FileTimeTesting::FileTimeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      existingFileName{ SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s) },
      creationTime{},
      lastAccessTime{},
      lastWriteTime{}
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileTimeTesting)

void System::FileTimeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileTimeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileTimeTest);
}

void System::FileTimeTesting::FileTimeTest()
{
    const auto handle = CreateSystemFile(existingFileName, FileHandleDesiredAccess::Write, FileHandleShareMode::ShareWrite, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(DoFileTimeTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::FileTimeTesting::DoFileTimeTest(WindowsHandle handle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    ASSERT_TRUE(GetSystemFileTime(handle, &creationTime, &lastAccessTime, &lastWriteTime));

    ASSERT_NOT_THROW_EXCEPTION_1(SetSystemFileTimeTest, handle);

    FileTime newCreationTime{};
    FileTime newLastAccessTime{};
    FileTime newLastWriteTime{};

    ASSERT_TRUE(GetSystemFileTime(handle, &newCreationTime, &newLastAccessTime, &newLastWriteTime));

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest, newCreationTime, newLastAccessTime, newLastWriteTime);
}

void System::FileTimeTesting::SetSystemFileTimeTest(WindowsHandle handle)
{
    ++creationTime.dwLowDateTime;
    ++creationTime.dwHighDateTime;
    ++lastAccessTime.dwLowDateTime;
    ++lastAccessTime.dwHighDateTime;
    ++lastWriteTime.dwLowDateTime;
    ++lastWriteTime.dwHighDateTime;
    ASSERT_TRUE(SetSystemFileTime(handle, &creationTime, &lastAccessTime, &lastWriteTime));
}

void System::FileTimeTesting::ResultTest(const FileTime& newCreationTime, const FileTime& newLastAccessTime, const FileTime& newLastWriteTime)
{
    ASSERT_EQUAL(creationTime.dwHighDateTime, newCreationTime.dwHighDateTime);
    ASSERT_EQUAL(lastAccessTime.dwHighDateTime, newLastAccessTime.dwHighDateTime);
    ASSERT_EQUAL(lastWriteTime.dwHighDateTime, newLastWriteTime.dwHighDateTime);

    ASSERT_EQUAL(creationTime.dwLowDateTime, newCreationTime.dwLowDateTime);
    ASSERT_EQUAL(lastAccessTime.dwLowDateTime, newLastAccessTime.dwLowDateTime);
    ASSERT_EQUAL(lastWriteTime.dwLowDateTime, newLastWriteTime.dwLowDateTime);
}

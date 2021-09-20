///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/24 15:40)

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
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileTimeTesting)

void System::FileTimeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileTimeTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileTimeTest);
}

void System::FileTimeTesting ::FileTimeTest()
{
    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);
    auto handle = CreateSystemFile(existingFileName, FileHandleDesiredAccess::Write, FileHandleShareMode::ShareWrite, FileHandleCreationDisposition::CreateAlways);
    ASSERT_TRUE(IsFileHandleValid(handle));

    FileTime creationTime{};
    FileTime lastAccessTime{};
    FileTime lastWriteTime{};

    ASSERT_TRUE(GetSystemFileTime(handle, &creationTime, &lastAccessTime, &lastWriteTime));

    ASSERT_TRUE(SetSystemFileTime(handle, &lastAccessTime, &lastWriteTime, &creationTime));

    FileTime newCreationTime{};
    FileTime newLastAccessTime{};
    FileTime newLastWriteTime{};

    ASSERT_TRUE(GetSystemFileTime(handle, &newCreationTime, &newLastAccessTime, &newLastWriteTime));

    ASSERT_EQUAL(lastAccessTime.dwHighDateTime, newCreationTime.dwHighDateTime);
    ASSERT_EQUAL(lastWriteTime.dwHighDateTime, newLastAccessTime.dwHighDateTime);
    ASSERT_EQUAL(creationTime.dwHighDateTime, newLastWriteTime.dwHighDateTime);

    ASSERT_EQUAL(lastAccessTime.dwLowDateTime, newCreationTime.dwLowDateTime);
    ASSERT_EQUAL(lastWriteTime.dwLowDateTime, newLastAccessTime.dwLowDateTime);
    ASSERT_EQUAL(creationTime.dwLowDateTime, newLastWriteTime.dwLowDateTime);

    ASSERT_TRUE(CloseSystemFile(handle));
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/15 21:49)

#include "FileTimeCompareTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/FileTime.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/FileManager/Flags/FileTimeFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::FileTimeCompareTesting::FileTimeCompareTesting(const OStreamShared& stream)
    : ParentType{ stream }, existingFileName{ SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileTimeCompareTesting)

void System::FileTimeCompareTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileTimeCompareTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileTimeTest);
}

void System::FileTimeCompareTesting::FileTimeTest()
{
    const auto handle = CreateSystemFile(existingFileName, FileHandleDesiredAccess::Write, FileHandleShareMode::ShareWrite, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(DoFileTimeTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::FileTimeCompareTesting::DoFileTimeTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));

    FileTime creationTime{};
    FileTime lastAccessTime{};
    FileTime lastWriteTime{};           
    ASSERT_TRUE(GetSystemFileTime(handle, &creationTime, &lastAccessTime, &lastWriteTime));

    ASSERT_ENUM_EQUAL(FileTimeCompare(&lastAccessTime, &lastAccessTime), ComparesFileTimeReturn::Equal);
      
    auto newLastWriteTime = lastAccessTime;
    ++newLastWriteTime.dwHighDateTime;

    ASSERT_ENUM_EQUAL(FileTimeCompare(&lastAccessTime, &newLastWriteTime), ComparesFileTimeReturn::Earlier);
    ASSERT_ENUM_EQUAL(FileTimeCompare(&newLastWriteTime, &lastAccessTime), ComparesFileTimeReturn::Later);
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:02)

#include "CreateDirectoryTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/FileTools.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateDirectoryTesting::CreateDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream },
      directoryName{ SYSTEM_TEXT("Resource/NewDirectory") },
      fileName{ directoryName + SYSTEM_TEXT("/CreateDirectory.txt") },
      recursionDirectoryName{ SYSTEM_TEXT("Resource/NewDirectory/NewDirectory") },
      recursionFileName{ recursionDirectoryName + SYSTEM_TEXT("/CreateDirectory.txt") }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateDirectoryTesting)

void System::CreateDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateDirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateDirectoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveDirectoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileFailTest);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionFileFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionDirectoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionFileSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveRecursionDirectoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionFileFailTest);
}

void System::CreateDirectoryTesting::CreateFileFailTest()
{
    const auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_FALSE(IsFileHandleValid(handle));
}

void System::CreateDirectoryTesting::CreateDirectoryTest()
{
    ASSERT_TRUE(CreateFileDirectory(directoryName, nullptr));
}

void System::CreateDirectoryTesting::CreateFileSuccessTest()
{
    const auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::CreateDirectoryTesting::RemoveDirectoryTest()
{
    ASSERT_TRUE(RemoveSystemFile(fileName));

    ASSERT_TRUE(DeleteFileDirectory(directoryName.c_str()));
}

void System::CreateDirectoryTesting::RemoveRecursionDirectoryTest()
{
    #ifdef SYSTEM_PLATFORM_LINUX

    RecursionDeleteFileDirectory(directoryName);

    #else // !SYSTEM_PLATFORM_LINUX

    RecursionDeleteFileDirectory(CoreTools::StringConversion::StandardConversionWideChar(directoryName));

    #endif  // SYSTEM_PLATFORM_LINUX


    ASSERT_TRUE(DeleteFileDirectory(directoryName.c_str()));
}

void System::CreateDirectoryTesting::CreateRecursionDirectoryTest() const noexcept
{
    CreateFileDirectory(directoryName);
    CreateFileDirectory(recursionDirectoryName);
}

void System::CreateDirectoryTesting::CreateRecursionFileFailTest()
{
    const auto handle = CreateSystemFile(recursionFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_FALSE(IsFileHandleValid(handle));
}

void System::CreateDirectoryTesting::CreateRecursionFileSuccessTest()
{
    const auto handle = CreateSystemFile(recursionFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}
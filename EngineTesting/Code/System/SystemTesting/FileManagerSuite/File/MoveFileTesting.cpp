/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:26)

#include "MoveFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MoveFileTesting::MoveFileTesting(const OStreamShared& stream)
    : ParentType{ stream },
      oldName{ SYSTEM_TEXT("Resource/FileTesting/Change.txt") },
      newName{ SYSTEM_TEXT("Resource/FileTesting/NewChange.txt") }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MoveFileTesting)

void System::MoveFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MoveFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MoveFileTest);
}

void System::MoveFileTesting::MoveFileTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateAlwaysTest);

    ASSERT_TRUE(MoveSystemFile(oldName, newName));

    ASSERT_NOT_THROW_EXCEPTION_0(MoveSuccessTest);

    ASSERT_NOT_THROW_EXCEPTION_0(RemoveFileTest);
}

void System::MoveFileTesting::CreateAlwaysTest()
{
    const auto handle = CreateSystemFile(oldName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::MoveFileTesting::MoveSuccessTest()
{
    const auto invalidHandle = CreateSystemFile(oldName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(invalidHandle));

    const auto validHandle = CreateSystemFile(newName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, validHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, validHandle);
}

void System::MoveFileTesting::RemoveFileTest()
{
    ASSERT_TRUE(RemoveSystemFile(newName));

    const auto handle = CreateSystemFile(newName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(handle));
}

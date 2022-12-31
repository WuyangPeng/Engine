///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/14 17:43)

#include "MoveFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::MoveFileTesting::MoveFileTesting(const OStreamShared& stream)
    : ParentType{ stream },
      oldName{ SYSTEM_TEXT("Resource/FileTesting/Change.txt"s) },
      newName{ SYSTEM_TEXT("Resource/FileTesting/NewChange.txt"s) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

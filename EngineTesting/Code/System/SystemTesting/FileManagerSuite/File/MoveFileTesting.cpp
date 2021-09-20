///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 10:47)

#include "MoveFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::MoveFileTesting::MoveFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    const auto oldName = SYSTEM_TEXT("Resource/FileTesting/Change.txt"s);
    const auto newName = SYSTEM_TEXT("Resource/FileTesting/NewChange.txt"s);

    auto handle = CreateSystemFile(oldName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_TRUE(IsFileHandleValid(handle));
    ASSERT_TRUE(CloseSystemFile(handle));

    ASSERT_TRUE(MoveSystemFile(oldName, newName));

    handle = CreateSystemFile(newName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));
    ASSERT_TRUE(CloseSystemFile(handle));

    handle = CreateSystemFile(oldName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(handle));

    ASSERT_TRUE(RemoveSystemFile(newName));

    handle = CreateSystemFile(newName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(handle));
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 11:26)

#include "DirectoryTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DirectoryTesting::DirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DirectoryTesting)

void System::DirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DirectoryTest);
}

void System::DirectoryTesting::DirectoryTest()
{
    const auto rootDirectory = CreateSystemFile(SYSTEM_TEXT("Resource"),
                                                FileHandleDesiredAccess::Read,
                                                FileHandleShareMode::ShareRead,
                                                FileHandleCreationDisposition::OpenExisting,
                                                FileHandleAttribute::Directory,
                                                FileHandleOther::BackupSemantics,
                                                FileHandleSecurity::Default);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, rootDirectory);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, rootDirectory);
}
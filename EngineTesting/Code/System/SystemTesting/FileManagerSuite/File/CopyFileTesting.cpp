///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:22)

#include "CopyFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CopyFileTesting::CopyFileTesting(const OStreamShared& stream)
    : ParentType{ stream },
      fileName{ SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt") },
      copyFileName{ SYSTEM_TEXT("Resource/FileTesting/CopyFileTestingText.txt") }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CopyFileTesting)

void System::CopyFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CopyFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnsureFileNotExist);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyFileTest);
}

void System::CopyFileTesting::EnsureFileNotExist()
{
    MAYBE_UNUSED const auto result = RemoveSystemFile(copyFileName);

    const auto handle = CreateSystemFile(copyFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(handle));
}

void System::CopyFileTesting::CopyFileTest()
{
    ASSERT_TRUE(CopySystemFile(fileName, copyFileName));
    ASSERT_FALSE(CopySystemFile(fileName, copyFileName, true));

    ASSERT_NOT_THROW_EXCEPTION_0(CopyFileResultTest);

    ASSERT_TRUE(CopySystemFile(fileName, copyFileName, false));

    ASSERT_NOT_THROW_EXCEPTION_0(CopyFileResultTest);
}

void System::CopyFileTesting::CopyFileResultTest()
{
    const auto handle = CreateSystemFile(copyFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);
    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(RemoveFile, copyFileName);
}

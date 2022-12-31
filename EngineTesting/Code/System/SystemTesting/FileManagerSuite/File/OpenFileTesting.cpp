///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 0:54)

#include "OpenFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::OpenFileTesting::OpenFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenFileTesting)

void System::OpenFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenValidFileTest);
}

void System::OpenFileTesting::OpenValidFileTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);

    const auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);
    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::OpenFileTesting::OpenInvalidFileTest()
{
    const auto fileErrorName = SYSTEM_TEXT("Resource/FileTesting/ErrorFileTestingText.txt"s);

    const auto handle = CreateSystemFile(fileErrorName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(handle));
}

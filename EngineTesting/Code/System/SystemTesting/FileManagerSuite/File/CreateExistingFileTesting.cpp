///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/12 23:38)

#include "CreateExistingFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateExistingFileTesting::CreateExistingFileTesting(const OStreamShared& stream)
    : ParentType{ stream }, existingFileName{ SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateExistingFileTesting)

void System::CreateExistingFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateExistingFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateExistingFileTest);
}

void System::CreateExistingFileTesting::CreateExistingFileTest()
{
    const auto handle = CreateSystemFile(existingFileName,
                                         FileHandleDesiredAccess::Read,
                                         FileHandleShareMode::ShareRead,
                                         FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

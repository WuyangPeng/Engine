///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/14 17:27)

#include "DirectoryTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::DirectoryTesting::DirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    const auto rootDirectory = CreateSystemFile(SYSTEM_TEXT("Resource"s),
                                                FileHandleDesiredAccess::Read,
                                                FileHandleShareMode::ShareRead,
                                                FileHandleCreationDisposition::OpenExisting,
                                                FileHandleAttributes::Directory,
                                                FileHandleOther::BackupSemantics,
                                                FileHandleSecurity::Default);

    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, rootDirectory);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, rootDirectory);
}
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/29 19:59)

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
    auto rootDirectory = CreateSystemFile(SYSTEM_TEXT("Resource"s),
                                          FileHandleDesiredAccess::Read,
                                          FileHandleShareMode::ShareRead,
                                          FileHandleCreationDisposition::OpenExisting,
                                          FileHandleAttributes::Directory,
                                          FileHandleOther::BackupSemantics,
                                          FileHandleSecurity::Default);
    ASSERT_TRUE(IsFileHandleValid(rootDirectory));

    ASSERT_TRUE(CloseSystemFile(rootDirectory));
}
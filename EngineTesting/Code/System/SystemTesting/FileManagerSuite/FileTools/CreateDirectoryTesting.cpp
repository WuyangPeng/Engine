///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/29 20:00)

#include "CreateDirectoryTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/FileTools.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateDirectoryTesting::CreateDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateDirectoryTesting)

void System::CreateDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateDirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateDirectoryTest);
}

void System::CreateDirectoryTesting::CreateDirectoryTest()
{
    const auto directoryName = SYSTEM_TEXT("Resource/NewDirectory"s);
    const auto fileName = directoryName + SYSTEM_TEXT("/CreateDirectory.txt"s);

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_FALSE(IsFileHandleValid(handle));

    ASSERT_TRUE(CreateFileDirectory(directoryName, nullptr));

    handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_TRUE(IsFileHandleValid(handle));
    ASSERT_TRUE(CloseSystemFile(handle));

    ASSERT_TRUE(RemoveSystemFile(fileName));

    ASSERT_TRUE(RemoveSystemDirectory(directoryName.c_str()));

    handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::CreateAlways);

    ASSERT_FALSE(IsFileHandleValid(handle));
}

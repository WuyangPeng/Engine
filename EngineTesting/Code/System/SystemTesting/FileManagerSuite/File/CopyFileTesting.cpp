///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/20 16:43)

#include "CopyFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CopyFileTesting::CopyFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_NOT_THROW_EXCEPTION_0(CopyFileTest);
}

void System::CopyFileTesting::CopyFileTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto copyFileName = SYSTEM_TEXT("Resource/FileTesting/CopyFileTestingText.txt"s);

    auto handle = CreateSystemFile(copyFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(handle));

    ASSERT_TRUE(CopySystemFile(fileName, copyFileName));
    ASSERT_FALSE(CopySystemFile(fileName, copyFileName, true));

    handle = CreateSystemFile(copyFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));
    ASSERT_TRUE(CloseSystemFile(handle));

    ASSERT_TRUE(RemoveSystemFile(copyFileName));

    ASSERT_TRUE(CopySystemFile(fileName, copyFileName, false));

    handle = CreateSystemFile(copyFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));
    ASSERT_TRUE(CloseSystemFile(handle));

    ASSERT_TRUE(RemoveSystemFile(copyFileName));
}
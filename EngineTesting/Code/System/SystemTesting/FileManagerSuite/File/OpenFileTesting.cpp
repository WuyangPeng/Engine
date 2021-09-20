///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 13:34)

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
    ASSERT_NOT_THROW_EXCEPTION_0(OpenFileTest);
}

void System::OpenFileTesting::OpenFileTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto fileErrorName = SYSTEM_TEXT("Resource/FileTesting/ErrorFileTestingText.txt"s);

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));
    ASSERT_TRUE(CloseSystemFile(handle));

    handle = CreateSystemFile(fileErrorName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_FALSE(IsFileHandleValid(handle));
}
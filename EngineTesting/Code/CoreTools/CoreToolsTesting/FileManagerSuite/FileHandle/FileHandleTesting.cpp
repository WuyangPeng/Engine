/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 17:01)

#include "FileHandleTesting.h"
#include "CoreTools/FileManager/ReadAndWriteFileHandle.h"
#include "CoreTools/FileManager/ReadFileHandle.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

System::String CoreTools::FileHandleTesting::GetFileHandleFileName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/FileHandleTestingText.txt");
}

CoreTools::FileHandleTesting::FileHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileHandleTesting)

void CoreTools::FileHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileHandleTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(InExistenceFileTest);
    ASSERT_THROW_EXCEPTION_0(CannotOpenWriteFileHandleTest);
    ASSERT_THROW_EXCEPTION_0(CannotOpenReadAndWriteFileHandleTest);
}

void CoreTools::FileHandleTesting::InExistenceFileTest()
{
    const auto inExistenceFileName = SYSTEM_TEXT("Resource/FileHandleTesting/InexistenceFile.txt");

    ReadFileHandle inExistenceFile{ inExistenceFileName };
}

void CoreTools::FileHandleTesting::CannotOpenWriteFileHandleTest()
{
    const auto fileHandleFileName = GetFileHandleFileName();

    WriteFileHandle handle0{ fileHandleFileName };
    WriteFileHandle handle1{ fileHandleFileName };
}

void CoreTools::FileHandleTesting::CannotOpenReadAndWriteFileHandleTest()
{
    const auto fileHandleFileName = GetFileHandleFileName();

    ReadAndWriteFileHandle handle0{ fileHandleFileName };
    ReadAndWriteFileHandle handle1{ fileHandleFileName };
}

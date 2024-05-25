/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/02 22:51)

#include "ReadAndWriteFileHandleTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadAndWriteFileHandle.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

CoreTools::ReadAndWriteFileHandleTesting::ReadAndWriteFileHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReadAndWriteFileHandleTesting)

void CoreTools::ReadAndWriteFileHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ReadAndWriteFileHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClearFile);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileByteSizeTest);
}

System::String CoreTools::ReadAndWriteFileHandleTesting::GetFileHandleName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/ReadAndWriteFileHandleTestingText.txt");
}

std::string CoreTools::ReadAndWriteFileHandleTesting::GetFileHandleContent()
{
    return "FileHandle Testing Text";
}

void CoreTools::ReadAndWriteFileHandleTesting::ClearFile()
{
    WriteFileHandle handle{ GetFileHandleName() };
}

void CoreTools::ReadAndWriteFileHandleTesting::WriteFileHandleTest()
{
    ReadAndWriteFileHandle handle{ GetFileHandleName() };

    const auto content = GetFileHandleContent();

    const auto size = content.size();
    handle.Write(sizeof(decltype(size)), &size);

    handle.Write(sizeof(char), size, content.data());
}

void CoreTools::ReadAndWriteFileHandleTesting::ReadFileHandleTest()
{
    const auto content = GetFileHandleContent();
    ReadAndWriteFileHandle manager{ GetFileHandleName() };

    const auto size = GetSize(content, manager);

    ASSERT_NOT_THROW_EXCEPTION_3(ReadResultTest, content, manager, size);
}

size_t CoreTools::ReadAndWriteFileHandleTesting::GetSize(const std::string& content, ReadAndWriteFileHandle& manager)
{
    size_t size{ 0 };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    return size;
}

void CoreTools::ReadAndWriteFileHandleTesting::ReadResultTest(const std::string& content, ReadAndWriteFileHandle& manager, size_t size)
{
    BufferType buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string result{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(result, content);
}

void CoreTools::ReadAndWriteFileHandleTesting::GetFileByteSizeTest()
{
    const auto content = GetFileHandleContent();

    const ReadAndWriteFileHandle handle{ GetFileHandleName() };

    ASSERT_EQUAL(handle.GetFileLength(), content.size() + sizeof(size_t));
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/03 22:55)

#include "ReadFileHandleTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadFileHandle.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

CoreTools::ReadFileHandleTesting::ReadFileHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReadFileHandleTesting)

void CoreTools::ReadFileHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ReadFileHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileByteSizeTest);
}

System::String CoreTools::ReadFileHandleTesting::GetFileHandleName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/ReadFileHandleTestingText.txt");
}

std::string CoreTools::ReadFileHandleTesting::GetFileHandleContent()
{
    return "FileHandle Testing Text";
}

void CoreTools::ReadFileHandleTesting::WriteFileHandleTest()
{
    WriteFileHandle handle{ GetFileHandleName() };

    const auto content = GetFileHandleContent();

    const auto size = content.size();
    handle.Write(sizeof(decltype(size)), &size);

    handle.Write(sizeof(char), size, content.data());
}

void CoreTools::ReadFileHandleTesting::ReadFileHandleTest()
{
    const auto content = GetFileHandleContent();
    ReadFileHandle manager{ GetFileHandleName() };

    const auto size = GetSize(content, manager);

    ASSERT_NOT_THROW_EXCEPTION_3(ReadResultTest, content, manager, size);
}

size_t CoreTools::ReadFileHandleTesting::GetSize(const std::string& content, ReadFileHandle& manager)
{
    size_t size{ 0 };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    return size;
}

void CoreTools::ReadFileHandleTesting::ReadResultTest(const std::string& content, ReadFileHandle& manager, size_t size)
{
    BufferType buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string result{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(result, content);
}

void CoreTools::ReadFileHandleTesting::GetFileByteSizeTest()
{
    const auto content = GetFileHandleContent();

    const ReadFileHandle handle{ GetFileHandleName() };

    ASSERT_EQUAL(handle.GetFileByteSize(), boost::numeric_cast<int>(content.size() + sizeof(size_t)));
}

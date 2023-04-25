///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:44)

#include "ReadAndWriteFileHandleTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadAndWriteFileHandle.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

using namespace std::literals;

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

    size_t size{ 0 };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    std::vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}

System::String CoreTools::ReadAndWriteFileHandleTesting::GetFileHandleName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/ReadAndWriteFileHandleTestingText.txt"s);
}

std::string CoreTools::ReadAndWriteFileHandleTesting::GetFileHandleContent()
{
    return "FileHandle Testing Text"s;
}

void CoreTools::ReadAndWriteFileHandleTesting::GetFileByteSizeTest()
{
    const ReadAndWriteFileHandle handle{ GetFileHandleName() };

    ASSERT_EQUAL(handle.GetFileLength(), GetFileHandleContent().size() + sizeof(size_t));
}

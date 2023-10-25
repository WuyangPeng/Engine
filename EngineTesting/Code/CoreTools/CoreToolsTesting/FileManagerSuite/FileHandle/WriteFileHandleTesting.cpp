///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:28)

#include "WriteFileHandleTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadFileHandle.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

using namespace std::literals;

CoreTools::WriteFileHandleTesting::WriteFileHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WriteFileHandleTesting)

void CoreTools::WriteFileHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WriteFileHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteResultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileByteSizeTest);
}

void CoreTools::WriteFileHandleTesting::WriteFileHandleTest()
{
    WriteFileHandle handle{ GetFileHandleName() };

    const auto content = GetFileHandleContent();

    const auto size = content.size();
    handle.Write(sizeof(decltype(size)), &size);

    handle.Write(sizeof(char), size, content.data());
}

void CoreTools::WriteFileHandleTesting::WriteResultTest()
{
    const auto content = GetFileHandleContent();
    ReadFileHandle manager{ GetFileHandleName() };

    size_t size{ 0 };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    std::vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}

System::String CoreTools::WriteFileHandleTesting::GetFileHandleName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/WriteFileHandleTestingText.txt"s);
}

std::string CoreTools::WriteFileHandleTesting::GetFileHandleContent()
{
    return "FileHandle Testing Text"s;
}

void CoreTools::WriteFileHandleTesting::GetFileByteSizeTest()
{
    const WriteFileHandle handle{ GetFileHandleName(), System::FileHandleCreationDisposition::OpenExisting };

    ASSERT_EQUAL(handle.GetFileByteSize(), boost::numeric_cast<int>(GetFileHandleContent().size() + sizeof(size_t)));
}

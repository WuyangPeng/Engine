///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/06 18:04)

#include "ReadAndWriteFileHandleTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadAndWriteFileHandle.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
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

    vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}

System::String CoreTools::ReadAndWriteFileHandleTesting::GetFileHandleName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/ReadAndWriteFileHandleTestingText.txt"s);
}

string CoreTools::ReadAndWriteFileHandleTesting::GetFileHandleContent()
{
    return "FileHandle Testing Text"s;
}

void CoreTools::ReadAndWriteFileHandleTesting::GetFileByteSizeTest()
{
    ReadAndWriteFileHandle handle{ GetFileHandleName() };

    ASSERT_EQUAL(handle.GetFileLength(), GetFileHandleContent().size() + sizeof(size_t));
}
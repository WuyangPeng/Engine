/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 17:08)

#include "WriteFileManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

CoreTools::WriteFileManagerTesting::WriteFileManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WriteFileManagerTesting)

void CoreTools::WriteFileManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WriteFileManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteResultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileByteSizeTest);
}

System::String CoreTools::WriteFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/FileManagerTesting/WriteFileManagerTestingText.txt");
}

std::string CoreTools::WriteFileManagerTesting::GetFileContent()
{
    return "WriteFileManager Testing Text";
}

void CoreTools::WriteFileManagerTesting::WriteFileHandleTest()
{
    WriteFileManager manager{ GetFileName() };

    const auto content = GetFileContent();

    ASSERT_NOT_THROW_EXCEPTION_2(WriteSizeTest, manager, content);
    ASSERT_NOT_THROW_EXCEPTION_2(SaveStdStringTest, manager, content);
}

void CoreTools::WriteFileManagerTesting::WriteSizeTest(WriteFileManager& manager, const std::string& content)
{
    const auto size = content.size();
    manager.Write(sizeof(decltype(size)), &size);

    manager.Write(sizeof(char), size, content.data());
}

void CoreTools::WriteFileManagerTesting::SaveStdStringTest(WriteFileManager& manager, const std::string& content)
{
    manager.SaveStdString(content);
}

void CoreTools::WriteFileManagerTesting::WriteResultTest()
{
    const auto content = GetFileContent();
    ReadFileManager manager{ GetFileName() };

    const auto size = GetReadSize(manager, content);

    ASSERT_NOT_THROW_EXCEPTION_3(ReadResultTest, manager, content, size);
    ASSERT_NOT_THROW_EXCEPTION_2(LoadStdStringTest, manager, content);
}

size_t CoreTools::WriteFileManagerTesting::GetReadSize(ReadFileManager& manager, const std::string& content)
{
    size_t size{ 0u };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    return size;
}

void CoreTools::WriteFileManagerTesting::ReadResultTest(ReadFileManager& manager, const std::string& content, size_t size)
{
    BufferType buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string result{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(result, content);
}

void CoreTools::WriteFileManagerTesting::LoadStdStringTest(ReadFileManager& manager, const std::string& content)
{
    const auto stdString = manager.LoadStdString();
    ASSERT_EQUAL(stdString, content);
}

void CoreTools::WriteFileManagerTesting::GetFileByteSizeTest()
{
    const WriteFileManager manager{ GetFileName(), true };
    const auto fineContent = GetFileContent();

    ASSERT_EQUAL(manager.GetFileByteSize(), boost::numeric_cast<int>(fineContent.size() + sizeof(size_t) + CoreTools::GetStreamSize(fineContent)));
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:45)

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

using namespace std::literals;

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

void CoreTools::WriteFileManagerTesting::WriteFileHandleTest()
{
    WriteFileManager manager{ GetFileName() };

    const auto content = GetFileContent();

    const auto size = content.size();
    manager.Write(sizeof(decltype(size)), &size);

    manager.Write(sizeof(char), size, content.data());

    manager.SaveStdString(content);
}

void CoreTools::WriteFileManagerTesting::WriteResultTest()
{
    const auto content = GetFileContent();
    ReadFileManager manager{ GetFileName() };

    size_t size{ 0u };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    std::vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);

    const auto stdString = manager.LoadStdString();
    ASSERT_EQUAL(stdString, content);
}

void CoreTools::WriteFileManagerTesting::GetFileByteSizeTest()
{
    const WriteFileManager manager{ GetFileName(), true };
    const auto fineContent = GetFileContent();

    ASSERT_EQUAL(manager.GetFileByteSize(), boost::numeric_cast<int>(fineContent.size() + sizeof(size_t) + CoreTools::GetStreamSize(fineContent)));
}

System::String CoreTools::WriteFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/FileManagerTesting/WriteFileManagerTestingText.txt"s);
}

std::string CoreTools::WriteFileManagerTesting::GetFileContent()
{
    return "WriteFileManager Testing Text"s;
}

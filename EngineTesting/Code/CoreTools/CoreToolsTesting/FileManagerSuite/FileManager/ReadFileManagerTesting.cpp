///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/07 13:45)

#include "ReadFileManagerTesting.h"
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

using std::string;
using std::vector;
using namespace std::literals;

CoreTools::ReadFileManagerTesting::ReadFileManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReadFileManagerTesting)

void CoreTools::ReadFileManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ReadFileManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileByteSizeTest);
}
 
void CoreTools::ReadFileManagerTesting::WriteFileManagerTest()
{
    WriteFileManager manager{ GetFileName() };

    const auto content = GetFileContent();

    const auto size = content.size();
    manager.Write(sizeof(decltype(size)), &size);

    manager.Write(sizeof(char), size, content.data());

    manager.SaveStdString(content);
}

void CoreTools::ReadFileManagerTesting::ReadFileManagerTest()
{
    const auto content = GetFileContent();
    ReadFileManager manager{ GetFileName() };

    size_t size{ 0 };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, content.size());

    vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);

    const auto stdString = manager.LoadStdString();
    ASSERT_EQUAL(stdString, content);
}

void CoreTools::ReadFileManagerTesting::GetFileByteSizeTest()
{
    ReadFileManager manager{ GetFileName() };
    const auto fineContent = GetFileContent();

    ASSERT_EQUAL(manager.GetFileByteSize(), boost::numeric_cast<int>(fineContent.size() + sizeof(size_t) + CoreTools::GetStreamSize(fineContent)));
}

System::String CoreTools::ReadFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/FileManagerTesting/ReadFileManagerTestingText.txt"s);
}

std::string CoreTools::ReadFileManagerTesting::GetFileContent()
{
    return "ReadFileManager Testing Text"s;
}

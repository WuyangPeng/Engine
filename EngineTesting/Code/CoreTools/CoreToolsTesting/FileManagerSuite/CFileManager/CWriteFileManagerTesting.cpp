///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:58)

#include "CWriteFileManagerTesting.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CReadFileManager.h"
#include "CoreTools/FileManager/CWriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace std::literals;

CoreTools::CWriteFileManagerTesting::CWriteFileManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CWriteFileManagerTesting)

void CoreTools::CWriteFileManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CWriteFileManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CWriteFileManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteResultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileByteSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PutTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PutWriteResultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PositionTest);
}

void CoreTools::CWriteFileManagerTesting::CWriteFileManagerTest()
{
    const auto cFileManagerContent = GetFileManagerContent();
    CWriteFileManager manager{ GetFileName() };

    const auto size = cFileManagerContent.size();
    manager.Write(sizeof(decltype(size)), &size);

    manager.Write(sizeof(char), size, cFileManagerContent.c_str());
}

void CoreTools::CWriteFileManagerTesting::WriteResultTest()
{
    const auto cFileManagerContent = GetFileManagerContent();
    CReadFileManager manager{ GetFileName() };

    size_t size{ 0 };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, cFileManagerContent.size());

    vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, cFileManagerContent);
}

System::String CoreTools::CWriteFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/CFileManagerTesting/CWriteFileManagerTestingText.txt"s);
}

string CoreTools::CWriteFileManagerTesting::GetFileManagerContent()
{
    return "CFileManager Testing Text"s;
}

void CoreTools::CWriteFileManagerTesting::GetFileByteSizeTest()
{
    const auto cFileManagerContent = GetFileManagerContent();
    CWriteFileManager manager{ GetFileName(), true };

    const auto size = cFileManagerContent.size();

    ASSERT_EQUAL(manager.GetFileByteSize(), size + sizeof(decltype(size)));
}

void CoreTools::CWriteFileManagerTesting::PutTest()
{
    const auto cFileManagerContent = GetFileManagerContent();
    CWriteFileManager manager{ GetFileName(), true };

    ASSERT_TRUE(manager.PutCharacter('a'));
    ASSERT_TRUE(manager.PutString(cFileManagerContent));
    ASSERT_FALSE(manager.IsEOF());
    ASSERT_TRUE(manager.Flush());
}

void CoreTools::CWriteFileManagerTesting::PutWriteResultTest()
{
    auto cFileManagerContent = GetFileManagerContent();
    CReadFileManager manager{ GetFileName() };

    size_t size{ 0 };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, cFileManagerContent.size());

    cFileManagerContent += 'a';
    cFileManagerContent += GetFileManagerContent();

    vector<char> buffer(cFileManagerContent.size());
    manager.Read(sizeof(char), buffer.size(), buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, cFileManagerContent);
}

void CoreTools::CWriteFileManagerTesting::PositionTest()
{
    const auto cFileManagerContent = GetFileManagerContent();
    CWriteFileManager manager{ GetFileName(), true };
    ASSERT_EQUAL(0, manager.GetPosition());

    ASSERT_TRUE(manager.Seek(1, System::FileSeek::Cur));
    ASSERT_EQUAL(1, manager.GetPosition());

    ASSERT_TRUE(manager.SetPosition(8));
    ASSERT_EQUAL(8, manager.GetPosition());

    ASSERT_TRUE(manager.Seek(0, System::FileSeek::End));

    const auto length = manager.Tell();

    ASSERT_EQUAL(length, boost::numeric_cast<decltype(length)>(cFileManagerContent.size() * 2 + 1 + sizeof(size_t)));

    manager.Rewind();
    ASSERT_EQUAL(0, manager.GetPosition());

    ASSERT_TRUE(manager.Setvbuf(System::FileSetvBuf::IOFBF, 256));
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:39)

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

CoreTools::CWriteFileManagerTesting::CWriteFileManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }, fileManagerContent{ "CFileManager Testing Text" }
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

System::String CoreTools::CWriteFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/CFileManagerTesting/CWriteFileManagerTestingText.txt");
}

void CoreTools::CWriteFileManagerTesting::CWriteFileManagerTest()
{
    CWriteFileManager manager{ GetFileName() };

    const auto size = fileManagerContent.size();

    manager.Write(sizeof(decltype(size)), &size);
    manager.Write(sizeof(char), size, fileManagerContent.c_str());
}

void CoreTools::CWriteFileManagerTesting::WriteResultTest()
{
    CReadFileManager manager{ GetFileName() };

    const auto size = ReadSizeTest(manager);

    ASSERT_NOT_THROW_EXCEPTION_3(ReadBufferTest, manager, size, fileManagerContent);
}

size_t CoreTools::CWriteFileManagerTesting::ReadSizeTest(CReadFileManager& manager)
{
    size_t size{ 0u };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, fileManagerContent.size());

    return size;
}

void CoreTools::CWriteFileManagerTesting::ReadBufferTest(CReadFileManager& manager, size_t size, const std::string& content)
{
    std::vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::CWriteFileManagerTesting::GetFileByteSizeTest()
{
    const CWriteFileManager manager{ GetFileName(), true };

    const auto size = fileManagerContent.size();

    ASSERT_EQUAL(manager.GetFileByteSize(), size + sizeof(decltype(size)));
}

void CoreTools::CWriteFileManagerTesting::PutTest()
{
    CWriteFileManager manager{ GetFileName(), true };

    ASSERT_TRUE(manager.PutCharacter('a'));
    ASSERT_TRUE(manager.PutString(fileManagerContent));
    ASSERT_FALSE(manager.IsEof());
    ASSERT_TRUE(manager.Flush());
}

void CoreTools::CWriteFileManagerTesting::PutWriteResultTest()
{
    auto result = fileManagerContent;
    CReadFileManager manager{ GetFileName() };

    std::ignore = ReadSizeTest(manager);

    result += 'a';
    result += fileManagerContent;

    ASSERT_NOT_THROW_EXCEPTION_3(ReadBufferTest, manager, result.size(), result);
}

void CoreTools::CWriteFileManagerTesting::PositionTest()
{
    CWriteFileManager manager{ GetFileName(), true };

    ASSERT_NOT_THROW_EXCEPTION_1(DoPositionTest, manager);
    ASSERT_NOT_THROW_EXCEPTION_1(MiscellaneousTest, manager);
}

void CoreTools::CWriteFileManagerTesting::DoPositionTest(CWriteFileManager& manager)
{
#ifdef SYSTEM_PLATFORM_WIN32

    ASSERT_EQUAL(0, manager.GetPosition());

    ASSERT_TRUE(manager.Seek(1, System::FileSeek::Cur));
    ASSERT_EQUAL(1, manager.GetPosition());

    ASSERT_TRUE(manager.SetPosition(8));
    ASSERT_EQUAL(8, manager.GetPosition());

#endif  // SYSTEM_PLATFORM_WIN32
}

void CoreTools::CWriteFileManagerTesting::MiscellaneousTest(CWriteFileManager& manager)
{
    ASSERT_TRUE(manager.Seek(0, System::FileSeek::End));

    const auto length = manager.Tell();

    ASSERT_EQUAL(length, boost::numeric_cast<decltype(length)>(fileManagerContent.size() * 2 + 1 + sizeof(size_t)));

    ASSERT_TRUE(manager.SetVBuffer(System::FileSetVBuffer::IoFullyBuffered, 256));
}
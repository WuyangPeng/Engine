/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/30 20:25)

#include "CReadFileManagerTesting.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CReadFileManager.h"
#include "CoreTools/FileManager/CWriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

CoreTools::CReadFileManagerTesting::CReadFileManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      fileManagerContent{ "CFileManager Testing Text" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CReadFileManagerTesting)

void CoreTools::CReadFileManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CReadFileManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CReadFileManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileByteSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetCharacterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PositionTest);
}

System::String CoreTools::CReadFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("Resource/CFileManagerTesting/CReadFileManagerTestingText.txt");
}

void CoreTools::CReadFileManagerTesting::WriteFileTest()
{
    CWriteFileManager manager{ GetFileName() };

    const auto size = fileManagerContent.size();

    manager.Write(sizeof(decltype(size)), &size);
    manager.Write(sizeof(char), size, fileManagerContent.c_str());
}

void CoreTools::CReadFileManagerTesting::CReadFileManagerTest()
{
    CReadFileManager manager{ GetFileName() };

    const auto size = ReadSizeTest(manager);

    ASSERT_NOT_THROW_EXCEPTION_2(ReadBufferTest, manager, size);
}

size_t CoreTools::CReadFileManagerTesting::ReadSizeTest(CReadFileManager& manager)
{
    size_t size{ 0u };
    manager.Read(sizeof(decltype(size)), &size);

    ASSERT_EQUAL(size, fileManagerContent.size());

    return size;
}

void CoreTools::CReadFileManagerTesting::ReadBufferTest(CReadFileManager& manager, size_t size)
{
    std::vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    const std::string result{ buffer.begin(), buffer.end() };
    ASSERT_EQUAL(result, fileManagerContent);
}

void CoreTools::CReadFileManagerTesting::GetFileByteSizeTest()
{
    const CReadFileManager manager{ GetFileName() };

    const auto size = fileManagerContent.size();

    ASSERT_EQUAL(manager.GetFileByteSize(), boost::numeric_cast<int>(size + sizeof(decltype(size))));
}

void CoreTools::CReadFileManagerTesting::GetCharacterTest()
{
    CReadFileManager manager{ GetFileName() };

    const auto size = ReadSizeTest(manager);

    ASSERT_NOT_THROW_EXCEPTION_2(DoGetCharacterTest, manager, size);

    ASSERT_FALSE(manager.IsEof());
    ASSERT_TRUE(manager.Flush());
}

void CoreTools::CReadFileManagerTesting::DoGetCharacterTest(CReadFileManager& manager, size_t size)
{
    const auto character = manager.GetCharacter();
    ASSERT_EQUAL(character, fileManagerContent.at(0));

    ASSERT_TRUE(manager.UnGetCharacter(fileManagerContent.at(0)));

    const auto content = manager.GetString(boost::numeric_cast<int>(size + 1));
    ASSERT_EQUAL(content, fileManagerContent);
}

void CoreTools::CReadFileManagerTesting::PositionTest()
{
    CReadFileManager manager{ GetFileName() };

    ASSERT_NOT_THROW_EXCEPTION_1(DoPositionTest, manager);
    ASSERT_NOT_THROW_EXCEPTION_1(MiscellaneousTest, manager);
}

void CoreTools::CReadFileManagerTesting::DoPositionTest(CReadFileManager& manager)
{
#ifdef SYSTEM_PLATFORM_WIN32

    ASSERT_EQUAL(0, manager.GetPosition());

    ASSERT_TRUE(manager.Seek(1, System::FileSeek::Cur));
    ASSERT_EQUAL(1, manager.GetPosition());

    ASSERT_TRUE(manager.SetPosition(8));
    ASSERT_EQUAL(8, manager.GetPosition());

#endif  // SYSTEM_PLATFORM_WIN32
}

void CoreTools::CReadFileManagerTesting::MiscellaneousTest(CReadFileManager& manager)
{
    ASSERT_TRUE(manager.Seek(0, System::FileSeek::End));

    const auto length = manager.Tell();
    ASSERT_EQUAL(length, boost::numeric_cast<decltype(length)>(fileManagerContent.size() + sizeof(size_t)));

    ASSERT_TRUE(manager.SetVBuffer(System::FileSetVBuffer::IoFullyBuffered, 256));
}
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:44)

#include "FileHandleTesting.h"
#include "CoreTools/FileManager/FileHandleHelper.h"
#include "CoreTools/FileManager/ReadAndWriteFileHandle.h"
#include "CoreTools/FileManager/ReadFileHandle.h"
#include "CoreTools/FileManager/WriteFileHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
    const auto g_FileHandleHelpFileName = SYSTEM_TEXT("Resource/FileHandleTesting/FileHandleHelpTestingText.txt"s);

    const auto g_FileHandleFileName = SYSTEM_TEXT("Resource/FileHandleTesting/FileHandleTestingText.txt"s);

    const auto g_FileHandleHelpContent = "FileHandleHelp Testing Text"s;

    const auto g_FileHandleContent = "FileHandle Testing Text"s;

    const auto g_InexistenceFileName = SYSTEM_TEXT("Resource/FileHandleTesting/InexistenceFile.txt"s);
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FileHandleTesting)

void CoreTools::FileHandleTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileHandleHelpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadAndWriteFileHandleTest);
    ASSERT_THROW_EXCEPTION_0(InexistenceFileTest);
    ASSERT_THROW_EXCEPTION_0(CannotOpenWriteFileHandleTest);
    ASSERT_THROW_EXCEPTION_0(CannotOpenReadAndWriteFileHandleTest);
}

// FileHandleHelp≤‚ ‘
void CoreTools::FileHandleTesting ::FileHandleHelpTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveIntoFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadFromFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AppendToFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SaveIntoFileTest);
}
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)
void CoreTools::FileHandleTesting ::LoadFromFileTest()
{
    auto buffer = FileHandleHelper::LoadFromFile(g_FileHandleHelpFileName);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    ASSERT_EQUAL(bufferContent, g_FileHandleHelpContent);
}

void CoreTools::FileHandleTesting ::AppendToFileTest()
{
    auto content = g_FileHandleHelpContent;

    vector<char> appendContent{ g_FileHandleHelpContent.begin(), g_FileHandleHelpContent.end() };

    FileHandleHelper::AppendToFile(g_FileHandleHelpFileName, boost::numeric_cast<int>(appendContent.size()), appendContent.data());

    auto buffer = FileHandleHelper::LoadFromFile(g_FileHandleHelpFileName);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    content += g_FileHandleHelpContent;

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::FileHandleTesting ::SaveIntoFileTest()
{
    vector<char> saveContent{ g_FileHandleHelpContent.begin(), g_FileHandleHelpContent.end() };

    FileHandleHelper::SaveIntoFile(g_FileHandleHelpFileName, boost::numeric_cast<int>(saveContent.size()), saveContent.data());

    auto buffer = FileHandleHelper::LoadFromFile(g_FileHandleHelpFileName);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    ASSERT_EQUAL(bufferContent, g_FileHandleHelpContent);
}

// ReadFileHandle≤‚ ‘
void CoreTools::FileHandleTesting ::ReadFileHandleTest()
{
    ReadFileHandle firstHandle{ g_FileHandleFileName };
    ReadFileHandle secondHandle{ g_FileHandleFileName };

    uint32_t size{ 0 };
    firstHandle.Read(sizeof(uint32_t), &size);

    ASSERT_EQUAL(size, g_FileHandleContent.size());

    vector<char> buffer(size);
    firstHandle.Read(sizeof(char), size, buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, g_FileHandleContent);
}

// WriteFileHandle≤‚ ‘
void CoreTools::FileHandleTesting ::WriteFileHandleTest()
{
    WriteFileHandle handle{ g_FileHandleFileName };

    const auto size = g_FileHandleContent.size();
    handle.Write(sizeof(uint32_t), &size);

    handle.Write(sizeof(char), size, g_FileHandleContent.c_str());
}

// ReadAndWriteFileHandle≤‚ ‘
void CoreTools::FileHandleTesting ::ReadAndWriteFileHandleTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReadAndWriteFileHandleWriteFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadAndWriteFileHandleReadFileTest);
}

void CoreTools::FileHandleTesting ::ReadAndWriteFileHandleWriteFileTest()
{
    ReadAndWriteFileHandle handle{ g_FileHandleFileName };

    const auto size = g_FileHandleContent.size();
    handle.Write(sizeof(uint32_t), &size);

    handle.Write(sizeof(char), size, g_FileHandleContent.c_str());
}

void CoreTools::FileHandleTesting ::ReadAndWriteFileHandleReadFileTest()
{
    ReadAndWriteFileHandle handle{ g_FileHandleFileName };

    uint32_t size{ 0 };
    handle.Read(sizeof(uint32_t), &size);

    ASSERT_EQUAL(size, g_FileHandleContent.size());

    vector<char> buffer(size);
    handle.Read(sizeof(char), size, buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, g_FileHandleContent);
}

// InexistenceFile≤‚ ‘
void CoreTools::FileHandleTesting ::InexistenceFileTest()
{
    ReadFileHandle inexistenceFile{ g_InexistenceFileName };
}

// CannotOpenWriteFileHandle≤‚ ‘
void CoreTools::FileHandleTesting ::CannotOpenWriteFileHandleTest()
{
    WriteFileHandle firstHandle{ g_FileHandleFileName };
    WriteFileHandle secondHandle{ g_FileHandleFileName };
}

// CannotOpenReadAndWriteFileHandle≤‚ ‘
void CoreTools::FileHandleTesting ::CannotOpenReadAndWriteFileHandleTest()
{
    ReadAndWriteFileHandle firstHandle{ g_FileHandleFileName };
    ReadAndWriteFileHandle secondHandle{ g_FileHandleFileName };
}
#include STSTEM_WARNING_POP
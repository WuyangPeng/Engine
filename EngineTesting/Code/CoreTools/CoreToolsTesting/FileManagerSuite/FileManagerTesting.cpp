// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:45)

#include "FileManagerTesting.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
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
    const auto g_FileManagerHelpFileName = SYSTEM_TEXT("Resource/FileManagerTesting/FileManagerHelpTestingText.txt"s);

    const auto g_FileManagerFileName = SYSTEM_TEXT("Resource/FileManagerTesting/FileManagerTestingText.txt"s);

    const auto g_FileManagerHelpContent = "FileManagerHelp Testing Text"s;

    const auto g_FileManagerContent = "FileManager Testing Text"s;
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FileManagerTesting)

void CoreTools::FileManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileManagerHelpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileManagerTest);
}

// FileManageHelp≤‚ ‘
void CoreTools::FileManagerTesting ::FileManagerHelpTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
void CoreTools::FileManagerTesting ::LoadFromFileTest(bool binaryFile)
{
    auto buffer = FileManagerHelper::LoadFromFile(g_FileManagerHelpFileName, binaryFile);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    ASSERT_EQUAL(bufferContent, g_FileManagerHelpContent);
}

void CoreTools::FileManagerTesting ::AppendToFileTest(bool binaryFile)
{
    auto content = g_FileManagerHelpContent;

    vector<char> appendContent{ g_FileManagerHelpContent.begin(), g_FileManagerHelpContent.end() };

    FileManagerHelper::AppendToFile(g_FileManagerHelpFileName, binaryFile, boost::numeric_cast<int>(appendContent.size()), appendContent.data());

    auto buffer = FileManagerHelper::LoadFromFile(g_FileManagerHelpFileName, binaryFile);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    content += g_FileManagerHelpContent;

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::FileManagerTesting ::SaveIntoFileTest(bool binaryFile)
{
    vector<char> saveContent{ g_FileManagerHelpContent.begin(), g_FileManagerHelpContent.end() };

    FileManagerHelper::SaveIntoFile(g_FileManagerHelpFileName, binaryFile, boost::numeric_cast<int>(saveContent.size()), saveContent.data());

    auto buffer = FileManagerHelper::LoadFromFile(g_FileManagerHelpFileName, binaryFile);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    ASSERT_EQUAL(bufferContent, g_FileManagerHelpContent);
}

// ReadFileManager≤‚ ‘
void CoreTools::FileManagerTesting ::ReadFileManagerTest()
{
    ReadFileManager manager{ g_FileManagerFileName };

    uint32_t size{ 0 };
    manager.Read(sizeof(uint32_t), &size);

    ASSERT_EQUAL(size, g_FileManagerContent.size());

    vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, g_FileManagerContent);
}

// WriteFileManager≤‚ ‘
void CoreTools::FileManagerTesting ::WriteFileManagerTest()
{
    WriteFileManager manager{ g_FileManagerFileName };

    const auto size = g_FileManagerContent.size();
    manager.Write(sizeof(uint32_t), &size);

    manager.Write(sizeof(char), size, g_FileManagerContent.c_str());
}

#include STSTEM_WARNING_POP
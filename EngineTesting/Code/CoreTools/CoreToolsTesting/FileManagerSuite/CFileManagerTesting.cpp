// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:34)

#include "CFileManagerTesting.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/CReadFileManager.h"
#include "CoreTools/FileManager/CWriteFileManager.h"
#include "CoreTools/FileManager/Environment.h"
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
    const auto g_FileName = SYSTEM_TEXT("CFileManagerHelpTestingText.txt"s);
    const auto g_Directory = SYSTEM_TEXT("Resource/CFileManagerTesting/"s);
    const auto g_CFileManagerHelpFileName = g_Directory + g_FileName;
    const auto g_CFileManagerFileName = SYSTEM_TEXT("Resource/CFileManagerTesting/CFileManagerTestingText.txt"s);
    const auto g_CFileManagerHelpContent = "CFileManagerHelp Testing Text"s;
    const auto g_CFileManagerContent = "CFileManager Testing Text"s;
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CFileManagerTesting)

void CoreTools::CFileManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CFileManagerHelpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CWriteFileManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CReadFileManagerTest);
}

// CFileManageHelp≤‚ ‘
void CoreTools::CFileManagerTesting ::CFileManagerHelpTest()
{
    Environment::Create();

    [[maybe_unused]] const auto value = ENVIRONMENT_SINGLETON.InsertDirectory(g_Directory);

    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileUseEnvironmentTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileUseEnvironmentTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);

    Environment::Destroy();
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
void CoreTools::CFileManagerTesting ::LoadFromFileTest(bool binaryFile)
{
    auto buffer = CFileManagerHelper::LoadFromFile(g_CFileManagerHelpFileName, binaryFile);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    ASSERT_EQUAL(bufferContent, g_CFileManagerHelpContent);
}

void CoreTools::CFileManagerTesting ::LoadFromFileUseEnvironmentTest(bool binaryFile)
{
    auto buffer = CFileManagerHelper::LoadFromFileUseEnvironment(g_FileName, binaryFile);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    ASSERT_EQUAL(bufferContent, g_CFileManagerHelpContent);
}

void CoreTools::CFileManagerTesting ::AppendToFileTest(bool binaryFile)
{
    auto content = g_CFileManagerHelpContent;

    vector<char> appendContent{ g_CFileManagerHelpContent.begin(), g_CFileManagerHelpContent.end() };

    CFileManagerHelper::AppendToFile(g_CFileManagerHelpFileName, binaryFile, boost::numeric_cast<int>(appendContent.size()), appendContent.data());

    auto buffer = CFileManagerHelper::LoadFromFile(g_CFileManagerHelpFileName, binaryFile);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    content += g_CFileManagerHelpContent;

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::CFileManagerTesting ::SaveIntoFileTest(bool binaryFile)
{
    vector<char> saveContent{ g_CFileManagerHelpContent.begin(), g_CFileManagerHelpContent.end() };

    CFileManagerHelper::SaveIntoFile(g_CFileManagerHelpFileName, binaryFile, boost::numeric_cast<int>(saveContent.size()), saveContent.data());

    auto buffer = CFileManagerHelper::LoadFromFile(g_CFileManagerHelpFileName, binaryFile);

    string bufferContent{ buffer.GetBufferBegin(), buffer.GetBufferBegin() + buffer.GetSize() };

    ASSERT_EQUAL(bufferContent, g_CFileManagerHelpContent);
}

// CReadFileManage≤‚ ‘
void CoreTools::CFileManagerTesting ::CReadFileManagerTest()
{
    CReadFileManager manager{ g_CFileManagerFileName };

    size_t size{ 0 };
    manager.Read(sizeof(size_t), &size);

    ASSERT_EQUAL(size, g_CFileManagerContent.size());

    vector<char> buffer(size);
    manager.Read(sizeof(char), size, buffer.data());

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, g_CFileManagerContent);
}

// CWriteFileManage≤‚ ‘
void CoreTools::CFileManagerTesting ::CWriteFileManagerTest()
{
    CWriteFileManager manager{ g_CFileManagerFileName };

    const auto size = g_CFileManagerContent.size();
    manager.Write(sizeof(size_t), &size);

    manager.Write(sizeof(char), size, g_CFileManagerContent.c_str());
}
#include STSTEM_WARNING_POP
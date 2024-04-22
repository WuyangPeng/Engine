/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 17:03)

#include "FileManagerHelperTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

CoreTools::FileManagerHelperTesting::String CoreTools::FileManagerHelperTesting::GetDirectory()
{
    return SYSTEM_TEXT("Resource/FileManagerTesting/");
}

CoreTools::FileManagerHelperTesting::String CoreTools::FileManagerHelperTesting::GetFileName()
{
    return SYSTEM_TEXT("FileManagerHelperTestingText.txt");
}

System::String CoreTools::FileManagerHelperTesting::GetFileManagerHelperName()
{
    return GetDirectory() + GetFileName();
}

std::string CoreTools::FileManagerHelperTesting::GetFileManagerHelperContent()
{
    return "FileManagerHelper Testing Text";
}

CoreTools::FileManagerHelperTesting::FileManagerHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }, environment{ Environment::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileManagerHelperTesting)

void CoreTools::FileManagerHelperTesting::DoRunUnitTest()
{
    ASSERT_TRUE(environment.InsertDirectory(GetDirectory()));

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileManagerHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileUseEnvironmentTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileUseEnvironmentTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);

    ASSERT_NOT_THROW_EXCEPTION_0(IsFileExistsTest);
}

void CoreTools::FileManagerHelperTesting::LoadFromFileTest(bool binaryFile)
{
    const auto buffer = FileManagerHelper::LoadFromFile(GetFileManagerHelperName(), binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileManagerHelperContent());
}

void CoreTools::FileManagerHelperTesting::LoadFromFileUseEnvironmentTest(bool binaryFile)
{
    const auto buffer = FileManagerHelper::LoadFromFileUseEnvironment(environment, GetFileName(), binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileManagerHelperContent());
}

void CoreTools::FileManagerHelperTesting::AppendToFileTest(bool binaryFile)
{
    auto content = GetFileManagerHelperContent();
    const auto fileName = GetFileManagerHelperName();

    FileManagerHelper::AppendToFile(fileName, binaryFile, boost::numeric_cast<int>(content.size()), content.c_str());

    const auto buffer = FileManagerHelper::LoadFromFile(fileName, binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    content += GetFileManagerHelperContent();

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::FileManagerHelperTesting::SaveIntoFileTest(bool binaryFile)
{
    const auto content = GetFileManagerHelperContent();
    const auto fileName = GetFileManagerHelperName();

    FileManagerHelper::SaveIntoFile(fileName, binaryFile, boost::numeric_cast<int>(content.size()), content.c_str());

    const auto buffer = FileManagerHelper::LoadFromFile(fileName, binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::FileManagerHelperTesting::IsFileExistsTest()
{
    ASSERT_TRUE(FileManagerHelper::IsFileExists(StringConversion::StandardConversionMultiByte(GetFileManagerHelperName())));
    ASSERT_FALSE(FileManagerHelper::IsFileExists("Resource/FileManagerTesting/ErrorFileManagerHelperTestingText.txt"));
}

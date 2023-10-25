///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:35)

#include "FileManagerHelperTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

using namespace std::literals;

System::String CoreTools::FileManagerHelperTesting::GetFileManagerHelperName()
{
    return SYSTEM_TEXT("Resource/FileManagerTesting/FileManagerHelperTestingText.txt"s);
}

std::string CoreTools::FileManagerHelperTesting::GetFileManagerHelperContent()
{
    return "FileManagerHelper Testing Text"s;
}

CoreTools::FileManagerHelperTesting::FileManagerHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileManagerHelperTesting)

void CoreTools::FileManagerHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileManagerHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);
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
    ASSERT_FALSE(FileManagerHelper::IsFileExists("Resource/FileManagerTesting/ErrorFileManagerHelperTestingText.txt"s));
}

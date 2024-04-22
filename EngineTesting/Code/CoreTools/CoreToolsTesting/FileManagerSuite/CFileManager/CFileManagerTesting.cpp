/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:31)

#include "CFileManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/CWriteFileManager.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

System::String CoreTools::CFileManagerTesting::GetDirectory()
{
    return SYSTEM_TEXT("Resource/CFileManagerTesting/");
}

System::String CoreTools::CFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("CFileManagerHelperTestingText.txt");
}

System::String CoreTools::CFileManagerTesting::GetFileManagerHelperFileName()
{
    static const auto fileName = GetDirectory() + GetFileName();

    return fileName;
}

std::string CoreTools::CFileManagerTesting::GetFileManagerContent()
{
    return "CFileManagerHelper Testing Text";
}

CoreTools::CFileManagerTesting::CFileManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }, environment{ Environment::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CFileManagerTesting)

void CoreTools::CFileManagerTesting::DoRunUnitTest()
{
    ASSERT_TRUE(environment.InsertDirectory(GetDirectory()));

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CFileManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CFileManagerHelperTest);
}

void CoreTools::CFileManagerTesting::CFileManagerHelperTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileUseEnvironmentTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(LoadFromFileUseEnvironmentTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(AppendToFileTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(SaveIntoFileTest, true);
}

void CoreTools::CFileManagerTesting::LoadFromFileTest(bool binaryFile)
{
    auto buffer = CFileManagerHelper::LoadFromFile(GetFileManagerHelperFileName(), binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileManagerContent());

    ASSERT_EQUAL(GetFileManagerContent(), CFileManagerHelper::LoadFromFile(StringConversion::StandardConversionMultiByte(GetFileManagerHelperFileName())));
}

void CoreTools::CFileManagerTesting::LoadFromFileUseEnvironmentTest(bool binaryFile)
{
    auto buffer = CFileManagerHelper::LoadFromFileUseEnvironment(environment, GetFileName(), binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileManagerContent());
}

void CoreTools::CFileManagerTesting::AppendToFileTest(bool binaryFile)
{
    auto content = GetFileManagerContent();

    CFileManagerHelper::AppendToFile(GetFileManagerHelperFileName(), binaryFile, boost::numeric_cast<int>(content.size()), content.c_str());

    auto buffer = CFileManagerHelper::LoadFromFile(GetFileManagerHelperFileName(), binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    content += GetFileManagerContent();

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::CFileManagerTesting::SaveIntoFileTest(bool binaryFile)
{
    const auto content = GetFileManagerContent();

    CFileManagerHelper::SaveIntoFile(GetFileManagerHelperFileName(), binaryFile, boost::numeric_cast<int>(content.size()), content.c_str());

    auto buffer = CFileManagerHelper::LoadFromFile(GetFileManagerHelperFileName(), binaryFile);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}

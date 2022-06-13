///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:58)

#include "CFileManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/CReadFileManager.h"
#include "CoreTools/FileManager/CWriteFileManager.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace std::literals;

System::String CoreTools::CFileManagerTesting::GetDirectory()
{
    return SYSTEM_TEXT("Resource/CFileManagerTesting/"s);
}

System::String CoreTools::CFileManagerTesting::GetFileName()
{
    return SYSTEM_TEXT("CFileManagerHelperTestingText.txt"s);
}

System::String CoreTools::CFileManagerTesting::GetFileManagerHelperFileName()
{
    static const auto fileName = GetDirectory() + GetFileName();

    return fileName;
}

string CoreTools::CFileManagerTesting::GetFileManagerContent()
{
    return "CFileManagerHelper Testing Text"s;
}

CoreTools::CFileManagerTesting::CFileManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CFileManagerTesting)

void CoreTools::CFileManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CFileManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CFileManagerHelperTest);
}

// CFileManageHelp测试
void CoreTools::CFileManagerTesting::CFileManagerHelperTest()
{
    Environment::Create();

    ASSERT_TRUE(ENVIRONMENT_SINGLETON.InsertDirectory(GetDirectory()));

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

void CoreTools::CFileManagerTesting::LoadFromFileTest(bool binaryFile)
{
    auto buffer = CFileManagerHelper::LoadFromFile(GetFileManagerHelperFileName(), binaryFile);

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileManagerContent());
}

void CoreTools::CFileManagerTesting::LoadFromFileUseEnvironmentTest(bool binaryFile)
{
    auto buffer = CFileManagerHelper::LoadFromFileUseEnvironment(GetFileName(), binaryFile);

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileManagerContent());
}

void CoreTools::CFileManagerTesting::AppendToFileTest(bool binaryFile)
{
    auto content = GetFileManagerContent();

    CFileManagerHelper::AppendToFile(GetFileManagerHelperFileName(), binaryFile, boost::numeric_cast<int>(content.size()), content.c_str());

    auto buffer = CFileManagerHelper::LoadFromFile(GetFileManagerHelperFileName(), binaryFile);

    string bufferContent{ buffer.begin(), buffer.end() };

    content += GetFileManagerContent();

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::CFileManagerTesting::SaveIntoFileTest(bool binaryFile)
{
    auto content = GetFileManagerContent();

    CFileManagerHelper::SaveIntoFile(GetFileManagerHelperFileName(), binaryFile, boost::numeric_cast<int>(content.size()), content.c_str());

    auto buffer = CFileManagerHelper::LoadFromFile(GetFileManagerHelperFileName(), binaryFile);

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}

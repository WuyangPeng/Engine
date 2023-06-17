///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:54)

#include "GenerateTestingTemplateCodeDirectoryTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateCodeDirectory.h"

using namespace std::literals;

AssistTools::GenerateTestingTemplateCodeDirectoryTesting::GenerateTestingTemplateCodeDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateCodeDirectoryTesting)

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);

    ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT(""s));
    ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT("MiddleLayer"s));
    ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT("Core"s));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting::GenerateToTest()
{
    const System::String newCoreName(SYSTEM_TEXT("Core"));
    const System::String newCoreCapitalName(SYSTEM_TEXT("CORE"));

    CopyrightData copyrightData = GetCopyrightData();

    GenerateTestingTemplateCodeDirectory generateTemplateCodeDirectory(GetResourceDirectory(), "Configuration/StringReplacing.json");

    generateTemplateCodeDirectory.GenerateTo(GetExportDirectory() + GetTesting(), GetSolutionName(), copyrightData, GetProjectCapital(), newCoreName, newCoreCapitalName);
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting::ManagerExistTest(const System::String& managerName)
{
    ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("Testing"s));
    ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("TestingHelper"s));
    ASSERT_NOT_THROW_EXCEPTION_2(ManagerCppExistTest, managerName, SYSTEM_TEXT("TestingHelper"s));
    ASSERT_NOT_THROW_EXCEPTION_2(ManagerCppExistTest, managerName, SYSTEM_TEXT("TestingMain"s));
    ASSERT_NOT_THROW_EXCEPTION_2(ManagerCppExistTest, managerName, SYSTEM_TEXT("TestingLib"s));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting::ManagerHeaderExistTest(const System::String& managerName, const System::String& resultName)
{
    const System::String newProjectName(GetSolutionName() + managerName);
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + newProjectName + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + resultName + extension;
    CopyrightData copyrightData(GetCopyrightData());

    int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
    int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
    int defaultProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());

    ASSERT_LESS(0, defaultProjectChineseNameCount);
    ASSERT_LESS(0, defaultVersionsCount);
    ASSERT_LESS(0, defaultProjectCapitalCount);

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 4);
    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 6);
    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting::ManagerCppExistTest(const System::String& managerName, const System::String& resultName)
{
    const System::String newProjectName(GetSolutionName() + managerName);
    const System::String extension(SYSTEM_TEXT(".cpp"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + newProjectName + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + resultName + extension;

    CopyrightData copyrightData(GetCopyrightData());

    int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
    int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());

    ASSERT_LESS(0, defaultProjectChineseNameCount);
    ASSERT_LESS(0, defaultVersionsCount);

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 4);
    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 6);
    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

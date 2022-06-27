///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 16:43)

#include "GenerateTestingTemplateCodeDirectoryTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateCodeDirectory.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTestingTemplateCodeDirectory)

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

    TestingType generateTemplateCodeDirectory(GetResourceDirectory(), "Configuration/StringReplacing.json");

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

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:53)

#include "GenerateTemplateMainTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMain.h"

AssistTools::GenerateTemplateMainTesting::GenerateTemplateMainTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateMainTesting)

void AssistTools::GenerateTemplateMainTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GenerateTemplateMainTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultGenerateToTest);
}

void AssistTools::GenerateTemplateMainTesting::GenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Main"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMainCppSpecial.txt"));
    const System::String extension(SYSTEM_TEXT(".cpp"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());
    const System::String projectName(SYSTEM_TEXT("Project"));

    GenerateTemplateMain::Replace replace = GetSpecialReplace();

    GenerateTemplateMain generateTemplateSolution(fileName, replace);

    int defaultEndYearCount = GetContentFindCount(fileName, GetSpecialEndYear());
    ASSERT_EQUAL(defaultEndYearCount, 1);

    int defaultProjectChineseNameCount = GetContentFindCount(fileName, GetSpecialProjectChineseName());
    ASSERT_LESS(0, defaultProjectChineseNameCount);

    int defaultVersionsCount = GetContentFindCount(fileName, GetSpecialVersions());
    ASSERT_LESS(0, defaultVersionsCount);

    int defaultDateCount = GetContentFindCount(fileName, GetSpecialDate());
    ASSERT_EQUAL(defaultDateCount, 1);

    int defaultHourCount = GetContentFindCount(fileName, GetSpecialHour());
    ASSERT_EQUAL(defaultHourCount, 1);

    int defaultMinuteCount = GetContentFindCount(fileName, GetSpecialMinute());
    ASSERT_EQUAL(defaultMinuteCount, 1);

    int defaultSolutionNameCount = GetContentFindCount(fileName, GetSpecialSolutionName());
    ASSERT_LESS(0, defaultSolutionNameCount);

    int defaultProjectNameCount = GetContentFindCount(fileName, GetSpecialProjectName());
    ASSERT_LESS(0, defaultProjectNameCount);

    CopyrightData copyrightData(GetCopyrightData());

    generateTemplateSolution.GenerateTo(fullDirectory, newProjectName, copyrightData, GetSolutionName(), projectName);

    System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

    ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetSpecialSolutionName(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetSpecialProjectName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, projectName, defaultProjectNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

void AssistTools::GenerateTemplateMainTesting::DefaultGenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Main"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMainCpp.txt"));
    const System::String extension(SYSTEM_TEXT(".cpp"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());
    const System::String projectName(SYSTEM_TEXT("Project"));

    GenerateTemplateMain generateTemplateSolution(fileName, GenerateTemplateMain::Replace());

    int defaultEndYearCount = GetContentFindCount(fileName, GetDefaultEndYear());
    ASSERT_EQUAL(defaultEndYearCount, 1);

    int defaultProjectChineseNameCount = GetContentFindCount(fileName, GetDefaultProjectChineseName());
    ASSERT_LESS(0, defaultProjectChineseNameCount);

    int defaultVersionsCount = GetContentFindCount(fileName, GetDefaultVersions());
    ASSERT_LESS(0, defaultVersionsCount);

    int defaultDateCount = GetContentFindCount(fileName, GetDefaultDate());
    ASSERT_EQUAL(defaultDateCount, 1);

    int defaultHourCount = GetContentFindCount(fileName, GetDefaultHour());
    ASSERT_EQUAL(defaultHourCount, 1);

    int defaultMinuteCount = GetContentFindCount(fileName, GetDefaultMinute());
    ASSERT_EQUAL(defaultMinuteCount, 1);

    int defaultSolutionNameCount = GetContentFindCount(fileName, GetDefaultSolutionName());
    ASSERT_LESS(0, defaultSolutionNameCount);

    int defaultProjectNameCount = GetContentFindCount(fileName, GetDefaultProjectName());
    ASSERT_LESS(0, defaultProjectNameCount);

    CopyrightData copyrightData(GetCopyrightData());

    generateTemplateSolution.GenerateTo(fullDirectory, newProjectName, copyrightData, GetSolutionName(), projectName);

    System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetDefaultProjectName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, projectName, defaultProjectNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

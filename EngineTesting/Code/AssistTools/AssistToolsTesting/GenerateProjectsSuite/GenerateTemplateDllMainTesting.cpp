///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 16:15)

#include "GenerateTemplateDllMainTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateDllMain.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateDllMain)

void AssistTools::GenerateTemplateDllMainTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultGenerateToTest);
}

void AssistTools::GenerateTemplateDllMainTesting::GenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllMainCppSpecial.txt"));
    const System::String extension(SYSTEM_TEXT(".cpp"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName);

    TestingType::Replace replace = GetSpecialReplace();

    TestingType generateTemplateSolution(fileName, replace);

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

    int defaultNameSpaceCount = GetContentFindCount(fileName, GetSpecialSolutionName());
    ASSERT_LESS(0, defaultNameSpaceCount);

    int defaultManagerNameCount = GetContentFindCount(fileName, GetSpecialManagerName());
    ASSERT_LESS(0, defaultManagerNameCount);

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName((SYSTEM_TEXT("DllMain")));

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetInputManagerName(), GetProjectCapital(), GetInputManagerCapitalName());

    System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

    ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetSpecialSolutionName(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetSpecialManagerName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

void AssistTools::GenerateTemplateDllMainTesting::DefaultGenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllMainCpp.txt"));
    const System::String extension(SYSTEM_TEXT(".cpp"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName);

    TestingType generateTemplateSolution(fileName, TestingType::Replace());

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

    int defaultNameSpaceCount = GetContentFindCount(fileName, GetDefaultSolutionName());
    ASSERT_LESS(0, defaultNameSpaceCount);

    int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());
    ASSERT_LESS(0, defaultManagerNameCount);

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName((SYSTEM_TEXT("DllMain")));

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetInputManagerName(), GetProjectCapital(), GetInputManagerCapitalName());

    System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

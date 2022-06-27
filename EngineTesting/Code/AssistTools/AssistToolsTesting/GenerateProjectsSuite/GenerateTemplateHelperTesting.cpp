///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 16:17)

#include "GenerateTemplateHelperTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateHelper.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateHelper)

void AssistTools::GenerateTemplateHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateHelperH.txt"s), SYSTEM_TEXT(".h"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateHelperCpp.txt"s), SYSTEM_TEXT(".cpp"s));
}

void AssistTools::GenerateTemplateHelperTesting::GenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Helper"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateHelperHSpecial.txt"));
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

    TestingType::Replace replace = GetSpecialReplace();
    TestingType generateTemplateSolution(fileName, extension, replace);

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

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetSpecialProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultSolutionNameCount = GetContentFindCount(fileName, GetSpecialSolutionName());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    CopyrightData copyrightData(GetCopyrightData());

    generateTemplateSolution.GenerateTo(fullDirectory, newProjectName, copyrightData, GetProjectCapital(), GetSolutionName());

    System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

    ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetSpecialProjectCapital(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetSpecialSolutionName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

void AssistTools::GenerateTemplateHelperTesting::DefaultGenerateToTest(const System::String& testFileName, const System::String& extension)
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Helper"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName);
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

    TestingType generateTemplateSolution(fileName, extension, TestingType::Replace());

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

    int defaultDefaultProjectCount = GetContentFindCount(fileName, GetDefaultProjectCapital());

    int defaultSolutionNameCount = GetContentFindCount(fileName, GetDefaultSolutionName());
    ASSERT_LESS(0, defaultSolutionNameCount);

    CopyrightData copyrightData(GetCopyrightData());

    generateTemplateSolution.GenerateTo(fullDirectory, newProjectName, copyrightData, GetProjectCapital(), GetSolutionName());

    System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetProjectCapital(), defaultDefaultProjectCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

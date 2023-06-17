///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:54)

#include "GenerateTemplateManagerLibTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateManagerLib.h"

AssistTools::GenerateTemplateManagerLibTesting::GenerateTemplateManagerLibTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateManagerLibTesting)

void AssistTools::GenerateTemplateManagerLibTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GenerateTemplateManagerLibTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultGenerateToTest);
}

void AssistTools::GenerateTemplateManagerLibTesting::GenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateManagerLibHSpecial.txt"));
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName);
    const System::String newFullProjectName(newProjectName + (SYSTEM_TEXT("Lib")));

    GenerateTemplateManagerLib::Replace replace = GetSpecialReplace();

    GenerateTemplateManagerLib generateTemplateSolution(fileName, replace);

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

    int defaultCapitalCount = GetContentFindCount(fileName, GetSpecialProjectCapital());
    ASSERT_LESS(0, defaultCapitalCount);

    int defaultManagerCapitalNameCount = GetContentFindCount(fileName, GetSpecialManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalNameCount);

    int defaultManagerNameCount = GetContentFindCount(fileName, GetSpecialManagerName());
    ASSERT_LESS(0, defaultManagerNameCount);

    int defaultSolutionNameCount = GetContentFindCount(fileName, GetSpecialSolutionName());
    ASSERT_LESS(0, defaultSolutionNameCount);

    CopyrightData copyrightData(GetCopyrightData());

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetProjectCapital(), GetInputManagerCapitalName(), GetSolutionName(), GetInputManagerName());

    System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

    ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetSpecialProjectCapital(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetProjectCapital(), defaultCapitalCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetSpecialManagerCapital(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetSpecialManagerName(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetSpecialSolutionName(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 13);
}

void AssistTools::GenerateTemplateManagerLibTesting::DefaultGenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateManagerLibH.txt"));
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName);

    GenerateTemplateManagerLib generateTemplateSolution(fileName, GenerateTemplateManagerLib::Replace());

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

    int defaultCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
    ASSERT_LESS(0, defaultCapitalCount);

    int defaultSolutionNameCount = GetContentFindCount(fileName, GetDefaultSolutionName());
    ASSERT_LESS(0, defaultSolutionNameCount);

    int defaultManagerCapitalNameCount = GetContentFindCount(fileName, GetDefaultManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalNameCount);

    int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());
    ASSERT_LESS(0, defaultManagerNameCount);

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName(newProjectName + (SYSTEM_TEXT("Lib")));

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetProjectCapital(), GetInputManagerCapitalName(), GetSolutionName(), GetInputManagerName());

    System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetProjectCapital(), defaultCapitalCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 13);
}

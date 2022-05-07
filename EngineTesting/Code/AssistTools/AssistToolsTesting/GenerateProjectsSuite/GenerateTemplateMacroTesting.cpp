// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:58)

#include "GenerateTemplateMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMacro.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateMacro)

void AssistTools::GenerateTemplateMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateExportMacroH.txt"s), SYSTEM_TEXT("ExportMacro"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerClassInvariantMacroH.txt"s), GetSolutionName() + SYSTEM_TEXT("InputManagerClassInvariantMacro"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerCustomAssertMacroH.txt"s), GetSolutionName() + SYSTEM_TEXT("InputManagerCustomAssertMacro"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateMacroH.txt"s), SYSTEM_TEXT("Macro"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateMacroFwdH.txt"s), SYSTEM_TEXT("MacroFwd"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateUserMacroH.txt"s), SYSTEM_TEXT("UserMacro"s));
}

void AssistTools::GenerateTemplateMacroTesting::GenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateExportMacroHSpecial.txt"));
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String macroDirectory(SYSTEM_TEXT("Macro"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName + GetForwardSlash() + macroDirectory);
    const System::String newFullProjectName(SYSTEM_TEXT("ExportMacro"));

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

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetSpecialProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultManagerCapitalCount = GetContentFindCount(fileName, GetSpecialManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalCount);

    CopyrightData copyrightData(GetCopyrightData());

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetInputManagerName(),
                                        GetProjectCapital(), GetInputManagerCapitalName());

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

    ContentCountTest(fullName, GetSpecialProjectCapital(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetSpecialManagerCapital(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 13);
}

void AssistTools::GenerateTemplateMacroTesting::DefaultGenerateToTest(const System::String& testFileName, const System::String& resultName)
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName);
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String macroDirectory(SYSTEM_TEXT("Macro"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName + GetForwardSlash() + macroDirectory);

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

    int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultManagerCapitalCount = GetContentFindCount(fileName, GetDefaultManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalCount);

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName(resultName);

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetInputManagerName(),
                                        GetProjectCapital(), GetInputManagerCapitalName());

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

    ContentCountTest(fullName, GetSpecialProjectCapital(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetSpecialManagerCapital(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 13);
}

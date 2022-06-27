///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 16:16)

#include "GenerateTemplateEngineTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateEngine.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateEngine)

void AssistTools::GenerateTemplateEngineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);

    ASSERT_NOT_THROW_EXCEPTION_2(DefaultEventManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateEngineH.txt"s), SYSTEM_TEXT("Engine"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultEventManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateEngineFwdH.txt"s), SYSTEM_TEXT("EngineFwd"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultEventManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateOtherManagerH.txt"s), SYSTEM_TEXT("EventManager"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultEventManagerCppGenerateToTest, SYSTEM_TEXT("GameTemplateOtherManagerCpp.txt"s), SYSTEM_TEXT("EventManager"s));

    ASSERT_NOT_THROW_EXCEPTION_2(DefaultInputManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateInputManagerEngineH.txt"s), SYSTEM_TEXT("Engine"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultInputManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateInputManagerEngineFwdH.txt"s), SYSTEM_TEXT("EngineFwd"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultInputManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateInputManagerH.txt"s), SYSTEM_TEXT("InputManager"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultInputManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateInputManagerDetailH.txt"s), SYSTEM_TEXT("InputManagerDetail"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultInputManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplatePlaceholderH.txt"s), SYSTEM_TEXT("Placeholder"s));
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultInputManagerCppGenerateToTest, SYSTEM_TEXT("GameTemplatePlaceholderCpp.txt"s), SYSTEM_TEXT("Placeholder"s));
}

void AssistTools::GenerateTemplateEngineTesting::GenerateToTest()
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("EventManager"));
    const System::String newFullProjectName(SYSTEM_TEXT("EventManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateOtherManagerHSpecial.txt"));
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName + GetForwardSlash() + GetEngineDirectory());

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

    int defaultNameSpaceCount = GetContentFindCount(fileName, GetSpecialSolutionName());
    ASSERT_LESS(0, defaultNameSpaceCount);

    int defaultManagerNameCount = GetContentFindCount(fileName, GetSpecialManagerName());
    ASSERT_LESS(0, defaultManagerNameCount);

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetSpecialProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultManagerCapitalCount = GetContentFindCount(fileName, GetSpecialManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalCount);

    int defaultInterfaceNameCount = GetContentFindCount(fileName, GetSpecialInterfaceName());
    ASSERT_LESS(0, defaultInterfaceNameCount);

    CopyrightData copyrightData(GetCopyrightData());

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetEventManagerName(), GetEventManagerInterface(), GetProjectCapital(), GetEventManagerCapitalName());

    System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

    ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetSpecialSolutionName(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetSpecialManagerName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetEventManagerName(), defaultManagerNameCount + defaultInterfaceNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetSpecialProjectCapital(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetSpecialManagerCapital(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetEventManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetSpecialInterfaceName(), 0, __FUNCTION__, 13);
    ContentCountTest(fullName, GetEventManagerInterface(), defaultInterfaceNameCount, __FUNCTION__, 14);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 15);
}

void AssistTools::GenerateTemplateEngineTesting::DefaultEventManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName)
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("EventManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName);
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName + GetForwardSlash() + GetEngineDirectory());

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

    int defaultNameSpaceCount = GetContentFindCount(fileName, GetDefaultSolutionName());

    int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultManagerCapitalCount = GetContentFindCount(fileName, GetDefaultManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalCount);

    int defaultInterfaceNameCount = GetContentFindCount(fileName, GetDefaultInterfaceName());

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName(resultName);

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetEventManagerName(), GetEventManagerInterface(), GetProjectCapital(), GetEventManagerCapitalName());

    System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetEventManagerName(), defaultManagerNameCount + defaultInterfaceNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetEventManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetDefaultInterfaceName(), 0, __FUNCTION__, 13);
    ContentCountTest(fullName, GetEventManagerInterface(), defaultInterfaceNameCount, __FUNCTION__, 14);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 15);
}

void AssistTools::GenerateTemplateEngineTesting::DefaultEventManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName)
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("EventManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName);
    const System::String extension(SYSTEM_TEXT(".cpp"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName + GetForwardSlash() + GetEngineDirectory());

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

    int defaultNameSpaceCount = GetContentFindCount(fileName, GetDefaultSolutionName());

    int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultManagerCapitalCount = GetContentFindCount(fileName, GetDefaultManagerCapital());

    int defaultInterfaceNameCount = GetContentFindCount(fileName, GetDefaultInterfaceName());

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName(resultName);

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetEventManagerName(), GetEventManagerInterface(),
                                        GetProjectCapital(), GetEventManagerCapitalName());

    System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

    ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
    ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

    ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
    ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

    ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 5);
    ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

    ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
    ContentCountTest(fullName, GetEventManagerName(), defaultManagerNameCount + defaultInterfaceNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetEventManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetDefaultInterfaceName(), 0, __FUNCTION__, 13);
    ContentCountTest(fullName, GetEventManagerInterface(), defaultInterfaceNameCount, __FUNCTION__, 14);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 15);
}

void AssistTools::GenerateTemplateEngineTesting::DefaultInputManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName)
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName);
    const System::String extension(SYSTEM_TEXT(".h"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName + GetForwardSlash() + GetEngineDirectory());

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

    int defaultNameSpaceCount = GetContentFindCount(fileName, GetDefaultSolutionName());

    int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultManagerCapitalCount = GetContentFindCount(fileName, GetDefaultManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalCount);

    int defaultInterfaceNameCount = GetContentFindCount(fileName, GetDefaultInterfaceName());

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName(resultName);

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetInputManagerName(), GetInputManagerInterface(),
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
    ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount + defaultInterfaceNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetDefaultInterfaceName(), 0, __FUNCTION__, 13);
    ContentCountTest(fullName, GetInputManagerInterface(), defaultInterfaceNameCount, __FUNCTION__, 14);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 15);
}

void AssistTools::GenerateTemplateEngineTesting::DefaultInputManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName)
{
    const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName);
    const System::String extension(SYSTEM_TEXT(".cpp"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName + GetForwardSlash() + GetEngineDirectory());

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

    int defaultNameSpaceCount = GetContentFindCount(fileName, GetDefaultSolutionName());

    int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());

    int defaultProjectCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
    ASSERT_LESS(0, defaultProjectCapitalCount);

    int defaultManagerCapitalCount = GetContentFindCount(fileName, GetDefaultManagerCapital());
    ASSERT_LESS(0, defaultManagerCapitalCount);

    int defaultInterfaceNameCount = GetContentFindCount(fileName, GetDefaultInterfaceName());

    CopyrightData copyrightData(GetCopyrightData());
    const System::String newFullProjectName(resultName);

    generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetSolutionName(), GetInputManagerName(), GetInputManagerInterface(),
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
    ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount + defaultInterfaceNameCount, __FUNCTION__, 8);

    ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
    ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

    ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 11);
    ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

    ContentCountTest(fullName, GetDefaultInterfaceName(), 0, __FUNCTION__, 13);
    ContentCountTest(fullName, GetInputManagerInterface(), defaultInterfaceNameCount, __FUNCTION__, 14);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 15);
}
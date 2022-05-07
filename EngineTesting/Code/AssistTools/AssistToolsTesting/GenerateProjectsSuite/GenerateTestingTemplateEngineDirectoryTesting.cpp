// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 11:00)

#include "GenerateTestingTemplateEngineDirectoryTesting.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateEngineDirectory.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTestingTemplateEngineDirectory)

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolutionExistTest);

    ASSERT_NOT_THROW_EXCEPTION_1(ModuleExistTest, SYSTEM_TEXT(""s));
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleExistTest, SYSTEM_TEXT("MiddleLayer"s));
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleExistTest, SYSTEM_TEXT("Core"s));
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::GenerateToTest()
{
    const System::String newCoreName(SYSTEM_TEXT("Core"));
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String newTestingIncludeName(SYSTEM_TEXT("GameTemplateTestingInclude"));
    const System::String newDebugLibName(SYSTEM_TEXT("GameTemplateDebugLib"));
    const System::String newReleaseLibName(SYSTEM_TEXT("GameTemplateReleaseLib"));

    TestingType generateTestingTemplateEngineDirectory(GetResourceDirectory(), "Configuration/StringReplacing.json");

    generateTestingTemplateEngineDirectory.GenerateTo(GetExportDirectory() + GetTesting(), GetSolutionName(), newCoreName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::SolutionExistTest()
{
    const System::String newCoreName(SYSTEM_TEXT("Core"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplate.txt"));
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String coreName(SYSTEM_TEXT("ToolsName"));
    const System::String extension(SYSTEM_TEXT(".sln"));
    const System::String fullDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName() + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    const int coreNameCount = GetContentFindCount(fullName, newCoreName);

    ASSERT_LESS(0, projectNameCount);
    ASSERT_LESS(0, coreNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);
    ContentCountTest(fullName, coreName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::ModuleExistTest(const System::String& managerName)
{
    VcxprojExistTest(managerName);
    VcxprojFiltersExistTest(managerName);
    LogJsonExistTest(managerName);
    EnvironmentVariableExistTest(managerName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::VcxprojExistTest(const System::String& managerName)
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String projectName(SYSTEM_TEXT("NewProjectName"));
    const System::String includeName(SYSTEM_TEXT("GameIncludeName"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String testingIncludeName(SYSTEM_TEXT("TestingIncludeName"));
    const System::String debugLibName(SYSTEM_TEXT("DebugLibName"));
    const System::String releaseLibName(SYSTEM_TEXT("ReleaseLibName"));
    const System::String mewTestingIncludeName(SYSTEM_TEXT("GameTemplateTestingInclude"));
    const System::String newDebugLibName(SYSTEM_TEXT("GameTemplateDebugLib"));
    const System::String newReleaseLibName(SYSTEM_TEXT("GameTemplateReleaseLib"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + GetSolutionName() + managerName + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + managerName + GetTesting() + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    const int includeNameCount = GetContentFindCount(fullName, newIncludeName);
    const int testingIncludeNameCount = GetContentFindCount(fullName, mewTestingIncludeName);
    const int moduleNameCount = GetContentFindCount(fullName, managerName);
    const int debugLibNameCount = GetContentFindCount(fullName, newDebugLibName);
    const int releaseLibNameCount = GetContentFindCount(fullName, newReleaseLibName);

    ASSERT_LESS(0, projectNameCount);
    ASSERT_LESS(0, includeNameCount);
    ASSERT_LESS(0, testingIncludeNameCount);

    if (!managerName.empty())
    {
        ASSERT_LESS(0, moduleNameCount);
    }

    ASSERT_LESS(0, debugLibNameCount);
    ASSERT_LESS(0, releaseLibNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);
    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 1);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 2);
    ContentCountTest(fullName, testingIncludeName, 0, __FUNCTION__, 3);
    ContentCountTest(fullName, debugLibName, 0, __FUNCTION__, 4);
    ContentCountTest(fullName, releaseLibName, 0, __FUNCTION__, 5);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::VcxprojFiltersExistTest(const System::String& managerName)
{
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + GetSolutionName() + managerName + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + managerName + GetTesting() + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    const int moduleNameCount = GetContentFindCount(fullName, managerName);

    ASSERT_LESS(0, projectNameCount);
    if (!managerName.empty())
    {
        ASSERT_LESS(0, moduleNameCount);
    }

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);
    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::LogJsonExistTest(const System::String& managerName)
{
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String extension(SYSTEM_TEXT(".json"));
    const System::String newFileName(SYSTEM_TEXT("Log"));
    const System::String configurationDirectory(SYSTEM_TEXT("Configuration"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + GetSolutionName() + managerName + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + configurationDirectory + GetForwardSlash() + newFileName + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    ASSERT_LESS(0, projectNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 1);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::TestingJsonExistTest(const System::String& managerName)
{
    const System::String configurationDirectory(SYSTEM_TEXT("Configuration"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + GetSolutionName() + managerName + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + configurationDirectory + GetForwardSlash() + SYSTEM_TEXT("Testing.json");

    CoreTools::ReadFileManager manager(fullName);
}

void AssistTools::GenerateTestingTemplateEngineDirectoryTesting::EnvironmentVariableExistTest(const System::String& managerName)
{
    const System::String configurationDirectory(SYSTEM_TEXT("Configuration"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + GetSolutionName() + managerName + GetTesting());

    System::String fullName = fullDirectory + GetForwardSlash() + configurationDirectory + GetForwardSlash() + SYSTEM_TEXT("EnvironmentVariable.json");

    CoreTools::ReadFileManager manager(fullName);
}
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:53)

#include "GenerateTemplateEngineDirectoryTesting.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateTemplateEngineDirectory.h"

using namespace std::literals;

AssistTools::GenerateTemplateEngineDirectoryTesting::GenerateTemplateEngineDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateEngineDirectoryTesting)

void AssistTools::GenerateTemplateEngineDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolutionExistTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VcxprojExistTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VcxprojFiltersExistTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleVcxprojExistTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleVcxprojFiltersExistTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogJsonExistTest);

    ASSERT_NOT_THROW_EXCEPTION_1(MiddleLayerExistTest, SYSTEM_TEXT("MiddleLayer"s));
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::GenerateToTest()
{
    const System::String newCoreName(SYSTEM_TEXT("Core"));
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));

    GenerateTemplateEngineDirectory generateTemplateEngineDirectory(GetResourceDirectory(), "Configuration/StringReplacing.json");

    generateTemplateEngineDirectory.GenerateTo(GetExportDirectory(), GetSolutionName(), newCoreName, newIncludeName);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::SolutionExistTest()
{
    const System::String newCoreName(SYSTEM_TEXT("Core"));
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String coreName(SYSTEM_TEXT("ToolsName"));
    const System::String extension(SYSTEM_TEXT(".sln"));
    const System::String fullDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    const int coreNameCount = GetContentFindCount(fullName, newCoreName);

    ASSERT_LESS(0, projectNameCount);
    ASSERT_LESS(0, coreNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);
    ContentCountTest(fullName, coreName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::VcxprojExistTest()
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String projectName(SYSTEM_TEXT("ExeProjectName"));
    const System::String includeName(SYSTEM_TEXT("IncludeName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    const int coreNameCount = GetContentFindCount(fullName, newIncludeName);

    ASSERT_LESS(0, projectNameCount);
    ASSERT_LESS(0, coreNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 1);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::VcxprojFiltersExistTest()
{
    const System::String projectName(SYSTEM_TEXT("ExeProjectName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    ASSERT_LESS(0, projectNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 1);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::ModuleVcxprojExistTest()
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String newModuleName(SYSTEM_TEXT("Core"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String includeName(SYSTEM_TEXT("IncludeName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + newModuleName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + newModuleName + extension;

    const int moduleNameCount = GetContentFindCount(fullName, newModuleName);
    ASSERT_LESS(0, moduleNameCount);

    const int coreNameCount = GetContentFindCount(fullName, newIncludeName);
    ASSERT_LESS(0, coreNameCount);

    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 0);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 1);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::ModuleVcxprojFiltersExistTest()
{
    const System::String newModuleName(SYSTEM_TEXT("Core"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + newModuleName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + newModuleName + extension;

    const int moduleNameCount = GetContentFindCount(fullName, newModuleName);
    ASSERT_LESS(0, moduleNameCount);

    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 1);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::LogJsonExistTest()
{
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String extension(SYSTEM_TEXT(".json"));
    const System::String newFileName(SYSTEM_TEXT("Log"));
    const System::String configurationDirectory(SYSTEM_TEXT("Configuration"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + configurationDirectory);

    System::String fullName = fullDirectory + GetForwardSlash() + newFileName + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    ASSERT_LESS(0, projectNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::MiddleLayerExistTest(const System::String& managerName)
{
    MiddleLayerVcxprojExistTest(managerName);
    MiddleLayerVcxprojFiltersExistTest(managerName);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::MiddleLayerVcxprojExistTest(const System::String& managerName)
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String includeName(SYSTEM_TEXT("IncludeName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + managerName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + managerName + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    ASSERT_LESS(0, projectNameCount);

    const int coreNameCount = GetContentFindCount(fullName, newIncludeName);
    ASSERT_LESS(0, coreNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 1);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::MiddleLayerVcxprojFiltersExistTest(const System::String& managerName)
{
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + managerName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + managerName + extension;

    int projectNameCount = GetContentFindCount(fullName, GetSolutionName());
    ASSERT_LESS(0, projectNameCount);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 0);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 1);
}

void AssistTools::GenerateTemplateEngineDirectoryTesting::EnvironmentVariableExistTest()
{
    const System::String fullDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + SYSTEM_TEXT("Configuration"));

    System::String fullName = fullDirectory + GetForwardSlash() + SYSTEM_TEXT("EnvironmentVariable.json");

    CoreTools::ReadFileManager manager(fullName);
}

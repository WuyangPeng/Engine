// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:59)

#include "GenerateTemplateModuleVcxprojFiltersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateModuleVcxprojFilters.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateModuleVcxprojFilters)

void AssistTools::GenerateTemplateModuleVcxprojFiltersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateModuleVcxprojFiltersTesting::GenerateToTest()
{
    const System::String newModuleName(SYSTEM_TEXT("Core"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateModuleVcxprojFilters.txt"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + newModuleName);

    const int moduleNameCount = GetContentFindCount(fileName, moduleName);

    TestingType generateTemplateSolution(fileName, projectName, moduleName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newModuleName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + newModuleName + extension;

    ContentCountTest(fullName, newModuleName, moduleNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

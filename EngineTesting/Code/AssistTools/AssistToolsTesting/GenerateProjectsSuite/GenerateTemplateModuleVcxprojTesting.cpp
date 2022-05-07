// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:59)

#include "GenerateTemplateModuleVcxprojTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateModuleVcxproj.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateModuleVcxproj)

void AssistTools::GenerateTemplateModuleVcxprojTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateModuleVcxprojTesting::GenerateToTest()
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String newModuleName(SYSTEM_TEXT("Core"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateModuleVcxproj.txt"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String includeName(SYSTEM_TEXT("IncludeName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + newModuleName);

    const int moduleNameCount = GetContentFindCount(fileName, moduleName);
    const int coreNameCount = GetContentFindCount(fileName, includeName);

    TestingType generateTemplateSolution(fileName, projectName, moduleName, includeName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newModuleName, newIncludeName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + newModuleName + extension;

    ContentCountTest(fullName, newModuleName, moduleNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, newIncludeName, coreNameCount, __FUNCTION__, 1);

    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 2);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 3);
}

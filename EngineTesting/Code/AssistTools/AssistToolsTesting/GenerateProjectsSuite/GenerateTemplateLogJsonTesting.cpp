// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:58)

#include "GenerateTemplateLogJsonTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateLogJson.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateLogJson)

void AssistTools::GenerateTemplateLogJsonTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateLogJsonTesting::GenerateToTest()
{
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLog.txt"));
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String extension(SYSTEM_TEXT(".json"));
    const System::String newFileName(SYSTEM_TEXT("Log"));
    const System::String configurationDirectory(SYSTEM_TEXT("Configuration"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + configurationDirectory);

    const int projectNameCount = GetContentFindCount(fileName, projectName);

    TestingType generateTemplateSolution(fileName, projectName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newFileName);

    System::String fullName = fullDirectory + GetForwardSlash() + newFileName + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

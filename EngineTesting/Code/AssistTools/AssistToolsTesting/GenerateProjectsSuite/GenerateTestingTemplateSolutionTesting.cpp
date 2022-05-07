// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 11:00)

#include "GenerateTestingTemplateSolutionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateSolution.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTestingTemplateSolution)

void AssistTools::GenerateTestingTemplateSolutionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTestingTemplateSolutionTesting::GenerateToTest()
{
    const System::String newCoreName(SYSTEM_TEXT("Core"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplate.txt"));
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String coreName(SYSTEM_TEXT("ToolsName"));
    const System::String extension(SYSTEM_TEXT(".sln"));
    const System::String fullDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName() + GetTesting());

    const int projectNameCount = GetContentFindCount(fileName, projectName);
    const int coreNameCount = GetContentFindCount(fileName, coreName);

    TestingType generateTestingTemplateSolution(fileName, projectName, coreName);

    generateTestingTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newCoreName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, newCoreName, coreNameCount, __FUNCTION__, 1);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 2);
    ContentCountTest(fullName, coreName, 0, __FUNCTION__, 3);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 4);
}

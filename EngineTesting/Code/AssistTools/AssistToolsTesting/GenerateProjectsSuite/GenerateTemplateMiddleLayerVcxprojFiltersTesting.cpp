// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:59)

#include "GenerateTemplateMiddleLayerVcxprojFiltersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMiddleLayerVcxprojFilters.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateMiddleLayerVcxprojFilters)

void AssistTools::GenerateTemplateMiddleLayerVcxprojFiltersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateMiddleLayerVcxprojFiltersTesting::GenerateToTest()
{
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMiddleLayerVcxprojFilters.txt"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + GetMiddleLayerName());

    const int projectNameCount = GetContentFindCount(fileName, projectName);

    TestingType generateTemplateSolution(fileName, projectName, GetDefaultManagerName());

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), GetMiddleLayerName());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + GetMiddleLayerName() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

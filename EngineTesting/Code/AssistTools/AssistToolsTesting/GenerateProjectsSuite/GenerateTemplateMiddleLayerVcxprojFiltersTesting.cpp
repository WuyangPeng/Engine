///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 16:39)

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

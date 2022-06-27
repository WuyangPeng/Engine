///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 16:43)

#include "GenerateTemplateVcxprojFiltersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateVcxprojFilters.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateVcxprojFilters)

void AssistTools::GenerateTemplateVcxprojFiltersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateVcxprojFiltersTesting::GenerateToTest()
{
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateVcxprojFilters.txt"));
    const System::String projectName(SYSTEM_TEXT("ExeProjectName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

    const int projectNameCount = GetContentFindCount(fileName, projectName);

    TestingType generateTemplateSolution(fileName, projectName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 16:44)

#include "GenerateTestingTemplateVcxprojFiltersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateVcxprojFilters.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTestingTemplateVcxprojFilters)

void AssistTools::GenerateTestingTemplateVcxprojFiltersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTestingTemplateVcxprojFiltersTesting::GenerateToTest()
{
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplateVcxprojFilters.txt"));
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + GetSolutionName() + GetInputManagerName() + GetTesting());

    const int projectNameCount = GetContentFindCount(fileName, projectName);
    const int moduleNameCount = GetContentFindCount(fileName, moduleName);

    TestingType generateTestingTemplateVcxprojFilters(fileName, projectName, moduleName);

    generateTestingTemplateVcxprojFilters.GenerateTo(fullDirectory, GetSolutionName(), GetInputManagerName());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + GetInputManagerName() + GetTesting() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, GetInputManagerName(), moduleNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);
    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 2);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 3);
}

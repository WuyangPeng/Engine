///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 16:41)

#include "GenerateTemplateSolutionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateSolution.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateSolution)

void AssistTools::GenerateTemplateSolutionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateSolutionTesting::GenerateToTest()
{
    const System::String newCoreName(SYSTEM_TEXT("Core"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplate.txt"));
    const System::String projectName(SYSTEM_TEXT("ProjectName"));
    const System::String coreName(SYSTEM_TEXT("ToolsName"));
    const System::String extension(SYSTEM_TEXT(".sln"));
    const System::String fullDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory() + GetForwardSlash() + GetSolutionName());

    const int projectNameCount = GetContentFindCount(fileName, projectName);
    const int coreNameCount = GetContentFindCount(fileName, coreName);

    TestingType generateTemplateSolution(fileName, projectName, coreName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newCoreName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, newCoreName, coreNameCount, __FUNCTION__, 1);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 2);
    ContentCountTest(fullName, coreName, 0, __FUNCTION__, 3);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 4);
}

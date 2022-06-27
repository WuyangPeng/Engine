///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 16:43)

#include "GenerateTemplateVcxprojTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateVcxproj.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateVcxproj)

void AssistTools::GenerateTemplateVcxprojTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateVcxprojTesting::GenerateToTest()
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateVcxproj.txt"));
    const System::String projectName(SYSTEM_TEXT("ExeProjectName"));
    const System::String includeName(SYSTEM_TEXT("IncludeName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

    const int projectNameCount = GetContentFindCount(fileName, projectName);
    const int coreNameCount = GetContentFindCount(fileName, includeName);

    TestingType generateTemplateSolution(fileName, projectName, includeName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newIncludeName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, newIncludeName, coreNameCount, __FUNCTION__, 1);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 2);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 3);
}
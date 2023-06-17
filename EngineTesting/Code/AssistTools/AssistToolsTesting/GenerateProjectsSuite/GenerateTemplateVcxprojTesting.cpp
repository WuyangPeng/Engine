///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:54)

#include "GenerateTemplateVcxprojTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateTemplateVcxproj.h"

AssistTools::GenerateTemplateVcxprojTesting::GenerateTemplateVcxprojTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateVcxprojTesting)

void AssistTools::GenerateTemplateVcxprojTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    GenerateTemplateVcxproj generateTemplateSolution(fileName, projectName, includeName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newIncludeName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, newIncludeName, coreNameCount, __FUNCTION__, 1);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 2);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 3);
}
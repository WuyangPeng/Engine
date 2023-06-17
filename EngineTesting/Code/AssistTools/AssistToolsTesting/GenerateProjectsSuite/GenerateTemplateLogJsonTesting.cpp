///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:53)

#include "GenerateTemplateLogJsonTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateTemplateLogJson.h"

AssistTools::GenerateTemplateLogJsonTesting::GenerateTemplateLogJsonTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateLogJsonTesting)

void AssistTools::GenerateTemplateLogJsonTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    GenerateTemplateLogJson generateTemplateSolution(fileName, projectName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newFileName);

    System::String fullName = fullDirectory + GetForwardSlash() + newFileName + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

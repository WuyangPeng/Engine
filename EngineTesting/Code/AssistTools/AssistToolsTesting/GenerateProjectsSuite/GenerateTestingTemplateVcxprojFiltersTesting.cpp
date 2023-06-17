///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:55)

#include "GenerateTestingTemplateVcxprojFiltersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateVcxprojFilters.h"

AssistTools::GenerateTestingTemplateVcxprojFiltersTesting::GenerateTestingTemplateVcxprojFiltersTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateVcxprojFiltersTesting)

void AssistTools::GenerateTestingTemplateVcxprojFiltersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    GenerateTestingTemplateVcxprojFilters generateTestingTemplateVcxprojFilters(fileName, projectName, moduleName);

    generateTestingTemplateVcxprojFilters.GenerateTo(fullDirectory, GetSolutionName(), GetInputManagerName());

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + GetInputManagerName() + GetTesting() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, GetInputManagerName(), moduleNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);
    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 2);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 3);
}

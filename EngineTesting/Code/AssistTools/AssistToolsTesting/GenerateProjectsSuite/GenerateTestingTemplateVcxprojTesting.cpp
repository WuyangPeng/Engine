///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:55)

#include "GenerateTestingTemplateVcxprojTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateVcxproj.h"

AssistTools::GenerateTestingTemplateVcxprojTesting::GenerateTestingTemplateVcxprojTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateVcxprojTesting)

void AssistTools::GenerateTestingTemplateVcxprojTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GenerateTestingTemplateVcxprojTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTestingTemplateVcxprojTesting::GenerateToTest()
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTestingTemplateVcxproj.txt"));
    const System::String projectName(SYSTEM_TEXT("NewProjectName"));
    const System::String includeName(SYSTEM_TEXT("GameIncludeName"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String testingIncludeName(SYSTEM_TEXT("TestingIncludeName"));
    const System::String debugLibName(SYSTEM_TEXT("DebugLibName"));
    const System::String releaseLibName(SYSTEM_TEXT("ReleaseLibName"));
    const System::String mewTestingIncludeName(SYSTEM_TEXT("GameTemplateTestingInclude"));
    const System::String newDebugLibName(SYSTEM_TEXT("GameTemplateDebugLib"));
    const System::String newReleaseLibName(SYSTEM_TEXT("GameTemplateReleaseLib"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + GetSolutionName() + GetInputManagerName() + GetTesting());

    const int projectNameCount = GetContentFindCount(fileName, projectName);
    const int includeNameCount = GetContentFindCount(fileName, includeName);
    const int testingIncludeNameCount = GetContentFindCount(fileName, testingIncludeName);
    const int moduleNameCount = GetContentFindCount(fileName, moduleName);
    const int debugLibNameCount = GetContentFindCount(fileName, debugLibName);
    const int releaseLibNameCount = GetContentFindCount(fileName, releaseLibName);

    GenerateTestingTemplateVcxproj generateTestingTemplateVcxproj(fileName, projectName, moduleName, includeName, testingIncludeName, debugLibName, releaseLibName);

    generateTestingTemplateVcxproj.GenerateTo(fullDirectory, GetSolutionName(), GetInputManagerName(), newIncludeName,
                                              mewTestingIncludeName, newDebugLibName, newReleaseLibName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + GetInputManagerName() + GetTesting() + extension;

    ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, GetInputManagerName(), moduleNameCount, __FUNCTION__, 1);
    ContentCountTest(fullName, newIncludeName, includeNameCount, __FUNCTION__, 2);
    ContentCountTest(fullName, mewTestingIncludeName, testingIncludeNameCount, __FUNCTION__, 3);
    ContentCountTest(fullName, newDebugLibName, debugLibNameCount, __FUNCTION__, 4);
    ContentCountTest(fullName, newReleaseLibName, releaseLibNameCount, __FUNCTION__, 5);

    ContentCountTest(fullName, projectName, 0, __FUNCTION__, 6);
    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 7);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 8);
    ContentCountTest(fullName, testingIncludeName, 0, __FUNCTION__, 9);
    ContentCountTest(fullName, debugLibName, 0, __FUNCTION__, 10);
    ContentCountTest(fullName, releaseLibName, 0, __FUNCTION__, 11);
}

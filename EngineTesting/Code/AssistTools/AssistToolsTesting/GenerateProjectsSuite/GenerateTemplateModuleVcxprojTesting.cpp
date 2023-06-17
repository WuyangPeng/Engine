///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:54)

#include "GenerateTemplateModuleVcxprojTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateTemplateModuleVcxproj.h"

AssistTools::GenerateTemplateModuleVcxprojTesting::GenerateTemplateModuleVcxprojTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateModuleVcxprojTesting)

void AssistTools::GenerateTemplateModuleVcxprojTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GenerateTemplateModuleVcxprojTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateModuleVcxprojTesting::GenerateToTest()
{
    const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude"));
    const System::String newModuleName(SYSTEM_TEXT("Core"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateModuleVcxproj.txt"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String includeName(SYSTEM_TEXT("IncludeName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + newModuleName);

    const int moduleNameCount = GetContentFindCount(fileName, moduleName);
    const int coreNameCount = GetContentFindCount(fileName, includeName);

    GenerateTemplateModuleVcxproj generateTemplateSolution(fileName, projectName, moduleName, includeName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newModuleName, newIncludeName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + newModuleName + extension;

    ContentCountTest(fullName, newModuleName, moduleNameCount, __FUNCTION__, 0);
    ContentCountTest(fullName, newIncludeName, coreNameCount, __FUNCTION__, 1);

    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 2);
    ContentCountTest(fullName, includeName, 0, __FUNCTION__, 3);
}

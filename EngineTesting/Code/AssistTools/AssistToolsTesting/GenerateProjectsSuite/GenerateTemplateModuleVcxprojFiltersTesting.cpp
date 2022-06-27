///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 16:40)

#include "GenerateTemplateModuleVcxprojFiltersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateModuleVcxprojFilters.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateModuleVcxprojFilters)

void AssistTools::GenerateTemplateModuleVcxprojFiltersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateModuleVcxprojFiltersTesting::GenerateToTest()
{
    const System::String newModuleName(SYSTEM_TEXT("Core"));
    const System::String moduleName(SYSTEM_TEXT("ModuleName"));
    const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateModuleVcxprojFilters.txt"));
    const System::String projectName(SYSTEM_TEXT("DllProjectName"));
    const System::String extension(SYSTEM_TEXT(".vcxproj.filters"));
    const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
    const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + newModuleName);

    const int moduleNameCount = GetContentFindCount(fileName, moduleName);

    TestingType generateTemplateSolution(fileName, projectName, moduleName);

    generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newModuleName);

    System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + newModuleName + extension;

    ContentCountTest(fullName, newModuleName, moduleNameCount, __FUNCTION__, 0);

    ContentCountTest(fullName, moduleName, 0, __FUNCTION__, 1);

    ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 15:48)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_DIRECTORY_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace AssistTools
{
    class GenerateTemplateEngineDirectoryTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTemplateEngineDirectoryTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTemplateEngineDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();

        void SolutionExistTest();
        void VcxprojExistTest();
        void VcxprojFiltersExistTest();
        void ModuleVcxprojExistTest();
        void ModuleVcxprojFiltersExistTest();
        void LogJsonExistTest();
        void MiddleLayerExistTest(const System::String& managerName);
        void MiddleLayerVcxprojExistTest(const System::String& managerName);
        void MiddleLayerVcxprojFiltersExistTest(const System::String& managerName);
        void EnvironmentVariableExistTest();

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_DIRECTORY_TESTING_H
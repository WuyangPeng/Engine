///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 16:10)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace AssistTools
{
    class GenerateTestingTemplateEngineDirectoryTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTestingTemplateEngineDirectoryTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTestingTemplateEngineDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();
        void SolutionExistTest();
        void ModuleExistTest(const System::String& managerName);
        void VcxprojExistTest(const System::String& managerName);
        void VcxprojFiltersExistTest(const System::String& managerName);
        void LogJsonExistTest(const System::String& managerName);
        void TestingJsonExistTest(const System::String& managerName);
        void EnvironmentVariableExistTest(const System::String& managerName);

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_TESTING_H
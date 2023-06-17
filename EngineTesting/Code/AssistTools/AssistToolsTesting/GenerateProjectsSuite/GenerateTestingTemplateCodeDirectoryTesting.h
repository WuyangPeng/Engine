///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:53)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class GenerateTestingTemplateCodeDirectoryTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTestingTemplateCodeDirectoryTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTestingTemplateCodeDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();
        void ManagerExistTest(const System::String& managerName);
        void ManagerHeaderExistTest(const System::String& managerName, const System::String& resultName);
        void ManagerCppExistTest(const System::String& managerName, const System::String& resultName);

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_TESTING_H
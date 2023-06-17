///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:53)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_VCXPROJ_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_VCXPROJ_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class GenerateTestingTemplateVcxprojTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTestingTemplateVcxprojTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTestingTemplateVcxprojTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_VCXPROJ_TESTING_H
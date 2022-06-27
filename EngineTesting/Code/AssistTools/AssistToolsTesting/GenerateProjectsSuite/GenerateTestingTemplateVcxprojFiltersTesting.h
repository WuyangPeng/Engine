///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 16:11)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace AssistTools
{
    class GenerateTestingTemplateVcxprojFiltersTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTestingTemplateVcxprojFiltersTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTestingTemplateVcxprojFiltersTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_TESTING_H
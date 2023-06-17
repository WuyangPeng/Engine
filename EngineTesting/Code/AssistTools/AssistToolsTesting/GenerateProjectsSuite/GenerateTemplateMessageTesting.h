///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:52)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MESSAGE_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MESSAGE_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class GenerateTemplateMessageTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTemplateMessageTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTemplateMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();
        void DefaultGenerateToTest(const System::String& testFileName, const System::String& extension);

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MESSAGE_TESTING_H
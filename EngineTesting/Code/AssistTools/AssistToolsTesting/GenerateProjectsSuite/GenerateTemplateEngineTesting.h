///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/22 15:48)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace AssistTools
{
    class GenerateTemplateEngineTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTemplateEngineTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTemplateEngineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();
        void DefaultEventManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName);
        void DefaultEventManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName);
        void DefaultInputManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName);
        void DefaultInputManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName);

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_TESTING_H
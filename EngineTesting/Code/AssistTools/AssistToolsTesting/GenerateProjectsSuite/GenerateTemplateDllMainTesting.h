// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:07)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_DLL_MAIN_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_DLL_MAIN_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace AssistTools
{
    class GenerateTemplateDllMainTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTemplateDllMainTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTemplateDllMainTesting(const OStreamShared& stream);
        CLASS_INVARIANT_OVERRIDE_DECLARE;
    private:
        void MainTest();

        void GenerateToTest();
        void DefaultGenerateToTest();

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_DLL_MAIN_TESTING_H
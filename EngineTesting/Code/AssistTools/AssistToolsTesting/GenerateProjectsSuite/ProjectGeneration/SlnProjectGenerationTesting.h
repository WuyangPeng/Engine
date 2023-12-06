/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 14:51)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_SLN_PROJECT_GENERATION_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_SLN_PROJECT_GENERATION_TESTING_H

#include "ProjectGenerationTesting.h"

namespace AssistTools
{
    class SlnProjectGenerationTesting final : public ProjectGenerationTesting
    {
    public:
        using ClassType = SlnProjectGenerationTesting;
        using ParentType = ProjectGenerationTesting;

    public:
        explicit SlnProjectGenerationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ToolProjectTest();
        void TestingToolProjectTest();
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_SLN_PROJECT_GENERATION_TESTING_H
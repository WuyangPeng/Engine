///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/13 11:19)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_UTF8_REPLACE_PROJECT_GENERATION_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_UTF8_REPLACE_PROJECT_GENERATION_TESTING_H

#include "ProjectGenerationTesting.h"

namespace AssistTools
{
    class Utf8ReplaceProjectGenerationTesting final : public ProjectGenerationTesting
    {
    public:
        using ClassType = Utf8ReplaceProjectGenerationTesting;
        using ParentType = ProjectGenerationTesting;

    public:
        explicit Utf8ReplaceProjectGenerationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_UTF8_REPLACE_PROJECT_GENERATION_TESTING_H
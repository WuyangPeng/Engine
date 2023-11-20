///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:42)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_REPLACE_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_REPLACE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class ReplaceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReplaceTesting;
        using ParentType = UnitTest;

    public:
        explicit ReplaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ReplaceTest();
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_REPLACE_TESTING_H
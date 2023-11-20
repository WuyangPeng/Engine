///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/09 15:01)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GAME_PARAMETER_ANALYSIS_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GAME_PARAMETER_ANALYSIS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class GameParameterAnalysisTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GameParameterAnalysisTesting;
        using ParentType = UnitTest;

    public:
        explicit GameParameterAnalysisTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ParameterTest();
        void ParameterDefaultTest();
        void ModuleTest();
        void ModuleDefaultTest();
        void MiddleLayerTest();
        void MiddleLayerDefaultTest();
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GAME_PARAMETER_ANALYSIS_TESTING_H
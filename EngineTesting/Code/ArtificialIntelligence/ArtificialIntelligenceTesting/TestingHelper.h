///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 19:33)

#ifndef ARTIFICIAL_INTELLIGENCE_TESTING_TESTING_HELPER_H
#define ARTIFICIAL_INTELLIGENCE_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace ArtificialIntelligence
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();
        void AddMiscellaneousSuite();
        void AddPathSearchSuite();
        void AddFiniteStateMachineSuite();
        void AddFuzzyStateMachineSuite();
        void AddGeneticAlgorithmSuite();
        void AddNeuralNetworkSuite();
    };
}

#endif  // ARTIFICIAL_INTELLIGENCE_TESTING_TESTING_HELPER_H
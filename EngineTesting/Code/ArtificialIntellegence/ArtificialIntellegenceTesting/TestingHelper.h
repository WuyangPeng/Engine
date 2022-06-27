///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/21 17:13)

#ifndef ARTIFICIAL_INTELLEGENCE_TESTING_TESTING_HELPER_H
#define ARTIFICIAL_INTELLEGENCE_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace ArtificialIntellegence
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

        void AddMacroSuite();
        void AddMiscellaneousSuite();
        void AddPathSearchSuite();
        void AddFiniteStateMachineSuite();
        void AddFuzzyStateMachineSuite();
        void AddGeneticAlgorithmSuite();
        void AddNeuralNetworkSuite();
    };
}

#endif  // ARTIFICIAL_INTELLEGENCE_TESTING_TESTING_HELPER_H
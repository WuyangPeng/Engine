// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/09 20:05)

#ifndef ARTIFICIAL_INTELLEGENCE_TESTING_TESTING_HELPER_H
#define ARTIFICIAL_INTELLEGENCE_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CoreTools
{
    class Suite;
}

namespace ArtificialIntellegence
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper);

        int DoRun() override;

    private:
        void AddSuites();

        void AddMacroSuite();
        void AddMiscellaneousSuite();
        void AddPathSearchSuite();
        void AddFiniteStateMachineSuite();
        void AddFuzzyStateMachineSuite();
        void AddGeneticAlgorithmSuite();
        void AddNeuralNetworkSuite();

    private:
        CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
    };
}

#endif  // ARTIFICIAL_INTELLEGENCE_TESTING_TESTING_HELPER_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 1:08)

#ifndef BOOK_ALGORITHM_TESTING_HELPER_H
#define BOOK_ALGORITHM_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookAlgorithm
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;
        using Suite = CoreTools::Suite;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddDiscreteMathematicsAndItsApplicationsSuite();

        Suite GetDiscreteMathematicsAndItsApplicationsSixthEditionSuite();
        Suite GetDiscreteMathematicsAndItsApplicationsSeventhEditionSuite();

        void AddIntroductionToAlgorithmsSuite();

        Suite GetIntroductionToAlgorithmsSecondEditionSuite();
        Suite GetIntroductionToAlgorithmsThirdEditionSuite();

        void AddProgrammingPearlsSuite();

        Suite GetProgrammingPearlsOneSuite();
        Suite GetMoreProgrammingPearlsSuite();

        void AddTheArtOfComputerProgrammingSuite();

        void AddAlgorithmsUnlockedSuite();

        void AddCryptographyForDevelopersSuite();

        void AddAlgorithmsSuite();

        Suite GetAlgorithmsInCppParts1_4Suite();
        Suite GetAlgorithmsInCppParts5Suite();
        Suite GetAlgorithmsFourthEditionSuite();

        void AddAlgorithmsSanjoyDasguptaSuite();

        void AddWriteGreatCodeSuite();

        Suite GetUnderstandingTheMachineSuite();
        Suite GetThinkingLowLevelWritingHighLevelSuite();

        void AddHackersDelightSuite();

        void AddPracticalAlgorithmsForProgrammersSuite();

        void AddDataStructuresWithCppUsingSTLSuite();

        void AddAppliedCryptographySuite();

        void AddDataStructuresAndAlgorithmAnalysisInCppSuite();

        void AddElementaryNumberTheoryAndItsApplicationsSuite();

        void AddLinearAlgebraAndItsApplicationsSuite();

        void AddDataStructuresAndAlgorithmsInCppSuite();

        void AddAlgorithmicPuzzlesSuite();

        void AddNumericalRecipesInCppSuite();

        void AddConcreteMathematicSuite();

        void AddGrokkingAlgorithmsSuite();

        void AddHowToSolveSuite();

        void AddIntroductionToTheDesignAndAnalysisOfAlgorithmsSuite();

        void AddDataAbstractionAndProblemSolvingWithCppSuite();
    };
}

#endif  // BOOK_ALGORITHM_TESTING_HELPER_H
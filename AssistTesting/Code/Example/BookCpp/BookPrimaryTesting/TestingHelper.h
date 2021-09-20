///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/02/06 1:12)

#ifndef BOOK_PRIMARY_TESTING_HELPER_H
#define BOOK_PRIMARY_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookPrimary
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

        void AddThinkingInCppSuite();
        Suite GetThinkingInCppVolumeOneSuite();
        Suite GetThinkingInCppVolumeOneExerciseSuite();
        Suite GetThinkingInCppVolumeTwoSuite();

        void AddCppPrimerSuite();
        Suite GetCppPrimerFourthEditionSuite();
        Suite GetCppPrimerFifthEditionSuite();

        void AddCppHowToProgramSuite();
        Suite GetHowToProgramSeventhEditionSuite();
        Suite GetHowToProgramNinthEditionSuite();

        void AddProgrammingPrinciplesAndPracticeUsingCppSuite();

        void AddATourOfCppSuite();

        void AddEssentialCppSuite();

        void AddCppADialogSuite();

        void AddSamsTeachYourselfCppInOneHourADaySuite();

        void AddCppPrimerPlusSuite();

        void AddBeginningCpp17Suite();

        void AddAcceleratedCppSuite();

        void AddCppForTheImpatientSuite();

        void AddProblemSolvingWithCppSuite();

        void AddCppProgrammingSuite();

        void AddCAndCppCodeCapsulesSuite();

        void AddCppDistilledSuite();

        void AddComputingConceptsWithCppEssentialsSuite();

        void AddCppTheCompleteReferenceSuite();

        void AddCppTheCoreLanguageSuite();
    };
}

#endif  // BOOK_PRIMARY_TESTING_HELPER_H
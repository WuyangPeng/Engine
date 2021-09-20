///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/02/05 23:31)

#ifndef BOOK_INTERMEDIATE_TESTING_HELPER_H
#define BOOK_INTERMEDIATE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookIntermediate
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

        void AddTheCppProgrammingLanguageSuite();
        Suite GetTheCppProgrammingLanguageSpecialEditionSuite();
        Suite GetTheCppProgrammingLanguageSpecialEditionExerciseSuite();
        Suite GetTheCppProgrammingLanguageFourthEditionSuite();

        void AddRuminationsOnCppSuite();

        void AddEfficientCppPerformanceProgrammingTechniquesSuite();

        void AddImperfectCppSuite();

        void AddAppliedCppSuite();

        void AddOptimizedCppSuite();

        void AddCppFootprintAndPerformanceOptimizationSuite();

        void AddCppProgrammingTodaySuite();

        void AddCppGotchasSuite();

        void AddCppInActionIndustrialStrengthProgrammingTechniquesSuite();

        void AddCppStrategiesAndTacticsSuite();

        void AddCppCookbookSuite();

        void AddAdvancedCppSuite();

        void AddProfessionalCppSuite();

        void AddCoreCppASoftwareEnginearingApproachSuite();

        void AddCppEffectiveObjectOrientedSoftwareConstructionSuite();

        void AddHowNotToProgramInCppSuite();
    };
}

#endif  // BOOK_INTERMEDIATE_TESTING_HELPER_H
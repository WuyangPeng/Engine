// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/16 19:13)

#ifndef MATHEMATICS_TESTING_TESTING_HELPER_H
#define MATHEMATICS_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CoreTools
{
    class Suite;
}

namespace Mathematics
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
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

        void AddMacroSuite();
        void AddBaseSuite();
        void AddAlgebraSuite();
        void AddObjects2DSuite();
        void AddObjects3DSuite();
        void AddRationalSuite();
        void AddNumericalAnalysisSuite();
        void AddQuerySuite();
        void AddApproximationSuite();
        void AddContainmentSuite();
        void AddIntersectionSuite();
        void AddComputationalGeometrySuite();
        void AddDistanceSuite();
        void AddMeshesSuite();
        void AddCurvesSurfacesVolumesSuite();
        void AddInterpolationSuite();
        void AddMiscellaneousSuite();

        Suite GetDistance2DSuite();
        Suite GetDistance3DSuite();

        Suite GetIntersection1DSuite();
        Suite GetIntersection2DSuite();
        Suite GetIntersection3DSuite();
    };
}

#endif  // MATHEMATICS_TESTING_TESTING_HELPER_H
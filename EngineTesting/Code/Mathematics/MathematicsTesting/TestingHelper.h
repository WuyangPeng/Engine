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
        CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper);

        virtual int DoRun() override;

    private:
        void AddSuites();

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

        void AddDistance2DSuite(Suite& suite);
        void AddDistance3DSuite(Suite& suite);

        void AddIntersection1DSuite(Suite& suite);
        void AddIntersection2DSuite(Suite& suite);
        void AddIntersection3DSuite(Suite& suite);

    private:
        CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
    };
}

#endif  // MATHEMATICS_TESTING_TESTING_HELPER_H
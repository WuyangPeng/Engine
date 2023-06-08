///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 11:05)

#ifndef MATHEMATICS_TESTING_TESTING_HELPER_H
#define MATHEMATICS_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

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

        NODISCARD Suite GetDistance2DSuite();
        NODISCARD Suite GetDistance3DSuite();

        NODISCARD Suite GetIntersection1DSuite();
        NODISCARD Suite GetIntersection2DSuite();
        NODISCARD Suite GetIntersection3DSuite();
    };
}

#endif  // MATHEMATICS_TESTING_TESTING_HELPER_H
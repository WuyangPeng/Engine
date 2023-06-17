///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 10:45)

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

        void AddHelperSuite();
        void AddBaseSuite();
        void AddAlgebraSuite();
        void AddObjects2DSuite();
        void AddObjects3DSuite();
        void AddPrimitivesSuite();
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
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 16:20)

#ifndef MATHEMATICS_TESTING_TESTING_HELPER_H
#define MATHEMATICS_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace Mathematics
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

        void AddHelperSuite();
        void AddBaseSuite();
        void AddAlgebraSuite();

        NODISCARD Suite GetTransformSuite();

        void AddObjects2DSuite();
        void AddObjects3DSuite();
        void AddPrimitivesSuite();
        void AddRationalSuite();
        void AddNumericalAnalysisSuite();
        void AddQuerySuite();
        void AddApproximationSuite();
        void AddContainmentSuite();
        void AddIntersectionSuite();

        NODISCARD Suite GetIntersection1DSuite();
        NODISCARD Suite GetIntersection2DSuite();
        NODISCARD Suite GetIntersection3DSuite();

        void AddComputationalGeometrySuite();
        void AddDistanceSuite();

        NODISCARD Suite GetDistance2DSuite();
        NODISCARD Suite GetDistance3DSuite();

        void AddMeshesSuite();
        void AddCurvesSurfacesVolumesSuite();
        void AddInterpolationSuite();
        void AddMiscellaneousSuite();
    };
}

#endif  // MATHEMATICS_TESTING_TESTING_HELPER_H
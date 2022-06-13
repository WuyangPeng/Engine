///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 15:51)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_RUNGE_KUTTA4_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_RUNGE_KUTTA4_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace Mathematics
{
    class OdeRungeKutta4Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OdeRungeKutta4Testing);

        int GetDimension() const noexcept;

    private:
        void MainTest();
        void SolverTest();

        void DoRunUnitTest() override;

        NODISCARD static std::vector<double> OdeRungeKutta4Function(double tIn, const std::vector<double>& xIn, const OdeRungeKutta4Testing* odeEulerTesting);

    private:
        int dimension;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_RUNGE_KUTTA4_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TEST_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TEST_H

#include "OdeSolverTesting.h"
#include "Mathematics/NumericalAnalysis/OdeSolver.h"

namespace Mathematics
{
    class OdeSolverTest : public OdeSolver<double, OdeSolverTesting>
    {
    public:
        using ClassType = OdeSolverTest;
        using ParentType = OdeSolver<double, OdeSolverTesting>;
        using RealVector = ParentType::Container;

    public:
        OdeSolverTest(int dimension, double step, Function function, const OdeSolverTesting* userData);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD static RealVector OdeSolverTestFunction(double tIn, const RealVector& xIn, const OdeSolverTesting* odeSolverTest);
        NODISCARD Data Update(double tIn, const RealVector& xIn) override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TEST_H
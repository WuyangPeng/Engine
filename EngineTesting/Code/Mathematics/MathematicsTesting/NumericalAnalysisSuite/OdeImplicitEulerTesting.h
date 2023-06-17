///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_IMPLICIT_EULER_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_IMPLICIT_EULER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <vector>

namespace Mathematics
{
    class OdeImplicitEulerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OdeImplicitEulerTesting;
        using ParentType = UnitTest;

    public:
        explicit OdeImplicitEulerTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetDimension() const noexcept;

    private:
        void MainTest();
        void SolverTest();

        void DoRunUnitTest() override;

        NODISCARD static std::vector<double> OdeImplicitEulerFunction(double tIn, const std::vector<double>& xIn, const OdeImplicitEulerTesting* odeEulerTesting);

        NODISCARD static VariableMatrixD OdeImplicitEulerDerivativeFunction(double tIn, const std::vector<double>& xIn, const OdeImplicitEulerTesting* odeEulerTesting);

    private:
        int dimension;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_IMPLICIT_EULER_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 16:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class OdeSolverTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OdeSolverTesting;
        using ParentType = UnitTest;

    public:
        explicit OdeSolverTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetDimension() const noexcept;

    private:
        void MainTest();
        void SolverTest();

        void DoRunUnitTest() override;

    private:
        int dimension;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TESTING_H
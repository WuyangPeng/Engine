///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 16:05)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class SolveSymmetricConjugateGradientTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SolveSymmetricConjugateGradientTesting;
        using ParentType = UnitTest;

    public:
        explicit SolveSymmetricConjugateGradientTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void VariableMatrixTest() noexcept;
        void SparseMatrixTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_TESTING_H
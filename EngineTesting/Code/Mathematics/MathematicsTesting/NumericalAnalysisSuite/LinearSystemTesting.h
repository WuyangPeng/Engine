///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_LINEAR_SYSTEM_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_LINEAR_SYSTEM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class LinearSystemTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = LinearSystemTesting;
        using ParentType = UnitTest;

    public:
        explicit LinearSystemTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void Solve2Test();
        void Solve3Test();
        void InverseTest();
        void SolveTest();
        void SolveTridiagonalTest();
        void SolveConstTridiagonalTest();
        void SolveSymmetricConjugateGradientTest();
        void SolveBandedTest();
        void InvertTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_LINEAR_SYSTEM_TESTING_H
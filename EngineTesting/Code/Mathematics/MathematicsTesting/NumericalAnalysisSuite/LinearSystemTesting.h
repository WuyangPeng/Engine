///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 14:59)

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
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_EIGEN_DECOMPOSITION_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_EIGEN_DECOMPOSITION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class EigenDecompositionTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = EigenDecompositionTesting;
        using ParentType = UnitTest;

    public:
        explicit EigenDecompositionTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void Eigenvalue2Test();
        void Eigenvalue3Test();
        void EigenvalueNTest();
        void BaseTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_EIGEN_DECOMPOSITION_TESTING_H
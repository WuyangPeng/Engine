///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 16:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SPARSE_MATRIX_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SPARSE_MATRIX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class SparseMatrixTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SparseMatrixTesting;
        using ParentType = UnitTest;

    public:
        explicit SparseMatrixTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void SparseMatrixTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SPARSE_MATRIX_TESTING_H
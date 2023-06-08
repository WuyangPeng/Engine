///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 16:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SPARSE_MATRIX_INDEX_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SPARSE_MATRIX_INDEX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class SparseMatrixIndexTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SparseMatrixIndexTesting;
        using ParentType = UnitTest;

    public:
        explicit SparseMatrixIndexTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void OperatorTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SPARSE_MATRIX_INDEX_TESTING_H
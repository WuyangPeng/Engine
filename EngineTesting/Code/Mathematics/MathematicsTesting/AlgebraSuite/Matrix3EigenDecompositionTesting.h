///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:11)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EIGEN_DECOMPOSITION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EIGEN_DECOMPOSITION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Matrix3EigenDecompositionTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Matrix3EigenDecompositionTesting;
        using ParentType = UnitTest;

    public:
        explicit Matrix3EigenDecompositionTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void EigenDecompositionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EIGEN_DECOMPOSITION_TESTING_H
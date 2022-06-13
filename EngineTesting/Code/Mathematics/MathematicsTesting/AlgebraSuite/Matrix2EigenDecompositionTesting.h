///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX2_EIGEN_DECOMPOSITION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX2_EIGEN_DECOMPOSITION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Matrix2EigenDecompositionTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Matrix2EigenDecompositionTesting);

    private:
        void MainTest();
        void EigenDecompositionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_MATRIX2_EIGEN_DECOMPOSITION_TESTING_H
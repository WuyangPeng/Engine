///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_BANDED_MATRIX_SOLVE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_BANDED_MATRIX_SOLVE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class BandedMatrixSolveTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BandedMatrixSolveTesting);

    private:
        void MainTest();
        void ConstructionTest();
        void SolveTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_BANDED_MATRIX_SOLVE_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:08)

#include "SingularValueDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/SingularValueDecompositionDetail.h"

#include <random>

using std::default_random_engine;
using std::swap;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class SingularValueDecomposition<float>;
    template class SingularValueDecomposition<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SingularValueDecompositionTesting)

void Mathematics::SingularValueDecompositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
}

void Mathematics::SingularValueDecompositionTesting::SingularValueTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);
    const uniform_int<> secondRandomDistribution(2, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        int row = secondRandomDistribution(generator);
        int colomn = secondRandomDistribution(generator);

        if (row < colomn)
        {
            swap(row, colomn);
        }

        VariableMatrixD matrix(row, colomn);

        for (int m = 0; m < row; ++m)
        {
            for (int j = 0; j < colomn; ++j)
            {
                matrix(m, j) = firstRandomDistribution(generator);
            }
        }

        SingularValueDecompositionD singularValueDecomposition(matrix);

        VariableMatrixD leftMatrix = singularValueDecomposition.GetLeftMatrix();
        VariableMatrixD diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
        VariableMatrixD rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

        VariableMatrixD result = leftMatrix * diagonalMatrix;
        result *= rightTransposeMatrix;

        using VariableMatrixdApproximate = bool (*)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-6);
    }
}

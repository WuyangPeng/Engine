///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:08)

#include "SingularValueDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/SingularValueDecompositionDetail.h"

#include <random>

namespace Mathematics
{
    template class SingularValueDecomposition<float>;
    template class SingularValueDecomposition<double>;
}

Mathematics::SingularValueDecompositionTesting::SingularValueDecompositionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, SingularValueDecompositionTesting)

void Mathematics::SingularValueDecompositionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::SingularValueDecompositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
}

void Mathematics::SingularValueDecompositionTesting::SingularValueTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-1.0e5, 1.0e5);
    const std::uniform_int<> randomDistribution1(2, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        int row = randomDistribution1(generator);
        int colomn = randomDistribution1(generator);

        if (row < colomn)
        {
            std::swap(row, colomn);
        }

        VariableMatrixD matrix(row, colomn);

        for (int m = 0; m < row; ++m)
        {
            for (int j = 0; j < colomn; ++j)
            {
                matrix(m, j) = randomDistribution0(generator);
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

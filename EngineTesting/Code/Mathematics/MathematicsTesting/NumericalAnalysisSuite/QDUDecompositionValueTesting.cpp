///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:07)

#include "QDUDecompositionValueTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/QDUDecompositionValueDetail.h"

#include <random>

using std::default_random_engine;
using std::swap;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class QDUDecompositionValue<float>;
    template class QDUDecompositionValue<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QDUDecompositionValueTesting)

void Mathematics::QDUDecompositionValueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QDUDecompositionValueTest);
}

void Mathematics::QDUDecompositionValueTesting::QDUDecompositionValueTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Matrix3D matrix;

        for (int m = 0; m < 3; ++m)
        {
            for (int j = 0; j < 3; ++j)
            {
                matrix(m, j) = firstRandomDistribution(generator);
            }
        }

        const QDUDecompositionValueD qDUDecompositionValue(matrix);

        const Matrix3D orthogonalMatrix = qDUDecompositionValue.GeOrthogonalMatrix();
        const Matrix3D diagonalMatrix = qDUDecompositionValue.GetDiagonalMatrix();
        const Matrix3D upperTriangularMatrix = qDUDecompositionValue.GetUpperTriangularMatrix();

        Matrix3D result = orthogonalMatrix * diagonalMatrix;
        result *= upperTriangularMatrix;

        using VariableMatrixdApproximate = bool (*)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-5);
    }
}

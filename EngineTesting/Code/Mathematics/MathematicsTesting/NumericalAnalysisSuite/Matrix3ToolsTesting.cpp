///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 21:47)

#include "Matrix3ToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Matrix3ToolsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class Matrix3Tools<float>;
    template class Matrix3Tools<double>;
}

Mathematics::Matrix3ToolsTesting::Matrix3ToolsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Matrix3ToolsTesting)

void Mathematics::Matrix3ToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Matrix3ToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PolarDecompositionValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QDUDecompositionValueTest);
}

void Mathematics::Matrix3ToolsTesting::SingularValueTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Matrix3D matrix;

        for (auto m = 0; m < 3; ++m)
        {
            for (auto j = 0; j < 3; ++j)
            {
                matrix(m, j) = firstRandomDistribution(generator);
            }
        }

        const Matrix3ToolsD matrix3Tools(matrix);

        const SingularValueD singularValueDecomposition = matrix3Tools.SingularValueDecomposition();

        const auto leftMatrix = singularValueDecomposition.GetLeftMatrix();
        const auto diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
        const auto rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

        auto result = leftMatrix * diagonalMatrix;
        result *= rightTransposeMatrix;

        using VariableMatrixdApproximate = bool (*)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-6);
    }
}

void Mathematics::Matrix3ToolsTesting::PolarDecompositionValueTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Matrix3D matrix;

        for (auto m = 0; m < 3; ++m)
        {
            for (auto j = 0; j < 3; ++j)
            {
                matrix(m, j) = firstRandomDistribution(generator);
            }
        }

        const Matrix3ToolsD matrix3Tools(matrix);

        const auto polarDecompositionValue = matrix3Tools.PolarDecomposition();

        const auto orthogonalMatrix = polarDecompositionValue.GeOrthogonalMatrix();
        const auto symmetryMatrix = polarDecompositionValue.GetSymmetryMatrix();

        const auto result = orthogonalMatrix * symmetryMatrix;

        using VariableMatrixdApproximate = bool (*)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-6);
    }
}

void Mathematics::Matrix3ToolsTesting::QDUDecompositionValueTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Matrix3D matrix;

        for (auto m = 0; m < 3; ++m)
        {
            for (auto j = 0; j < 3; ++j)
            {
                matrix(m, j) = firstRandomDistribution(generator);
            }
        }
        const Matrix3ToolsD matrix3Tools(matrix);

        const QDUDecompositionValueD qDUDecompositionValue(matrix3Tools.QDUDecomposition());

        const auto orthogonalMatrix = qDUDecompositionValue.GeOrthogonalMatrix();
        const auto diagonalMatrix = qDUDecompositionValue.GetDiagonalMatrix();
        const auto upperTriangularMatrix = qDUDecompositionValue.GetUpperTriangularMatrix();

        auto result = orthogonalMatrix * diagonalMatrix;
        result *= upperTriangularMatrix;

        using VariableMatrixdApproximate = bool (*)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-5);
    }
}

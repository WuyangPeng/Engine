// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:02)

#include "Matrix3ToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Matrix3ToolsDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26481)
namespace Mathematics
{
    template class Matrix3Tools<float>;
    template class Matrix3Tools<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Matrix3ToolsTesting)

void Mathematics::Matrix3ToolsTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PolarDecompositionValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QDUDecompositionValueTest);
}

void Mathematics::Matrix3ToolsTesting ::SingularValueTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

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

        Matrix3ToolsD matrix3Tools(matrix);

        SingularValueD singularValueDecomposition = matrix3Tools.SingularValueDecomposition();

        Matrix3D leftMatrix = singularValueDecomposition.GetLeftMatrix();
        Matrix3D diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
        Matrix3D rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

        Matrix3D result = leftMatrix * diagonalMatrix;
        result *= rightTransposeMatrix;

        typedef bool (*VariableMatrixdApproximate)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-6);
    }
}

void Mathematics::Matrix3ToolsTesting ::PolarDecompositionValueTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

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

        Matrix3ToolsD matrix3Tools(matrix);

        PolarDecompositionValueD polarDecompositionValue = matrix3Tools.PolarDecomposition();

        Matrix3D orthogonalMatrix = polarDecompositionValue.GeOrthogonalMatrix();
        Matrix3D symmetryMatrix = polarDecompositionValue.GetSymmetryMatrix();

        Matrix3D result = orthogonalMatrix * symmetryMatrix;

        typedef bool (*VariableMatrixdApproximate)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-6);
    }
}

void Mathematics::Matrix3ToolsTesting ::QDUDecompositionValueTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

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
        Matrix3ToolsD matrix3Tools(matrix);

        QDUDecompositionValueD qDUDecompositionValue(matrix3Tools.QDUDecomposition());

        Matrix3D orthogonalMatrix = qDUDecompositionValue.GeOrthogonalMatrix();
        Matrix3D diagonalMatrix = qDUDecompositionValue.GetDiagonalMatrix();
        Matrix3D upperTriangularMatrix = qDUDecompositionValue.GetUpperTriangularMatrix();

        Matrix3D result = orthogonalMatrix * diagonalMatrix;
        result *= upperTriangularMatrix;

        typedef bool (*VariableMatrixdApproximate)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-5);
    }
}

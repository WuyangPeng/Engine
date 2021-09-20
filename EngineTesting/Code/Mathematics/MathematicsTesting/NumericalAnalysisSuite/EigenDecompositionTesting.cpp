// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 15:08)

#include "EigenDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Matrix3.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class EigenDecomposition<float>;
    template class EigenDecomposition<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EigenDecompositionTesting)

void Mathematics::EigenDecompositionTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Eigenvalue2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Eigenvalue3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(EigenvalueNTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Mathematics::EigenDecompositionTesting ::Eigenvalue2Test()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-1.0e2, 1.0e2);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleMatrix2 firstMatrix(randomDistribution(generator),
                                  randomDistribution(generator),
                                  0.0,
                                  randomDistribution(generator));

        firstMatrix(1, 0) = firstMatrix(0, 1);

        DoubleEigenDecomposition eigenDecomposition(firstMatrix);

        eigenDecomposition.Solve(true);

        DoubleMatrix2 rotation = eigenDecomposition.GetEigenvectors2();
        DoubleMatrix2 diagonal(eigenDecomposition.GetEigenvalue(0), eigenDecomposition.GetEigenvalue(1));

        DoubleMatrix2 secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors2();
        diagonal = DoubleMatrix2(eigenDecomposition.GetEigenvalue(0), eigenDecomposition.GetEigenvalue(1));

        secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));
    }
}

void Mathematics::EigenDecompositionTesting ::Eigenvalue3Test()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-1.0e2, 1.0e2);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleMatrix3 firstMatrix(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator),
                                  0.0,
                                  randomDistribution(generator),
                                  randomDistribution(generator),
                                  0.0,
                                  0.0,
                                  randomDistribution(generator));

        firstMatrix(1, 0) = firstMatrix(0, 1);
        firstMatrix(2, 0) = firstMatrix(0, 2);
        firstMatrix(2, 1) = firstMatrix(1, 2);

        DoubleEigenDecomposition eigenDecomposition(firstMatrix);

        eigenDecomposition.Solve(true);

        DoubleMatrix3 rotation = eigenDecomposition.GetEigenvectors3();
        DoubleMatrix3 diagonal(eigenDecomposition.GetEigenvalue(0),
                               eigenDecomposition.GetEigenvalue(1),
                               eigenDecomposition.GetEigenvalue(2));

        DoubleMatrix3 secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-8));

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors3();
        diagonal = DoubleMatrix3(eigenDecomposition.GetEigenvalue(0),
                                 eigenDecomposition.GetEigenvalue(1),
                                 eigenDecomposition.GetEigenvalue(2));

        secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-8));
    }
}

void Mathematics::EigenDecompositionTesting ::EigenvalueNTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-1.0e2, 1.0e2);
    uniform_int<> secondRandomDistribution(4, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        int size = secondRandomDistribution(generator);
        DoubleVariableMatrix firstMatrix(size, size);

        for (int row = 0; row < size; ++row)
        {
            for (int column = 0; column < size; ++column)
            {
                firstMatrix(row, column) = firstRandomDistribution(generator);
            }
        }

        for (int row = 0; row < size; ++row)
        {
            for (int column = 0; column < size; ++column)
            {
                if (row <= column)
                {
                    firstMatrix(column, row) = firstMatrix(row, column);
                }
            }
        }

        DoubleEigenDecomposition eigenDecomposition(firstMatrix);

        eigenDecomposition.Solve(true);

        DoubleVariableMatrix rotation = eigenDecomposition.GetEigenvectors();
        DoubleVariableMatrix diagonal(size, size);

        for (int m = 0; m < size; ++m)
        {
            diagonal(m, m) = eigenDecomposition.GetEigenvalue(m);
        }

        DoubleVariableMatrix secondMatrix = rotation * diagonal * rotation.Transpose();

        typedef bool (*VariableMatrixdApproximate)(const DoubleVariableMatrix& lhs, const DoubleVariableMatrix& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, firstMatrix, secondMatrix, 1e-6);

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors();

        for (int m = 0; m < size; ++m)
        {
            diagonal(m, m) = eigenDecomposition.GetEigenvalue(m);
        }

        secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_APPROXIMATE_USE_FUNCTION(function, firstMatrix, secondMatrix, 1e-6);
    }
}

void Mathematics::EigenDecompositionTesting ::BaseTest()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-1.0e2, 1.0e2);
    constexpr int size = 4;

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatEigenDecomposition firstEigenDecomposition(size);

        ASSERT_EQUAL(firstEigenDecomposition.GetSize(), 4);

        DoubleMatrix2 firstMatrix(randomDistribution(generator),
                                  randomDistribution(generator),
                                  0.0,
                                  randomDistribution(generator));

        firstMatrix(1, 0) = firstMatrix(0, 1);

        DoubleEigenDecomposition secondEigenDecomposition(2);
        secondEigenDecomposition = firstMatrix;

        ASSERT_EQUAL(secondEigenDecomposition.GetSize(), 2);

        secondEigenDecomposition.Solve(true);

        DoubleMatrix2 eigenvectors2 = secondEigenDecomposition.GetEigenvectors2();

        for (int m = 0; m < 2; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,
                                            secondEigenDecomposition.GetEigenvector2(m),
                                            DoubleVector2D(eigenvectors2(0, m), eigenvectors2(1, m)), 1e-10);
        }

        DoubleMatrix3 secondMatrix(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator),
                                   0.0,
                                   randomDistribution(generator),
                                   randomDistribution(generator),
                                   0.0,
                                   0.0,
                                   randomDistribution(generator));

        secondMatrix(1, 0) = secondMatrix(0, 1);
        secondMatrix(2, 0) = secondMatrix(0, 2);
        secondMatrix(2, 1) = secondMatrix(1, 2);

        secondEigenDecomposition = secondMatrix;

        ASSERT_EQUAL(secondEigenDecomposition.GetSize(), 3);

        secondEigenDecomposition.Solve(true);

        DoubleMatrix3 eigenvectors3 = secondEigenDecomposition.GetEigenvectors3();

        for (int m = 0; m < 3; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,
                                            secondEigenDecomposition.GetEigenvector3(m),
                                            DoubleVector3D(eigenvectors3(0, m), eigenvectors3(1, m), eigenvectors3(2, m)),
                                            1e-10);
        }

        DoubleVariableMatrix thirdMatrix(size, size);

        for (int row = 0; row < size; ++row)
        {
            for (int column = 0; column < size; ++column)
            {
                thirdMatrix(row, column) = randomDistribution(generator);
            }
        }

        for (int row = 0; row < size; ++row)
        {
            for (int column = 0; column < size; ++column)
            {
                if (row <= column)
                {
                    thirdMatrix(column, row) = thirdMatrix(row, column);
                }
            }
        }

        secondEigenDecomposition = thirdMatrix;

        ASSERT_EQUAL(secondEigenDecomposition.GetSize(), size);

        secondEigenDecomposition.Solve(true);

        DoubleVariableMatrix eigenvectors = secondEigenDecomposition.GetEigenvectors();

        typedef bool (*VariableLengthVectorApproximate)(const DoubleVariableLengthVector& lhs, const DoubleVariableLengthVector& rhs, const double epsilon);

        VariableLengthVectorApproximate function = Approximate<double>;

        for (int m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(function, secondEigenDecomposition.GetEigenvector(m), eigenvectors.GetColumn(m), 1e-10);
        }
    }
}

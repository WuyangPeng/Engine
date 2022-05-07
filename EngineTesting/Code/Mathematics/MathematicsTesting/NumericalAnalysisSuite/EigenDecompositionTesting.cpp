// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/27 15:08)

#include "EigenDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
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
void Mathematics::EigenDecompositionTesting ::Eigenvalue2Test()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-1.0e2, 1.0e2);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Matrix2D firstMatrix(randomDistribution(generator),
                                  randomDistribution(generator),
                                  0.0,
                                  randomDistribution(generator));

        firstMatrix(1, 0) = firstMatrix(0, 1);

        EigenDecompositionD eigenDecomposition(firstMatrix);

        eigenDecomposition.Solve(true);

        Matrix2D rotation = eigenDecomposition.GetEigenvectors2();
        Matrix2D diagonal(eigenDecomposition.GetEigenvalue(0), eigenDecomposition.GetEigenvalue(1));

        Matrix2D secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors2();
        diagonal = Matrix2D(eigenDecomposition.GetEigenvalue(0), eigenDecomposition.GetEigenvalue(1));

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
        Matrix3D firstMatrix(randomDistribution(generator),
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

        EigenDecompositionD eigenDecomposition(firstMatrix);

        eigenDecomposition.Solve(true);

        Matrix3D rotation = eigenDecomposition.GetEigenvectors3();
        Matrix3D diagonal(eigenDecomposition.GetEigenvalue(0),
                               eigenDecomposition.GetEigenvalue(1),
                               eigenDecomposition.GetEigenvalue(2));

        Matrix3D secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-8));

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors3();
        diagonal = Matrix3D(eigenDecomposition.GetEigenvalue(0),
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
        VariableMatrixD firstMatrix(size, size);

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

        EigenDecompositionD eigenDecomposition(firstMatrix);

        eigenDecomposition.Solve(true);

        VariableMatrixD rotation = eigenDecomposition.GetEigenvectors();
        VariableMatrixD diagonal(size, size);

        for (int m = 0; m < size; ++m)
        {
            diagonal(m, m) = eigenDecomposition.GetEigenvalue(m);
        }

        VariableMatrixD secondMatrix = rotation * diagonal * rotation.Transpose();

        typedef bool (*VariableMatrixdApproximate)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

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
        EigenDecompositionF firstEigenDecomposition(size);

        ASSERT_EQUAL(firstEigenDecomposition.GetSize(), 4);

        Matrix2D firstMatrix(randomDistribution(generator),
                                  randomDistribution(generator),
                                  0.0,
                                  randomDistribution(generator));

        firstMatrix(1, 0) = firstMatrix(0, 1);

        EigenDecompositionD secondEigenDecomposition(2);
        secondEigenDecomposition = firstMatrix;

        ASSERT_EQUAL(secondEigenDecomposition.GetSize(), 2);

        secondEigenDecomposition.Solve(true);

        Matrix2D eigenvectors2 = secondEigenDecomposition.GetEigenvectors2();

        for (int m = 0; m < 2; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate,
                                            secondEigenDecomposition.GetEigenvector2(m),
                                            Vector2(eigenvectors2(0, m), eigenvectors2(1, m)), 1e-10);
        }

        Matrix3D secondMatrix(randomDistribution(generator),
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

        Matrix3D eigenvectors3 = secondEigenDecomposition.GetEigenvectors3();

        for (int m = 0; m < 3; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate,
                                            secondEigenDecomposition.GetEigenvector3(m),
                                            Vector3D(eigenvectors3(0, m), eigenvectors3(1, m), eigenvectors3(2, m)),
                                            1e-10);
        }

        VariableMatrixD thirdMatrix(size, size);

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

        VariableMatrixD eigenvectors = secondEigenDecomposition.GetEigenvectors();

        typedef bool (*VariableLengthVectorApproximate)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectorApproximate function = Approximate<double>;

        for (int m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(function, secondEigenDecomposition.GetEigenvector(m), eigenvectors.GetColumn(m), 1e-10);
        }
    }
}
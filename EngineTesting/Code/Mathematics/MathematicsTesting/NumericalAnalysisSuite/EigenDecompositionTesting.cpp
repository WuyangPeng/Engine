///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:01)

#include "EigenDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

#include <random>

namespace Mathematics
{
    template class EigenDecomposition<float>;
    template class EigenDecomposition<double>;
}

Mathematics::EigenDecompositionTesting::EigenDecompositionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EigenDecompositionTesting)

void Mathematics::EigenDecompositionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::EigenDecompositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Eigenvalue2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Eigenvalue3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(EigenvalueNTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Mathematics::EigenDecompositionTesting::Eigenvalue2Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution(-1.0e2, 1.0e2);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Matrix2D matrix0(randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         randomDistribution(generator));

        matrix0(1, 0) = matrix0(0, 1);

        EigenDecompositionD eigenDecomposition(matrix0);

        eigenDecomposition.Solve(true);

        Matrix2D rotation = eigenDecomposition.GetEigenvectors2();
        Matrix2D diagonal(eigenDecomposition.GetEigenvalue(0), eigenDecomposition.GetEigenvalue(1));

        Matrix2D matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors2();
        diagonal = Matrix2D(eigenDecomposition.GetEigenvalue(0), eigenDecomposition.GetEigenvalue(1));

        matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));
    }
}

void Mathematics::EigenDecompositionTesting::Eigenvalue3Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution(-1.0e2, 1.0e2);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Matrix3D matrix0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         0.0,
                         randomDistribution(generator));

        matrix0(1, 0) = matrix0(0, 1);
        matrix0(2, 0) = matrix0(0, 2);
        matrix0(2, 1) = matrix0(1, 2);

        EigenDecompositionD eigenDecomposition(matrix0);

        eigenDecomposition.Solve(true);

        Matrix3D rotation = eigenDecomposition.GetEigenvectors3();
        Matrix3D diagonal(eigenDecomposition.GetEigenvalue(0),
                          eigenDecomposition.GetEigenvalue(1),
                          eigenDecomposition.GetEigenvalue(2));

        Matrix3D matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-8));

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors3();
        diagonal = Matrix3D(eigenDecomposition.GetEigenvalue(0),
                            eigenDecomposition.GetEigenvalue(1),
                            eigenDecomposition.GetEigenvalue(2));

        matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-8));
    }
}

void Mathematics::EigenDecompositionTesting::EigenvalueNTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-1.0e2, 1.0e2);
    const std::uniform_int<> randomDistribution1(4, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const auto size = randomDistribution1(generator);
        VariableMatrixD matrix0(size, size);

        for (auto row = 0; row < size; ++row)
        {
            for (auto column = 0; column < size; ++column)
            {
                matrix0(row, column) = randomDistribution0(generator);
            }
        }

        for (auto row = 0; row < size; ++row)
        {
            for (auto column = 0; column < size; ++column)
            {
                if (row <= column)
                {
                    matrix0(column, row) = matrix0(row, column);
                }
            }
        }

        EigenDecompositionD eigenDecomposition(matrix0);

        eigenDecomposition.Solve(true);

        VariableMatrixD rotation = eigenDecomposition.GetEigenvectors();
        VariableMatrixD diagonal(size, size);

        for (int m = 0; m < size; ++m)
        {
            diagonal(m, m) = eigenDecomposition.GetEigenvalue(m);
        }

        VariableMatrixD matrix1 = rotation * diagonal * rotation.Transpose();

        using VariableMatrixdApproximate = bool (*)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix0, matrix1, 1e-6);

        eigenDecomposition.Solve(false);

        rotation = eigenDecomposition.GetEigenvectors();

        for (int m = 0; m < size; ++m)
        {
            diagonal(m, m) = eigenDecomposition.GetEigenvalue(m);
        }

        matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix0, matrix1, 1e-6);
    }
}

void Mathematics::EigenDecompositionTesting::BaseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution(-1.0e2, 1.0e2);
    constexpr int size = 4;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        EigenDecompositionF firstEigenDecomposition(size);

        ASSERT_EQUAL(firstEigenDecomposition.GetSize(), 4);

        Matrix2D matrix0(randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         randomDistribution(generator));

        matrix0(1, 0) = matrix0(0, 1);

        EigenDecompositionD secondEigenDecomposition(2);
        secondEigenDecomposition = matrix0;

        ASSERT_EQUAL(secondEigenDecomposition.GetSize(), 2);

        secondEigenDecomposition.Solve(true);

        Matrix2D eigenvectors2 = secondEigenDecomposition.GetEigenvectors2();

        for (int m = 0; m < 2; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate,
                                            secondEigenDecomposition.GetEigenvector2(m),
                                            Vector2(eigenvectors2(0, m), eigenvectors2(1, m)), 1e-10);
        }

        Matrix3D matrix1(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         0.0,
                         randomDistribution(generator));

        matrix1(1, 0) = matrix1(0, 1);
        matrix1(2, 0) = matrix1(0, 2);
        matrix1(2, 1) = matrix1(1, 2);

        secondEigenDecomposition = matrix1;

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

        VariableMatrixD matrix2(size, size);

        for (int row = 0; row < size; ++row)
        {
            for (int column = 0; column < size; ++column)
            {
                matrix2(row, column) = randomDistribution(generator);
            }
        }

        for (int row = 0; row < size; ++row)
        {
            for (int column = 0; column < size; ++column)
            {
                if (row <= column)
                {
                    matrix2(column, row) = matrix2(row, column);
                }
            }
        }

        secondEigenDecomposition = matrix2;

        ASSERT_EQUAL(secondEigenDecomposition.GetSize(), size);

        secondEigenDecomposition.Solve(true);

        VariableMatrixD eigenvectors = secondEigenDecomposition.GetEigenvectors();

        using VariableLengthVectorApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectorApproximate function = Approximate<double>;

        for (int m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(function, secondEigenDecomposition.GetEigenvector(m), eigenvectors.GetColumn(m), 1e-10);
        }
    }
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:02)

#include "LinearSystemTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

#include <gsl/util>
#include <random>

namespace Mathematics
{
    template class LinearSystem<float>;
    template class LinearSystem<double>;
}

Mathematics::LinearSystemTesting::LinearSystemTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, LinearSystemTesting)

void Mathematics::LinearSystemTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::LinearSystemTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Solve2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Solve3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(InverseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolveTridiagonalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolveConstTridiagonalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolveSymmetricConjugateGradientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolveBandedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InvertTest);
}

void Mathematics::LinearSystemTesting::Solve2Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(1, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        LinearSystemD::Matrix2 matrix{ LinearSystemD::Vector2{ floatRandomDistribution(generator), floatRandomDistribution(generator) },
                                       LinearSystemD::Vector2{ floatRandomDistribution(generator), floatRandomDistribution(generator) } };
        LinearSystemD::Vector2 inputVector{ floatRandomDistribution(generator), floatRandomDistribution(generator) };

        auto outputVector = linearsystem.Solve2(matrix, inputVector);

        const Matrix2D matrix0(matrix.at(0).at(0), matrix.at(0).at(1), matrix.at(1).at(0), matrix.at(1).at(1));
        const Vector2D vector0(inputVector.at(0), inputVector.at(1));
        const Vector2D vector1(outputVector.at(0), outputVector.at(1));

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, vector0, matrix0 * vector1, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::Solve3Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(1, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        LinearSystemD::Matrix3 matrix = { LinearSystemD::Vector3{ floatRandomDistribution(generator),
                                                                  floatRandomDistribution(generator),
                                                                  floatRandomDistribution(generator) },
                                          LinearSystemD::Vector3{ floatRandomDistribution(generator),
                                                                  floatRandomDistribution(generator),
                                                                  floatRandomDistribution(generator) },
                                          LinearSystemD::Vector3{ floatRandomDistribution(generator),
                                                                  floatRandomDistribution(generator),
                                                                  floatRandomDistribution(generator) } };
        LinearSystemD::Vector3 inputVector = { floatRandomDistribution(generator),
                                               floatRandomDistribution(generator),
                                               floatRandomDistribution(generator) };
        auto outputVector = linearsystem.Solve3(matrix, inputVector);

        const Matrix3D matrix0(matrix.at(0).at(0), matrix.at(0).at(1), matrix.at(0).at(2), matrix.at(1).at(0), matrix.at(1).at(1), matrix.at(1).at(2), matrix.at(2).at(0), matrix.at(2).at(1), matrix.at(2).at(2));
        const Vector3D vector0(inputVector.at(0), inputVector.at(1), inputVector.at(2));
        const Vector3D vector1(outputVector.at(0), outputVector.at(1), outputVector.at(2));

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, vector0, matrix0 * vector1, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::InverseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(1, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const auto size = integerRandomDistribution(generator);

        VariableMatrixD matrix0(size, size);

        for (auto row = 0; row < matrix0.GetRowsNumber(); ++row)
        {
            for (auto column = 0; column < matrix0.GetColumnsNumber(); ++column)
            {
                matrix0(row, column) = floatRandomDistribution(generator);
            }
        }

        auto matrix1 = linearsystem.Inverse(matrix0);
        auto matrix2 = matrix0 * matrix1;
        VariableMatrixD matrix3(size, size);

        for (auto row = 0; row < matrix3.GetRowsNumber(); ++row)
        {
            matrix3(row, row) = 1.0;
        }

        using VariableMatrixdApproximate = bool (*)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix2, matrix3, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::SolveTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(1, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const auto size = integerRandomDistribution(generator);

        VariableMatrixD matrix0(size, size);

        for (auto row = 0; row < matrix0.GetRowsNumber(); ++row)
        {
            for (auto column = 0; column < matrix0.GetColumnsNumber(); ++column)
            {
                matrix0(row, column) = floatRandomDistribution(generator);
            }
        }

        std::vector<double> input{};

        for (auto i = 0; i < size; ++i)
        {
            input.emplace_back(floatRandomDistribution(generator));
        }

        auto output = linearsystem.Solve(matrix0, input);

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = matrix0 * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::SolveTridiagonalTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(3, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        auto size = integerRandomDistribution(generator);

        std::vector<double> lower(gsl::narrow_cast<size_t>(size) - 1);
        std::vector<double> main(size);
        std::vector<double> upper(gsl::narrow_cast<size_t>(size) - 1);
        std::vector<double> input(size);

        for (auto i = 0; i < size - 1; ++i)
        {
            lower.at(i) = floatRandomDistribution(generator);
            main.at(i) = floatRandomDistribution(generator);
            upper.at(i) = floatRandomDistribution(generator);
            input.at(i) = floatRandomDistribution(generator);
        }

        main.at(gsl::narrow_cast<size_t>(size) - 1) = floatRandomDistribution(generator);
        input.at(gsl::narrow_cast<size_t>(size) - 1) = floatRandomDistribution(generator);

        auto output = linearsystem.SolveTridiagonal(size, lower, main, upper, input);

        VariableMatrixD matrix0(size, size);

        for (auto i = 0; i < size - 1; ++i)
        {
            matrix0(i, i + 1) = upper.at(i);
            matrix0(i + 1, i) = lower.at(i);
        }

        for (auto i = 0; i < size; ++i)
        {
            matrix0(i, i) = main.at(i);
        }

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = matrix0 * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::SolveConstTridiagonalTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(1, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        double lower = floatRandomDistribution(generator);
        double main = floatRandomDistribution(generator);
        double upper = floatRandomDistribution(generator);
        std::vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input.at(i) = floatRandomDistribution(generator);
        }

        auto output = linearsystem.SolveConstTridiagonal(size, lower, main, upper, input);

        VariableMatrixD matrix0(size, size);

        for (int i = 0; i < size - 1; ++i)
        {
            matrix0(i, i + 1) = upper;
            matrix0(i + 1, i) = lower;
        }

        for (int i = 0; i < size; ++i)
        {
            matrix0(i, i) = main;
        }

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = matrix0 * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-5);
    }
}

void Mathematics::LinearSystemTesting::SolveSymmetricConjugateGradientTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(1, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        VariableMatrixD matrix0(size, size);

        for (int row = 0; row < matrix0.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix0.GetColumnsNumber(); ++column)
            {
                matrix0(row, column) = floatRandomDistribution(generator);
            }
        }

        for (int row = 0; row < matrix0.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix0.GetColumnsNumber(); ++column)
            {
                if (row < column)
                    matrix0(row, column) = matrix0(column, row);
            }
        }

        std::vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input.at(i) = floatRandomDistribution(generator);
        }

        auto output = linearsystem.SolveSymmetricConjugateGradient(matrix0, input);

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = matrix0 * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);

        SparseMatrixD matrix1(size, size);

        for (int row = 0; row < matrix1.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix1.GetColumnsNumber(); ++column)
            {
                matrix1(row, column) = floatRandomDistribution(generator);
            }
        }

        output = linearsystem.SolveSymmetricConjugateGradient(matrix1, input);

        firstVariableLengthVector = VariableLengthVectorD(input);
        secondVariableLengthVector = VariableLengthVectorD(output);
        thirdVariableLengthVector = matrix1 * secondVariableLengthVector;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-7);
    }
}

void Mathematics::LinearSystemTesting::SolveBandedTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(4, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        BandedMatrixD matrix0(size, size - 1, size - 2);

        for (int i = 0; i < matrix0.GetSize(); ++i)
        {
            matrix0(i, i) = floatRandomDistribution(generator);
        }

        for (int row = 0; row < matrix0.GetSize(); ++row)
        {
            for (int column = 0; column < matrix0.GetSize(); ++column)
            {
                const int band = column - row;
                if (band < 0 && -band - 1 < matrix0.GetLowerBandsNumber())
                {
                    matrix0(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        for (int row = 0; row < matrix0.GetSize(); ++row)
        {
            for (int column = 0; column < matrix0.GetSize(); ++column)
            {
                const int band = column - row;
                if (0 < band && band - 1 < matrix0.GetUpperBandsNumber())
                {
                    matrix0(row, column) = floatRandomDistribution(generator);
                }
            }
        }
        std::vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input.at(i) = floatRandomDistribution(generator);
        }

        auto output = linearsystem.SolveBanded(matrix0, input);

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = matrix0.ToVariableMatrix() * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);
    }
}

void Mathematics::LinearSystemTesting::InvertTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> integerRandomDistribution(4, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        BandedMatrixD matrix0(size, size - 1, size - 2);

        auto diagonalBand = matrix0.GetDiagonalBand();
        for (int i = 0; i < matrix0.GetSize(); ++i)
        {
            matrix0(i, i) = floatRandomDistribution(generator);
        }

        for (int row = 0; row < matrix0.GetSize(); ++row)
        {
            for (int column = 0; column < matrix0.GetSize(); ++column)
            {
                const int band = column - row;
                if (band < 0 && -band - 1 < matrix0.GetLowerBandsNumber())
                {
                    matrix0(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        for (int row = 0; row < matrix0.GetSize(); ++row)
        {
            for (int column = 0; column < matrix0.GetSize(); ++column)
            {
                const int band = column - row;
                if (0 < band && band - 1 < matrix0.GetUpperBandsNumber())
                {
                    matrix0(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        VariableMatrixD matrix1 = linearsystem.Invert(matrix0);
        VariableMatrixD matrix2 = matrix0.ToVariableMatrix() * matrix1;
        VariableMatrixD matrix3(size, size);

        for (int row = 0; row < matrix3.GetRowsNumber(); ++row)
        {
            matrix3(row, row) = 1.0;
        }

        using VariableMatrixdApproximate = bool (*)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix2, matrix3, 1e-10);
    }
}

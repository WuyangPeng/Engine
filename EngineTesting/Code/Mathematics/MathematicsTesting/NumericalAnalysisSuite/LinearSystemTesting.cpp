///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 18:19)

#include "LinearSystemTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class LinearSystem<float>;
    template class LinearSystem<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, LinearSystemTesting)

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
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        LinearSystemD::Matrix2 matrix{ LinearSystemD::Vector2{ floatRandomDistribution(generator), floatRandomDistribution(generator) },
                                       LinearSystemD::Vector2{ floatRandomDistribution(generator), floatRandomDistribution(generator) } };
        LinearSystemD::Vector2 inputVector{ floatRandomDistribution(generator), floatRandomDistribution(generator) };

        auto outputVector = linearsystem.Solve2(matrix, inputVector);

        const Matrix2D firstMatrix(matrix.at(0).at(0), matrix.at(0).at(1), matrix.at(1).at(0), matrix.at(1).at(1));
        const Vector2D firstVector(inputVector.at(0), inputVector.at(1));
        const Vector2D secondVector(outputVector.at(0), outputVector.at(1));

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, firstVector, firstMatrix * secondVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::Solve3Test()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

        const Matrix3D firstMatrix(matrix.at(0).at(0), matrix.at(0).at(1), matrix.at(0).at(2), matrix.at(1).at(0), matrix.at(1).at(1), matrix.at(1).at(2), matrix.at(2).at(0), matrix.at(2).at(1), matrix.at(2).at(2));
        const Vector3D firstVector(inputVector.at(0), inputVector.at(1), inputVector.at(2));
        const Vector3D secondVector(outputVector.at(0), outputVector.at(1), outputVector.at(2));

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, firstVector, firstMatrix * secondVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::InverseTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const auto size = integerRandomDistribution(generator);

        VariableMatrixD firstMatrix(size, size);

        for (auto row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (auto column = 0; column < firstMatrix.GetColumnsNumber(); ++column)
            {
                firstMatrix(row, column) = floatRandomDistribution(generator);
            }
        }

        auto secondMatrix = linearsystem.Inverse(firstMatrix);
        auto thirdMatrix = firstMatrix * secondMatrix;
        VariableMatrixD fourthMatrix(size, size);

        for (auto row = 0; row < fourthMatrix.GetRowsNumber(); ++row)
        {
            fourthMatrix(row, row) = 1.0;
        }

        using VariableMatrixdApproximate = bool (*)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdMatrix, fourthMatrix, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::SolveTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const auto size = integerRandomDistribution(generator);

        VariableMatrixD firstMatrix(size, size);

        for (auto row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (auto column = 0; column < firstMatrix.GetColumnsNumber(); ++column)
            {
                firstMatrix(row, column) = floatRandomDistribution(generator);
            }
        }

        vector<double> input{};

        for (auto i = 0; i < size; ++i)
        {
            input.emplace_back(floatRandomDistribution(generator));
        }

        auto output = linearsystem.Solve(firstMatrix, input);

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = firstMatrix * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::SolveTridiagonalTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(3, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        auto size = integerRandomDistribution(generator);

        vector<double> lower(gsl::narrow_cast<size_t>(size) - 1);
        vector<double> main(size);
        vector<double> upper(gsl::narrow_cast<size_t>(size) - 1);
        vector<double> input(size);

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

        VariableMatrixD firstMatrix(size, size);

        for (auto i = 0; i < size - 1; ++i)
        {
            firstMatrix(i, i + 1) = upper.at(i);
            firstMatrix(i + 1, i) = lower.at(i);
        }

        for (auto i = 0; i < size; ++i)
        {
            firstMatrix(i, i) = main.at(i);
        }

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = firstMatrix * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::SolveConstTridiagonalTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        double lower = floatRandomDistribution(generator);
        double main = floatRandomDistribution(generator);
        double upper = floatRandomDistribution(generator);
        vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input.at(i) = floatRandomDistribution(generator);
        }

        auto output = linearsystem.SolveConstTridiagonal(size, lower, main, upper, input);

        VariableMatrixD firstMatrix(size, size);

        for (int i = 0; i < size - 1; ++i)
        {
            firstMatrix(i, i + 1) = upper;
            firstMatrix(i + 1, i) = lower;
        }

        for (int i = 0; i < size; ++i)
        {
            firstMatrix(i, i) = main;
        }

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = firstMatrix * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting::SolveSymmetricConjugateGradientTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        VariableMatrixD firstMatrix(size, size);

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber(); ++column)
            {
                firstMatrix(row, column) = floatRandomDistribution(generator);
            }
        }

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber(); ++column)
            {
                if (row < column)
                    firstMatrix(row, column) = firstMatrix(column, row);
            }
        }

        vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input.at(i) = floatRandomDistribution(generator);
        }

        auto output = linearsystem.SolveSymmetricConjugateGradient(firstMatrix, input);

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = firstMatrix * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);

        SparseMatrixD secondMatrix(size, size);

        for (int row = 0; row < secondMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < secondMatrix.GetColumnsNumber(); ++column)
            {
                secondMatrix(row, column) = floatRandomDistribution(generator);
            }
        }

        output = linearsystem.SolveSymmetricConjugateGradient(secondMatrix, input);

        firstVariableLengthVector = VariableLengthVectorD(input);
        secondVariableLengthVector = VariableLengthVectorD(output);
        thirdVariableLengthVector = secondMatrix * secondVariableLengthVector;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);
    }
}

void Mathematics::LinearSystemTesting::SolveBandedTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(4, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        BandedMatrixD firstMatrix(size, size - 1, size - 2);

        for (int i = 0; i < firstMatrix.GetSize(); ++i)
        {
            firstMatrix(i, i) = floatRandomDistribution(generator);
        }

        for (int row = 0; row < firstMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetSize(); ++column)
            {
                const int band = column - row;
                if (band < 0 && -band - 1 < firstMatrix.GetLowerBandsNumber())
                {
                    firstMatrix(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        for (int row = 0; row < firstMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetSize(); ++column)
            {
                const int band = column - row;
                if (0 < band && band - 1 < firstMatrix.GetUpperBandsNumber())
                {
                    firstMatrix(row, column) = floatRandomDistribution(generator);
                }
            }
        }
        vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input.at(i) = floatRandomDistribution(generator);
        }

        auto output = linearsystem.SolveBanded(firstMatrix, input);

        VariableLengthVectorD firstVariableLengthVector(input);
        VariableLengthVectorD secondVariableLengthVector(output);
        VariableLengthVectorD thirdVariableLengthVector = firstMatrix.ToVariableMatrix() * secondVariableLengthVector;

        using VariableLengthVectordApproximate = bool (*)(const VariableLengthVectorD& lhs, const VariableLengthVectorD& rhs, const double epsilon);

        VariableLengthVectordApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);
    }
}

void Mathematics::LinearSystemTesting::InvertTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(4, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const LinearSystemD linearsystem(1e-10);

        const int size = integerRandomDistribution(generator);

        BandedMatrixD firstMatrix(size, size - 1, size - 2);

        auto diagonalBand = firstMatrix.GetDiagonalBand();
        for (int i = 0; i < firstMatrix.GetSize(); ++i)
        {
            firstMatrix(i, i) = floatRandomDistribution(generator);
        }

        for (int row = 0; row < firstMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetSize(); ++column)
            {
                const int band = column - row;
                if (band < 0 && -band - 1 < firstMatrix.GetLowerBandsNumber())
                {
                    firstMatrix(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        for (int row = 0; row < firstMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetSize(); ++column)
            {
                const int band = column - row;
                if (0 < band && band - 1 < firstMatrix.GetUpperBandsNumber())
                {
                    firstMatrix(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        VariableMatrixD secondMatrix = linearsystem.Invert(firstMatrix);
        VariableMatrixD thirdMatrix = firstMatrix.ToVariableMatrix() * secondMatrix;
        VariableMatrixD fourthMatrix(size, size);

        for (int row = 0; row < fourthMatrix.GetRowsNumber(); ++row)
        {
            fourthMatrix(row, row) = 1.0;
        }

        using VariableMatrixdApproximate = bool (*)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdMatrix, fourthMatrix, 1e-10);
    }
}

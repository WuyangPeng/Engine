// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 15:43)

#include "LinearSystemTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

#include <random>
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

void Mathematics::LinearSystemTesting ::MainTest()
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

void Mathematics::LinearSystemTesting ::Solve2Test()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        double matrix[2][2]{ { floatRandomDistribution(generator), floatRandomDistribution(generator) },
                             { floatRandomDistribution(generator), floatRandomDistribution(generator) } };
        double inputVector[2]{ floatRandomDistribution(generator), floatRandomDistribution(generator) };
        double outputVector[2]{ 0, 0 };

        // 		linearsystem.Solve2(matrix, inputVector, outputVector);
        //
        // 		DoubleMatrix2 firstMatrix(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
        // 		DoubleVector2 firstVector(inputVector[0], inputVector[1]);
        // 		DoubleVector2 secondVector(outputVector[0], outputVector[1]);
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2Tools::Approximate, firstVector, firstMatrix * secondVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting ::Solve3Test()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        double matrix[3][3] = { { floatRandomDistribution(generator),
                                  floatRandomDistribution(generator),
                                  floatRandomDistribution(generator) },
                                { floatRandomDistribution(generator),
                                  floatRandomDistribution(generator),
                                  floatRandomDistribution(generator) },
                                { floatRandomDistribution(generator),
                                  floatRandomDistribution(generator),
                                  floatRandomDistribution(generator) } };
        double inputVector[3] = { floatRandomDistribution(generator),
                                  floatRandomDistribution(generator),
                                  floatRandomDistribution(generator) };
        double outputVector[3] = { 0, 0, 0 };

        // 		linearsystem.Solve3(matrix, inputVector, outputVector);
        //
        // 		DoubleMatrix3 firstMatrix(matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
        // 		DoubleVector3 firstVector(inputVector[0], inputVector[1],inputVector[2]);
        // 		DoubleVector3 secondVector(outputVector[0], outputVector[1],outputVector[2]);
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3Tools::Approximate, firstVector, firstMatrix * secondVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting ::InverseTest()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        int size = integerRandomDistribution(generator);

        VariableMatrixD firstMatrix(size, size);

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber();
                 ++column)
            {
                firstMatrix(row, column) = floatRandomDistribution(generator);
            }
        }

        VariableMatrixD secondMatrix = linearsystem.Inverse(firstMatrix);
        VariableMatrixD thirdMatrix = firstMatrix * secondMatrix;
        VariableMatrixD fourthMatrix(size, size);

        for (int row = 0; row < fourthMatrix.GetRowsNumber(); ++row)
        {
            fourthMatrix(row, row) = 1.0;
        }

        typedef bool (*VariableMatrixdApproximate)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdMatrix, fourthMatrix, 1e-10);
    }
}

void Mathematics::LinearSystemTesting ::SolveTest()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        int size = integerRandomDistribution(generator);

        VariableMatrixD firstMatrix(size, size);

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber(); ++column)
            {
                firstMatrix(row, column) = floatRandomDistribution(generator);
            }
        }

        vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input[i] = floatRandomDistribution(generator);
        }

        vector<double> output(size);

        // 		linearsystem.Solve(firstMatrix, &input[0],&output[0]);
        //
        // 		DoubleVariableLengthVector firstVariableLengthVector(input);
        // 		DoubleVariableLengthVector secondVariableLengthVector(output);
        // 		DoubleVariableLengthVector thirdVariableLengthVector =
        // 			firstMatrix * secondVariableLengthVector;
        //
        // 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs,const DoubleVariableLengthVector& rhs,const double epsilon);
        //
        // 		VariableLengthVectordApproximate function = Approximate<double>;
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting ::SolveTridiagonalTest()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(3, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        int size = integerRandomDistribution(generator);

        vector<double> lower(static_cast<size_t>(size) - 1);
        vector<double> main(size);
        vector<double> upper(static_cast<size_t>(size) - 1);
        vector<double> input(size);

        for (int i = 0; i < size - 1; ++i)
        {
            lower[i] = floatRandomDistribution(generator);
            main[i] = floatRandomDistribution(generator);
            upper[i] = floatRandomDistribution(generator);
            input[i] = floatRandomDistribution(generator);
        }

        main[static_cast<size_t>(size) - 1] = floatRandomDistribution(generator);
        input[static_cast<size_t>(size) - 1] = floatRandomDistribution(generator);

        vector<double> output(size);

        // 		linearsystem.SolveTridiagonal(size, &lower[0], &main[0], &upper[0], &input[0], &output[0]);
        //
        // 		DoubleVariableMatrix firstMatrix(size, size);
        //
        // 		for (int i = 0; i < size - 1;++i)
        // 		{
        // 			firstMatrix(i, i + 1) = upper[i];
        // 			firstMatrix(i + 1, i) = lower[i];
        // 		}
        //
        // 		for (int i = 0; i < size; ++i)
        // 		{
        // 			firstMatrix(i, i) = main[i];
        // 		}
        //
        // 		DoubleVariableLengthVector firstVariableLengthVector(input);
        // 		DoubleVariableLengthVector secondVariableLengthVector(output);
        // 		DoubleVariableLengthVector thirdVariableLengthVector = firstMatrix * secondVariableLengthVector;
        //
        // 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs,const DoubleVariableLengthVector& rhs,const double epsilon);
        //
        // 		VariableLengthVectordApproximate function = Approximate<double>;
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting ::SolveConstTridiagonalTest()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        // 		DoubleLinearSystem linearsystem(1e-10);
        //
        // 		int size = integerRandomDistribution(generator);
        //
        // 		double lower = floatRandomDistribution(generator);
        // 		double main = floatRandomDistribution(generator);
        // 		double upper = floatRandomDistribution(generator);
        // 		vector<double> input(size);
        //
        // 		for (int i = 0; i < size; ++i)
        // 		{
        // 			input[i] = floatRandomDistribution(generator);
        // 		}
        //
        // 		vector<double> output(size);

        // 		linearsystem.SolveConstTridiagonal(size, lower, main, upper, &input[0], &output[0]);
        //
        // 		DoubleVariableMatrix firstMatrix(size, size);
        //
        // 		for (int i = 0; i < size - 1;++i)
        // 		{
        // 			firstMatrix(i, i + 1) = upper;
        // 			firstMatrix(i + 1, i) = lower;
        // 		}
        //
        // 		for (int i = 0; i < size; ++i)
        // 		{
        // 			firstMatrix(i, i) = main;
        // 		}
        //
        // 		DoubleVariableLengthVector firstVariableLengthVector(input);
        // 		DoubleVariableLengthVector secondVariableLengthVector(output);
        // 		DoubleVariableLengthVector thirdVariableLengthVector =
        // 			firstMatrix * secondVariableLengthVector;
        //
        // 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs,const DoubleVariableLengthVector& rhs,const double epsilon);
        //
        // 		VariableLengthVectordApproximate function = Approximate<double>;
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-10);
    }
}

void Mathematics::LinearSystemTesting ::SolveSymmetricConjugateGradientTest()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(1, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        int size = integerRandomDistribution(generator);

        VariableMatrixD firstMatrix(size, size);

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber();
                 ++column)
            {
                firstMatrix(row, column) = floatRandomDistribution(generator);
            }
        }

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber();
                 ++column)
            {
                if (row < column)
                    firstMatrix(row, column) = firstMatrix(column, row);
            }
        }

        vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input[i] = floatRandomDistribution(generator);
        }
        // 		vector<double> output(size);
        // 		linearsystem.SolveSymmetricConjugateGradient(firstMatrix, &input[0], &output[0]);
        //
        // 		DoubleVariableLengthVector firstVariableLengthVector(input);
        // 		DoubleVariableLengthVector secondVariableLengthVector(output);
        // 		DoubleVariableLengthVector thirdVariableLengthVector =
        // 			firstMatrix * secondVariableLengthVector;
        //
        // 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs,const DoubleVariableLengthVector& rhs,const double epsilon);
        //
        // 		VariableLengthVectordApproximate function = Approximate<double>;
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);
        //
        // 	 	DoubleSparseMatrix secondMatrix(size, size);
        //
        // 		for (int row = 0; row < secondMatrix.GetRowsNumber(); ++row)
        // 		{
        // 			for (int column = 0; column < secondMatrix.GetColumnsNumber();++column)
        // 			{
        // 				secondMatrix(row, column) = floatRandomDistribution(generator);
        // 			}
        // 		}
        //
        // 		linearsystem.SolveSymmetricConjugateGradient(secondMatrix, &input[0], &output[0]);
        //
        // 		firstVariableLengthVector = DoubleVariableLengthVector(input);
        // 		secondVariableLengthVector = DoubleVariableLengthVector(output);
        // 		thirdVariableLengthVector =	secondMatrix * secondVariableLengthVector;
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);
    }
}

void Mathematics::LinearSystemTesting ::SolveBandedTest()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(4, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        int size = integerRandomDistribution(generator);

        BandedMatrixD firstMatrix(size, size - 1, size - 2);

        auto diagonalBand = firstMatrix.GetDiagonalBand();
        for (int i = 0; i < firstMatrix.GetSize(); ++i)
        {
            diagonalBand[i] = floatRandomDistribution(generator);
        }

        for (int row = 0; row < firstMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetSize(); ++column)
            {
                int band = column - row;
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
                int band = column - row;
                if (0 < band && band - 1 < firstMatrix.GetUpperBandsNumber())
                {
                    firstMatrix(row, column) = floatRandomDistribution(generator);
                }
            }
        }
        vector<double> input(size);

        for (int i = 0; i < size; ++i)
        {
            input[i] = floatRandomDistribution(generator);
        }

        vector<double> output(size);

        // 		linearsystem.SolveBanded(firstMatrix, &input[0], &output[0]);
        //
        // 		DoubleVariableLengthVector firstVariableLengthVector(input);
        // 		DoubleVariableLengthVector secondVariableLengthVector(output);
        // 		DoubleVariableLengthVector thirdVariableLengthVector = firstMatrix.ToVariableMatrix() * secondVariableLengthVector;
        //
        // 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs,const DoubleVariableLengthVector& rhs, const double epsilon);
        //
        // 		VariableLengthVectordApproximate function = Approximate<double>;
        //
        // 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8);
        //
    }
}

void Mathematics::LinearSystemTesting ::InvertTest()
{
    default_random_engine generator;
    uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    uniform_int<> integerRandomDistribution(4, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        LinearSystemD linearsystem(1e-10);

        int size = integerRandomDistribution(generator);

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
                int band = column - row;
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
                int band = column - row;
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

        typedef bool (*VariableMatrixdApproximate)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdMatrix, fourthMatrix, 1e-10);
    }
}

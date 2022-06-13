///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:45)

#include "VariableMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, VariableMatrixTesting)

void Mathematics::VariableMatrixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MatrixCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::VariableMatrixTesting::ConstructionTest()
{
    VariableMatrixF firstVariableMatrix;

    ASSERT_EQUAL(firstVariableMatrix.GetRowsNumber(), 0);
    ASSERT_EQUAL(firstVariableMatrix.GetColumnsNumber(), 0);
    ASSERT_EQUAL(firstVariableMatrix.GetElementsNumber(), 0);

    VariableMatrixD secondVariableMatrix(5, 6);

    ASSERT_EQUAL(secondVariableMatrix.GetRowsNumber(), 5);
    ASSERT_EQUAL(secondVariableMatrix.GetColumnsNumber(), 6);
    ASSERT_EQUAL(secondVariableMatrix.GetElementsNumber(), 30);

    for (int row = 0; row < secondVariableMatrix.GetRowsNumber(); ++row)
    {
        for (int column = 0; column < secondVariableMatrix.GetColumnsNumber(); ++column)
        {
            ASSERT_APPROXIMATE(secondVariableMatrix(row, column), 0.0, 1e-10);
        }
    }

    vector<double> firstEntry{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

    VariableMatrixD thirdVariableMatrix(2, 4, firstEntry);

    ASSERT_EQUAL(thirdVariableMatrix.GetRowsNumber(), 2);
    ASSERT_EQUAL(thirdVariableMatrix.GetColumnsNumber(), 4);
    ASSERT_EQUAL(thirdVariableMatrix.GetElementsNumber(), 8);

    for (int row = 0; row < thirdVariableMatrix.GetRowsNumber(); ++row)
    {
        for (int column = 0; column < thirdVariableMatrix.GetColumnsNumber(); ++column)
        {
            const auto temp = row * thirdVariableMatrix.GetColumnsNumber();
            const auto temp2 = temp + column;
            ASSERT_APPROXIMATE(thirdVariableMatrix(row, column),
                               firstEntry.at(temp2),
                               1e-10);
        }
    }

    vector<double> secondEntry{ -3.0, -4.0, -5.0, -6.0, -7.0, -8.0, -9.0, -10.0 };

    vector<vector<double>> entryVector{ firstEntry, secondEntry };
}

void Mathematics::VariableMatrixTesting::AccessTest()
{
    vector<double> firstEntry{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

    const VariableMatrixD firstVariableMatrix(2, 4, firstEntry);

    ASSERT_EQUAL(firstVariableMatrix.GetRowsNumber(), 2);
    ASSERT_EQUAL(firstVariableMatrix.GetColumnsNumber(), 4);
    ASSERT_EQUAL(firstVariableMatrix.GetElementsNumber(), 8);
}

void Mathematics::VariableMatrixTesting::ArithmeticCalculateTest()
{
    default_random_engine generator{};

    const uniform_real<float> floatRandomDistribution{ -100.0f, 100.0f };
    const uniform_int<> integerRandomDistribution(1, 20);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        VariableMatrixF firstMatrix(integerRandomDistribution(generator), integerRandomDistribution(generator));

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber();
                 ++column)
            {
                firstMatrix[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixF secondMatrix(firstMatrix.GetColumnsNumber(), integerRandomDistribution(generator));

        for (int row = 0; row < secondMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < secondMatrix.GetColumnsNumber(); ++column)
            {
                secondMatrix[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixF thirdMatrix = firstMatrix * secondMatrix;

        ASSERT_EQUAL(thirdMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(thirdMatrix.GetColumnsNumber(), secondMatrix.GetColumnsNumber());
        ASSERT_EQUAL(thirdMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * secondMatrix.GetColumnsNumber());

        for (int row = 0; row < thirdMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < thirdMatrix.GetColumnsNumber(); ++column)
            {
                float sum = 0;
                for (int index = 0; index < firstMatrix.GetColumnsNumber(); ++index)
                {
                    sum += firstMatrix(row, index) * secondMatrix(index, column);
                }

                ASSERT_APPROXIMATE(sum, thirdMatrix(row, column), 1e-10f);
            }
        }

        thirdMatrix = firstMatrix;

        thirdMatrix *= secondMatrix;

        ASSERT_EQUAL(thirdMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(thirdMatrix.GetColumnsNumber(), secondMatrix.GetColumnsNumber());
        ASSERT_EQUAL(thirdMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * secondMatrix.GetColumnsNumber());

        for (int row = 0; row < thirdMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < thirdMatrix.GetColumnsNumber(); ++column)
            {
                float sum = 0;
                for (int index = 0; index < firstMatrix.GetColumnsNumber(); ++index)
                {
                    sum += firstMatrix(row, index) * secondMatrix(index, column);
                }

                ASSERT_APPROXIMATE(sum, thirdMatrix(row, column), 1e-10f);
            }
        }

        thirdMatrix = -firstMatrix;

        ASSERT_EQUAL(thirdMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(thirdMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(thirdMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < thirdMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < thirdMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(firstMatrix(row, column), -thirdMatrix(row, column), 1e-10f);
            }
        }

        VariableMatrixF fourthMatrix(firstMatrix.GetRowsNumber(), firstMatrix.GetColumnsNumber());

        VariableMatrixF fifthMatrix = firstMatrix + fourthMatrix;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) + fourthMatrix(row, column), 1e-10f);
            }
        }

        fifthMatrix = firstMatrix;

        fifthMatrix += fourthMatrix;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) + fourthMatrix(row, column), 1e-10f);
            }
        }

        fifthMatrix = firstMatrix - fourthMatrix;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) - fourthMatrix(row, column), 1e-10f);
            }
        }

        fifthMatrix = firstMatrix;

        fifthMatrix -= fourthMatrix;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) - fourthMatrix(row, column), 1e-10f);
            }
        }

        fifthMatrix = firstMatrix * 3.0f;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) * 3.0f, 1e-10f);
            }
        }

        fifthMatrix = 2.5f * firstMatrix;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) * 2.5f, 1e-10f);
            }
        }

        fifthMatrix = firstMatrix;

        fifthMatrix *= 4.0f;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) * 4.0f, 1e-10f);
            }
        }

        fifthMatrix = firstMatrix / 3.0f;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) / 3.0f, 1e-10f);
            }
        }

        fifthMatrix = firstMatrix;

        fifthMatrix /= 4.0f;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), firstMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

        for (int row = 0; row < fifthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fifthMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(fifthMatrix(row, column), firstMatrix(row, column) / 4.0f, 1e-10f);
            }
        }
    }
}

void Mathematics::VariableMatrixTesting::MatrixCalculateTest()
{
    default_random_engine generator{};

    const uniform_real<float> floatRandomDistribution{ -100.0f, 100.0f };
    const uniform_int<> integerRandomDistribution(1, 20);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        VariableMatrixF firstMatrix(integerRandomDistribution(generator), integerRandomDistribution(generator));

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber(); ++column)
            {
                firstMatrix[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableLengthVectorF firstVector(firstMatrix.GetRowsNumber());

        for (int index = 0; index < firstVector.GetSize(); ++index)
        {
            firstVector[index] = floatRandomDistribution(generator);
        }

        VariableLengthVectorF secondVector(firstMatrix.GetColumnsNumber());

        for (int index = 0; index < secondVector.GetSize(); ++index)
        {
            secondVector[index] = floatRandomDistribution(generator);
        }

        float quadraticForm = Dot(firstVector, firstMatrix * secondVector);

        ASSERT_APPROXIMATE(quadraticForm, firstMatrix.QuadraticForm(firstVector, secondVector), 1e-10f);

        VariableMatrixF secondMatrix = firstMatrix.Transpose();

        ASSERT_EQUAL(firstMatrix.GetRowsNumber(), secondMatrix.GetColumnsNumber());
        ASSERT_EQUAL(firstMatrix.GetColumnsNumber(), secondMatrix.GetRowsNumber());
        ASSERT_EQUAL(firstMatrix.GetElementsNumber(), secondMatrix.GetElementsNumber());

        for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < firstMatrix.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(firstMatrix[row][column], secondMatrix[column][row], 1e-10f);
            }
        }

        VariableLengthVectorF thirdVector = firstMatrix * secondVector;

        ASSERT_EQUAL(thirdVector.GetSize(), firstMatrix.GetRowsNumber());

        VariableLengthVectorF fourthVector(firstMatrix.GetRowsNumber());

        for (int rows = 0; rows < firstMatrix.GetRowsNumber(); ++rows)
        {
            for (int columns = 0; columns < firstMatrix.GetColumnsNumber(); ++columns)
            {
                fourthVector[rows] += firstMatrix[rows][columns] * secondVector[columns];
            }
        }

        ASSERT_TRUE(Approximate(thirdVector, fourthVector, 1e-10f));

        secondVector.ResetSize(firstMatrix.GetRowsNumber());

        for (int index = 0; index < secondVector.GetSize(); ++index)
        {
            secondVector[index] = floatRandomDistribution(generator);
        }

        thirdVector = secondVector * firstMatrix;

        ASSERT_EQUAL(thirdVector.GetSize(), firstMatrix.GetColumnsNumber());

        fourthVector.ResetSize(firstMatrix.GetColumnsNumber());

        for (int rows = 0; rows < firstMatrix.GetRowsNumber(); ++rows)
        {
            for (int columns = 0; columns < firstMatrix.GetColumnsNumber(); ++columns)
            {
                fourthVector[columns] += firstMatrix[rows][columns] * secondVector[rows];
            }
        }

        ASSERT_TRUE(Approximate(thirdVector, fourthVector, 1e-10f));

        VariableMatrixD thirdMatrix(integerRandomDistribution(generator), integerRandomDistribution(generator));

        for (int row = 0; row < thirdMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < thirdMatrix.GetColumnsNumber(); ++column)
            {
                thirdMatrix[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixD fourthMatrix(thirdMatrix.GetRowsNumber(), integerRandomDistribution(generator));

        for (int row = 0; row < fourthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fourthMatrix.GetColumnsNumber(); ++column)
            {
                fourthMatrix[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixD fifthMatrix = TransposeTimes(thirdMatrix, fourthMatrix);
        VariableMatrixD sixthMatrix = thirdMatrix.Transpose() * fourthMatrix;

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), sixthMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), sixthMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), sixthMatrix.GetElementsNumber());

        ASSERT_TRUE(Approximate(fifthMatrix, sixthMatrix, 1e-8));

        fourthMatrix.ResetSize(integerRandomDistribution(generator), thirdMatrix.GetColumnsNumber());

        for (int row = 0; row < fourthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fourthMatrix.GetColumnsNumber(); ++column)
            {
                fourthMatrix[row][column] = floatRandomDistribution(generator);
            }
        }

        fifthMatrix = TimesTranspose(thirdMatrix, fourthMatrix);
        sixthMatrix = thirdMatrix * fourthMatrix.Transpose();

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), sixthMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), sixthMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), sixthMatrix.GetElementsNumber());

        ASSERT_TRUE(Approximate(fifthMatrix, sixthMatrix, 1e-10));

        fourthMatrix.ResetSize(integerRandomDistribution(generator), thirdMatrix.GetRowsNumber());

        for (int row = 0; row < fourthMatrix.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < fourthMatrix.GetColumnsNumber(); ++column)
            {
                fourthMatrix[row][column] = floatRandomDistribution(generator);
            }
        }

        fifthMatrix = TransposeTimesTranspose(thirdMatrix, fourthMatrix);
        sixthMatrix = thirdMatrix.Transpose() * fourthMatrix.Transpose();

        ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), sixthMatrix.GetRowsNumber());
        ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(), sixthMatrix.GetColumnsNumber());
        ASSERT_EQUAL(fifthMatrix.GetElementsNumber(), sixthMatrix.GetElementsNumber());

        ASSERT_TRUE(Approximate(fifthMatrix, sixthMatrix, 1e-10));
    }
}

void Mathematics::VariableMatrixTesting::CompareTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableMatrixD firstMatrix(3, 5, firstDoubleVector);
    VariableMatrixD secondMatrix(3, 5, secondDoubleVector);

    firstMatrix[0][0] = 0.0;
    secondMatrix[0][0] = 1.0;

    ASSERT_TRUE(firstMatrix == firstMatrix);
    ASSERT_FALSE(firstMatrix != firstMatrix);
    ASSERT_FALSE(firstMatrix == secondMatrix);
    ASSERT_TRUE(firstMatrix != secondMatrix);
    ASSERT_TRUE(firstMatrix < secondMatrix);
    ASSERT_TRUE(firstMatrix <= secondMatrix);
    ASSERT_FALSE(firstMatrix > secondMatrix);
    ASSERT_FALSE(firstMatrix >= secondMatrix);

    ASSERT_TRUE(Approximate(firstMatrix, firstMatrix, 1e-10));
    ASSERT_TRUE(Approximate(secondMatrix, secondMatrix));
    ASSERT_FALSE(Approximate(secondMatrix, firstMatrix));
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:40)

#include "VariableMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include <random>

Mathematics::VariableMatrixTesting::VariableMatrixTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, VariableMatrixTesting)

void Mathematics::VariableMatrixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    std::vector<double> firstEntry{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

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

    std::vector<double> secondEntry{ -3.0, -4.0, -5.0, -6.0, -7.0, -8.0, -9.0, -10.0 };

    std::vector<std::vector<double>> entryVector{ firstEntry, secondEntry };
}

void Mathematics::VariableMatrixTesting::AccessTest()
{
    std::vector<double> firstEntry{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

    const VariableMatrixD firstVariableMatrix(2, 4, firstEntry);

    ASSERT_EQUAL(firstVariableMatrix.GetRowsNumber(), 2);
    ASSERT_EQUAL(firstVariableMatrix.GetColumnsNumber(), 4);
    ASSERT_EQUAL(firstVariableMatrix.GetElementsNumber(), 8);
}

void Mathematics::VariableMatrixTesting::ArithmeticCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<float> floatRandomDistribution{ -100.0f, 100.0f };
    const std::uniform_int<> integerRandomDistribution(1, 20);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        VariableMatrixF matrix0(integerRandomDistribution(generator), integerRandomDistribution(generator));

        for (int row = 0; row < matrix0.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix0.GetColumnsNumber();
                 ++column)
            {
                matrix0[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixF matrix1(matrix0.GetColumnsNumber(), integerRandomDistribution(generator));

        for (int row = 0; row < matrix1.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix1.GetColumnsNumber(); ++column)
            {
                matrix1[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixF matrix2 = matrix0 * matrix1;

        ASSERT_EQUAL(matrix2.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix2.GetColumnsNumber(), matrix1.GetColumnsNumber());
        ASSERT_EQUAL(matrix2.GetElementsNumber(), matrix0.GetRowsNumber() * matrix1.GetColumnsNumber());

        for (int row = 0; row < matrix2.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix2.GetColumnsNumber(); ++column)
            {
                float sum = 0;
                for (int index = 0; index < matrix0.GetColumnsNumber(); ++index)
                {
                    sum += matrix0(row, index) * matrix1(index, column);
                }

                ASSERT_APPROXIMATE(sum, matrix2(row, column), 1e-10f);
            }
        }

        matrix2 = matrix0;

        matrix2 *= matrix1;

        ASSERT_EQUAL(matrix2.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix2.GetColumnsNumber(), matrix1.GetColumnsNumber());
        ASSERT_EQUAL(matrix2.GetElementsNumber(), matrix0.GetRowsNumber() * matrix1.GetColumnsNumber());

        for (int row = 0; row < matrix2.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix2.GetColumnsNumber(); ++column)
            {
                float sum = 0;
                for (int index = 0; index < matrix0.GetColumnsNumber(); ++index)
                {
                    sum += matrix0(row, index) * matrix1(index, column);
                }

                ASSERT_APPROXIMATE(sum, matrix2(row, column), 1e-10f);
            }
        }

        matrix2 = -matrix0;

        ASSERT_EQUAL(matrix2.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix2.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix2.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix2.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix2.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix0(row, column), -matrix2(row, column), 1e-10f);
            }
        }

        VariableMatrixF matrix3(matrix0.GetRowsNumber(), matrix0.GetColumnsNumber());

        VariableMatrixF matrix4 = matrix0 + matrix3;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) + matrix3(row, column), 1e-10f);
            }
        }

        matrix4 = matrix0;

        matrix4 += matrix3;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) + matrix3(row, column), 1e-10f);
            }
        }

        matrix4 = matrix0 - matrix3;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) - matrix3(row, column), 1e-10f);
            }
        }

        matrix4 = matrix0;

        matrix4 -= matrix3;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) - matrix3(row, column), 1e-10f);
            }
        }

        matrix4 = matrix0 * 3.0f;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) * 3.0f, 1e-10f);
            }
        }

        matrix4 = 2.5f * matrix0;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) * 2.5f, 1e-10f);
            }
        }

        matrix4 = matrix0;

        matrix4 *= 4.0f;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) * 4.0f, 1e-10f);
            }
        }

        matrix4 = matrix0 / 3.0f;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) / 3.0f, 1e-10f);
            }
        }

        matrix4 = matrix0;

        matrix4 /= 4.0f;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix0.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix0.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix0.GetRowsNumber() * matrix0.GetColumnsNumber());

        for (int row = 0; row < matrix4.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix4.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix4(row, column), matrix0(row, column) / 4.0f, 1e-10f);
            }
        }
    }
}

void Mathematics::VariableMatrixTesting::MatrixCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<float> floatRandomDistribution{ -100.0f, 100.0f };
    const std::uniform_int<> integerRandomDistribution(1, 20);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        VariableMatrixF matrix0(integerRandomDistribution(generator), integerRandomDistribution(generator));

        for (int row = 0; row < matrix0.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix0.GetColumnsNumber(); ++column)
            {
                matrix0[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableLengthVectorF vector0(matrix0.GetRowsNumber());

        for (int index = 0; index < vector0.GetSize(); ++index)
        {
            vector0[index] = floatRandomDistribution(generator);
        }

        VariableLengthVectorF vector1(matrix0.GetColumnsNumber());

        for (int index = 0; index < vector1.GetSize(); ++index)
        {
            vector1[index] = floatRandomDistribution(generator);
        }

        float quadraticForm = Dot(vector0, matrix0 * vector1);

        ASSERT_APPROXIMATE(quadraticForm, matrix0.QuadraticForm(vector0, vector1), 1e-10f);

        VariableMatrixF matrix1 = matrix0.Transpose();

        ASSERT_EQUAL(matrix0.GetRowsNumber(), matrix1.GetColumnsNumber());
        ASSERT_EQUAL(matrix0.GetColumnsNumber(), matrix1.GetRowsNumber());
        ASSERT_EQUAL(matrix0.GetElementsNumber(), matrix1.GetElementsNumber());

        for (int row = 0; row < matrix0.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix0.GetColumnsNumber(); ++column)
            {
                ASSERT_APPROXIMATE(matrix0[row][column], matrix1[column][row], 1e-10f);
            }
        }

        VariableLengthVectorF vector2 = matrix0 * vector1;

        ASSERT_EQUAL(vector2.GetSize(), matrix0.GetRowsNumber());

        VariableLengthVectorF vector3(matrix0.GetRowsNumber());

        for (int rows = 0; rows < matrix0.GetRowsNumber(); ++rows)
        {
            for (int columns = 0; columns < matrix0.GetColumnsNumber(); ++columns)
            {
                vector3[rows] += matrix0[rows][columns] * vector1[columns];
            }
        }

        ASSERT_TRUE(Approximate(vector2, vector3, 1e-10f));

        vector1.ResetSize(matrix0.GetRowsNumber());

        for (int index = 0; index < vector1.GetSize(); ++index)
        {
            vector1[index] = floatRandomDistribution(generator);
        }

        vector2 = vector1 * matrix0;

        ASSERT_EQUAL(vector2.GetSize(), matrix0.GetColumnsNumber());

        vector3.ResetSize(matrix0.GetColumnsNumber());

        for (int rows = 0; rows < matrix0.GetRowsNumber(); ++rows)
        {
            for (int columns = 0; columns < matrix0.GetColumnsNumber(); ++columns)
            {
                vector3[columns] += matrix0[rows][columns] * vector1[rows];
            }
        }

        ASSERT_TRUE(Approximate(vector2, vector3, 1e-10f));

        VariableMatrixD matrix2(integerRandomDistribution(generator), integerRandomDistribution(generator));

        for (int row = 0; row < matrix2.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix2.GetColumnsNumber(); ++column)
            {
                matrix2[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixD matrix3(matrix2.GetRowsNumber(), integerRandomDistribution(generator));

        for (int row = 0; row < matrix3.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix3.GetColumnsNumber(); ++column)
            {
                matrix3[row][column] = floatRandomDistribution(generator);
            }
        }

        VariableMatrixD matrix4 = TransposeTimes(matrix2, matrix3);
        VariableMatrixD matrix5 = matrix2.Transpose() * matrix3;

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix5.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix5.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix5.GetElementsNumber());

        ASSERT_TRUE(Approximate(matrix4, matrix5, 1e-8));

        matrix3.ResetSize(integerRandomDistribution(generator), matrix2.GetColumnsNumber());

        for (int row = 0; row < matrix3.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix3.GetColumnsNumber(); ++column)
            {
                matrix3[row][column] = floatRandomDistribution(generator);
            }
        }

        matrix4 = TimesTranspose(matrix2, matrix3);
        matrix5 = matrix2 * matrix3.Transpose();

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix5.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix5.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix5.GetElementsNumber());

        ASSERT_TRUE(Approximate(matrix4, matrix5, 1e-10));

        matrix3.ResetSize(integerRandomDistribution(generator), matrix2.GetRowsNumber());

        for (int row = 0; row < matrix3.GetRowsNumber(); ++row)
        {
            for (int column = 0; column < matrix3.GetColumnsNumber(); ++column)
            {
                matrix3[row][column] = floatRandomDistribution(generator);
            }
        }

        matrix4 = TransposeTimesTranspose(matrix2, matrix3);
        matrix5 = matrix2.Transpose() * matrix3.Transpose();

        ASSERT_EQUAL(matrix4.GetRowsNumber(), matrix5.GetRowsNumber());
        ASSERT_EQUAL(matrix4.GetColumnsNumber(), matrix5.GetColumnsNumber());
        ASSERT_EQUAL(matrix4.GetElementsNumber(), matrix5.GetElementsNumber());

        ASSERT_TRUE(Approximate(matrix4, matrix5, 1e-10));
    }
}

void Mathematics::VariableMatrixTesting::CompareTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    std::vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    std::vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableMatrixD matrix0(3, 5, firstDoubleVector);
    VariableMatrixD matrix1(3, 5, secondDoubleVector);

    matrix0[0][0] = 0.0;
    matrix1[0][0] = 1.0;

    ASSERT_TRUE(matrix0 == matrix0);
    ASSERT_FALSE(matrix0 != matrix0);
    ASSERT_FALSE(matrix0 == matrix1);
    ASSERT_TRUE(matrix0 != matrix1);
    ASSERT_TRUE(matrix0 < matrix1);
    ASSERT_TRUE(matrix0 <= matrix1);
    ASSERT_FALSE(matrix0 > matrix1);
    ASSERT_FALSE(matrix0 >= matrix1);

    ASSERT_TRUE(Approximate(matrix0, matrix0, 1e-10));
    ASSERT_TRUE(Approximate(matrix1, matrix1));
    ASSERT_FALSE(Approximate(matrix1, matrix0));
}

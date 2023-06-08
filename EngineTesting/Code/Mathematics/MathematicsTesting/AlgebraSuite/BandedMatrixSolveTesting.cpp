///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 21:21)

#include "BandedMatrixSolveTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/BandedMatrixSolveDetail.h"
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class BandedMatrixSolve<float>;
    template class BandedMatrixSolve<double>;
}

Mathematics::BandedMatrixSolveTesting::BandedMatrixSolveTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BandedMatrixSolveTesting)

void Mathematics::BandedMatrixSolveTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BandedMatrixSolveTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolveTest);
}

void Mathematics::BandedMatrixSolveTesting::ConstructionTest()
{
    default_random_engine generator{};
    const uniform_int<> firstIntegerRandomDistribution{ 2, 20 };

    const int size = firstIntegerRandomDistribution(generator);

    const uniform_int<> secondIntegerRandomDistribution{ 1, size };

    const int lowerBoundNumber = secondIntegerRandomDistribution(generator);
    const int upperBoundNumber = secondIntegerRandomDistribution(generator);

    BandedMatrixSolveD firstBandedMatrix(size, lowerBoundNumber, upperBoundNumber);

    ASSERT_EQUAL(firstBandedMatrix.GetSize(), size);
    ASSERT_EQUAL(firstBandedMatrix.GetLowerBandsNumber(), lowerBoundNumber);
    ASSERT_EQUAL(firstBandedMatrix.GetUpperBandsNumber(), upperBoundNumber);

    // 对角线
    for (int i = 0; i < firstBandedMatrix.GetSize(); ++i)
    {
        firstBandedMatrix(i, i) = i * 1.0;
    }

    auto firstPtr = firstBandedMatrix.GetDiagonalBand();

    for (int i = 0; i < firstBandedMatrix.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(firstBandedMatrix(i, i), firstPtr.at(i), 1e-10);
    }

    // 下三角
    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            const int band = column - row;
            if (band < 0 && -band - 1 < firstBandedMatrix.GetLowerBandsNumber())
            {
                firstBandedMatrix(row, column) = row * 1.0 - column * 0.1;
            }
        }
    }

    for (int i = 0; i < firstBandedMatrix.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(firstBandedMatrix.GetLowerBandMax(i), firstBandedMatrix.GetSize() - 1 - i);

        auto secondPtr = firstBandedMatrix.GetLowerBand(i);

        for (int j = 0; j < firstBandedMatrix.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(firstBandedMatrix(i + 1 + j, j), secondPtr.at(j), 1e-10);
        }
    }

    // 上三角
    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            const int band = column - row;
            if (0 < band && band - 1 < firstBandedMatrix.GetUpperBandsNumber())
            {
                firstBandedMatrix(row, column) = row * 2.0 - column * 0.3;
            }
        }
    }

    for (int i = 0; i < firstBandedMatrix.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(firstBandedMatrix.GetUpperBandMax(i), firstBandedMatrix.GetSize() - 1 - i);

        auto secondPtr = firstBandedMatrix.GetUpperBand(i);

        for (int j = 0; j < firstBandedMatrix.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(firstBandedMatrix(j, i + 1 + j), secondPtr.at(j), 1e-10);
        }
    }

    // 其他元素为零
    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            const int band = column - row;

            if (0 < band && firstBandedMatrix.GetUpperBandsNumber() <= band - 1)
            {
                ASSERT_APPROXIMATE(firstBandedMatrix(row, column), 0.0, 1e-10);
            }
            else if (band < 0 && firstBandedMatrix.GetUpperBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(firstBandedMatrix(row, column), 0.0, 1e-10);
            }
        }
    }

    const BandedMatrixSolveD secondBandedMatrix(firstBandedMatrix);

    ASSERT_EQUAL(secondBandedMatrix.GetSize(), firstBandedMatrix.GetSize());
    ASSERT_EQUAL(secondBandedMatrix.GetLowerBandsNumber(), firstBandedMatrix.GetLowerBandsNumber());
    ASSERT_EQUAL(secondBandedMatrix.GetUpperBandsNumber(), firstBandedMatrix.GetUpperBandsNumber());

    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(firstBandedMatrix(row, column), secondBandedMatrix(row, column), 1e-10);
        }
    }

    // 对角线
    const auto thirdPtr = secondBandedMatrix.GetDiagonalBand();

    for (int i = 0; i < secondBandedMatrix.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(secondBandedMatrix(i, i), thirdPtr.at(i), 1e-10);
    }

    // 下三角

    for (int i = 0; i < secondBandedMatrix.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(secondBandedMatrix.GetLowerBandMax(i), secondBandedMatrix.GetSize() - 1 - i);

        const auto fourthPtr = secondBandedMatrix.GetLowerBand(i);

        for (int j = 0; j < secondBandedMatrix.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(secondBandedMatrix(i + 1 + j, j), fourthPtr.at(j), 1e-10);
        }
    }

    // 上三角

    for (int i = 0; i < secondBandedMatrix.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(secondBandedMatrix.GetUpperBandMax(i), secondBandedMatrix.GetSize() - 1 - i);

        const auto fifthPtr = secondBandedMatrix.GetUpperBand(i);

        for (int j = 0; j < secondBandedMatrix.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(secondBandedMatrix(j, i + 1 + j), fifthPtr.at(j), 1e-10);
        }
    }

    // 其他元素为零
    for (int row = 0; row < secondBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < secondBandedMatrix.GetSize(); ++column)
        {
            const int band = column - row;

            if (0 < band && secondBandedMatrix.GetUpperBandsNumber() <= band - 1)
            {
                ASSERT_APPROXIMATE(secondBandedMatrix(row, column), 0.0, 1e-10);
            }
            else if (band < 0 && secondBandedMatrix.GetUpperBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(secondBandedMatrix(row, column), 0.0, 1e-10);
            }
        }
    }

    BandedMatrixSolveD thirdBandedMatrix(5, 1, 1);

    for (int i = 0; i < thirdBandedMatrix.GetSize(); ++i)
    {
        thirdBandedMatrix(i, i) = i * 1.0;
    }

    for (int row = 0; row < thirdBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < thirdBandedMatrix.GetSize(); ++column)
        {
            const int band = column - row;
            if (band < 0 && -band - 1 < thirdBandedMatrix.GetLowerBandsNumber())
            {
                thirdBandedMatrix(row, column) = row * 1.0 - column * 0.1;
            }
        }
    }

    for (int row = 0; row < thirdBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < thirdBandedMatrix.GetSize(); ++column)
        {
            const int band = column - row;
            if (0 < band && band - 1 < thirdBandedMatrix.GetUpperBandsNumber())
            {
                thirdBandedMatrix(row, column) = row * 2.0 - column * 0.2;
            }
        }
    }

    firstBandedMatrix = thirdBandedMatrix;

    ASSERT_EQUAL(thirdBandedMatrix.GetSize(), firstBandedMatrix.GetSize());
    ASSERT_EQUAL(thirdBandedMatrix.GetLowerBandsNumber(), firstBandedMatrix.GetLowerBandsNumber());
    ASSERT_EQUAL(thirdBandedMatrix.GetUpperBandsNumber(), firstBandedMatrix.GetUpperBandsNumber());

    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(firstBandedMatrix(row, column), thirdBandedMatrix(row, column), 1e-10);
        }
    }

    BandedMatrixSolveD fourthBandedMatrix(secondBandedMatrix);

    fourthBandedMatrix.SetZero();

    for (int row = 0; row < fourthBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < fourthBandedMatrix.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(fourthBandedMatrix(row, column), 0.0, 1e-10);
        }
    }

    fourthBandedMatrix.SetIdentity();

    for (int row = 0; row < fourthBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < fourthBandedMatrix.GetSize(); ++column)
        {
            if (row == column)
            {
                ASSERT_APPROXIMATE(fourthBandedMatrix(row, column), 1.0, 1e-10);
            }
            else
            {
                ASSERT_APPROXIMATE(fourthBandedMatrix(row, column), 0.0, 1e-10);
            }
        }
    }

    fourthBandedMatrix.SetEpsilon(1e-11);
    ASSERT_APPROXIMATE(fourthBandedMatrix.GetEpsilon(), 1e-11, 1e-10);
}

void Mathematics::BandedMatrixSolveTesting::SolveTest()
{
    default_random_engine generator{};
    const uniform_int<> firstIntegerRandomDistribution{ 2, 20 };
    const uniform_real<> doubleRandomDistribution{ 1.0, 3.0 };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const int size = firstIntegerRandomDistribution(generator);

        const uniform_int<> secondIntegerRandomDistribution(1, size - 1);

        const int boundNumber = secondIntegerRandomDistribution(generator);

        BandedMatrixSolveD firstBandedMatrix(size, boundNumber, boundNumber, 1e-5);

        // 下三角
        for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
            {
                const int band = column - row;
                if (band < 0 && -band - 1 < firstBandedMatrix.GetLowerBandsNumber())
                {
                    firstBandedMatrix(row, column) = doubleRandomDistribution(generator);
                }
            }
        }

        // 上三角
        for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
            {
                const int band = column - row;
                if (0 < band && band - 1 < firstBandedMatrix.GetUpperBandsNumber())
                {
                    firstBandedMatrix(row, column) = firstBandedMatrix(column, row);
                }
            }
        }

        // 对角线
        firstBandedMatrix(0, 0) = doubleRandomDistribution(generator);

        for (int index = 1; index < firstBandedMatrix.GetSize(); ++index)
        {
            firstBandedMatrix(index, index) = firstBandedMatrix(index - 1, index - 1) * firstBandedMatrix(index, index - 1) + doubleRandomDistribution(generator);
        }

        ASSERT_ENUM_EQUAL(firstBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Unsolved);

        if (!firstBandedMatrix.CholeskyFactor())
        {
            ASSERT_ENUM_EQUAL(firstBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Failure);
            continue;
        }

        ASSERT_ENUM_EQUAL(firstBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Succeed);

        VariableLengthVectorD firstVector(firstBandedMatrix.GetSize());

        for (int index = 0; index < firstVector.GetSize(); ++index)
        {
            firstVector[index] = doubleRandomDistribution(generator);
        }

        VariableLengthVectorD secondVector = firstBandedMatrix.SolveSystem(firstVector);

        ASSERT_TRUE(Approximate(firstBandedMatrix.ToInputVariableMatrix() * secondVector, firstVector, 1e-10));

        VariableMatrixD firstVariableMatrix(firstBandedMatrix.GetSize(), firstBandedMatrix.GetSize());

        for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
        {
            for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
            {
                firstVariableMatrix[row][column] = doubleRandomDistribution(generator);
            }
        }

        VariableMatrixD secondVariableMatrix = firstBandedMatrix.SolveSystem(firstVariableMatrix);

        ASSERT_TRUE(Approximate(firstBandedMatrix.ToInputVariableMatrix() * secondVariableMatrix, firstVariableMatrix, 1e-10));
    }

    BandedMatrixSolveD fifthBandedMatrix(3, 2, 2);

    fifthBandedMatrix(0, 0) = 6;
    fifthBandedMatrix(0, 1) = 7;
    fifthBandedMatrix(0, 2) = 5;
    fifthBandedMatrix(1, 0) = 7;
    fifthBandedMatrix(1, 1) = 13;
    fifthBandedMatrix(1, 2) = 8;
    fifthBandedMatrix(2, 0) = 5;
    fifthBandedMatrix(2, 1) = 8;
    fifthBandedMatrix(2, 2) = 6;

    ASSERT_ENUM_EQUAL(fifthBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Unsolved);

    if (!fifthBandedMatrix.CholeskyFactor())
    {
        ASSERT_ENUM_EQUAL(fifthBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Failure);
    }
    else
    {
        ASSERT_ENUM_EQUAL(fifthBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Succeed);
    }
}

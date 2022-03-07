// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/21 14:38)

#include "BandedMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class BandedMatrix<float>;
    template class BandedMatrix<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, BandedMatrixTesting)

void Mathematics::BandedMatrixTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::BandedMatrixTesting ::ConstructionTest()
{
    default_random_engine generator{};
    uniform_int<> firstIntegerRandomDistribution{ 2, 20 };

    int size = firstIntegerRandomDistribution(generator);

    uniform_int<> secondIntegerRandomDistribution(1, size);

    int lowerBoundNumber = secondIntegerRandomDistribution(generator);
    int upperBoundNumber = secondIntegerRandomDistribution(generator);

    BandedMatrixF firstBandedMatrix(size, lowerBoundNumber, upperBoundNumber);

    ASSERT_EQUAL(firstBandedMatrix.GetSize(), size);
    ASSERT_EQUAL(firstBandedMatrix.GetLowerBandsNumber(), lowerBoundNumber);
    ASSERT_EQUAL(firstBandedMatrix.GetUpperBandsNumber(), upperBoundNumber);

    // 对角线
    for (int i = 0; i < firstBandedMatrix.GetSize(); ++i)
    {
        firstBandedMatrix(i, i) = i * 1.0f;
    }

    auto firstPtr = firstBandedMatrix.GetDiagonalBand();

    for (int i = 0; i < firstBandedMatrix.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(firstBandedMatrix(i, i), firstPtr[i], 1e-8f);
    }

    // 下三角
    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            int band = column - row;
            if (band < 0 && -band - 1 < firstBandedMatrix.GetLowerBandsNumber())
            {
                firstBandedMatrix(row, column) = row * 1.0f - column * 0.1f;
            }
        }
    }

    for (int i = 0; i < firstBandedMatrix.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(firstBandedMatrix.GetLowerBandMax(i), firstBandedMatrix.GetSize() - 1 - i);

        auto secondPtr = firstBandedMatrix.GetLowerBand(i);

        for (int j = 0; j < firstBandedMatrix.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(firstBandedMatrix(i + 1 + j, j), secondPtr[j], 1e-8f);
        }
    }

    // 上三角
    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            int band = column - row;
            if (0 < band && band - 1 < firstBandedMatrix.GetUpperBandsNumber())
            {
                firstBandedMatrix(row, column) = row * 2.0f - column * 0.3f;
            }
        }
    }

    for (int i = 0; i < firstBandedMatrix.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(firstBandedMatrix.GetUpperBandMax(i), firstBandedMatrix.GetSize() - 1 - i);

        auto secondPtr = firstBandedMatrix.GetUpperBand(i);

        for (int j = 0; j < firstBandedMatrix.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(firstBandedMatrix(j, i + 1 + j), secondPtr[j], 1e-8f);
        }
    }

    // 其他元素为零
    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            int band = column - row;

            if (0 < band && firstBandedMatrix.GetUpperBandsNumber() <= band - 1)
            {
                ASSERT_APPROXIMATE(firstBandedMatrix(row, column), 0.0f, 1e-10f);
            }
            else if (band < 0 && firstBandedMatrix.GetUpperBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(firstBandedMatrix(row, column), 0.0f, 1e-8f);
            }
        }
    }

    const BandedMatrixF secondBandedMatrix(firstBandedMatrix);

    ASSERT_EQUAL(secondBandedMatrix.GetSize(), firstBandedMatrix.GetSize());
    ASSERT_EQUAL(secondBandedMatrix.GetLowerBandsNumber(), firstBandedMatrix.GetLowerBandsNumber());
    ASSERT_EQUAL(secondBandedMatrix.GetUpperBandsNumber(), firstBandedMatrix.GetUpperBandsNumber());

    for (int row = 0; row < firstBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < firstBandedMatrix.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(firstBandedMatrix(row, column), secondBandedMatrix(row, column), 1e-8f);
        }
    }

    // 对角线
    const auto thirdPtr = secondBandedMatrix.GetDiagonalBand();

    for (int i = 0; i < secondBandedMatrix.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(secondBandedMatrix(i, i), thirdPtr[i], 1e-8f);
    }

    // 下三角

    for (int i = 0; i < secondBandedMatrix.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(secondBandedMatrix.GetLowerBandMax(i), secondBandedMatrix.GetSize() - 1 - i);

        const auto fourthPtr = secondBandedMatrix.GetLowerBand(i);

        for (int j = 0; j < secondBandedMatrix.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(secondBandedMatrix(i + 1 + j, j), fourthPtr[j], 1e-8f);
        }
    }

    // 上三角

    for (int i = 0; i < secondBandedMatrix.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(secondBandedMatrix.GetUpperBandMax(i), secondBandedMatrix.GetSize() - 1 - i);

        const auto fifthPtr = secondBandedMatrix.GetUpperBand(i);

        for (int j = 0; j < secondBandedMatrix.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(secondBandedMatrix(j, i + 1 + j), fifthPtr[j], 1e-8f);
        }
    }

    // 其他元素为零
    for (int row = 0; row < secondBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < secondBandedMatrix.GetSize(); ++column)
        {
            int band = column - row;

            if (0 < band && secondBandedMatrix.GetUpperBandsNumber() <= band - 1)
            {
                ASSERT_APPROXIMATE(secondBandedMatrix(row, column), 0.0f, 1e-8f);
            }
            else if (band < 0 && secondBandedMatrix.GetUpperBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(secondBandedMatrix(row, column), 0.0f, 1e-8f);
            }
        }
    }

    VariableMatrixF variableMatrix = secondBandedMatrix.ToVariableMatrix();

    for (int row = 0; row < secondBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < secondBandedMatrix.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(variableMatrix(row, column), secondBandedMatrix(row, column), 1e-8f);
        }
    }

    BandedMatrixF thirdBandedMatrix(5, 1, 1);

    for (int i = 0; i < thirdBandedMatrix.GetSize(); ++i)
    {
        thirdBandedMatrix(i, i) = i * 1.0f;
    }

    for (int row = 0; row < thirdBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < thirdBandedMatrix.GetSize(); ++column)
        {
            int band = column - row;
            if (band < 0 && -band - 1 < thirdBandedMatrix.GetLowerBandsNumber())
            {
                thirdBandedMatrix(row, column) = row * 1.0f - column * 0.1f;
            }
        }
    }

    for (int row = 0; row < thirdBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < thirdBandedMatrix.GetSize(); ++column)
        {
            int band = column - row;
            if (0 < band && band - 1 < thirdBandedMatrix.GetUpperBandsNumber())
            {
                thirdBandedMatrix(row, column) = row * 2.0f - column * 0.2f;
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
            ASSERT_APPROXIMATE(firstBandedMatrix(row, column), thirdBandedMatrix(row, column), 1e-8f);
        }
    }

    BandedMatrixF fourthBandedMatrix(secondBandedMatrix);

    fourthBandedMatrix.SetZero();

    for (int row = 0; row < fourthBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < fourthBandedMatrix.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(fourthBandedMatrix(row, column), 0.0f, 1e-8f);
        }
    }

    fourthBandedMatrix.SetIdentity();

    for (int row = 0; row < fourthBandedMatrix.GetSize(); ++row)
    {
        for (int column = 0; column < fourthBandedMatrix.GetSize(); ++column)
        {
            if (row == column)
            {
                ASSERT_APPROXIMATE(fourthBandedMatrix(row, column), 1.0f, 1e-8f);
            }
            else
            {
                ASSERT_APPROXIMATE(fourthBandedMatrix(row, column), 0.0f, 1e-8f);
            }
        }
    }
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:15)

#include "BandedMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class BandedMatrix<float>;
    template class BandedMatrix<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::BandedMatrixTesting::BandedMatrixTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BandedMatrixTesting)

void Mathematics::BandedMatrixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BandedMatrixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::BandedMatrixTesting::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<> integerRandomDistribution0{ 2, 20 };

    const auto size = integerRandomDistribution0(generator);

    std::uniform_int_distribution<> secondIntegerRandomDistribution(1, size);

    const auto lowerBoundNumber = secondIntegerRandomDistribution(generator);
    const auto upperBoundNumber = secondIntegerRandomDistribution(generator);

    BandedMatrixF bandedMatrix0(size, lowerBoundNumber, upperBoundNumber);

    ASSERT_EQUAL(bandedMatrix0.GetSize(), size);
    ASSERT_EQUAL(bandedMatrix0.GetLowerBandsNumber(), lowerBoundNumber);
    ASSERT_EQUAL(bandedMatrix0.GetUpperBandsNumber(), upperBoundNumber);

    // 对角线
    for (auto i = 0; i < bandedMatrix0.GetSize(); ++i)
    {
        bandedMatrix0(i, i) = i * 1.0f;
    }

    auto ptr0 = bandedMatrix0.GetDiagonalBand();

    for (auto i = 0; i < bandedMatrix0.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(bandedMatrix0(i, i), ptr0.at(i), 1e-8f);
    }

    // 下三角
    for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            const auto band = column - row;
            if (band < 0 && -band - 1 < bandedMatrix0.GetLowerBandsNumber())
            {
                bandedMatrix0(row, column) = row * 1.0f - column * 0.1f;
            }
        }
    }

    for (auto i = 0; i < bandedMatrix0.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix0.GetLowerBandMax(i), bandedMatrix0.GetSize() - 1 - i);

        auto ptr1 = bandedMatrix0.GetLowerBand(i);

        for (int j = 0; j < bandedMatrix0.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(i + 1 + j, j), ptr1.at(j), 1e-8f);
        }
    }

    // 上三角
    for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            const auto band = column - row;
            if (0 < band && band - 1 < bandedMatrix0.GetUpperBandsNumber())
            {
                bandedMatrix0(row, column) = row * 2.0f - column * 0.3f;
            }
        }
    }

    for (auto i = 0; i < bandedMatrix0.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix0.GetUpperBandMax(i), bandedMatrix0.GetSize() - 1 - i);

        auto ptr2 = bandedMatrix0.GetUpperBand(i);

        for (int j = 0; j < bandedMatrix0.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(j, i + 1 + j), ptr2.at(j), 1e-8f);
        }
    }

    // 其他元素为零
    for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            const auto band = column - row;

            if (0 < band && bandedMatrix0.GetUpperBandsNumber() <= band - 1)
            {
                ASSERT_APPROXIMATE(bandedMatrix0(row, column), 0.0f, 1e-10f);
            }
            else if (band < 0 && bandedMatrix0.GetLowerBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(bandedMatrix0(row, column), 0.0f, 1e-8f);
            }
        }
    }

    const BandedMatrixF bandedMatrix1(bandedMatrix0);

    ASSERT_EQUAL(bandedMatrix1.GetSize(), bandedMatrix0.GetSize());
    ASSERT_EQUAL(bandedMatrix1.GetLowerBandsNumber(), bandedMatrix0.GetLowerBandsNumber());
    ASSERT_EQUAL(bandedMatrix1.GetUpperBandsNumber(), bandedMatrix0.GetUpperBandsNumber());

    for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(row, column), bandedMatrix1(row, column), 1e-8f);
        }
    }

    // 对角线
    const auto ptr2 = bandedMatrix1.GetDiagonalBand();

    for (auto i = 0; i < bandedMatrix1.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(bandedMatrix1(i, i), ptr2.at(i), 1e-8f);
    }

    // 下三角

    for (auto i = 0; i < bandedMatrix1.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix1.GetLowerBandMax(i), bandedMatrix1.GetSize() - 1 - i);

        const auto ptr3 = bandedMatrix1.GetLowerBand(i);

        for (auto j = 0; j < bandedMatrix1.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix1(i + 1 + j, j), ptr3.at(j), 1e-8f);
        }
    }

    // 上三角

    for (auto i = 0; i < bandedMatrix1.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix1.GetUpperBandMax(i), bandedMatrix1.GetSize() - 1 - i);

        const auto ptr4 = bandedMatrix1.GetUpperBand(i);

        for (auto j = 0; j < bandedMatrix1.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix1(j, i + 1 + j), ptr4.at(j), 1e-8f);
        }
    }

    // 其他元素为零
    for (auto row = 0; row < bandedMatrix1.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix1.GetSize(); ++column)
        {
            const auto band = column - row;

            if (0 < band && bandedMatrix1.GetUpperBandsNumber() <= band - 1)
            {
                ASSERT_APPROXIMATE(bandedMatrix1(row, column), 0.0f, 1e-8f);
            }
            else if (band < 0 && bandedMatrix1.GetLowerBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(bandedMatrix1(row, column), 0.0f, 1e-8f);
            }
        }
    }

    VariableMatrixF variableMatrix = bandedMatrix1.ToVariableMatrix();

    for (auto row = 0; row < bandedMatrix1.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix1.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(variableMatrix(row, column), bandedMatrix1(row, column), 1e-8f);
        }
    }

    BandedMatrixF bandedMatrix2(5, 1, 1);

    for (auto i = 0; i < bandedMatrix2.GetSize(); ++i)
    {
        bandedMatrix2(i, i) = i * 1.0f;
    }

    for (auto row = 0; row < bandedMatrix2.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix2.GetSize(); ++column)
        {
            const auto band = column - row;
            if (band < 0 && -band - 1 < bandedMatrix2.GetLowerBandsNumber())
            {
                bandedMatrix2(row, column) = row * 1.0f - column * 0.1f;
            }
        }
    }

    for (auto row = 0; row < bandedMatrix2.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix2.GetSize(); ++column)
        {
            const auto band = column - row;
            if (0 < band && band - 1 < bandedMatrix2.GetUpperBandsNumber())
            {
                bandedMatrix2(row, column) = row * 2.0f - column * 0.2f;
            }
        }
    }

    bandedMatrix0 = bandedMatrix2;

    ASSERT_EQUAL(bandedMatrix2.GetSize(), bandedMatrix0.GetSize());
    ASSERT_EQUAL(bandedMatrix2.GetLowerBandsNumber(), bandedMatrix0.GetLowerBandsNumber());
    ASSERT_EQUAL(bandedMatrix2.GetUpperBandsNumber(), bandedMatrix0.GetUpperBandsNumber());

    for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(row, column), bandedMatrix2(row, column), 1e-8f);
        }
    }

    BandedMatrixF bandedMatrix3(bandedMatrix1);

    bandedMatrix3.SetZero();

    for (auto row = 0; row < bandedMatrix3.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix3.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(bandedMatrix3(row, column), 0.0f, 1e-8f);
        }
    }

    bandedMatrix3.SetIdentity();

    for (auto row = 0; row < bandedMatrix3.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix3.GetSize(); ++column)
        {
            if (row == column)
            {
                ASSERT_APPROXIMATE(bandedMatrix3(row, column), 1.0f, 1e-8f);
            }
            else
            {
                ASSERT_APPROXIMATE(bandedMatrix3(row, column), 0.0f, 1e-8f);
            }
        }
    }
}

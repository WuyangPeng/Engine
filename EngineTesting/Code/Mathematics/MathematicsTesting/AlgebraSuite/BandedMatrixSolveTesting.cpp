///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:50)

#include "BandedMatrixSolveTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/BandedMatrixSolveDetail.h"
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include <random>

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
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> integerRandomDistribution0{ 2, 20 };

    const int size = integerRandomDistribution0(generator);

    std::uniform_int<> integerRandomDistribution1{ 1, size };

    const int lowerBoundNumber = integerRandomDistribution1(generator);
    const int upperBoundNumber = integerRandomDistribution1(generator);

    BandedMatrixSolveD bandedMatrix0(size, lowerBoundNumber, upperBoundNumber);

    ASSERT_EQUAL(bandedMatrix0.GetSize(), size);
    ASSERT_EQUAL(bandedMatrix0.GetLowerBandsNumber(), lowerBoundNumber);
    ASSERT_EQUAL(bandedMatrix0.GetUpperBandsNumber(), upperBoundNumber);

    // 对角线
    for (int i = 0; i < bandedMatrix0.GetSize(); ++i)
    {
        bandedMatrix0(i, i) = i * 1.0;
    }

    auto ptr0 = bandedMatrix0.GetDiagonalBand();

    for (auto i = 0; i < bandedMatrix0.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(bandedMatrix0(i, i), ptr0.at(i), 1e-10);
    }

    // 下三角
    for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            const auto band = column - row;
            if (band < 0 && -band - 1 < bandedMatrix0.GetLowerBandsNumber())
            {
                bandedMatrix0(row, column) = row * 1.0 - column * 0.1;
            }
        }
    }

    for (auto i = 0; i < bandedMatrix0.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix0.GetLowerBandMax(i), bandedMatrix0.GetSize() - 1 - i);

        auto ptr1 = bandedMatrix0.GetLowerBand(i);

        for (int j = 0; j < bandedMatrix0.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(i + 1 + j, j), ptr1.at(j), 1e-10);
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
                bandedMatrix0(row, column) = row * 2.0 - column * 0.3;
            }
        }
    }

    for (auto i = 0; i < bandedMatrix0.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix0.GetUpperBandMax(i), bandedMatrix0.GetSize() - 1 - i);

        auto ptr1 = bandedMatrix0.GetUpperBand(i);

        for (int j = 0; j < bandedMatrix0.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(j, i + 1 + j), ptr1.at(j), 1e-10);
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
                ASSERT_APPROXIMATE(bandedMatrix0(row, column), 0.0, 1e-10);
            }
            else if (band < 0 && bandedMatrix0.GetLowerBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(bandedMatrix0(row, column), 0.0, 1e-10);
            }
        }
    }

    const BandedMatrixSolveD bandedMatrix1(bandedMatrix0);

    ASSERT_EQUAL(bandedMatrix1.GetSize(), bandedMatrix0.GetSize());
    ASSERT_EQUAL(bandedMatrix1.GetLowerBandsNumber(), bandedMatrix0.GetLowerBandsNumber());
    ASSERT_EQUAL(bandedMatrix1.GetUpperBandsNumber(), bandedMatrix0.GetUpperBandsNumber());

    for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(row, column), bandedMatrix1(row, column), 1e-10);
        }
    }

    // 对角线
    const auto ptr2 = bandedMatrix1.GetDiagonalBand();

    for (auto i = 0; i < bandedMatrix1.GetSize(); ++i)
    {
        ASSERT_APPROXIMATE(bandedMatrix1(i, i), ptr2.at(i), 1e-10);
    }

    // 下三角

    for (auto i = 0; i < bandedMatrix1.GetLowerBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix1.GetLowerBandMax(i), bandedMatrix1.GetSize() - 1 - i);

        const auto ptr3 = bandedMatrix1.GetLowerBand(i);

        for (auto j = 0; j < bandedMatrix1.GetLowerBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix1(i + 1 + j, j), ptr3.at(j), 1e-10);
        }
    }

    // 上三角

    for (auto i = 0; i < bandedMatrix1.GetUpperBandsNumber(); ++i)
    {
        ASSERT_EQUAL(bandedMatrix1.GetUpperBandMax(i), bandedMatrix1.GetSize() - 1 - i);

        const auto ptr4 = bandedMatrix1.GetUpperBand(i);

        for (int j = 0; j < bandedMatrix1.GetUpperBandMax(i); ++j)
        {
            ASSERT_APPROXIMATE(bandedMatrix1(j, i + 1 + j), ptr4.at(j), 1e-10);
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
                ASSERT_APPROXIMATE(bandedMatrix1(row, column), 0.0, 1e-10);
            }
            else if (band < 0 && bandedMatrix1.GetLowerBandsNumber() <= -band - 1)
            {
                ASSERT_APPROXIMATE(bandedMatrix1(row, column), 0.0, 1e-10);
            }
        }
    }

    BandedMatrixSolveD bandedMatrix2(5, 1, 1);

    for (auto i = 0; i < bandedMatrix2.GetSize(); ++i)
    {
        bandedMatrix2(i, i) = i * 1.0;
    }

    for (auto row = 0; row < bandedMatrix2.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix2.GetSize(); ++column)
        {
            const auto band = column - row;
            if (band < 0 && -band - 1 < bandedMatrix2.GetLowerBandsNumber())
            {
                bandedMatrix2(row, column) = row * 1.0 - column * 0.1;
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
                bandedMatrix2(row, column) = row * 2.0 - column * 0.2;
            }
        }
    }

    bandedMatrix0 = bandedMatrix2;

    ASSERT_EQUAL(bandedMatrix2.GetSize(), bandedMatrix0.GetSize());
    ASSERT_EQUAL(bandedMatrix2.GetLowerBandsNumber(), bandedMatrix0.GetLowerBandsNumber());
    ASSERT_EQUAL(bandedMatrix2.GetUpperBandsNumber(), bandedMatrix0.GetUpperBandsNumber());

    for (int row = 0; row < bandedMatrix0.GetSize(); ++row)
    {
        for (int column = 0; column < bandedMatrix0.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(bandedMatrix0(row, column), bandedMatrix2(row, column), 1e-10);
        }
    }

    BandedMatrixSolveD bandedMatrix3(bandedMatrix1);

    bandedMatrix3.SetZero();

    for (auto row = 0; row < bandedMatrix3.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix3.GetSize(); ++column)
        {
            ASSERT_APPROXIMATE(bandedMatrix3(row, column), 0.0, 1e-10);
        }
    }

    bandedMatrix3.SetIdentity();

    for (auto row = 0; row < bandedMatrix3.GetSize(); ++row)
    {
        for (auto column = 0; column < bandedMatrix3.GetSize(); ++column)
        {
            if (row == column)
            {
                ASSERT_APPROXIMATE(bandedMatrix3(row, column), 1.0, 1e-10);
            }
            else
            {
                ASSERT_APPROXIMATE(bandedMatrix3(row, column), 0.0, 1e-10);
            }
        }
    }
}

void Mathematics::BandedMatrixSolveTesting::SolveTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> integerRandomDistribution0{ 2, 20 };
    std::uniform_real<> doubleRandomDistribution{ 1.0, 3.0 };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto size = integerRandomDistribution0(generator);

        std::uniform_int<> integerRandomDistribution1(1, size - 1);

        const auto boundNumber = integerRandomDistribution1(generator);

        BandedMatrixSolveD bandedMatrix0(size, boundNumber, boundNumber, 1e-5);

        // 下三角
        for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
        {
            for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
            {
                const auto band = column - row;
                if (band < 0 && -band - 1 < bandedMatrix0.GetLowerBandsNumber())
                {
                    bandedMatrix0(row, column) = doubleRandomDistribution(generator);
                }
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
                    bandedMatrix0(row, column) = bandedMatrix0(column, row);
                }
            }
        }

        // 对角线
        bandedMatrix0(0, 0) = doubleRandomDistribution(generator);

        for (auto index = 1; index < bandedMatrix0.GetSize(); ++index)
        {
            bandedMatrix0(index, index) = bandedMatrix0(index - 1, index - 1) * bandedMatrix0(index, index - 1) + doubleRandomDistribution(generator);
        }

        ASSERT_EQUAL(bandedMatrix0.GetSolve(), BandedMatrixSolveFlags::Unsolved);

        if (!bandedMatrix0.CholeskyFactor())
        {
            ASSERT_EQUAL(bandedMatrix0.GetSolve(), BandedMatrixSolveFlags::Failure);
            continue;
        }

        ASSERT_EQUAL(bandedMatrix0.GetSolve(), BandedMatrixSolveFlags::Succeed);

        VariableLengthVectorD vector0(bandedMatrix0.GetSize());

        for (auto index = 0; index < vector0.GetSize(); ++index)
        {
            vector0[index] = doubleRandomDistribution(generator);
        }

        VariableLengthVectorD vector1 = bandedMatrix0.SolveSystem(vector0);

        ASSERT_TRUE(Approximate(bandedMatrix0.ToInputVariableMatrix() * vector1, vector0, 1e-10));

        VariableMatrixD variableMatrix0(bandedMatrix0.GetSize(), bandedMatrix0.GetSize());

        for (auto row = 0; row < bandedMatrix0.GetSize(); ++row)
        {
            for (auto column = 0; column < bandedMatrix0.GetSize(); ++column)
            {
                variableMatrix0(row, column) = doubleRandomDistribution(generator);
            }
        }

        VariableMatrixD variableMatrix1 = bandedMatrix0.SolveSystem(variableMatrix0);

        ASSERT_TRUE(Approximate(bandedMatrix0.ToInputVariableMatrix() * variableMatrix1, variableMatrix0, 1e-10));
    }

    BandedMatrixSolveD bandedMatrix4(3, 2, 2);

    bandedMatrix4(0, 0) = 6;
    bandedMatrix4(0, 1) = 7;
    bandedMatrix4(0, 2) = 5;
    bandedMatrix4(1, 0) = 7;
    bandedMatrix4(1, 1) = 13;
    bandedMatrix4(1, 2) = 8;
    bandedMatrix4(2, 0) = 5;
    bandedMatrix4(2, 1) = 8;
    bandedMatrix4(2, 2) = 6;

    ASSERT_EQUAL(bandedMatrix4.GetSolve(), BandedMatrixSolveFlags::Unsolved);

    if (!bandedMatrix4.CholeskyFactor())
    {
        ASSERT_EQUAL(bandedMatrix4.GetSolve(), BandedMatrixSolveFlags::Failure);
    }
    else
    {
        ASSERT_EQUAL(bandedMatrix4.GetSolve(), BandedMatrixSolveFlags::Succeed);
    }
}

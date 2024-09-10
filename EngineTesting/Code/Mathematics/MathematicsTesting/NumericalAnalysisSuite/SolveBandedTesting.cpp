///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:08)

#include "SolveBandedTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include <random>

Mathematics::SolveBandedTesting::SolveBandedTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, SolveBandedTesting)

void Mathematics::SolveBandedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::SolveBandedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BandedTest);
}

void Mathematics::SolveBandedTesting::BandedTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> floatRandomDistribution(-100.0, 100.0);
    std::uniform_int_distribution<> integerRandomDistribution(4, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const int size = integerRandomDistribution(generator);

        BandedMatrix<double> matrix0(size, size - 1, size - 2);

        auto diagonalBand = matrix0.GetDiagonalBand();
        for (int i = 0; i < matrix0.GetSize(); ++i)
        {
            diagonalBand.at(i) = floatRandomDistribution(generator);
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
    }
}

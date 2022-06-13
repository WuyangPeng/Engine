///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:09)

#include "SolveBandedTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SolveBandedTesting)

void Mathematics::SolveBandedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BandedTest);
}

void Mathematics::SolveBandedTesting::BandedTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(4, 10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const int size = integerRandomDistribution(generator);

        BandedMatrix<double> firstMatrix(size, size - 1, size - 2);

        auto diagonalBand = firstMatrix.GetDiagonalBand();
        for (int i = 0; i < firstMatrix.GetSize(); ++i)
        {
            diagonalBand.at(i) = floatRandomDistribution(generator);
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
    }
}

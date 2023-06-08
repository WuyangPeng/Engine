///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 16:28)

#include "BandedMatrixInvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/BandedMatrixInvertDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class BandedMatrixInvert<float>;
    template class BandedMatrixInvert<double>;
}

Mathematics::BandedMatrixInvertTesting::BandedMatrixInvertTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BandedMatrixInvertTesting)

void Mathematics::BandedMatrixInvertTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BandedMatrixInvertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BandedTest);
}

void Mathematics::BandedMatrixInvertTesting::BandedTest()
{
    default_random_engine generator;
    const uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    const uniform_int<> integerRandomDistribution(4, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const auto size = integerRandomDistribution(generator);

        BandedMatrixD firstMatrix(size, size - 1, size - 2);

        auto diagonalBand = firstMatrix.GetDiagonalBand();
        for (auto i = 0; i < firstMatrix.GetSize(); ++i)
        {
            firstMatrix(i, i) = floatRandomDistribution(generator);
        }

        for (auto row = 0; row < firstMatrix.GetSize(); ++row)
        {
            for (auto column = 0; column < firstMatrix.GetSize(); ++column)
            {
                const auto band = column - row;
                if (band < 0 && -band - 1 < firstMatrix.GetLowerBandsNumber())
                {
                    firstMatrix(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        for (auto row = 0; row < firstMatrix.GetSize(); ++row)
        {
            for (auto column = 0; column < firstMatrix.GetSize(); ++column)
            {
                const auto band = column - row;
                if (0 < band && band - 1 < firstMatrix.GetUpperBandsNumber())
                {
                    firstMatrix(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        BandedMatrixInvert<double> invert(firstMatrix, 1e-10);

        VariableMatrixD secondMatrix = invert.GetInvert();
        VariableMatrixD thirdMatrix = firstMatrix.ToVariableMatrix() * secondMatrix;
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

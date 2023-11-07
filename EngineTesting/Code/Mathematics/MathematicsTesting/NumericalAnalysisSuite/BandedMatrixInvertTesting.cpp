///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:59)

#include "BandedMatrixInvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/BandedMatrixInvertDetail.h"

#include <random>

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
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> floatRandomDistribution(-100.0, 100.0);
    std::uniform_int<> integerRandomDistribution(4, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const auto size = integerRandomDistribution(generator);

        BandedMatrixD matrix0(size, size - 1, size - 2);

        auto diagonalBand = matrix0.GetDiagonalBand();
        for (auto i = 0; i < matrix0.GetSize(); ++i)
        {
            matrix0(i, i) = floatRandomDistribution(generator);
        }

        for (auto row = 0; row < matrix0.GetSize(); ++row)
        {
            for (auto column = 0; column < matrix0.GetSize(); ++column)
            {
                const auto band = column - row;
                if (band < 0 && -band - 1 < matrix0.GetLowerBandsNumber())
                {
                    matrix0(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        for (auto row = 0; row < matrix0.GetSize(); ++row)
        {
            for (auto column = 0; column < matrix0.GetSize(); ++column)
            {
                const auto band = column - row;
                if (0 < band && band - 1 < matrix0.GetUpperBandsNumber())
                {
                    matrix0(row, column) = floatRandomDistribution(generator);
                }
            }
        }

        BandedMatrixInvert<double> invert(matrix0, 1e-10);

        VariableMatrixD matrix1 = invert.GetInvert();
        VariableMatrixD matrix2 = matrix0.ToVariableMatrix() * matrix1;
        VariableMatrixD matrix3(size, size);

        for (auto row = 0; row < matrix3.GetRowsNumber(); ++row)
        {
            matrix3(row, row) = 1.0;
        }

        using VariableMatrixdApproximate = bool (*)(const VariableMatrixD& lhs, const VariableMatrixD& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix2, matrix3, 1e-10);
    }
}

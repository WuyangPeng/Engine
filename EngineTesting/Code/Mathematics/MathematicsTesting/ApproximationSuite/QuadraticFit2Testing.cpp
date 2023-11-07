///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:19)

#include "QuadraticFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Approximation/QuadraticFit2Detail.h"

#include <random>

namespace Mathematics
{
    template class QuadraticFit2<float>;
    template class QuadraticFit2<double>;
}

Mathematics::QuadraticFit2Testing::QuadraticFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuadraticFit2Testing)

void Mathematics::QuadraticFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuadraticFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticFit2Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(3, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = randomDistribution1(generator);

        for (int k = 0; k < size; ++k)
        {
            vertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
        }

        QuadraticFit2D quadraticFit2(vertices);

        VariableLengthVectorD coeff = quadraticFit2.GetCoeff();
        const double eigenValue = quadraticFit2.GetEigenValue();

        ASSERT_TRUE(0.0 <= eigenValue && eigenValue <= 1.0);

        ASSERT_TRUE(MathD::FAbs(coeff.Length() - 1.0) <= MathD::GetZeroTolerance());

        for (int k = 0; k < size; ++k)
        {
            const double value = coeff[0] + coeff[1] * vertices.at(k).GetX() +
                                 coeff[2] * vertices.at(k).GetY() +
                                 coeff[3] * vertices.at(k).GetX() * vertices.at(k).GetX() +
                                 coeff[4] * vertices.at(k).GetY() * vertices.at(k).GetY() +
                                 coeff[5] * vertices.at(k).GetX() * vertices.at(k).GetY();

            if (eigenValue <= MathD::GetZeroTolerance())
            {
                ASSERT_APPROXIMATE(value, 0.0, 1e-8);
            }
            else if (eigenValue <= 0.6)
            {
                ASSERT_LESS_EQUAL(MathD::FAbs(value), 1.4);
            }
            else if (eigenValue <= 1.0)
            {
                ASSERT_TRUE(MathD::FAbs(value) <= 1.5);
            }
        }
    }
}

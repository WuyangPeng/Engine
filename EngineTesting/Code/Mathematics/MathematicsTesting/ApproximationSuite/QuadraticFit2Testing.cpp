///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 16:57)

#include "QuadraticFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Approximation/QuadraticFit2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class QuadraticFit2<float>;
    template class QuadraticFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuadraticFit2Testing)

void Mathematics::QuadraticFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticFit2Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(3, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int k = 0; k < size; ++k)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
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
                ASSERT_TRUE(MathD::FAbs(value) <= 1.2);
            }
            else if (eigenValue <= 1.0)
            {
                ASSERT_TRUE(MathD::FAbs(value) <= 1.5);
            }
        }
    }
}

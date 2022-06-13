///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 17:20)

#include "GaussianQuadratureTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/GaussianQuadratureDetail.h"

namespace Mathematics
{
    template class GaussianQuadrature<float, GaussianQuadratureTesting>;
    template class GaussianQuadrature<double, GaussianQuadratureTesting>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, GaussianQuadratureTesting)

void Mathematics::GaussianQuadratureTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResultTest);
}

double Mathematics::GaussianQuadratureTesting::Solution(double input, const GaussianQuadratureTesting* userData) noexcept
{
    if (userData != nullptr)
        return input * userData->GetUserData() + 3;
    else
        return 0.0;
}

double Mathematics::GaussianQuadratureTesting::GetUserData() const noexcept
{
    return -5;
}

void Mathematics::GaussianQuadratureTesting::ResultTest()
{
    constexpr int degree = 5;
    const std::array<double, degree> root{ -0.9061798459, -0.5384693101, 0.0, +0.5384693101, +0.9061798459 };
    const std::array<double, degree> coeff{ 0.2369268850, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268850 };

    constexpr double firstValue = 3.5;
    constexpr double secondValue = 1.5;

    constexpr double radius = (0.5) * (secondValue - firstValue);
    constexpr double center = (0.5) * (secondValue + firstValue);

    double result = 0.0;

    for (auto i = 0; i < degree; ++i)
    {
        result += coeff.at(i) * Solution(radius * root.at(i) + center, this);
    }

    result *= radius;

    const GaussianQuadrature<double, GaussianQuadratureTesting> gaussianQuadrature(firstValue, secondValue, Solution, this);

    ASSERT_APPROXIMATE(result, gaussianQuadrature.GetResult(), 1e-10);
}

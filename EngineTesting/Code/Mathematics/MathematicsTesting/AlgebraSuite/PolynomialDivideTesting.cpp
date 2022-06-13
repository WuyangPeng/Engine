///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:16)

#include "PolynomialDivideTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/PolynomialDivideDetail.h"

#include <random>
#include <vector>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class PolynomialDivide<float>;
    template class PolynomialDivide<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialDivideTesting)

void Mathematics::PolynomialDivideTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::PolynomialDivideTesting::ConstructionTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                      randomDistribution(generator), randomDistribution(generator) };

    PolynomialD firstPolynomial(firstDoubleVector);

    vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    PolynomialD secondPolynomial(secondDoubleVector);

    PolynomialDivideD polynomialDivide(firstPolynomial, secondPolynomial);

    ASSERT_TRUE(Approximate(polynomialDivide.GetQuotient(), firstPolynomial));
    ASSERT_TRUE(Approximate(polynomialDivide.GetRemainder(), secondPolynomial));
}

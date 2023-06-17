///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:35)

#include "PolynomialDivideTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/PolynomialDivideDetail.h"

#include <random>
#include <vector>

namespace Mathematics
{
    template class PolynomialDivide<float>;
    template class PolynomialDivide<double>;
}

Mathematics::PolynomialDivideTesting::PolynomialDivideTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialDivideTesting)

void Mathematics::PolynomialDivideTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialDivideTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::PolynomialDivideTesting::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    std::vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                           randomDistribution(generator), randomDistribution(generator) };

    PolynomialD firstPolynomial(firstDoubleVector);

    std::vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    PolynomialD secondPolynomial(secondDoubleVector);

    PolynomialDivideD polynomialDivide(firstPolynomial, secondPolynomial);

    ASSERT_TRUE(Approximate(polynomialDivide.GetQuotient(), firstPolynomial));
    ASSERT_TRUE(Approximate(polynomialDivide.GetRemainder(), secondPolynomial));
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:16)

#include "PolynomialTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <boost/numeric/conversion/cast.hpp>
#include <random>
#include <vector>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Polynomial<float>;
    template class Polynomial<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::PolynomialTesting::PolynomialTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialTesting)

void Mathematics::PolynomialTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::PolynomialTesting::ConstructionTest()
{
    PolynomialF firstPolynomial{ 0 };

    ASSERT_EQUAL(firstPolynomial.GetDegree(), 0);

    PolynomialF secondPolynomial(2);

    ASSERT_EQUAL(secondPolynomial.GetDegree(), 2);

    vector<double> doubleVector{ 3.0, 5.0, 2.0, 1.0, 0.0, 2.0 };
    const int degree = boost::numeric_cast<int>(doubleVector.size() - 1);

    PolynomialD thirdPolynomial(doubleVector);

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), degree);
    for (int i = 0; i <= degree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], doubleVector.at(i), 1e-10);
    }

    PolynomialD fourthPolynomial(thirdPolynomial);

    ASSERT_EQUAL(fourthPolynomial.GetDegree(), degree);
    ASSERT_TRUE(Approximate(fourthPolynomial, thirdPolynomial));

    fourthPolynomial.ResetDegree(3);

    for (int i = 0; i <= fourthPolynomial.GetDegree(); ++i)
    {
        fourthPolynomial[i] = 2.0;
    }

    thirdPolynomial = fourthPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), 3);
    ASSERT_EQUAL(fourthPolynomial.GetDegree(), 3);
    for (int i = 0; i <= thirdPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], 2.0, 1e-10);
        ASSERT_APPROXIMATE(fourthPolynomial[i], 2.0, 1e-10);
    }
}

void Mathematics::PolynomialTesting::AccessTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> doubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                 randomDistribution(generator), randomDistribution(generator) };

    const int degree = boost::numeric_cast<int>(doubleVector.size() - 1);

    const PolynomialD firstPolynomial(doubleVector);
    PolynomialD secondPolynomial(doubleVector);

    ASSERT_EQUAL(firstPolynomial.GetDegree(), degree);
    ASSERT_EQUAL(secondPolynomial.GetDegree(), degree);
}

void Mathematics::PolynomialTesting::UpdateOperatorTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                      randomDistribution(generator), randomDistribution(generator) };

    PolynomialD firstPolynomial(firstDoubleVector);

    PolynomialD secondPolynomial = -firstPolynomial;
    const int firstDegree = boost::numeric_cast<int>(firstDoubleVector.size() - 1);

    ASSERT_EQUAL(secondPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i <= firstDegree; ++i)
    {
        ASSERT_APPROXIMATE(secondPolynomial[i], -firstDoubleVector.at(i), 1e-10);
    }

    vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    PolynomialD thirdPolynomial(secondDoubleVector);
    const int secondDegree = boost::numeric_cast<int>(secondDoubleVector.size() - 1);
    ASSERT_EQUAL(thirdPolynomial.GetDegree(), secondDegree);

    thirdPolynomial += secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i <= secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], -firstDoubleVector.at(i) + secondDoubleVector.at(i), 1e-10);
    }

    ASSERT_APPROXIMATE(thirdPolynomial[firstDegree], -firstDoubleVector.at(firstDegree), 1e-10);

    PolynomialD fourthPolynomial(secondDoubleVector);
    ASSERT_EQUAL(fourthPolynomial.GetDegree(), secondDegree);

    fourthPolynomial -= firstPolynomial;

    ASSERT_EQUAL(fourthPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i <= secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(fourthPolynomial[i], -firstDoubleVector.at(i) + secondDoubleVector.at(i), 1e-10);
    }

    ASSERT_APPROXIMATE(fourthPolynomial[firstDegree], -firstDoubleVector.at(firstDegree), 1e-10);

    PolynomialD fifthPolynomial(secondDoubleVector);
    PolynomialD sixthPolynomial(firstDoubleVector);

    firstPolynomial *= fifthPolynomial;

    ASSERT_EQUAL(firstPolynomial.GetDegree(), firstDegree + secondDegree);

    PolynomialD seventhPolynomial(firstDegree + secondDegree);

    MAYBE_UNUSED const auto degree = seventhPolynomial.GetDegree() + 1;

    for (int lhsIndex = 0; lhsIndex <= firstDegree; ++lhsIndex)
    {
        for (int rhsIndex = 0; rhsIndex <= secondDegree; ++rhsIndex)
        {
            const int index = lhsIndex + rhsIndex;
            seventhPolynomial[index] += sixthPolynomial[lhsIndex] * fifthPolynomial[rhsIndex];
        }
    }

    ASSERT_TRUE(Approximate(seventhPolynomial, firstPolynomial, 1e-10));

    firstPolynomial += 3.0;

    ASSERT_APPROXIMATE(seventhPolynomial[0] + 3.0, firstPolynomial[0], 0.000001);

    for (int i = 1; i <= firstPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(seventhPolynomial[i], firstPolynomial[i], 1e-10);
    }

    firstPolynomial -= 4.0;

    ASSERT_APPROXIMATE(seventhPolynomial[0] - 1.0, firstPolynomial[0], 1e-10);

    for (int i = 1; i <= firstPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(seventhPolynomial[i], firstPolynomial[i], 1e-10);
    }

    firstPolynomial += 1.0;
    firstPolynomial *= 2.0;

    for (int i = 0; i <= firstPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(seventhPolynomial[i] * 2.0, firstPolynomial[i], 1e-10);
    }

    firstPolynomial /= 3.0;

    for (int i = 0; i <= firstPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(seventhPolynomial[i] * 2.0 / 3.0, firstPolynomial[i], 1e-10);
    }
}

void Mathematics::PolynomialTesting::OperationTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                      randomDistribution(generator), randomDistribution(generator) };

    PolynomialD firstPolynomial(firstDoubleVector);

    const int firstDegree = boost::numeric_cast<int>(firstDoubleVector.size() - 1);

    vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    PolynomialD secondPolynomial(secondDoubleVector);
    const int secondDegree = boost::numeric_cast<int>(secondDoubleVector.size() - 1);

    PolynomialD thirdPolynomial = firstPolynomial + secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i < secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], firstDoubleVector.at(i) + secondDoubleVector.at(i), 1e-10);
    }

    ASSERT_APPROXIMATE(thirdPolynomial[firstDegree], firstDoubleVector.at(firstDegree), 1e-10);

    thirdPolynomial = firstPolynomial - secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i < secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], firstDoubleVector.at(i) - secondDoubleVector.at(i), 1e-10);
    }

    ASSERT_APPROXIMATE(thirdPolynomial[firstDegree], firstDoubleVector.at(firstDegree), 1e-10);

    thirdPolynomial = firstPolynomial * secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree + secondDegree);

    PolynomialD fourthPolynomial(firstDegree + secondDegree);

    MAYBE_UNUSED const auto degree = fourthPolynomial.GetDegree() + 1;

    for (int lhsIndex = 0; lhsIndex <= firstDegree; ++lhsIndex)
    {
        for (int rhsIndex = 0; rhsIndex <= secondDegree; ++rhsIndex)
        {
            const int index = lhsIndex + rhsIndex;
            fourthPolynomial[index] += firstPolynomial[lhsIndex] * secondPolynomial[rhsIndex];
        }
    }

    ASSERT_TRUE(Approximate(thirdPolynomial, fourthPolynomial));

    thirdPolynomial = firstPolynomial + 3.0;

    ASSERT_APPROXIMATE(firstPolynomial[0] + 3.0, thirdPolynomial[0], 1e-10);

    for (int i = 1; i <= firstPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(firstPolynomial[i], thirdPolynomial[i], 1e-10);
    }

    thirdPolynomial = 7.0 + firstPolynomial;

    ASSERT_APPROXIMATE(firstPolynomial[0] + 7.0, thirdPolynomial[0], 1e-10);

    for (int i = 1; i <= firstPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(firstPolynomial[i], thirdPolynomial[i], 1e-10);
    }

    thirdPolynomial = firstPolynomial - 3.0;

    ASSERT_APPROXIMATE(firstPolynomial[0] - 3.0, thirdPolynomial[0], 1e-10);

    for (int i = 1; i <= firstPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(firstPolynomial[i], thirdPolynomial[i], 1e-10);
    }

    thirdPolynomial = firstPolynomial * 2.0;

    for (int i = 0; i <= thirdPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], firstPolynomial[i] * 2.0, 1e-10);
    }

    thirdPolynomial = 7.0 * firstPolynomial * 2.0;

    for (int i = 0; i <= thirdPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], firstPolynomial[i] * 14.0, 1e-10);
    }

    thirdPolynomial = firstPolynomial / 2.0;

    for (int i = 0; i <= thirdPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], firstPolynomial[i] / 2.0, 1e-10);
    }
}

void Mathematics::PolynomialTesting::CalculateTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                      randomDistribution(generator), randomDistribution(generator) };

    PolynomialD firstPolynomial(firstDoubleVector);

    const double value = randomDistribution(generator);

    const double result = firstDoubleVector.at(0) + firstDoubleVector.at(1) * value +
                          firstDoubleVector.at(2) * value * value +
                          firstDoubleVector.at(3) * value * value * value +
                          firstDoubleVector.at(4) * value * value * value * value;

    ASSERT_APPROXIMATE(result, firstPolynomial(value), 1e-10);

    PolynomialD secondPolynomial(firstPolynomial.GetDegree() - 1);

    for (int index = 0; index <= secondPolynomial.GetDegree(); ++index)
    {
        auto temp = index + 1;
        secondPolynomial[index] = temp * firstPolynomial[temp];
    }

    PolynomialD thirdPolynomial = firstPolynomial.GetDerivative();

    ASSERT_TRUE(Approximate(thirdPolynomial, secondPolynomial));

    PolynomialD fourthPolynomial(firstPolynomial.GetDegree());
    for (int i = 0; i <= fourthPolynomial.GetDegree(); ++i)
    {
        fourthPolynomial[i] = firstPolynomial[fourthPolynomial.GetDegree() - i];
    }

    PolynomialD fifthPolynomial = firstPolynomial.GetInversion();

    ASSERT_TRUE(Approximate(fourthPolynomial, fifthPolynomial));

    PolynomialD sixthPolynomial(firstPolynomial);
    for (int i = 0; i <= sixthPolynomial.GetDegree(); ++i)
    {
        sixthPolynomial[i] /= sixthPolynomial[sixthPolynomial.GetDegree()];
    }

    PolynomialD seventhPolynomial(firstPolynomial);
    seventhPolynomial.Compress(0.0001);

    for (int i = 0; i <= seventhPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(seventhPolynomial[i], sixthPolynomial[i], 1e-10);
    }

    vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    PolynomialD eighthPolynomial(secondDoubleVector);

    PolynomialD::PolynomialDivide polynomialDivide = firstPolynomial.Divide(eighthPolynomial, 1e-10);

    PolynomialD ninthPolynomial = polynomialDivide.GetQuotient() * eighthPolynomial + polynomialDivide.GetRemainder();

    ASSERT_TRUE(Approximate(ninthPolynomial, firstPolynomial, 1e-10));
}

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 09:33)

#include "PolynomialTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/PolynomialDetail.h"

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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialTesting)

void Mathematics::PolynomialTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::PolynomialTesting ::ConstructionTest()
{
    FloatPolynomial firstPolynomial;

    ASSERT_EQUAL(firstPolynomial.GetDegree(), 0);

    FloatPolynomial secondPolynomial(2);

    ASSERT_EQUAL(secondPolynomial.GetDegree(), 2);

    vector<double> doubleVector{ 3.0, 5.0, 2.0, 1.0, 0.0, 2.0 };
    int degree = boost::numeric_cast<int>(doubleVector.size() - 1);

    DoublePolynomial thirdPolynomial(doubleVector);

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), degree);
    for (int i = 0; i <= degree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], doubleVector[i], 1e-10);
    }

    DoublePolynomial fourthPolynomial(thirdPolynomial);

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

    // 	DoublePolynomial fifthPolynomial(boost::numeric_cast<int>(doubleVector.size()),&doubleVector[0]);
    //
    // 	ASSERT_EQUAL(fifthPolynomial.GetDegree(),degree);
    // 	for(int i = 0;i <= degree;++i)
    // 	{
    // 		ASSERT_APPROXIMATE(fifthPolynomial[i],doubleVector[i],1e-10);
    // 	}
}

void Mathematics::PolynomialTesting ::AccessTest()
{
    default_random_engine generator{};
    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> doubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                 randomDistribution(generator), randomDistribution(generator) };

    int degree = boost::numeric_cast<int>(doubleVector.size() - 1);

    const DoublePolynomial firstPolynomial(doubleVector);
    DoublePolynomial secondPolynomial(doubleVector);

    ASSERT_EQUAL(firstPolynomial.GetDegree(), degree);
    ASSERT_EQUAL(secondPolynomial.GetDegree(), degree);

    // 	const double* firstPtr = firstPolynomial.GetElements();
    // 	double* secondPtr = secondPolynomial.GetElements();
    //
    // 	for(int i = 0;i <= degree;++i)
    // 	{
    // 		ASSERT_APPROXIMATE(firstPolynomial[i],doubleVector[i],1e-10);
    // 		ASSERT_APPROXIMATE(secondPolynomial[i],doubleVector[i],1e-10);
    // 		ASSERT_APPROXIMATE(firstPtr[i],doubleVector[i],1e-10);
    // 		ASSERT_APPROXIMATE(secondPtr[i],doubleVector[i],1e-10);
    // 	}
}

void Mathematics::PolynomialTesting ::UpdateOperatorTest()
{
    default_random_engine generator{};
    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                      randomDistribution(generator), randomDistribution(generator) };

    DoublePolynomial firstPolynomial(firstDoubleVector);

    DoublePolynomial secondPolynomial = -firstPolynomial;
    int firstDegree = boost::numeric_cast<int>(firstDoubleVector.size() - 1);

    ASSERT_EQUAL(secondPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i <= firstDegree; ++i)
    {
        ASSERT_APPROXIMATE(secondPolynomial[i], -firstDoubleVector[i], 1e-10);
    }

    vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    DoublePolynomial thirdPolynomial(secondDoubleVector);
    int secondDegree = boost::numeric_cast<int>(secondDoubleVector.size() - 1);
    ASSERT_EQUAL(thirdPolynomial.GetDegree(), secondDegree);

    thirdPolynomial += secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i <= secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], -firstDoubleVector[i] + secondDoubleVector[i], 1e-10);
    }

    ASSERT_APPROXIMATE(thirdPolynomial[firstDegree], -firstDoubleVector[firstDegree], 1e-10);

    DoublePolynomial fourthPolynomial(secondDoubleVector);
    ASSERT_EQUAL(fourthPolynomial.GetDegree(), secondDegree);

    fourthPolynomial -= firstPolynomial;

    ASSERT_EQUAL(fourthPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i <= secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(fourthPolynomial[i], -firstDoubleVector[i] + secondDoubleVector[i], 1e-10);
    }

    ASSERT_APPROXIMATE(fourthPolynomial[firstDegree], -firstDoubleVector[firstDegree], 1e-10);

    DoublePolynomial fifthPolynomial(secondDoubleVector);
    DoublePolynomial sixthPolynomial(firstDoubleVector);

    firstPolynomial *= fifthPolynomial;

    ASSERT_EQUAL(firstPolynomial.GetDegree(), firstDegree + secondDegree);

    DoublePolynomial seventhPolynomial(firstDegree + secondDegree);

    [[maybe_unused]] auto degree = seventhPolynomial.GetDegree() + 1;
    //	memset(seventhPolynomial.GetElements(), 0, degree * sizeof(double));

    for (int lhsIndex = 0; lhsIndex <= firstDegree; ++lhsIndex)
    {
        for (int rhsIndex = 0; rhsIndex <= secondDegree; ++rhsIndex)
        {
            int index = lhsIndex + rhsIndex;
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

void Mathematics::PolynomialTesting ::OperationTest()
{
    default_random_engine generator{};
    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                      randomDistribution(generator), randomDistribution(generator) };

    DoublePolynomial firstPolynomial(firstDoubleVector);

    int firstDegree = boost::numeric_cast<int>(firstDoubleVector.size() - 1);

    vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    DoublePolynomial secondPolynomial(secondDoubleVector);
    int secondDegree = boost::numeric_cast<int>(secondDoubleVector.size() - 1);

    DoublePolynomial thirdPolynomial = firstPolynomial + secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i < secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], firstDoubleVector[i] + secondDoubleVector[i], 1e-10);
    }

    ASSERT_APPROXIMATE(thirdPolynomial[firstDegree], firstDoubleVector[firstDegree], 1e-10);

    thirdPolynomial = firstPolynomial - secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree);
    for (int i = 0; i < secondDegree; ++i)
    {
        ASSERT_APPROXIMATE(thirdPolynomial[i], firstDoubleVector[i] - secondDoubleVector[i], 1e-10);
    }

    ASSERT_APPROXIMATE(thirdPolynomial[firstDegree], firstDoubleVector[firstDegree], 1e-10);

    thirdPolynomial = firstPolynomial * secondPolynomial;

    ASSERT_EQUAL(thirdPolynomial.GetDegree(), firstDegree + secondDegree);

    DoublePolynomial fourthPolynomial(firstDegree + secondDegree);

    [[maybe_unused]] auto degree = fourthPolynomial.GetDegree() + 1;
    //	memset(fourthPolynomial.GetElements(), 0, degree * sizeof(double));

    for (int lhsIndex = 0; lhsIndex <= firstDegree; ++lhsIndex)
    {
        for (int rhsIndex = 0; rhsIndex <= secondDegree; ++rhsIndex)
        {
            int index = lhsIndex + rhsIndex;
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

void Mathematics::PolynomialTesting ::CalculateTest()
{
    default_random_engine generator{};
    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                                      randomDistribution(generator), randomDistribution(generator) };

    DoublePolynomial firstPolynomial(firstDoubleVector);

    double value = randomDistribution(generator);

    double result = firstDoubleVector[0] + firstDoubleVector[1] * value +
                    firstDoubleVector[2] * value * value +
                    firstDoubleVector[3] * value * value * value +
                    firstDoubleVector[4] * value * value * value * value;

    ASSERT_APPROXIMATE(result, firstPolynomial(value), 1e-10);

    DoublePolynomial secondPolynomial(firstPolynomial.GetDegree() - 1);

    for (int index = 0; index <= secondPolynomial.GetDegree(); ++index)
    {
        auto temp = index + 1;
        secondPolynomial[index] = temp * firstPolynomial[temp];
    }

    DoublePolynomial thirdPolynomial = firstPolynomial.GetDerivative();

    ASSERT_TRUE(Approximate(thirdPolynomial, secondPolynomial));

    DoublePolynomial fourthPolynomial(firstPolynomial.GetDegree());
    for (int i = 0; i <= fourthPolynomial.GetDegree(); ++i)
    {
        fourthPolynomial[i] = firstPolynomial[fourthPolynomial.GetDegree() - i];
    }

    DoublePolynomial fifthPolynomial = firstPolynomial.GetInversion();

    ASSERT_TRUE(Approximate(fourthPolynomial, fifthPolynomial));

    DoublePolynomial sixthPolynomial(firstPolynomial);
    for (int i = 0; i <= sixthPolynomial.GetDegree(); ++i)
    {
        sixthPolynomial[i] /= sixthPolynomial[sixthPolynomial.GetDegree()];
    }

    DoublePolynomial seventhPolynomial(firstPolynomial);
    seventhPolynomial.Compress(0.0001);

    for (int i = 0; i <= seventhPolynomial.GetDegree(); ++i)
    {
        ASSERT_APPROXIMATE(seventhPolynomial[i], sixthPolynomial[i], 1e-10);
    }

    vector<double> secondDoubleVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

    DoublePolynomial eighthPolynomial(secondDoubleVector);

    DoublePolynomial::PolynomialDivide polynomialDivide = firstPolynomial.Divide(eighthPolynomial, 1e-10);

    DoublePolynomial ninthPolynomial = polynomialDivide.GetQuotient() * eighthPolynomial +
                                       polynomialDivide.GetRemainder();

    ASSERT_TRUE(Approximate(ninthPolynomial, firstPolynomial, 1e-10));
}

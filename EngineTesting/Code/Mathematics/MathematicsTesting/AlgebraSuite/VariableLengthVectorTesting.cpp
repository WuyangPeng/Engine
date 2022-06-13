///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:45)

#include "VariableLengthVectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"

#include <boost/numeric/conversion/cast.hpp>
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class VariableLengthVector<float>;
    template class VariableLengthVector<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, VariableLengthVectorTesting)

void Mathematics::VariableLengthVectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::VariableLengthVectorTesting::ConstructionTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    VariableLengthVectorF firstVector(5);

    ASSERT_EQUAL(firstVector.GetSize(), 5);

    vector<double> doubleVector;
    for (int i = 0; i < 15; ++i)
    {
        doubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD secondVector(doubleVector);
    ASSERT_EQUAL(secondVector.GetSize(), boost::numeric_cast<int>(doubleVector.size()));

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(secondVector[i], doubleVector.at(i), 1e-10);
    }

    VariableLengthVectorD thirdVector(secondVector);
    ASSERT_EQUAL(secondVector.GetSize(), thirdVector.GetSize());

    ASSERT_TRUE(Approximate(secondVector, thirdVector, 1e-10));

    ASSERT_EQUAL(secondVector.GetSize(), boost::numeric_cast<int>(doubleVector.size()));

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(secondVector[i], doubleVector.at(i), 1e-10);
    }

    VariableLengthVectorD fourthVector;
    thirdVector = fourthVector;

    ASSERT_EQUAL(thirdVector.GetSize(), 0);

    fourthVector.ResetSize(10);

    ASSERT_EQUAL(fourthVector.GetSize(), 10);
    ASSERT_EQUAL(thirdVector.GetSize(), 0);
}

void Mathematics::VariableLengthVectorTesting::AccessTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> doubleVector;
    for (int i = 0; i < 15; ++i)
    {
        doubleVector.push_back(randomDistribution(generator));
    }

    const VariableLengthVectorD firstVector(doubleVector);
    VariableLengthVectorD secondVector(doubleVector);

    ASSERT_EQUAL(firstVector.GetSize(), 15);
    ASSERT_EQUAL(secondVector.GetSize(), 15);
}

void Mathematics::VariableLengthVectorTesting::ArithmeticCalculateTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD firstVector(firstDoubleVector);
    VariableLengthVectorD secondVector(secondDoubleVector);

    VariableLengthVectorD thirdVector = -firstVector;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(thirdVector[i], -firstDoubleVector.at(i), 1e-10);
    }

    firstVector += secondVector;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(firstVector[i], firstDoubleVector.at(i) + secondDoubleVector.at(i), 1e-10);
    }

    secondVector -= firstVector;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(secondVector[i], -firstDoubleVector.at(i), 1e-10);
    }

    thirdVector *= 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(thirdVector[i], -firstDoubleVector.at(i) * 2.0, 1e-10);
    }

    secondVector /= 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(secondVector[i], -firstDoubleVector.at(i) / 2.0, 1e-10);
    }

    thirdVector = firstVector + secondVector;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(thirdVector[i], firstDoubleVector.at(i) / 2.0 + secondDoubleVector.at(i), 1e-10);
    }

    thirdVector = firstVector - secondVector;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(thirdVector[i], firstDoubleVector.at(i) * 1.5 + secondDoubleVector.at(i), 1e-10);
    }

    thirdVector = firstVector * 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(thirdVector[i], firstDoubleVector.at(i) * 2.0 + secondDoubleVector.at(i) * 2.0, 1e-10);
    }

    thirdVector = 2.0 * firstVector;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(thirdVector[i], firstDoubleVector.at(i) * 2.0 + secondDoubleVector.at(i) * 2.0, 1e-10);
    }

    thirdVector = firstVector / 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(thirdVector[i], firstDoubleVector.at(i) / 2.0 + secondDoubleVector.at(i) / 2.0, 1e-10);
    }
}

void Mathematics::VariableLengthVectorTesting::VectorCalculateTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD firstVector(firstDoubleVector);

    double squaredLength = 0.0f;
    for (int i = 0; i < 15; ++i)
    {
        squaredLength += firstVector[i] * firstVector[i];
    }

    ASSERT_APPROXIMATE(squaredLength, firstVector.SquaredLength(), 1e-10);
    ASSERT_APPROXIMATE(MathD::Sqrt(squaredLength), firstVector.Length(), 1e-10);
    firstVector.Normalize();

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(firstVector[i], firstDoubleVector.at(i) / MathD::Sqrt(squaredLength), 1e-10);
    }

    vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD secondVector(secondDoubleVector);

    double dotProduct = 0.0;
    for (int i = 0; i < 15; ++i)
    {
        dotProduct += firstVector[i] * secondVector[i];
    }

    ASSERT_APPROXIMATE(dotProduct, Dot(firstVector, secondVector), 1e-10);
}

void Mathematics::VariableLengthVectorTesting::CompareTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD firstVector(firstDoubleVector);
    VariableLengthVectorD secondVector(secondDoubleVector);

    firstVector[0] = 0.0;
    secondVector[0] = 1.0;

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_TRUE(firstVector != secondVector);
    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);

    ASSERT_TRUE(Approximate(firstVector, firstVector, 1e-10));
    ASSERT_TRUE(Approximate(secondVector, secondVector, 1e-10));
    ASSERT_FALSE(Approximate(firstVector, secondVector, 1e-10));
}

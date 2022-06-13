///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 18:08)

#include "RationalVectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, RationalVectorTesting)

void Mathematics::RationalVectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::RationalVectorTesting::ConstructionTest()
{
    default_random_engine generator{};
    const uniform_int<int> firstRandomDistribution(INT32_MIN, INT32_MAX);

    RationalVector<3, 7> firstVector;

    for (auto i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(firstVector[i], SignRational<7>(0));
    }

    for (auto i = 0; i < 3; ++i)
    {
        firstVector[i] = SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator));
    }

    RationalVector<3, 7> secondVector(firstVector);

    for (auto i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(firstVector[i], secondVector[i]);
    }

    RationalVector<3, 7> thirdVector;

    for (auto i = 0; i < 3; ++i)
    {
        thirdVector[i] = SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator));
    }

    firstVector = thirdVector;

    for (auto i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(firstVector[i], thirdVector[i]);
    }
}

void Mathematics::RationalVectorTesting::CalculateTest()
{
    default_random_engine generator{};
    const uniform_int<int> firstRandomDistribution(INT16_MIN, INT16_MAX);

    RationalVector<4, 15> firstVector;
    RationalVector<4, 15> secondVector;

    for (auto i = 0; i < 4; ++i)
    {
        firstVector[i] = SignRational<15>(firstRandomDistribution(generator), firstRandomDistribution(generator));
        secondVector[i] = SignRational<15>(firstRandomDistribution(generator), firstRandomDistribution(generator));
    }

    SignRational<15> squaredLength(0);
    for (auto i = 0; i < 4; ++i)
    {
        squaredLength += firstVector[i] * firstVector[i];
    }

    ASSERT_EQUAL(squaredLength, firstVector.SquaredLength());

    SignRational<15> dot(0);
    for (auto i = 0; i < 4; ++i)
    {
        dot += firstVector[i] * secondVector[i];
    }

    ASSERT_EQUAL(dot, Dot(firstVector, secondVector));
}

void Mathematics::RationalVectorTesting::OperatorTest()
{
    default_random_engine generator{};
    const uniform_int<int> firstRandomDistribution(INT16_MIN, INT16_MAX);

    RationalVector<4, 12> firstVector;
    RationalVector<4, 12> secondVector;

    for (auto i = 0; i < 4; ++i)
    {
        firstVector[i] = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));
        secondVector[i] = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));
    }

    RationalVector<4, 12> thirdVector = firstVector + secondVector;
    RationalVector<4, 12> fourthVector;

    for (auto i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] + secondVector[i];
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    thirdVector = firstVector - secondVector;

    for (auto i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] - secondVector[i];
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    SignRational<12> firstValue(firstRandomDistribution(generator), firstRandomDistribution(generator));

    thirdVector = firstVector * firstValue;

    for (auto i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] * firstValue;
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));

    thirdVector = firstValue * firstVector;

    for (auto i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] * firstValue;
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));

    thirdVector = firstVector / firstValue;

    for (auto i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] / firstValue;
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    fourthVector = -firstVector;

    for (auto i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(-fourthVector[i], firstVector[i]);
    }
}

void Mathematics::RationalVectorTesting::CompareTest()
{
    default_random_engine generator{};
    const uniform_int<int> firstRandomDistribution(INT16_MIN, INT16_MAX);

    RationalVector<2, 3> firstVector;
    RationalVector<2, 3> secondVector;

    for (auto i = 0; i < 2; ++i)
    {
        firstVector[i] = SignRational<3>(firstRandomDistribution(generator), firstRandomDistribution(generator));
        secondVector[i] = SignRational<3>(firstRandomDistribution(generator), firstRandomDistribution(generator));
    }

    firstVector[0] = SignRational<3>(0);
    secondVector[0] = SignRational<3>(1);

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_FALSE(secondVector != secondVector);
    ASSERT_TRUE(firstVector != secondVector);

    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);
}
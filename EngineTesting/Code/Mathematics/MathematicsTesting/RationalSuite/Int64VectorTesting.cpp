// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 13:31)

#include "Int64VectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Rational/Int64VectorDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Int64VectorTesting)

void Mathematics::Int64VectorTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::Int64VectorTesting ::ConstructionTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector<4> firstVector;

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(firstVector[i], 0);
    }

    for (int i = 0; i < 4; ++i)
    {
        firstVector[i] = firstRandomDistribution(generator);
    }

    Int64Vector<4> secondVector(firstVector);

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(firstVector[i], secondVector[i]);
    }

    Int64Vector<4> thirdVector;

    for (int i = 0; i < 4; ++i)
    {
        thirdVector[i] = firstRandomDistribution(generator);
    }

    firstVector = thirdVector;

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(firstVector[i], thirdVector[i]);
    }
}

void Mathematics::Int64VectorTesting ::CalculateTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector<4> firstVector;
    Int64Vector<4> secondVector;

    for (int i = 0; i < 4; ++i)
    {
        firstVector[i] = firstRandomDistribution(generator);
        secondVector[i] = firstRandomDistribution(generator);
    }

    int64_t squaredLength = 0;
    for (int i = 0; i < 4; ++i)
    {
        squaredLength += firstVector[i] * firstVector[i];
    }

    ASSERT_EQUAL(squaredLength, firstVector.SquaredLength());

    int64_t dot = 0;
    for (int i = 0; i < 4; ++i)
    {
        dot += firstVector[i] * secondVector[i];
    }

    ASSERT_EQUAL(dot, Dot(firstVector, secondVector));
}

void Mathematics::Int64VectorTesting ::OperatorTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector<4> firstVector;
    Int64Vector<4> secondVector;

    for (int i = 0; i < 4; ++i)
    {
        firstVector[i] = firstRandomDistribution(generator);
        secondVector[i] = firstRandomDistribution(generator);
    }

    Int64Vector<4> thirdVector = firstVector + secondVector;
    Int64Vector<4> fourthVector;

    for (int i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] + secondVector[i];
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    thirdVector = firstVector - secondVector;

    for (int i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] - secondVector[i];
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    int64_t firstValue = firstRandomDistribution(generator);

    thirdVector = firstVector * firstValue;

    for (int i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] * firstValue;
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = firstRandomDistribution(generator);

    thirdVector = firstValue * firstVector;

    for (int i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] * firstValue;
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = firstRandomDistribution(generator);

    thirdVector = firstVector / firstValue;

    for (int i = 0; i < 4; ++i)
    {
        fourthVector[i] = firstVector[i] / firstValue;
    }

    ASSERT_EQUAL(thirdVector, fourthVector);

    fourthVector = -firstVector;

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(-fourthVector[i], firstVector[i]);
    }
}

void Mathematics::Int64VectorTesting ::CompareTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector<4> firstVector;
    Int64Vector<4> secondVector;

    for (int i = 0; i < 4; ++i)
    {
        firstVector[i] = firstRandomDistribution(generator);
        secondVector[i] = firstRandomDistribution(generator);
    }

    firstVector[0] = 0;
    secondVector[0] = 1;

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_FALSE(secondVector != secondVector);
    ASSERT_TRUE(firstVector != secondVector);

    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);
}
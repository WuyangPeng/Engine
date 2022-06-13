///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 13:18)

#include "Int64Vector2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Rational/Int64Vector2.h"
#include "Mathematics/Rational/Int64VectorDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Int64Vector2Testing)

void Mathematics::Int64Vector2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::Int64Vector2Testing::ConstructionTest()
{
    default_random_engine generator{};
    const uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector2 firstVector = Int64Vector2::CreateDefault();

    ASSERT_EQUAL(firstVector.GetX(), 0);
    ASSERT_EQUAL(firstVector.GetY(), 0);

    firstVector.SetX(firstRandomDistribution(generator));
    firstVector.SetY(firstRandomDistribution(generator));

    Int64Vector2 secondVector(firstVector);

    ASSERT_EQUAL(firstVector.GetX(), secondVector.GetX());
    ASSERT_EQUAL(firstVector.GetY(), secondVector.GetY());

    Int64Vector2 thirdVector = Int64Vector2::CreateDefault();

    thirdVector.SetX(firstRandomDistribution(generator));
    thirdVector.SetY(firstRandomDistribution(generator));

    firstVector = thirdVector;

    ASSERT_EQUAL(firstVector.GetX(), thirdVector.GetX());
    ASSERT_EQUAL(firstVector.GetY(), thirdVector.GetY());

    Int64Vector<2> fourthVector;

    fourthVector[0] = firstRandomDistribution(generator);
    fourthVector[1] = firstRandomDistribution(generator);

    Int64Vector2 fifthVector(fourthVector);

    ASSERT_EQUAL(fifthVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(fifthVector.GetY(), fourthVector[1]);

    thirdVector = fourthVector;

    ASSERT_EQUAL(thirdVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(thirdVector.GetY(), fourthVector[1]);

    Int64Vector2 sixthVector(fourthVector[0], fourthVector[1]);

    ASSERT_EQUAL(sixthVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(sixthVector.GetY(), fourthVector[1]);

    sixthVector.SetX(fourthVector[1]);
    sixthVector.SetY(fourthVector[0]);

    ASSERT_EQUAL(sixthVector.GetX(), fourthVector[1]);
    ASSERT_EQUAL(sixthVector.GetY(), fourthVector[0]);
}

void Mathematics::Int64Vector2Testing::CalculateTest()
{
    default_random_engine generator{};
    const uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector2 firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator));
    Int64Vector2 secondVector(firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

    const auto squaredLength = firstVector.GetX() * firstVector.GetX() + firstVector.GetY() * firstVector.GetY();

    ASSERT_EQUAL(squaredLength, firstVector.SquaredLength());

    const auto dot = firstVector.GetX() * secondVector.GetX() + firstVector.GetY() * secondVector.GetY();

    ASSERT_EQUAL(dot, firstVector.Dot(secondVector));

    Int64Vector2 thirdVector = firstVector.Perp();

    ASSERT_EQUAL(thirdVector.GetX(), firstVector.GetY());
    ASSERT_EQUAL(thirdVector.GetY(), -firstVector.GetX());

    const auto dotPerp = firstVector.GetX() * secondVector.GetY() - firstVector.GetY() * secondVector.GetX();

    ASSERT_EQUAL(dotPerp, firstVector.DotPerp(secondVector));
}

void Mathematics::Int64Vector2Testing::OperatorTest()
{
    default_random_engine generator{};
    const uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector2 firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator));
    Int64Vector2 secondVector(firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

    Int64Vector2 thirdVector = firstVector + secondVector;
    Int64Vector2 fourthVector(firstVector.GetX() + secondVector.GetX(), firstVector.GetY() + secondVector.GetY());

    ASSERT_EQUAL(thirdVector, fourthVector);

    thirdVector = firstVector - secondVector;

    fourthVector.SetX(firstVector.GetX() - secondVector.GetX());
    fourthVector.SetY(firstVector.GetY() - secondVector.GetY());

    ASSERT_EQUAL(thirdVector, fourthVector);

    int64_t firstValue = firstRandomDistribution(generator);

    thirdVector = firstVector * firstValue;

    fourthVector.SetX(firstVector.GetX() * firstValue);
    fourthVector.SetY(firstVector.GetY() * firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = firstRandomDistribution(generator);

    thirdVector = firstValue * firstVector;

    fourthVector.SetX(firstVector.GetX() * firstValue);
    fourthVector.SetY(firstVector.GetY() * firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = firstRandomDistribution(generator);

    thirdVector = firstVector / firstValue;

    fourthVector.SetX(firstVector.GetX() / firstValue);
    fourthVector.SetY(firstVector.GetY() / firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    fourthVector = -firstVector;

    ASSERT_EQUAL(-fourthVector.GetX(), firstVector.GetX());
    ASSERT_EQUAL(-fourthVector.GetY(), firstVector.GetY());
}

void Mathematics::Int64Vector2Testing::CompareTest()
{
    const default_random_engine generator{};
    const uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector2 firstVector(0, 5);
    Int64Vector2 secondVector(1, 3);

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_FALSE(secondVector != secondVector);
    ASSERT_TRUE(firstVector != secondVector);

    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);
}
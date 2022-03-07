// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 13:30)

#include "Int64Vector3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Rational/Int64Vector3.h"
#include "Mathematics/Rational/Int64VectorDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Int64Vector3Testing)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Int64Vector3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::Int64Vector3Testing ::ConstructionTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector3 firstVector = Int64Vector3::CreateDefault();

    ASSERT_EQUAL(firstVector.GetX(), 0);
    ASSERT_EQUAL(firstVector.GetY(), 0);
    ASSERT_EQUAL(firstVector.GetZ(), 0);

    firstVector.SetX(firstRandomDistribution(generator));
    firstVector.SetY(firstRandomDistribution(generator));
    firstVector.SetZ(firstRandomDistribution(generator));

    Int64Vector3 secondVector(firstVector);

    ASSERT_EQUAL(firstVector.GetX(), secondVector.GetX());
    ASSERT_EQUAL(firstVector.GetY(), secondVector.GetY());
    ASSERT_EQUAL(firstVector.GetZ(), secondVector.GetZ());

    Int64Vector3 thirdVector = Int64Vector3::CreateDefault();

    thirdVector.SetX(firstRandomDistribution(generator));
    thirdVector.SetY(firstRandomDistribution(generator));
    thirdVector.SetZ(firstRandomDistribution(generator));

    firstVector = thirdVector;

    ASSERT_EQUAL(firstVector.GetX(), thirdVector.GetX());
    ASSERT_EQUAL(firstVector.GetY(), thirdVector.GetY());
    ASSERT_EQUAL(firstVector.GetZ(), thirdVector.GetZ());

    Int64Vector<3> fourthVector;

    fourthVector[0] = firstRandomDistribution(generator);
    fourthVector[1] = firstRandomDistribution(generator);
    fourthVector[2] = firstRandomDistribution(generator);

    Int64Vector3 fifthVector(fourthVector);

    ASSERT_EQUAL(fifthVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(fifthVector.GetY(), fourthVector[1]);
    ASSERT_EQUAL(fifthVector.GetZ(), fourthVector[2]);

    thirdVector = fourthVector;

    ASSERT_EQUAL(thirdVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(thirdVector.GetY(), fourthVector[1]);
    ASSERT_EQUAL(thirdVector.GetZ(), fourthVector[2]);

    Int64Vector3 sixthVector(fourthVector[0], fourthVector[1], fourthVector[2]);

    ASSERT_EQUAL(sixthVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(sixthVector.GetY(), fourthVector[1]);
    ASSERT_EQUAL(sixthVector.GetZ(), fourthVector[2]);

    sixthVector.SetX(fourthVector[1]);
    sixthVector.SetY(fourthVector[2]);
    sixthVector.SetZ(fourthVector[0]);

    ASSERT_EQUAL(sixthVector.GetX(), fourthVector[1]);
    ASSERT_EQUAL(sixthVector.GetY(), fourthVector[2]);
    ASSERT_EQUAL(sixthVector.GetZ(), fourthVector[0]);
}

void Mathematics::Int64Vector3Testing ::CalculateTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector3 firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));
    Int64Vector3 secondVector(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

    int64_t squaredLength = firstVector.GetX() * firstVector.GetX() +
                            firstVector.GetY() * firstVector.GetY() +
                            firstVector.GetZ() * firstVector.GetZ();

    ASSERT_EQUAL(squaredLength, firstVector.SquaredLength());

    int64_t dot = firstVector.GetX() * secondVector.GetX() +
                  firstVector.GetY() * secondVector.GetY() +
                  firstVector.GetZ() * secondVector.GetZ();

    ASSERT_EQUAL(dot, firstVector.Dot(secondVector));

    Int64Vector3 thirdVector = firstVector.Cross(secondVector);

    Int64Vector3 fourthVector(firstVector.GetY() * secondVector.GetZ() -
                                  firstVector.GetZ() * secondVector.GetY(),
                              firstVector.GetZ() * secondVector.GetX() -
                                  firstVector.GetX() * secondVector.GetZ(),
                              firstVector.GetX() * secondVector.GetY() -
                                  firstVector.GetY() * secondVector.GetX());

    ASSERT_EQUAL(thirdVector, fourthVector);

    int64_t tripleScalar = firstVector.Dot(secondVector.Cross(thirdVector));

    ASSERT_EQUAL(tripleScalar, firstVector.TripleScalar(secondVector, thirdVector));
}

void Mathematics::Int64Vector3Testing ::OperatorTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector3 firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));
    Int64Vector3 secondVector(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

    Int64Vector3 thirdVector = firstVector + secondVector;
    Int64Vector3 fourthVector(firstVector.GetX() + secondVector.GetX(),
                              firstVector.GetY() + secondVector.GetY(),
                              firstVector.GetZ() + secondVector.GetZ());

    ASSERT_EQUAL(thirdVector, fourthVector);

    thirdVector = firstVector - secondVector;

    fourthVector.SetX(firstVector.GetX() - secondVector.GetX());
    fourthVector.SetY(firstVector.GetY() - secondVector.GetY());
    fourthVector.SetZ(firstVector.GetZ() - secondVector.GetZ());

    ASSERT_EQUAL(thirdVector, fourthVector);

    int64_t firstValue = firstRandomDistribution(generator);

    thirdVector = firstVector * firstValue;

    fourthVector.SetX(firstVector.GetX() * firstValue);
    fourthVector.SetY(firstVector.GetY() * firstValue);
    fourthVector.SetZ(firstVector.GetZ() * firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = firstRandomDistribution(generator);

    thirdVector = firstValue * firstVector;

    fourthVector.SetX(firstVector.GetX() * firstValue);
    fourthVector.SetY(firstVector.GetY() * firstValue);
    fourthVector.SetZ(firstVector.GetZ() * firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = firstRandomDistribution(generator);

    thirdVector = firstVector / firstValue;

    fourthVector.SetX(firstVector.GetX() / firstValue);
    fourthVector.SetY(firstVector.GetY() / firstValue);
    fourthVector.SetZ(firstVector.GetZ() / firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    fourthVector = -firstVector;

    ASSERT_EQUAL(-fourthVector.GetX(), firstVector.GetX());
    ASSERT_EQUAL(-fourthVector.GetY(), firstVector.GetY());
    ASSERT_EQUAL(-fourthVector.GetZ(), firstVector.GetZ());
}

void Mathematics::Int64Vector3Testing ::CompareTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution{ INT64_MIN, INT64_MAX };

    Int64Vector3 firstVector(0, 2, 5);
    Int64Vector3 secondVector(0, 3, 1);

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_FALSE(secondVector != secondVector);
    ASSERT_TRUE(firstVector != secondVector);

    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);
}
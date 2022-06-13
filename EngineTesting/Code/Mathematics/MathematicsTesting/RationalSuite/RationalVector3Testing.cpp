///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 18:06)

#include "RationalVector3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/RationalVector3Detail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;

namespace Mathematics
{
    template class RationalVector3<6>;
    template class RationalVector3<7>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, RationalVector3Testing)

void Mathematics::RationalVector3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::RationalVector3Testing::ConstructionTest()
{
    default_random_engine generator{};
    const uniform_int<int> firstRandomDistribution(INT32_MIN, INT32_MAX);

    RationalVector3<7> firstVector;

    ASSERT_EQUAL(firstVector.GetX(), SignRational<7>(0));
    ASSERT_EQUAL(firstVector.GetY(), SignRational<7>(0));
    ASSERT_EQUAL(firstVector.GetZ(), SignRational<7>(0));

    firstVector.SetX(SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator)));

    firstVector.SetY(SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator)));

    firstVector.SetZ(SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator)));

    const RationalVector3<7> secondVector(firstVector);

    ASSERT_EQUAL(firstVector.GetX(), secondVector.GetX());
    ASSERT_EQUAL(firstVector.GetY(), secondVector.GetY());
    ASSERT_EQUAL(firstVector.GetZ(), secondVector.GetZ());

    const SignRational<7> firstRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<7> secondRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<7> thirdRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const RationalVector3<7> thirdVector(firstRational, secondRational, thirdRational);

    ASSERT_EQUAL(firstRational, thirdVector.GetX());
    ASSERT_EQUAL(secondRational, thirdVector.GetY());
    ASSERT_EQUAL(thirdRational, thirdVector.GetZ());

    firstVector = thirdVector;

    ASSERT_EQUAL(firstVector.GetX(), thirdVector.GetX());
    ASSERT_EQUAL(firstVector.GetY(), thirdVector.GetY());
    ASSERT_EQUAL(firstVector.GetZ(), thirdVector.GetZ());

    RationalVector<3, 7> fourthVector;

    fourthVector[0] = SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator));

    fourthVector[1] = SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator));

    fourthVector[2] = SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator));

    firstVector = fourthVector;

    ASSERT_EQUAL(firstVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(firstVector.GetY(), fourthVector[1]);
    ASSERT_EQUAL(firstVector.GetZ(), fourthVector[2]);

    const RationalVector3<7> fifthVector(fourthVector);

    ASSERT_EQUAL(fifthVector.GetX(), fourthVector[0]);
    ASSERT_EQUAL(fifthVector.GetY(), fourthVector[1]);
    ASSERT_EQUAL(fifthVector.GetZ(), fourthVector[2]);
}

void Mathematics::RationalVector3Testing::CalculateTest()
{
    default_random_engine generator{};

    const uniform_int<int> firstRandomDistribution(INT16_MIN, INT16_MAX);

    const SignRational<15> firstRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<15> secondRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<15> thirdRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<15> fourthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<15> fifthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<15> sixthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const RationalVector3<15> firstVector(firstRational, secondRational, thirdRational);
    const RationalVector3<15> secondVector(fourthRational, fifthRational, sixthRational);

    const SignRational<15> squaredLength = firstRational * firstRational + secondRational * secondRational + thirdRational * thirdRational;

    ASSERT_EQUAL(squaredLength, firstVector.SquaredLength());

    const SignRational<15> dot = firstRational * fourthRational + secondRational * fifthRational + thirdRational * sixthRational;

    ASSERT_EQUAL(dot, Dot(firstVector, secondVector));

    const RationalVector3<15> thirdVector(secondRational * sixthRational - thirdRational * fifthRational,
                                          thirdRational * fourthRational - firstRational * sixthRational,
                                          firstRational * fifthRational - secondRational * fourthRational);

    ASSERT_EQUAL(thirdVector, Cross(firstVector, secondVector));

    const SignRational<15> seventhRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<15> eighthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<15> ninthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const RationalVector3<15> fourthVector(seventhRational, eighthRational, ninthRational);

    ASSERT_EQUAL(Dot(firstVector, Cross(secondVector, fourthVector)), TripleScalar(firstVector, secondVector, fourthVector));
}

void Mathematics::RationalVector3Testing::OperatorTest()
{
    default_random_engine generator{};
    const uniform_int<int> firstRandomDistribution(INT16_MIN, INT16_MAX);

    const SignRational<12> firstRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<12> secondRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<12> thirdRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<12> fourthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<12> fifthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<12> sixthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const RationalVector3<12> firstVector(firstRational, secondRational, thirdRational);
    const RationalVector3<12> secondVector(fourthRational, fifthRational, sixthRational);

    RationalVector3<12> thirdVector = firstVector + secondVector;
    RationalVector3<12> fourthVector(firstRational + fourthRational, secondRational + fifthRational, thirdRational + sixthRational);

    ASSERT_EQUAL(thirdVector, fourthVector);

    thirdVector = firstVector - secondVector;

    fourthVector.SetX(firstRational - fourthRational);
    fourthVector.SetY(secondRational - fifthRational);
    fourthVector.SetZ(thirdRational - sixthRational);

    ASSERT_EQUAL(thirdVector, fourthVector);

    SignRational<12> firstValue(firstRandomDistribution(generator), firstRandomDistribution(generator));

    thirdVector = firstVector * firstValue;

    fourthVector.SetX(firstRational * firstValue);
    fourthVector.SetY(secondRational * firstValue);
    fourthVector.SetZ(thirdRational * firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));

    thirdVector = firstValue * firstVector;

    fourthVector.SetX(firstRational * firstValue);
    fourthVector.SetY(secondRational * firstValue);
    fourthVector.SetZ(thirdRational * firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    firstValue = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));

    thirdVector = firstVector / firstValue;

    fourthVector.SetX(firstRational / firstValue);
    fourthVector.SetY(secondRational / firstValue);
    fourthVector.SetZ(thirdRational / firstValue);

    ASSERT_EQUAL(thirdVector, fourthVector);

    fourthVector = -firstVector;

    ASSERT_EQUAL(-fourthVector.GetX(), firstVector.GetX());
    ASSERT_EQUAL(-fourthVector.GetY(), firstVector.GetY());
    ASSERT_EQUAL(-fourthVector.GetZ(), firstVector.GetZ());
}

void Mathematics::RationalVector3Testing::CompareTest()
{
    default_random_engine generator{};
    const uniform_int<int> firstRandomDistribution(INT16_MIN, INT16_MAX);

    const SignRational<3> firstRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const SignRational<3> secondRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

    const RationalVector3<3> firstVector(SignRational<3>(0), firstRational, secondRational);
    const RationalVector3<3> secondVector(SignRational<3>(1), secondRational, firstRational);

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_FALSE(secondVector != secondVector);
    ASSERT_TRUE(firstVector != secondVector);

    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);
}
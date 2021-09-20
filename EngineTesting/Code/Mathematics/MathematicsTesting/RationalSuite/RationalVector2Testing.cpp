// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/26 17:06)

#include "RationalVector2Testing.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"
#include "Mathematics/Rational/RationalVector2Detail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class RationalVector2<5>;
	template class RationalVector2<8>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,RationalVector2Testing) 

void Mathematics::RationalVector2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::RationalVector2Testing
	::ConstructionTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT32_MIN,INT32_MAX);

	RationalVector2<7> firstVector;
	
	ASSERT_EQUAL(firstVector.GetX(), SignRational<7>(0));
	ASSERT_EQUAL(firstVector.GetY(), SignRational<7>(0));

	firstVector.SetX(SignRational<7>(firstRandomDistribution(generator),firstRandomDistribution(generator)));

	firstVector.SetY(SignRational<7>(firstRandomDistribution(generator),firstRandomDistribution(generator)));	

	RationalVector2<7> secondVector(firstVector);

	ASSERT_EQUAL(firstVector.GetX(), secondVector.GetX());
	ASSERT_EQUAL(firstVector.GetY(), secondVector.GetY());

	SignRational<7> firstRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	SignRational<7> secondRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

	RationalVector2<7> thirdVector(firstRational, secondRational);

	ASSERT_EQUAL(firstRational, thirdVector.GetX());
	ASSERT_EQUAL(secondRational, thirdVector.GetY());

	firstVector = thirdVector;

	ASSERT_EQUAL(firstVector.GetX(), thirdVector.GetX());
	ASSERT_EQUAL(firstVector.GetY(), thirdVector.GetY());

	RationalVector<2,7> fourthVector;

	fourthVector[0] = SignRational<7>(firstRandomDistribution(generator),firstRandomDistribution(generator));

	fourthVector[1] = SignRational<7>(firstRandomDistribution(generator), firstRandomDistribution(generator));

	firstVector = fourthVector;

	ASSERT_EQUAL(firstVector.GetX(), fourthVector[0]);
	ASSERT_EQUAL(firstVector.GetY(), fourthVector[1]);

	RationalVector2<7> fifthVector(fourthVector);

	ASSERT_EQUAL(fifthVector.GetX(), fourthVector[0]);
	ASSERT_EQUAL(fifthVector.GetY(), fourthVector[1]);
}

void Mathematics::RationalVector2Testing
	::CalculateTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT16_MIN,INT16_MAX);

	SignRational<15> firstRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	SignRational<15> secondRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	SignRational<15> thirdRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

	SignRational<15> fourthRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	RationalVector2<15> firstVector(firstRational,secondRational);
	RationalVector2<15> secondVector(thirdRational,fourthRational);

	SignRational<15> squaredLength = firstRational * firstRational + secondRational * secondRational;	

	ASSERT_EQUAL(squaredLength, firstVector.SquaredLength());

	SignRational<15> dot = firstRational * thirdRational + secondRational * fourthRational;	

	ASSERT_EQUAL(dot, Dot(firstVector, secondVector));

	RationalVector2<15> thirdVector(fourthRational,-thirdRational);

	ASSERT_EQUAL(thirdVector, secondVector.Perp());

	SignRational<15> fifthRational = firstRational * fourthRational - secondRational * thirdRational;

	ASSERT_EQUAL(fifthRational, DotPerp(firstVector, secondVector));
}

void Mathematics::RationalVector2Testing
	::OperatorTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT16_MIN,INT16_MAX);;

	SignRational<12> firstRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	SignRational<12> secondRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	SignRational<12> thirdRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	SignRational<12> fourthRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

	RationalVector2<12> firstVector(firstRational,secondRational);	
	RationalVector2<12> secondVector(thirdRational,fourthRational);	

	RationalVector2<12> thirdVector = firstVector + secondVector;
	RationalVector2<12> fourthVector(firstRational + thirdRational,secondRational + fourthRational);	

	ASSERT_EQUAL(thirdVector, fourthVector);

	thirdVector = firstVector - secondVector;

	fourthVector.SetX(firstRational - thirdRational);
	fourthVector.SetY(secondRational - fourthRational);

	ASSERT_EQUAL(thirdVector, fourthVector);

	SignRational<12> firstValue(firstRandomDistribution(generator), firstRandomDistribution(generator));

	thirdVector = firstVector * firstValue;

	fourthVector.SetX(firstRational * firstValue);
	fourthVector.SetY(secondRational * firstValue);	

	ASSERT_EQUAL(thirdVector, fourthVector);

	firstValue = SignRational<12>(firstRandomDistribution(generator),firstRandomDistribution(generator));

	thirdVector = firstValue * firstVector;

	fourthVector.SetX(firstRational * firstValue);
	fourthVector.SetY(secondRational * firstValue);	

	ASSERT_EQUAL(thirdVector, fourthVector);

	firstValue = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));

	thirdVector = firstVector / firstValue;

	fourthVector.SetX(firstRational / firstValue);
	fourthVector.SetY(secondRational / firstValue);	

	ASSERT_EQUAL(thirdVector, fourthVector);

	fourthVector = -firstVector;

	ASSERT_EQUAL(-fourthVector.GetX(), firstVector.GetX());
	ASSERT_EQUAL(-fourthVector.GetY(), firstVector.GetY());
}

void Mathematics::RationalVector2Testing
	::CompareTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT16_MIN,INT16_MAX);

	SignRational<3> firstRational(firstRandomDistribution(generator),firstRandomDistribution(generator));

	SignRational<3> secondRational(firstRandomDistribution(generator), firstRandomDistribution(generator));

	RationalVector2<3> firstVector(SignRational<3>(0), firstRational);
	RationalVector2<3> secondVector(SignRational<3>(1), secondRational);

	ASSERT_TRUE(firstVector == firstVector);
	ASSERT_FALSE(firstVector == secondVector);
	ASSERT_FALSE(secondVector != secondVector);
	ASSERT_TRUE(firstVector != secondVector);

	ASSERT_TRUE(firstVector < secondVector);
	ASSERT_TRUE(firstVector <= secondVector);
	ASSERT_FALSE(firstVector > secondVector);
	ASSERT_FALSE(firstVector >= secondVector);
}
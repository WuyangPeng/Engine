// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 09:01)

#include "RationalVectorTesting.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_int;
using std::default_random_engine;

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,RationalVectorTesting) 

void Mathematics::RationalVectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::RationalVectorTesting
	::ConstructionTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT32_MIN,INT32_MAX);

	RationalVector<3,7> firstVector;

	for(int i = 0;i < 3;++i)
	{
		ASSERT_EQUAL(firstVector[i], SignRational<7>(0));
	}

	for(int i = 0;i < 3;++i)
	{
		firstVector[i] = SignRational<7>(firstRandomDistribution(generator),firstRandomDistribution(generator));
	}

	RationalVector<3,7> secondVector(firstVector);

	for(int i = 0;i < 3;++i)
	{
		ASSERT_EQUAL(firstVector[i],secondVector[i]);
	}

	RationalVector<3,7> thirdVector;

	for(int i = 0;i < 3;++i)
	{
		thirdVector[i] = SignRational<7>(firstRandomDistribution(generator),firstRandomDistribution(generator));
	}

	firstVector = thirdVector;

	for(int i = 0;i < 3;++i)
	{
		ASSERT_EQUAL(firstVector[i],thirdVector[i]);
	}
}

void Mathematics::RationalVectorTesting
	::CalculateTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT16_MIN,INT16_MAX);

	RationalVector<4,15> firstVector;
	RationalVector<4,15> secondVector;

	for(int i = 0;i < 4;++i)
	{
		firstVector[i] = SignRational<15>(firstRandomDistribution(generator), firstRandomDistribution(generator));
		secondVector[i] = SignRational<15>(firstRandomDistribution(generator),firstRandomDistribution(generator)); 
	}

	SignRational<15> squaredLength(0);
	for (int i = 0; i < 4; ++i)
	{
		squaredLength += firstVector[i] * firstVector[i];
	}

	ASSERT_EQUAL(squaredLength,firstVector.SquaredLength());

	SignRational<15> dot(0);
	for (int i = 0; i < 4; ++i)
	{
		dot += firstVector[i] * secondVector[i];
	}

	ASSERT_EQUAL(dot,Dot(firstVector,secondVector));

}

void Mathematics::RationalVectorTesting
	::OperatorTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT16_MIN,INT16_MAX);;

	RationalVector<4,12> firstVector;	
	RationalVector<4,12> secondVector;

	for(int i = 0;i < 4;++i)
	{
		firstVector[i] = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));
		secondVector[i] = SignRational<12>(firstRandomDistribution(generator), firstRandomDistribution(generator));
	}

	RationalVector<4,12> thirdVector = firstVector + secondVector;
	RationalVector<4,12> fourthVector;

	for(int i = 0;i < 4;++i)
	{
		fourthVector[i] = firstVector[i] + secondVector[i];
	}

	ASSERT_EQUAL(thirdVector,fourthVector);

	thirdVector = firstVector - secondVector;

	for(int i = 0;i < 4;++i)
	{
		fourthVector[i] = firstVector[i] - secondVector[i];
	}

	ASSERT_EQUAL(thirdVector,fourthVector);

	SignRational<12> firstValue(firstRandomDistribution(generator),firstRandomDistribution(generator));

	thirdVector = firstVector * firstValue;

	for(int i = 0;i < 4;++i)
	{
		fourthVector[i] = firstVector[i] * firstValue;
	}

	ASSERT_EQUAL(thirdVector,fourthVector);

	firstValue = SignRational<12>(firstRandomDistribution(generator),firstRandomDistribution(generator));

	thirdVector = firstValue * firstVector;

	for(int i = 0;i < 4;++i)
	{
		fourthVector[i] = firstVector[i] * firstValue;
	}

	ASSERT_EQUAL(thirdVector,fourthVector);

	firstValue = SignRational<12>(firstRandomDistribution(generator),firstRandomDistribution(generator));

	thirdVector = firstVector / firstValue;

	for(int i = 0;i < 4;++i)
	{
		fourthVector[i] = firstVector[i] / firstValue;
	}

	ASSERT_EQUAL(thirdVector,fourthVector);

	fourthVector = -firstVector;

	for(int i = 0;i < 4;++i)
	{
		ASSERT_EQUAL(-fourthVector[i],firstVector[i]);
	}
}

void Mathematics::RationalVectorTesting
	::CompareTest()
{
	default_random_engine generator{};
	uniform_int<int> firstRandomDistribution(INT16_MIN,INT16_MAX);;

	RationalVector<2,3> firstVector;	
	RationalVector<2,3> secondVector;

	for(int i = 0;i < 2;++i)
	{
		firstVector[i] = SignRational<3>(firstRandomDistribution(generator),firstRandomDistribution(generator));
		secondVector[i] = SignRational<3>(firstRandomDistribution(generator),firstRandomDistribution(generator));
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
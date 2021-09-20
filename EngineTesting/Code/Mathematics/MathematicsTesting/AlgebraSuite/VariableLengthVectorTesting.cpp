// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 10:20)

#include "VariableLengthVectorTesting.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class VariableLengthVector<float>;
	template class VariableLengthVector<double>;
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,VariableLengthVectorTesting) 

void Mathematics::VariableLengthVectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(VectorCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::VariableLengthVectorTesting
	::ConstructionTest()
{
	default_random_engine generator{};
	uniform_real<float> randomDistribution{ -100.0f,100.0f }; 

	FloatVariableLengthVector firstVector(5);

	ASSERT_EQUAL(firstVector.GetSize(),5);

	vector<double> doubleVector;
	for(int i = 0;i < 15;++i)
	{
		doubleVector.push_back(randomDistribution(generator));
	}

	DoubleVariableLengthVector secondVector(doubleVector);
	ASSERT_EQUAL(secondVector.GetSize(),boost::numeric_cast<int>(doubleVector.size()));

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(secondVector[i],doubleVector[i],1e-10);
	}

	DoubleVariableLengthVector thirdVector(secondVector);
	ASSERT_EQUAL(secondVector.GetSize(),thirdVector.GetSize());

	ASSERT_TRUE(Approximate(secondVector,thirdVector,1e-10));

	ASSERT_EQUAL(secondVector.GetSize(), boost::numeric_cast<int>(doubleVector.size()));

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(secondVector[i],doubleVector[i],1e-10);
	}

	DoubleVariableLengthVector fourthVector;
	thirdVector = fourthVector;

	ASSERT_EQUAL(thirdVector.GetSize(),0);	

	fourthVector.ResetSize(10);

	ASSERT_EQUAL(fourthVector.GetSize(),10);	
	ASSERT_EQUAL(thirdVector.GetSize(),0);

// 	DoubleVariableLengthVector fifthVector(boost::numeric_cast<int>(doubleVector.size()),&doubleVector[0]);
// 
// 	ASSERT_EQUAL(fifthVector.GetSize(), boost::numeric_cast<int>(doubleVector.size()));
// 
// 	for(int i = 0;i < 15;++i)
// 	{
// 		ASSERT_APPROXIMATE(fifthVector[i],doubleVector[i],1e-10);
// 	}
}

void Mathematics::VariableLengthVectorTesting
	::AccessTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -100.0,100.0 };

	vector<double> doubleVector;
	for(int i = 0;i < 15;++i)
	{
		doubleVector.push_back(randomDistribution(generator));
	}

	const DoubleVariableLengthVector firstVector(doubleVector);
	DoubleVariableLengthVector secondVector(doubleVector);

	ASSERT_EQUAL(firstVector.GetSize(),15);	
	ASSERT_EQUAL(secondVector.GetSize(),15);	

// 	const double* firstPtr = firstVector.GetElements();
// 	double* secondPtr = secondVector.GetElements();
// 
// 	for(int i = 0;i < 15;++i)
// 	{
// 		ASSERT_APPROXIMATE(firstPtr[i],doubleVector[i],1e-10);
// 		ASSERT_APPROXIMATE(secondPtr[i],doubleVector[i],1e-10);
// 		ASSERT_APPROXIMATE(firstVector[i],doubleVector[i],1e-10);
// 		ASSERT_APPROXIMATE(secondVector[i],doubleVector[i],1e-10);
// 	}
}


void Mathematics::VariableLengthVectorTesting
	::ArithmeticCalculateTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -100.0,100.0 };

	vector<double> firstDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		firstDoubleVector.push_back(randomDistribution(generator));
	}

	vector<double> secondDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		secondDoubleVector.push_back(randomDistribution(generator));
	}

	DoubleVariableLengthVector firstVector(firstDoubleVector);
	DoubleVariableLengthVector secondVector(secondDoubleVector);	

	DoubleVariableLengthVector thirdVector = -firstVector;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(thirdVector[i],-firstDoubleVector[i],1e-10);
	}

	firstVector += secondVector;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(firstVector[i],firstDoubleVector[i] + secondDoubleVector[i],1e-10);
	}

	secondVector -= firstVector;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(secondVector[i],-firstDoubleVector[i],1e-10);
	}

	thirdVector *= 2.0;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(thirdVector[i], -firstDoubleVector[i] * 2.0,1e-10);
	}

	secondVector /= 2.0;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(secondVector[i], -firstDoubleVector[i] / 2.0,1e-10);
	}

	thirdVector = firstVector + secondVector;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(thirdVector[i],firstDoubleVector[i] / 2.0 + secondDoubleVector[i],1e-10);
	}

	thirdVector = firstVector - secondVector;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(thirdVector[i],firstDoubleVector[i] * 1.5 + secondDoubleVector[i],1e-10);
	}

	thirdVector = firstVector * 2.0;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(thirdVector[i],firstDoubleVector[i] * 2.0 + secondDoubleVector[i] * 2.0,1e-10);
	}

	thirdVector = 2.0 * firstVector;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(thirdVector[i],firstDoubleVector[i] * 2.0 + secondDoubleVector[i] * 2.0,1e-10);
	}

	thirdVector = firstVector / 2.0;

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(thirdVector[i],firstDoubleVector[i] / 2.0 + secondDoubleVector[i] / 2.0,1e-10);
	}
}


void Mathematics::VariableLengthVectorTesting
	::VectorCalculateTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -100.0,100.0 };

	vector<double> firstDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		firstDoubleVector.push_back(randomDistribution(generator));
	}

	DoubleVariableLengthVector firstVector(firstDoubleVector);

	double squaredLength = 0.0f;
	for(int i = 0;i < 15;++i)
	{
		squaredLength += firstVector[i] * firstVector[i];
	}

	ASSERT_APPROXIMATE(squaredLength,firstVector.SquaredLength(),1e-10);
	ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredLength),firstVector.Length(),1e-10);
	firstVector.Normalize();

	for(int i = 0;i < 15;++i)
	{
		ASSERT_APPROXIMATE(firstVector[i],firstDoubleVector[i] / DoubleMath::Sqrt(squaredLength),1e-10);	
	}

	vector<double> secondDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		secondDoubleVector.push_back(randomDistribution(generator));
	}

	DoubleVariableLengthVector secondVector(secondDoubleVector);

	double dotProduct = 0.0;
	for(int i = 0;i < 15;++i)
	{
		dotProduct += firstVector[i] * secondVector[i];
	}

	ASSERT_APPROXIMATE(dotProduct,Dot(firstVector,secondVector),1e-10);
}

void Mathematics::VariableLengthVectorTesting
	::CompareTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -100.0,100.0 };

	vector<double> firstDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		firstDoubleVector.push_back(randomDistribution(generator));
	}

	vector<double> secondDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		secondDoubleVector.push_back(randomDistribution(generator));
	}

	DoubleVariableLengthVector firstVector(firstDoubleVector);
	DoubleVariableLengthVector secondVector(secondDoubleVector);	

	firstVector[0] = 0.0;
	secondVector[0] = 1.0;

	ASSERT_TRUE(firstVector == firstVector);
	ASSERT_FALSE(firstVector == secondVector);
	ASSERT_TRUE(firstVector != secondVector);
	ASSERT_TRUE(firstVector < secondVector);
	ASSERT_TRUE(firstVector <= secondVector);
	ASSERT_FALSE(firstVector > secondVector);
	ASSERT_FALSE(firstVector >= secondVector);

	ASSERT_TRUE(Approximate(firstVector,firstVector,1e-10));
	ASSERT_TRUE(Approximate(secondVector,secondVector,1e-10));
	ASSERT_FALSE(Approximate(firstVector,secondVector,1e-10));
}




// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 11:56)

#include "APointTesting.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Base/Float.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class APoint<float>;
	template class APoint<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,APointTesting) 

void Mathematics::APointTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::APointTesting
	::ConstructionTest()
{
	Float3 tuple{ 3.0f,5.0f,9.0f };
	FloatVector3D vector{ 9.0f,6.0f,1.0f };

	FloatAPoint firstPoint;

	ASSERT_APPROXIMATE(firstPoint[0],0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstPoint[1],0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstPoint[2],0.0f,1e-8f);

	FloatAPoint secondPoint{ 6.0f,9.0f,1.0f };

	ASSERT_APPROXIMATE(secondPoint[0],6.0f,1e-8f);
	ASSERT_APPROXIMATE(secondPoint[1],9.0f,1e-8f);
	ASSERT_APPROXIMATE(secondPoint[2],1.0f,1e-8f);

	FloatAPoint thirdPoint{  };

	ASSERT_APPROXIMATE(thirdPoint[0],3.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdPoint[1],5.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdPoint[2],9.0f,1e-8f);

	FloatAPoint fourthPoint{ vector };

	ASSERT_APPROXIMATE(fourthPoint[0],9.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthPoint[1],6.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthPoint[2],1.0f,1e-8f);

	FloatAPoint fifthPoint{ fourthPoint };

	ASSERT_APPROXIMATE(fourthPoint[0],9.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthPoint[1],6.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthPoint[2],1.0f,1e-8f);

	thirdPoint = secondPoint;

	ASSERT_APPROXIMATE(thirdPoint[0],6.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdPoint[1],9.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdPoint[2],1.0f,1e-8f);
}

void Mathematics::APointTesting
	::AccessTest()
{
// 	DoubleAPoint firstPoint{ 6.0,9.0,1.0 };
// 
// 	auto tuple = firstPoint.GetFloat3();
// 	auto vector = firstPoint.GetVector3D();
// 	auto point = firstPoint.GetHomogeneousPoint();
// 
// 	ASSERT_APPROXIMATE(tuple.GetFirstValue(),6.0f,1e-8f);
// 	ASSERT_APPROXIMATE(tuple.GetSecondValue(),9.0f,1e-8f);
// 	ASSERT_APPROXIMATE(tuple.GetThirdValue(),1.0f,1e-8f);
// 
// 	ASSERT_APPROXIMATE(vector.GetX(),6.0,1e-10);
// 	ASSERT_APPROXIMATE(vector.GetY(),9.0,1e-10);
// 	ASSERT_APPROXIMATE(vector.GetZ(),1.0,1e-10);
// 
// 	ASSERT_APPROXIMATE(point.GetX(),6.0,1e-10);
// 	ASSERT_APPROXIMATE(point.GetY(),9.0,1e-10);
// 	ASSERT_APPROXIMATE(point.GetZ(),1.0,1e-10);
// 
// 	ASSERT_APPROXIMATE(firstPoint[0],6.0,1e-10);
// 	ASSERT_APPROXIMATE(firstPoint[1],9.0,1e-10);
// 	ASSERT_APPROXIMATE(firstPoint[2],1.0,1e-10);
// 
// 	const DoubleAPoint secondPoint{ 16.0,92.0,11.0 };
// 
// 	ASSERT_APPROXIMATE(secondPoint[0],16.0,1e-10);
// 	ASSERT_APPROXIMATE(secondPoint[1],92.0,1e-10);
// 	ASSERT_APPROXIMATE(secondPoint[2],11.0,1e-10);
}

void Mathematics::APointTesting
	::CalculateTest()
{
	FloatAPoint firstPoint{ 6.1f,3.0f,8.2f };
	FloatAVector firstVector{ 16.1f,23.0f,18.2f };

	firstPoint += firstVector;

	ASSERT_APPROXIMATE(firstPoint[0],22.2f,1e-8f);
	ASSERT_APPROXIMATE(firstPoint[1],26.0f,1e-8f);
	ASSERT_APPROXIMATE(firstPoint[2],26.4f,1e-5f);

	FloatAVector secondVector{ 22.1f,123.0f,118.2f };

	firstPoint -= secondVector;

	ASSERT_APPROXIMATE(firstPoint[0],0.1f,1e-6f);
	ASSERT_APPROXIMATE(firstPoint[1],-97.0f,1e-8f);
	ASSERT_APPROXIMATE(firstPoint[2],-91.8f,1e-5f);

	FloatAPoint secondPoint{ 26.1f,31.0f,8.22f };

	firstPoint += secondPoint;

	ASSERT_APPROXIMATE(firstPoint[0],26.2f,1e-8f);
	ASSERT_APPROXIMATE(firstPoint[1],-66.0f,1e-8f);
	ASSERT_APPROXIMATE(firstPoint[2],-83.58f,1e-5f);

	FloatAPoint thirdPoint{ 26.3f,-66.1f,-83.57f };

	firstPoint -= thirdPoint;

	ASSERT_APPROXIMATE(firstPoint[0],-0.1f,1e-5f);
	ASSERT_APPROXIMATE(firstPoint[1],0.1f,1e-5f);
	ASSERT_APPROXIMATE(firstPoint[2],-0.01f,1e-5f);

	firstPoint *= 0.7f;

	ASSERT_APPROXIMATE(firstPoint[0],-0.07f,1e-5f);
	ASSERT_APPROXIMATE(firstPoint[1],0.07f,1e-5f);
	ASSERT_APPROXIMATE(firstPoint[2],-0.007f,1e-5f);

	firstPoint /= 0.1f;

	ASSERT_APPROXIMATE(firstPoint[0],-0.7f,1e-4f);
	ASSERT_APPROXIMATE(firstPoint[1],0.7f,1e-4f);
	ASSERT_APPROXIMATE(firstPoint[2],-0.07f,1e-4f);

	secondPoint = -firstPoint;

	ASSERT_APPROXIMATE(secondPoint[0],0.7f,1e-4f);
	ASSERT_APPROXIMATE(secondPoint[1],-0.7f,1e-4f);
	ASSERT_APPROXIMATE(secondPoint[2],0.07f,1e-4f);

	auto thirdVector = firstPoint - secondPoint;

	ASSERT_APPROXIMATE(thirdVector[0],-1.4f,1e-4f);
	ASSERT_APPROXIMATE(thirdVector[1],1.4f,1e-4f);
	ASSERT_APPROXIMATE(thirdVector[2],-0.14f,1e-4f);

	auto fourthPoint = firstPoint + thirdVector;

	ASSERT_APPROXIMATE(fourthPoint[0],-2.1f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[1],2.1f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[2],-0.21f,1e-3f);

	fourthPoint = firstPoint - thirdVector;

	ASSERT_APPROXIMATE(fourthPoint[0],0.7f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[1],-0.7f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[2],0.07f,1e-4f);

	fourthPoint = secondPoint + thirdPoint;

	ASSERT_APPROXIMATE(fourthPoint[0],27.0f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[1],-66.8f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[2],-83.5f,1e-4f);

	fourthPoint = secondPoint * 2.0f;

	ASSERT_APPROXIMATE(fourthPoint[0],1.4f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[1],-1.4f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[2],0.14f,1e-4f);

	fourthPoint = secondPoint / 0.5f;

	ASSERT_APPROXIMATE(fourthPoint[0],1.4f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[1],-1.4f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[2],0.14f,1e-4f);

	fourthPoint = 2.0f * secondPoint;

	ASSERT_APPROXIMATE(fourthPoint[0],1.4f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[1],-1.4f,1e-4f);
	ASSERT_APPROXIMATE(fourthPoint[2],0.14f,1e-4f);

	default_random_engine randomEngine{};
	uniform_real<float> randomDistribution{ -100.0f,100.0f }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleAPoint fifthPoint{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };

		DoubleAVector fourthVector{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };

		auto dotProduct = fifthPoint[0] * fourthVector[0] + fifthPoint[1] * fourthVector[1] + fifthPoint[2] * fourthVector[2];

		ASSERT_APPROXIMATE(Dot(fifthPoint,fourthVector),dotProduct,1e-10);

		auto sixthPoint = fifthPoint + DoubleAPoint{ 0.001,0.001,0.001 };

		ASSERT_TRUE(Approximate(fifthPoint,fifthPoint,1e-10));
		ASSERT_TRUE(Approximate(fifthPoint,sixthPoint,1e-2));
		ASSERT_FALSE(Approximate(fifthPoint,sixthPoint,1e-4));

		ASSERT_TRUE(Approximate(fifthPoint,fifthPoint));
	}	
}


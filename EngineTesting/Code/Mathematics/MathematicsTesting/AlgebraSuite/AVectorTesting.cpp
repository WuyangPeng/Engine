// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 13:40)

#include "AVectorTesting.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Base/Float.h"

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class AVector<float>;
	template class AVector<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,AVectorTesting) 

void Mathematics::AVectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(VectorCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);	
}

void Mathematics::AVectorTesting
	::ConstructionTest()
{
	Float3 tuple{ 3.0f,5.0f,9.0f };
	FloatVector3D vector{ 9.0f,6.0f,1.0f };

	FloatAVector firstVector;

	ASSERT_APPROXIMATE(firstVector[0],0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstVector[1],0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstVector[2],0.0f,1e-8f);

	FloatAVector secondVector{ 6.0f,9.0f,1.0f };
 
	ASSERT_APPROXIMATE(secondVector[0],6.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector[1],9.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector[2],1.0f,1e-8f);

	FloatAVector thirdVector{   };

	ASSERT_APPROXIMATE(thirdVector[0],3.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdVector[1],5.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdVector[2],9.0f,1e-8f);

	FloatAVector fourthVector{ vector };

	ASSERT_APPROXIMATE(fourthVector[0],9.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthVector[1],6.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthVector[2],1.0f,1e-8f);

	FloatAVector fifthVector{ fourthVector };

	ASSERT_APPROXIMATE(fifthVector[0],9.0f,1e-8f);
	ASSERT_APPROXIMATE(fifthVector[1],6.0f,1e-8f);
	ASSERT_APPROXIMATE(fifthVector[2],1.0f,1e-8f);

	thirdVector = secondVector;

	ASSERT_APPROXIMATE(thirdVector[0],6.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdVector[1],9.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdVector[2],1.0f,1e-8f);
}

void Mathematics::AVectorTesting
	::AccessTest()
{
// 	DoubleAVector firstVector{ 6.0,9.0,1.0 };
// 
// 	auto tuple = firstVector.GetFloat3();
// 	auto vector = firstVector.GetVector3D();
// 
// 	ASSERT_APPROXIMATE(tuple.GetFirstValue(),6.0f,1e-10f);
// 	ASSERT_APPROXIMATE(tuple.GetSecondValue(),9.0f,1e-10f);
// 	ASSERT_APPROXIMATE(tuple.GetThirdValue(),1.0f,1e-10f);
// 
// 	ASSERT_APPROXIMATE(vector.GetX(),6.0,1e-10f);
// 	ASSERT_APPROXIMATE(vector.GetY(),9.0,1e-10f);
// 	ASSERT_APPROXIMATE(vector.GetZ(),1.0,1e-10f);
// 
// 	ASSERT_APPROXIMATE(firstVector[0],6.0,1e-10f);
// 	ASSERT_APPROXIMATE(firstVector[1],9.0,1e-10f);
// 	ASSERT_APPROXIMATE(firstVector[2],1.0,1e-10f);
// 
// 	const DoubleAVector secondVector{ 16.0,92.0,11.0 };
// 
// 	ASSERT_APPROXIMATE(secondVector[0],16.0,1e-10);
// 	ASSERT_APPROXIMATE(secondVector[1],92.0,1e-10);
// 	ASSERT_APPROXIMATE(secondVector[2],11.0,1e-10);
}

void Mathematics::AVectorTesting
	::ArithmeticCalculateTest()
{
	FloatAVector firstVector{ 26.0f,91.0f,8.0f };

	auto secondVector = -firstVector;
	ASSERT_APPROXIMATE(secondVector[0],-26.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector[1],-91.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector[2],-8.0f,1e-8f);

	secondVector[0] = 3.0f;
	secondVector[1] = 7.0f;
	secondVector[2] = 17.0f;

	ASSERT_APPROXIMATE(secondVector[0],3.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector[1],7.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector[2],17.0f,1e-8f);

	const DoubleAVector thirdVector{ 6.0,5.0,15.0 };

	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[1],5.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[2],15.0,1e-10);

	DoubleAVector fourthVector{ 9.0,3.0,3.0 };
	fourthVector += thirdVector;
	ASSERT_APPROXIMATE(fourthVector[0],15.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],8.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],18.0,1e-10);

	auto fifthVector = thirdVector + fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],21.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],13.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],33.0,1e-10);

	fifthVector -= fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],5.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],15.0,1e-10);

	fourthVector = fifthVector - thirdVector;

	ASSERT_APPROXIMATE(fourthVector[0],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],0.0,1e-10);

	fifthVector *= 6.0;

	ASSERT_APPROXIMATE(fifthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],30.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],90.0,1e-10);

	fourthVector = 0.5 * fifthVector;

	ASSERT_APPROXIMATE(fourthVector[0],18.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],15.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],45.0,1e-10);

	fourthVector = fifthVector * 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],72.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],60.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],180.0,1e-10);

	fourthVector /= 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],30.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],90.0,1e-10);

	fifthVector = fourthVector / 3.0;

	ASSERT_APPROXIMATE(fifthVector[0],12.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],10.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],30.0,1e-10);
}

void Mathematics::AVectorTesting
	::VectorCalculateTest()
{
	default_random_engine randomEngine{};
	uniform_real<double> randomDistribution{ -100.0,100.0 }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop) 
	{
		DoubleAVector firstVector{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };

		DoubleAVector secondVector{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };

		auto dotProduct = firstVector[0] * secondVector[0] + firstVector[1] * secondVector[1] + firstVector[2] * secondVector[2];

		ASSERT_APPROXIMATE(Dot(firstVector,secondVector), dotProduct,1e-10);

		DoubleAVector crossProduct{ firstVector[1] * secondVector[2] - firstVector[2] * secondVector[1],
							   firstVector[2] * secondVector[0] - firstVector[0] * secondVector[2],
							   firstVector[0] * secondVector[1] - firstVector[1] * secondVector[0] };

		auto testCross = Cross(firstVector,secondVector);

		ASSERT_TRUE(Approximate(testCross,crossProduct,1e-10));
		
		crossProduct.Normalize();
		testCross = UnitCross(firstVector,secondVector);

		ASSERT_TRUE(Approximate(testCross,crossProduct,1e-10));
	}

	FloatAVector thirdVector{ 3.0f,4.0f,5.0f };

	ASSERT_APPROXIMATE(thirdVector.Length(),FloatMath::Sqrt(50.0f),1e-8f);
	ASSERT_APPROXIMATE(thirdVector.SquaredLength(),50.0f,1e-8f);

	thirdVector.Normalize();

	ASSERT_APPROXIMATE(thirdVector[0],3.0f / sqrt(50.0f),1e-8f);
	ASSERT_APPROXIMATE(thirdVector[1],4.0f / sqrt(50.0f),1e-8f);
	ASSERT_APPROXIMATE(thirdVector[2],5.0f / sqrt(50.0f),1e-8f);
}


void Mathematics::AVectorTesting
	::OtherCalculateTest()
{
	default_random_engine randomEngine{};
	uniform_real<double> randomDistribution{ -100.0,100.0 }; 

	DoubleAVector firstVector{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };
	DoubleAVector secondVector{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };

	DoubleAVector thirdVector{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };

	vector<DoubleAVector> vectors;
	vectors.push_back(firstVector);
	vectors.push_back(secondVector);
	vectors.push_back(thirdVector);
	
	auto firstOrthonormalize = Orthonormalize(firstVector,secondVector,thirdVector);
	
	auto secondOrthonormalize = Orthonormalize(vectors);
	 
	firstVector.Normalize();
	auto dot0 = Dot(firstVector,secondVector);
	secondVector -= dot0 * firstVector;
	secondVector.Normalize();

	auto dot1 = Dot(secondVector,thirdVector);
	dot0 =  Dot(firstVector,thirdVector);
	thirdVector -= dot0 * firstVector + dot1 * secondVector;
	thirdVector.Normalize();
	
	ASSERT_TRUE(Approximate(firstVector,firstOrthonormalize.GetUVector(),1e-10));
	ASSERT_TRUE(Approximate(secondVector,firstOrthonormalize.GetVVector(),1e-10));
	ASSERT_TRUE(Approximate(thirdVector,firstOrthonormalize.GetWVector(),1e-10));
	ASSERT_TRUE(Approximate(firstVector,secondOrthonormalize.GetUVector(),1e-10));
	ASSERT_TRUE(Approximate(secondVector,secondOrthonormalize.GetVVector(),1e-10));
	ASSERT_TRUE(Approximate(thirdVector,secondOrthonormalize.GetWVector(),1e-10));	
	
	DoubleAVector fourthVector{ randomDistribution(randomEngine),randomDistribution(randomEngine),randomDistribution(randomEngine) };

	auto firstOrthonormalBasis = GenerateOrthonormalBasis(fourthVector);

	fourthVector.Normalize();

	auto secondOrthonormalBasis = GenerateComplementBasis(fourthVector);

	ASSERT_TRUE(Approximate(fourthVector,firstOrthonormalBasis.GetWVector(),1e-10));
	ASSERT_TRUE(Approximate(fourthVector,secondOrthonormalBasis.GetWVector(),1e-10)); 

	auto fifthVector = Cross(firstOrthonormalBasis.GetUVector(), firstOrthonormalBasis.GetVVector());

	ASSERT_TRUE(Approximate(firstOrthonormalBasis.GetWVector(),fifthVector,1e-10));

	auto sixthVector = Cross(firstOrthonormalBasis.GetVVector(), firstOrthonormalBasis.GetWVector());

	ASSERT_TRUE(Approximate(firstOrthonormalBasis.GetUVector(),sixthVector,1e-10));

	auto seventhVector = Cross(firstOrthonormalBasis.GetWVector(), firstOrthonormalBasis.GetUVector());

	ASSERT_TRUE(Approximate(firstOrthonormalBasis.GetVVector(),seventhVector));
}


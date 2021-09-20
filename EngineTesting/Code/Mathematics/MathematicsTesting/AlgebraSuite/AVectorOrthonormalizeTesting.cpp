// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 13:26)

#include "AVectorOrthonormalizeTesting.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class AVectorOrthonormalize<float>;
	template class AVectorOrthonormalize<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,AVectorOrthonormalizeTesting)
 
void Mathematics::AVectorOrthonormalizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest); 
}

void Mathematics::AVectorOrthonormalizeTesting
	::OrthonormalizeTest()
{
	default_random_engine randomEngine{};
	uniform_real<double> firstRandomDistribution{ -10.0,10.0 };
	uniform_real<float> secondRandomDistribution{ -10.0f,10.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleAVector firstVector{ firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine) };
		DoubleAVector secondVector{ firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine) };
		DoubleAVector thirdVector{ firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine) };

		FloatAVector fourthVector{ secondRandomDistribution(randomEngine),secondRandomDistribution(randomEngine),secondRandomDistribution(randomEngine) };
		FloatAVector fifthVector{ secondRandomDistribution(randomEngine),secondRandomDistribution(randomEngine),secondRandomDistribution(randomEngine) };
		FloatAVector sixthVector{ secondRandomDistribution(randomEngine),secondRandomDistribution(randomEngine),secondRandomDistribution(randomEngine) };

		DoubleAVectorOrthonormalize firstOrthonormalize{ firstVector,secondVector,thirdVector,1e-10 };

		firstVector.Normalize();
		auto dot0 = Dot(firstVector, secondVector); 
		secondVector -= firstVector * dot0;
		secondVector.Normalize();
		dot0 = Dot(firstVector, thirdVector); 
		thirdVector -= firstVector * dot0;
		dot0 = Dot(secondVector, thirdVector); 
		thirdVector -= secondVector * dot0;
		thirdVector.Normalize();

		ASSERT_TRUE(Approximate(firstVector,firstOrthonormalize.GetUVector(),1e-10));

		ASSERT_TRUE(Approximate(secondVector,firstOrthonormalize.GetVVector(),1e-10));

		ASSERT_TRUE(Approximate(thirdVector,firstOrthonormalize.GetWVector(),1e-10));

		FloatAVectorOrthonormalize secondOrthonormalize{ fourthVector,fifthVector,sixthVector,1e-4f };

		fourthVector.Normalize();
		auto dot1 = Dot(fourthVector, fifthVector); 
		fifthVector -= fourthVector * dot1;
		fifthVector.Normalize();

		dot1 = Dot(fourthVector, sixthVector); 
		sixthVector -= fourthVector * dot1;
		dot1 = Dot(fifthVector, sixthVector); 
		sixthVector -= fifthVector * dot1;
		sixthVector.Normalize();

		ASSERT_TRUE(Approximate(fourthVector,secondOrthonormalize.GetUVector(),1e-8f));

		ASSERT_TRUE(Approximate(fifthVector,secondOrthonormalize.GetVVector(),1e-8f));
		
		ASSERT_TRUE(Approximate(sixthVector,secondOrthonormalize.GetWVector(),1e-4f));
	}
}


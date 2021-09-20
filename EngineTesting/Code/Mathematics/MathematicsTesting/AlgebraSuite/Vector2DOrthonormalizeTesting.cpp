// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 11:07)

#include "Vector2DOrthonormalizeTesting.h"
#include "Mathematics/Algebra/Vector2DOrthonormalizeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector2DTools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector2DOrthonormalize<float>;
	template class Vector2DOrthonormalize<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector2DOrthonormalizeTesting) 

void Mathematics::Vector2DOrthonormalizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest); 
}

void Mathematics::Vector2DOrthonormalizeTesting
	::OrthonormalizeTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution{ -10.0,10.0 };
	uniform_real<float> secondRandomDistribution{ -10.0f,10.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator));
		DoubleVector2D secondVector(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator));


		FloatVector2D thirdVector(secondRandomDistribution(generator),
			                  secondRandomDistribution(generator));
		FloatVector2D fourthVector(secondRandomDistribution(generator),
			                   secondRandomDistribution(generator));

		DoubleVector2DOrthonormalize firstOrthonormalize(firstVector,secondVector,1e-10);

		firstVector.Normalize();
		double dot0 = DoubleVector2DTools::DotProduct(firstVector, secondVector); 
		secondVector -= firstVector * dot0;
		secondVector.Normalize();

		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstVector,firstOrthonormalize.GetUVector(),1e-10));

		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondVector,firstOrthonormalize.GetVVector(),1e-10));

		FloatVector2DOrthonormalize secondOrthonormalize(thirdVector, fourthVector,1e-5f);

		thirdVector.Normalize();
		float dot1 = FloatVector2DTools::DotProduct(thirdVector, fourthVector); 
		fourthVector -= thirdVector * dot1;
		fourthVector.Normalize();

		ASSERT_TRUE(FloatVector2DTools::Approximate(thirdVector,secondOrthonormalize.GetUVector(),1e-8f));

		ASSERT_TRUE(FloatVector2DTools::Approximate(fourthVector,secondOrthonormalize.GetVVector(),1e-8f));
	}
}


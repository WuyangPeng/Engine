// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:52)

#include "StaticTestIntersectorBox2Box2Testing.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorBox2Box2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include "Mathematics/Algebra/Vector2DTools.h"


namespace Mathematics
{
	template class StaticTestIntersectorBox2Box2<float>;
	template class StaticTestIntersectorBox2Box2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorBox2Box2Testing)

void Mathematics::StaticTestIntersectorBox2Box2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BoxTest); 
}

void Mathematics::StaticTestIntersectorBox2Box2Testing
	::BoxTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> randomDistribution(-100.0f,100.0f);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector2D lhsCenter(randomDistribution(generator),
			                randomDistribution(generator));		 

		FloatVector2D rhsCenter(randomDistribution(generator),
			                randomDistribution(generator));

		FloatVector2D lhsFirstAxis(randomDistribution(generator),
			                   randomDistribution(generator));		 

		FloatVector2D rhsFirstAxis(randomDistribution(generator),
			                   randomDistribution(generator));

		lhsFirstAxis.Normalize();
		rhsFirstAxis.Normalize();

		float lhsFirstExtent = FloatMath::FAbs(randomDistribution(generator));
		float rhsFirstExtent = FloatMath::FAbs(randomDistribution(generator));

		FloatVector2D lhsSecondAxis(randomDistribution(generator),
			                    randomDistribution(generator));		 

		FloatVector2D rhsSecondAxis(randomDistribution(generator),
			                    randomDistribution(generator));

		lhsSecondAxis.Normalize();
		rhsSecondAxis.Normalize();

		float lhsSecondExtent = FloatMath::FAbs(randomDistribution(generator));
		float rhsSecondExtent = FloatMath::FAbs(randomDistribution(generator));

		FloatBox2 lhsBox(lhsCenter, lhsFirstAxis, lhsSecondAxis, lhsFirstExtent, lhsSecondExtent);
		FloatBox2 rhsBox(rhsCenter,rhsFirstAxis, rhsSecondAxis, rhsFirstExtent, rhsSecondExtent);

		FloatStaticTestIntersectorBox2Box2  intersector(lhsBox, rhsBox);

		FloatVector2D boxCentersDifference = rhsCenter - lhsCenter;	 
		 
		float absA0DotB0 = FloatMath::FAbs(FloatVector2DTools::DotProduct(lhsFirstAxis, rhsFirstAxis));
		float absA0DotB1 = FloatMath::FAbs(FloatVector2DTools::DotProduct(lhsFirstAxis, rhsSecondAxis));		 
		float absADotD = FloatMath::FAbs(FloatVector2DTools::DotProduct(lhsFirstAxis,boxCentersDifference));
	 
		if (lhsFirstExtent + rhsFirstExtent * absA0DotB0 + rhsSecondExtent * absA0DotB1 < absADotD)
		{
			ASSERT_FALSE(intersector.IsIntersection());
			continue;
		}

		float absA1DotB0 = FloatMath::FAbs(FloatVector2DTools::DotProduct(lhsSecondAxis, rhsFirstAxis));
		float absA1DotB1 = FloatMath::FAbs(FloatVector2DTools::DotProduct(lhsSecondAxis, rhsSecondAxis));
		absADotD = FloatMath::FAbs(FloatVector2DTools::DotProduct(lhsSecondAxis, boxCentersDifference));

		if (lhsSecondExtent + rhsFirstExtent * absA1DotB0 + rhsSecondExtent * absA1DotB1 < absADotD)
		{
			ASSERT_FALSE(intersector.IsIntersection());
			continue;
		}

		absADotD = FloatMath::FAbs(FloatVector2DTools::DotProduct(rhsFirstAxis, boxCentersDifference));

		if (rhsFirstExtent + lhsFirstExtent * absA0DotB0 + lhsSecondExtent * absA1DotB0 < absADotD)
		{
			ASSERT_FALSE(intersector.IsIntersection());
			continue;
		}

		absADotD = FloatMath::FAbs(FloatVector2DTools::DotProduct(rhsSecondAxis, boxCentersDifference));

		if (rhsSecondExtent + lhsFirstExtent * absA0DotB1 + lhsSecondExtent * absA1DotB1 < absADotD)
		{
			ASSERT_FALSE(intersector.IsIntersection());
			continue;
		}

		ASSERT_TRUE(intersector.IsIntersection());
	}
}
 
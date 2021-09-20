// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:52)

#include "StaticFindIntersectorRay2Ray2Testing.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorRay2Ray2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"

namespace Mathematics
{
	template class StaticFindIntersectorRay2Ray2<float>;
	template class StaticFindIntersectorRay2Ray2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorRay2Ray2Testing)

void Mathematics::StaticFindIntersectorRay2Ray2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RayTest); 
}

void Mathematics::StaticFindIntersectorRay2Ray2Testing
	::RayTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> randomDistribution(-10.0f,10.0f);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector2D lhsOrigin(randomDistribution(generator),
			                randomDistribution(generator));
		FloatVector2D lhsDirection(randomDistribution(generator),
			                   randomDistribution(generator));
		FloatVector2D rhsOrigin(randomDistribution(generator),
			                randomDistribution(generator));
		FloatVector2D rhsDirection(randomDistribution(generator),
			                   randomDistribution(generator));

		lhsDirection.Normalize();
		rhsDirection.Normalize();

		FloatStaticFindIntersectorRay2Ray2 firstClassify(FloatRay2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Ray);
		ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
		ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin, firstClassify.GetPoint(0),1e-8f);

		FloatStaticFindIntersectorRay2Ray2 secondClassify(FloatRay2(lhsOrigin, lhsDirection), FloatRay2(rhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
		ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

		FloatStaticFindIntersectorRay2Ray2 thirdClassify(FloatRay2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin, -lhsDirection));

		ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
		ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);
		ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin, thirdClassify.GetPoint(0), 1e-8f);

		FloatStaticFindIntersectorRay2Ray2 fourthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin + lhsDirection, -lhsDirection));

		ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
		ASSERT_EQUAL(fourthClassify.GetQuantity(), 2);
		ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin, fourthClassify.GetPoint(0), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin + lhsDirection, fourthClassify.GetPoint(1), 1e-8f);

		FloatStaticFindIntersectorRay2Ray2 fifthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin - lhsDirection, -lhsDirection));

		ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
		ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

		FloatStaticFindIntersectorRay2Ray2 sixthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatRay2(rhsOrigin, rhsDirection));

		FloatStaticTestIntersectorLine2Classify seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,			                                        
													        true);

		if (0.0f <= seventhClassify.GetParameter0() && 0.0f <= seventhClassify.GetParameter1())
		{
			ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
			ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);
			ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, lhsOrigin + lhsDirection * seventhClassify.GetParameter0(),
				                            sixthClassify.GetPoint(0), 1e-8f); 
		}
		else
		{
			ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
			ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
		}
	}	
}
 
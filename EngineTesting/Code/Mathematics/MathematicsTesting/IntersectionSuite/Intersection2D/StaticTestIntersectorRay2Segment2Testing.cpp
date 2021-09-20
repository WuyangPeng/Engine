// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:54)

#include "StaticTestIntersectorRay2Segment2Testing.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorRay2Segment2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"

namespace Mathematics
{
	template class StaticTestIntersectorRay2Segment2<float>;
	template class StaticTestIntersectorRay2Segment2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorRay2Segment2Testing)

void Mathematics::StaticTestIntersectorRay2Segment2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest); 
}

void Mathematics::StaticTestIntersectorRay2Segment2Testing
	::SegmentTest()
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

		float extent = FloatMath::FAbs(randomDistribution(generator));

		FloatStaticTestIntersectorRay2Segment2 firstClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Segment);
		ASSERT_EQUAL(firstClassify.GetQuantity(), 2);

		FloatStaticTestIntersectorRay2Segment2 secondClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, rhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
		ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

		FloatStaticTestIntersectorRay2Segment2 thirdClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin, -lhsDirection));

		ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Segment);
		ASSERT_EQUAL(thirdClassify.GetQuantity(), 2);

		FloatStaticTestIntersectorRay2Segment2 fourthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, lhsOrigin + lhsDirection, -lhsDirection));

		ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Segment);
		ASSERT_EQUAL(fourthClassify.GetQuantity(), 2);

		FloatStaticTestIntersectorRay2Segment2 fifthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(lhsOrigin - lhsDirection,lhsOrigin - lhsDirection - extent * lhsDirection));

		ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Empty);
		ASSERT_EQUAL(fifthClassify.GetQuantity(), 0);

		FloatStaticTestIntersectorRay2Segment2 sixthClassify(FloatRay2(lhsOrigin, lhsDirection), FloatSegment2(extent, rhsOrigin, rhsDirection));

		FloatStaticTestIntersectorLine2Classify seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,			                                        
													        true);
	
		if (0.0f <= seventhClassify.GetParameter0() &&
			FloatMath::FAbs(seventhClassify.GetParameter1()) <= sixthClassify.GetSegment().GetExtent())
		{
			ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
			ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);
		}
		else
		{
			ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
			ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
		}
	}	
}
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:51)

#include "StaticFindIntersectorLine2Ray2Testing.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Ray2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"

 
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorLine2Ray2Testing)

void Mathematics::StaticFindIntersectorLine2Ray2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RayTest); 
}

void Mathematics::StaticFindIntersectorLine2Ray2Testing
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

		FloatStaticFindIntersectorLine2Ray2 firstClassify(FloatLine2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Ray);
		ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
		ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

		FloatStaticFindIntersectorLine2Ray2 secondClassify(FloatLine2(lhsOrigin, lhsDirection), FloatRay2(rhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
		ASSERT_EQUAL(secondClassify.GetQuantity(), 0);
		ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

		FloatStaticFindIntersectorLine2Ray2 thirdClassify(FloatLine2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin, -lhsDirection));

		ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Ray);
		ASSERT_EQUAL(thirdClassify.GetQuantity(), INT_MAX);
		ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

		FloatStaticFindIntersectorLine2Ray2 fourthClassify(FloatLine2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin + lhsDirection, -lhsDirection));

		ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Ray);
		ASSERT_EQUAL(fourthClassify.GetQuantity(), INT_MAX);
		ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

		FloatStaticFindIntersectorLine2Ray2 fifthClassify(FloatLine2(lhsOrigin, lhsDirection), FloatRay2(lhsOrigin - lhsDirection, -lhsDirection));

		ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Ray);
		ASSERT_EQUAL(fifthClassify.GetQuantity(), INT_MAX);
		ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

		FloatStaticFindIntersectorLine2Ray2 sixthClassify(FloatLine2(lhsOrigin, lhsDirection), FloatRay2(rhsOrigin, rhsDirection));

		FloatStaticTestIntersectorLine2Classify seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,			                                        
													        true);

		if (0.0f <= seventhClassify.GetParameter1())
		{
			ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
			ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);

			FloatVector2D firstPoint = sixthClassify.GetPoint() - lhsOrigin;
			FloatVector2D secondPoint = sixthClassify.GetPoint() - rhsOrigin;

			firstPoint.Normalize();
			secondPoint.Normalize();

			ASSERT_TRUE(FloatVector2DTools::Approximate(firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f) ||
			            FloatVector2DTools::Approximate(-firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f));

			ASSERT_TRUE(FloatVector2DTools::Approximate(secondPoint, sixthClassify.GetRay().GetDirection(), 1e-4f) ||
			            FloatVector2DTools::Approximate(-secondPoint, sixthClassify.GetRay().GetDirection(), 1e-4f));
		}
		else
		{
			ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
			ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
			ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);
		}
	}	
}

void Mathematics::StaticFindIntersectorLine2Ray2Testing
	::ExceptionTest(const StaticFindIntersectorLine2Ray2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetPoint();
}


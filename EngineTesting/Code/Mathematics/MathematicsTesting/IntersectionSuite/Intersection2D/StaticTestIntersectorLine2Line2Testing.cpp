// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:53)

#include "StaticTestIntersectorLine2Line2Testing.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Line2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>

namespace Mathematics
{
	template class StaticTestIntersectorLine2Line2<float>;
	template class StaticTestIntersectorLine2Line2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticTestIntersectorLine2Line2Testing)

void Mathematics::StaticTestIntersectorLine2Line2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(LineTest); 
}

void Mathematics::StaticTestIntersectorLine2Line2Testing
	::LineTest()
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

		FloatStaticTestIntersectorLine2Line2 firstClassify(FloatLine2(lhsOrigin, lhsDirection), FloatLine2( lhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Line);
		ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);

		FloatStaticTestIntersectorLine2Line2 secondClassify(FloatLine2(lhsOrigin, lhsDirection), FloatLine2(rhsOrigin, lhsDirection));

		ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
		ASSERT_EQUAL(secondClassify.GetQuantity(), 0);

		FloatStaticTestIntersectorLine2Line2 thirdClassify(FloatLine2(lhsOrigin, lhsDirection), FloatLine2( rhsOrigin, rhsDirection));

		ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
		ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);

	}
}
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 17:28)

#include "DynamicIntersectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/DynamicIntersectorTestDetail.h"

#include <random>
#include "Mathematics/Algebra/Vector3DTools.h"

namespace Mathematics
{
	template class DynamicIntersectorTest<float, Vector2D>;
	template class DynamicIntersectorTest<double, Vector2D>;
	template class DynamicIntersectorTest<float, Vector3D>;
	template class DynamicIntersectorTest<double, Vector3D>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DynamicIntersectorTesting)

void Mathematics::DynamicIntersectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTypeTest); 
}

void Mathematics::DynamicIntersectorTesting
	::IntersectionTypeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0,100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		for (auto i = IntersectionType::Empty; i <= IntersectionType::Other; ++i)
		{
			double tMax = randomDistribution(generator);
			DoubleVector3D lhsVelocity(randomDistribution(generator),
				                  randomDistribution(generator),
								  randomDistribution(generator));
			DoubleVector3D rhsVelocity(randomDistribution(generator),
				                  randomDistribution(generator),
								  randomDistribution(generator));
			double contactTime = DoubleMath::FAbs(randomDistribution(generator));

			DynamicIntersectorTest<double, Vector3D> intersectorTest(tMax, lhsVelocity, rhsVelocity, IntersectionType(i), contactTime, 1e-10);

			ASSERT_ENUM_EQUAL(intersectorTest.GetIntersectionType(), IntersectionType(i));
			ASSERT_APPROXIMATE(intersectorTest.GetEpsilon(), 1e-10, 1e-10);

			if (intersectorTest.GetIntersectionType() == IntersectionType::Empty)
			{
				ASSERT_FALSE(intersectorTest.IsIntersection());
			}
			else
			{
				ASSERT_TRUE(intersectorTest.IsIntersection());
			}

			ASSERT_APPROXIMATE(intersectorTest.GetTMax(), tMax, 1e-10);
			ASSERT_APPROXIMATE(intersectorTest.GetContactTime(), contactTime, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, intersectorTest.GetLhsVelocity(), lhsVelocity, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, intersectorTest.GetRhsVelocity(), rhsVelocity, 1e-10);
		}
	}
}
 
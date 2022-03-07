// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:49)

#include "StaticIntersectorTesting.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/StaticIntersectorTestDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class StaticIntersectorTest<float, Vector2>;
	template class StaticIntersectorTest<double, Vector2>;
	template class StaticIntersectorTest<float, Vector3>;
	template class StaticIntersectorTest<double, Vector3>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticIntersectorTesting)

void Mathematics::StaticIntersectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTypeTest); 
}

void Mathematics::StaticIntersectorTesting
	::IntersectionTypeTest()
{
	for (auto i = IntersectionType::Empty; i <= IntersectionType::Other; ++i)
	{
		StaticIntersectorTest<double, Vector3> intersectorTest(IntersectionType(i), 1e-10);

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
	}	
}
 
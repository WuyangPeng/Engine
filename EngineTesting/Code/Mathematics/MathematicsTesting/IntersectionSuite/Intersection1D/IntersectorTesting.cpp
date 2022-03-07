// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:49)

#include "IntersectorTesting.h"
#include "Mathematics/MathematicsTesting/IntersectionSuite/Detail/IntersectorTestDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class IntersectorTest<float, Vector2>;
	template class IntersectorTest<double, Vector2>;
	template class IntersectorTest<float, Vector3>;
	template class IntersectorTest<double, Vector3>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntersectorTesting)

void Mathematics::IntersectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTypeTest); 
}

void Mathematics::IntersectorTesting
	::IntersectionTypeTest()
{
	for (auto i = IntersectionType::Empty; i <= IntersectionType::Other; ++i)
	{
		IntersectorTest<float, Vector2> intersectorTest(IntersectionType(i), 1e-8f);

		ASSERT_ENUM_EQUAL(intersectorTest.GetIntersectionType(), IntersectionType(i));
		ASSERT_APPROXIMATE(intersectorTest.GetEpsilon(), 1e-8f, 1e-8f);

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
 
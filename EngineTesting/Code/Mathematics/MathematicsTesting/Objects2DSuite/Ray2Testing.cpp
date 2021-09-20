// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:45)

#include "Ray2Testing.h"
#include "Mathematics/Objects2D/Ray2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Ray2<float>;
	template class Ray2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Ray2Testing) 

void Mathematics::Ray2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RayTest);
}

void Mathematics::Ray2Testing
	::RayTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D origin(firstRandomDistribution(generator), firstRandomDistribution(generator));

		DoubleVector2D direction(firstRandomDistribution(generator), firstRandomDistribution(generator));

		direction.Normalize();

		DoubleRay2 line(origin,direction);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(origin,line.GetOrigin()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(direction,line.GetDirection()));		
	}
}


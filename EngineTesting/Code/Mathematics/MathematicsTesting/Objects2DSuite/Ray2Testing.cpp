// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:45)

#include "Ray2Testing.h"
#include "Mathematics/Objects2D/Ray2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
		Vector2 origin(firstRandomDistribution(generator), firstRandomDistribution(generator));

		Vector2 direction(firstRandomDistribution(generator), firstRandomDistribution(generator));

		direction.Normalize();

		Ray2D line(origin,direction);

		ASSERT_TRUE(Vector2ToolsD::Approximate(origin,line.GetOrigin()));
		ASSERT_TRUE(Vector2ToolsD::Approximate(direction,line.GetDirection()));		
	}
}


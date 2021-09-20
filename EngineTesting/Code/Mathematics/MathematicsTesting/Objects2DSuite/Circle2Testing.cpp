// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:06)

#include "Circle2Testing.h"
#include "Mathematics/Objects2D/Circle2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Circle2<float>;
	template class Circle2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Circle2Testing) 

void Mathematics::Circle2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CircleTest);
}

void Mathematics::Circle2Testing
	::CircleTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D center(firstRandomDistribution(generator),firstRandomDistribution(generator));

		
		double radius(DoubleMath::FAbs(firstRandomDistribution(generator)));

		DoubleCircle2 circle(center,radius);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(center,circle.GetCenter()));
		ASSERT_APPROXIMATE(radius,circle.GetRadius(),1e-10);
	}
}


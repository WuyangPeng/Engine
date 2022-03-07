// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:46)

#include "Segment2Testing.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Segment2<float>;
	template class Segment2<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Segment2Testing) 

void Mathematics::Segment2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::Segment2Testing
	::SegmentTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));

		Vector2 secondPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));

		Segment2D firstSegment(firstPoint,secondPoint);

		ASSERT_TRUE(Vector2ToolsD::Approximate(firstPoint, firstSegment.GetBeginPoint()));
		ASSERT_TRUE(Vector2ToolsD::Approximate(secondPoint, firstSegment.GetEndPoint()));
		
		Vector2 center = firstSegment.GetCenterPoint();
		Vector2 direction = firstSegment.GetDirection();
		double extent = firstSegment.GetExtent();

		Segment2D secondSegment(extent,center,direction);

		ASSERT_TRUE(Vector2ToolsD::Approximate(firstPoint,secondSegment.GetBeginPoint()));
		ASSERT_TRUE(Vector2ToolsD::Approximate(secondPoint,secondSegment.GetEndPoint()));
		ASSERT_TRUE(Vector2ToolsD::Approximate(center,secondSegment.GetCenterPoint()));
		ASSERT_TRUE(Vector2ToolsD::Approximate(direction,secondSegment.GetDirection()));
		ASSERT_APPROXIMATE(extent,secondSegment.GetExtent(),1e-10);
	}
}


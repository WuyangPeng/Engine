// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.2 (2019/08/22 14:46)

#include "Segment2Testing.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
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
		DoubleVector2D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));

		DoubleVector2D secondPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));

		DoubleSegment2 firstSegment(firstPoint,secondPoint);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstPoint, firstSegment.GetBeginPoint()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondPoint, firstSegment.GetEndPoint()));
		
		DoubleVector2D center = firstSegment.GetCenterPoint();
		DoubleVector2D direction = firstSegment.GetDirection();
		double extent = firstSegment.GetExtent();

		DoubleSegment2 secondSegment(extent,center,direction);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstPoint,secondSegment.GetBeginPoint()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondPoint,secondSegment.GetEndPoint()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(center,secondSegment.GetCenterPoint()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(direction,secondSegment.GetDirection()));
		ASSERT_APPROXIMATE(extent,secondSegment.GetExtent(),1e-10);
	}
}


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.2 (2019/08/22 17:57)

#include "Segment3Testing.h"
#include "Mathematics/Objects3D/Segment3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
 
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Segment3<float>;
	template class Segment3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Segment3Testing) 

void Mathematics::Segment3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::Segment3Testing
	::SegmentTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		DoubleVector3D secondPoint(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		DoubleSegment3 firstSegment(firstPoint,secondPoint);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(firstPoint,  firstSegment.GetBeginPoint()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondPoint, firstSegment.GetEndPoint()));
		
		DoubleVector3D center = firstSegment.GetCenterPoint();
		DoubleVector3D direction = firstSegment.GetDirection();
		double extent = firstSegment.GetExtent();

		DoubleSegment3 secondSegment(extent,center,direction);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(firstPoint,secondSegment.GetBeginPoint()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondPoint,secondSegment.GetEndPoint()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(center,secondSegment.GetCenterPoint()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(direction,secondSegment.GetDirection()));
		ASSERT_APPROXIMATE(extent,secondSegment.GetExtent(),1e-10);

	}
}


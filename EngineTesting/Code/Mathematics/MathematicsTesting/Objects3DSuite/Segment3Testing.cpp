// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:57)

#include "Segment3Testing.h"
#include "Mathematics/Objects3D/Segment3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
		Vector3D firstPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		Vector3D secondPoint(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		Segment3D firstSegment(firstPoint,secondPoint);

		ASSERT_TRUE(Vector3ToolsD::Approximate(firstPoint,  firstSegment.GetBeginPoint()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondPoint, firstSegment.GetEndPoint()));
		
		Vector3D center = firstSegment.GetCenterPoint();
		Vector3D direction = firstSegment.GetDirection();
		double extent = firstSegment.GetExtent();

		Segment3D secondSegment(extent,center,direction);

		ASSERT_TRUE(Vector3ToolsD::Approximate(firstPoint,secondSegment.GetBeginPoint()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondPoint,secondSegment.GetEndPoint()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(center,secondSegment.GetCenterPoint()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(direction,secondSegment.GetDirection()));
		ASSERT_APPROXIMATE(extent,secondSegment.GetExtent(),1e-10);

	}
}


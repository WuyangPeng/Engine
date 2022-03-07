// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:09)

#include "Capsule3Testing.h"
#include "Mathematics/Objects3D/Capsule3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Capsule3<float>;
	template class Capsule3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Capsule3Testing) 

void Mathematics::Capsule3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CapsuleTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Capsule3Testing
	::CapsuleTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

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
		
		double radius(MathD::FAbs(firstRandomDistribution(generator)));

		Capsule3D capsule(firstSegment,radius);

		ASSERT_TRUE(Vector3ToolsD::Approximate(capsule.GetSegment().GetBeginPoint(),firstSegment.GetBeginPoint()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(capsule.GetSegment().GetEndPoint(),firstSegment.GetEndPoint()));
		ASSERT_APPROXIMATE(radius,capsule.GetRadius(),1e-10);
	}
}


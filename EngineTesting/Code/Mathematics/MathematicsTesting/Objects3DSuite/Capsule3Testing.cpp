// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:09)

#include "Capsule3Testing.h"
#include "Mathematics/Objects3D/Capsule3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
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

void Mathematics::Capsule3Testing
	::CapsuleTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

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
		
		double radius(DoubleMath::FAbs(firstRandomDistribution(generator)));

		DoubleCapsule3 capsule(firstSegment,radius);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(capsule.GetSegment().GetBeginPoint(),firstSegment.GetBeginPoint()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(capsule.GetSegment().GetEndPoint(),firstSegment.GetEndPoint()));
		ASSERT_APPROXIMATE(radius,capsule.GetRadius(),1e-10);
	}
}


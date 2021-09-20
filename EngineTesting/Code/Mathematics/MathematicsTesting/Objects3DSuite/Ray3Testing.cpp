// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:52)

#include "Ray3Testing.h"
#include "Mathematics/Objects3D/Ray3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Ray3<float>;
	template class Ray3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Ray3Testing) 

void Mathematics::Ray3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RayTest);
}

void Mathematics::Ray3Testing
	::RayTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D origin(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		DoubleVector3D direction(firstRandomDistribution(generator),
			                firstRandomDistribution(generator),
							firstRandomDistribution(generator));

		direction.Normalize();

		DoubleRay3 line(origin,direction);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(origin,line.GetOrigin()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(direction,line.GetDirection()));	
	}
}


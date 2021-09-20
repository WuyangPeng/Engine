// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:30)

#include "Line3Testing.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/Vector3DTools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Line3<float>;
	template class Line3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Line3Testing) 

void Mathematics::Line3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::Line3Testing
	::LineTest()
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

		DoubleLine3 line(origin,direction);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(origin,line.GetOrigin()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(direction,line.GetDirection()));	
	}
}


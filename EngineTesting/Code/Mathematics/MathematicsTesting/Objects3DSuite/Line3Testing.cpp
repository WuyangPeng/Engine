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
#include "Mathematics/Algebra/Vector3Tools.h"

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Line3Testing
	::LineTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D origin(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		Vector3D direction(firstRandomDistribution(generator),
			                firstRandomDistribution(generator),
							firstRandomDistribution(generator));

		direction.Normalize();

		Line3D line(origin,direction);

		ASSERT_TRUE(Vector3ToolsD::Approximate(origin,line.GetOrigin()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(direction,line.GetDirection()));	
	}
}


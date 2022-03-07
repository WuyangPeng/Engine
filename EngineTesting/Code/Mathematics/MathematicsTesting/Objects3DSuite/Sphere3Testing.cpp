// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:57)

#include "Sphere3Testing.h"
#include "Mathematics/Objects3D/Sphere3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Sphere3<float>;
	template class Sphere3<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Sphere3Testing) 

void Mathematics::Sphere3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SphereTest);
}

void Mathematics::Sphere3Testing
	::SphereTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		
		double radius(MathD::FAbs(firstRandomDistribution(generator)));

		Sphere3D circle(center,radius);

		ASSERT_TRUE(Vector3ToolsD::Approximate(center,circle.GetCenter()));
		ASSERT_APPROXIMATE(radius,circle.GetRadius(),1e-10);
	}
}


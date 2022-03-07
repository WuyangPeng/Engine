// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:10)

#include "Circle3Testing.h"
#include "Mathematics/Objects3D/Circle3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Circle3<float>;
	template class Circle3<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Circle3Testing) 

void Mathematics::Circle3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CircleTest);
}

void Mathematics::Circle3Testing
	::CircleTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));
		
		double radius(firstRandomDistribution(generator));

		Vector3D direction0(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		Vector3D direction1(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		Vector3D normal = Vector3ToolsD::CrossProduct(direction0,direction1);

		Vector3ToolsD::Vector3Orthonormalize orthonormalize =	Vector3ToolsD::Orthonormalize(direction0,direction1,normal);

		Circle3D circle(center, orthonormalize.GetUVector(),orthonormalize.GetVVector(),orthonormalize.GetWVector(),radius);

		ASSERT_TRUE(Vector3ToolsD::Approximate(center,circle.GetCenter()));
		ASSERT_APPROXIMATE(radius,circle.GetRadius(),1e-10);

		ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetUVector(),circle.GetDirection0()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetVVector(),circle.GetDirection1()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetWVector(),circle.GetNormal()));
	}
}


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:55)

#include "Cylinder3Testing.h"
#include "Mathematics/Objects3D/Cylinder3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Cylinder3<float>;
	template class Cylinder3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Cylinder3Testing) 

void Mathematics::Cylinder3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CylinderTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)

void Mathematics::Cylinder3Testing
	::CylinderTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ 0.0,100.0 };
	uniform_real<double> secondRandomDistribution(0.0, MathD::GetHalfPI()); 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D origin(firstRandomDistribution(generator), firstRandomDistribution(generator),  firstRandomDistribution(generator));

		Vector3D direction(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

		direction.Normalize();

		Line3D line(origin,direction);

		double radius(MathD::FAbs(secondRandomDistribution(generator)));

		double height(MathD::FAbs(firstRandomDistribution(generator)));

		Cylinder3D cylinder3(line,radius,height);

		ASSERT_TRUE(Vector3ToolsD::Approximate(cylinder3.GetAxis().GetOrigin(),origin));
		ASSERT_TRUE(Vector3ToolsD::Approximate(cylinder3.GetAxis().GetDirection(),direction));
		ASSERT_APPROXIMATE(cylinder3.GetRadius(),radius,1e-10);
		ASSERT_APPROXIMATE(cylinder3.GetHeight(),height,1e-10);		
	}
}


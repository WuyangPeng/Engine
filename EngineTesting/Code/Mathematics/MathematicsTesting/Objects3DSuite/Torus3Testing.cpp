// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 18:00)

#include "Torus3Testing.h"
#include "Mathematics/Objects3D/Torus3Detail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class Torus3<float>;
	template class Torus3<double>;
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Torus3Testing) 

void Mathematics::Torus3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(TorusTest);
}

void Mathematics::Torus3Testing
	::TorusTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(0.1, 100.0);
	uniform_real<double> secondRandomDistribution(0.0, 1.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		double innerRadius = firstRandomDistribution(generator);

		uniform_real<double> thirdRandomDistribution(innerRadius,105.0);

		double outerRadius = thirdRandomDistribution(generator);

		Torus3D torus(outerRadius,innerRadius);

		ASSERT_APPROXIMATE(outerRadius,torus.GetOuterRadius(),1e-10);
		ASSERT_APPROXIMATE(innerRadius,torus.GetInnerRadius(),1e-10);

		double t = secondRandomDistribution(generator);
		double s = secondRandomDistribution(generator);
	
		double radius = torus.GetOuterRadius() + torus.GetInnerRadius() * cos(MathD::GetTwoPI() * t);

		double x = radius * cos(MathD::GetTwoPI() * s);
		double y = radius * sin(MathD::GetTwoPI() * s);
		double z = torus.GetInnerRadius() * sin(MathD::GetTwoPI() * t);

		ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3D(x,y,z),torus.GetPosition(s,t)));

		Vector3D normal(x - torus.GetOuterRadius() * cos(MathD::GetTwoPI() * s),y - torus.GetOuterRadius() * sin(MathD::GetTwoPI() * s),z);
		normal.Normalize();

		ASSERT_TRUE(Vector3ToolsD::Approximate(normal,torus.GetNormal(s,t)));

		Torus3D::Torus3Parameters parameters = torus.GetParameters(Vector3D(x,y,z));

		ASSERT_APPROXIMATE(parameters.GetS(),s,1e-10);
		ASSERT_APPROXIMATE(parameters.GetT(),t,1e-10);
	}
}


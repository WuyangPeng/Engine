// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 18:00)

#include "Torus3Testing.h"
#include "Mathematics/Objects3D/Torus3Detail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

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

		DoubleTorus3 torus(outerRadius,innerRadius);

		ASSERT_APPROXIMATE(outerRadius,torus.GetOuterRadius(),1e-10);
		ASSERT_APPROXIMATE(innerRadius,torus.GetInnerRadius(),1e-10);

		double t = secondRandomDistribution(generator);
		double s = secondRandomDistribution(generator);
	
		double radius = torus.GetOuterRadius() + torus.GetInnerRadius() * cos(DoubleMath::GetTwoPI() * t);

		double x = radius * cos(DoubleMath::GetTwoPI() * s);
		double y = radius * sin(DoubleMath::GetTwoPI() * s);
		double z = torus.GetInnerRadius() * sin(DoubleMath::GetTwoPI() * t);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(DoubleVector3D(x,y,z),torus.GetPosition(s,t)));

		DoubleVector3D normal(x - torus.GetOuterRadius() * cos(DoubleMath::GetTwoPI() * s),y - torus.GetOuterRadius() * sin(DoubleMath::GetTwoPI() * s),z);
		normal.Normalize();

		ASSERT_TRUE(DoubleVector3DTools::Approximate(normal,torus.GetNormal(s,t)));

		DoubleTorus3::Torus3Parameters parameters = torus.GetParameters(DoubleVector3D(x,y,z));

		ASSERT_APPROXIMATE(parameters.GetS(),s,1e-10);
		ASSERT_APPROXIMATE(parameters.GetT(),t,1e-10);
	}
}


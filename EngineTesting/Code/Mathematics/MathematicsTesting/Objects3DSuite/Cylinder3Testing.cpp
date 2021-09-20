// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:55)

#include "Cylinder3Testing.h"
#include "Mathematics/Objects3D/Cylinder3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
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

void Mathematics::Cylinder3Testing
	::CylinderTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ 0.0,100.0 };
	uniform_real<double> secondRandomDistribution(0.0, DoubleMath::GetHalfPI()); 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D origin(firstRandomDistribution(generator), firstRandomDistribution(generator),  firstRandomDistribution(generator));

		DoubleVector3D direction(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

		direction.Normalize();

		DoubleLine3 line(origin,direction);

		double radius(DoubleMath::FAbs(secondRandomDistribution(generator)));

		double height(DoubleMath::FAbs(firstRandomDistribution(generator)));

		DoubleCylinder3 cylinder3(line,radius,height);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(cylinder3.GetAxis().GetOrigin(),origin));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(cylinder3.GetAxis().GetDirection(),direction));
		ASSERT_APPROXIMATE(cylinder3.GetRadius(),radius,1e-10);
		ASSERT_APPROXIMATE(cylinder3.GetHeight(),height,1e-10);		
	}
}


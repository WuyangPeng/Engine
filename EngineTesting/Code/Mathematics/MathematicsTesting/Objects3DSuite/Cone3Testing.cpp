// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:13)

#include "Cone3Testing.h"
#include "Mathematics/Objects3D/Cone3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Cone3<float>;
	template class Cone3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Cone3Testing) 

void Mathematics::Cone3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConeTest);
}

void Mathematics::Cone3Testing
	::ConeTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };
	uniform_real<double> secondRandomDistribution(0.0, DoubleMath::GetHalfPI());

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D vertex(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		DoubleVector3D axis(firstRandomDistribution(generator),
			           firstRandomDistribution(generator),
					   firstRandomDistribution(generator));

		axis.Normalize();

		double angle(secondRandomDistribution(generator));

		double height(DoubleMath::FAbs(firstRandomDistribution(generator)));

		DoubleCone3 cone(vertex,axis,angle,height);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(cone.GetVertex(),vertex));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(cone.GetAxis(),axis));
		ASSERT_APPROXIMATE(DoubleMath::Cos(angle),cone.GetCosAngle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::Sin(angle),cone.GetSinAngle(),1e-10);
		ASSERT_APPROXIMATE(height,cone.GetHeight(),1e-10);

		DoubleCone3 secondCone(DoubleMath::Cos(angle),DoubleMath::Sin(angle),height,vertex,axis);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondCone.GetVertex(),vertex));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondCone.GetAxis(),axis));
		ASSERT_APPROXIMATE(DoubleMath::Cos(angle),secondCone.GetCosAngle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::Sin(angle),secondCone.GetSinAngle(),1e-10);
		ASSERT_APPROXIMATE(height,secondCone.GetHeight(),1e-10);
	}
}


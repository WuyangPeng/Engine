// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:13)

#include "Cone3Testing.h"
#include "Mathematics/Objects3D/Cone3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Cone3Testing
	::ConeTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };
	uniform_real<double> secondRandomDistribution(0.0, MathD::GetHalfPI());

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D vertex(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		Vector3D axis(firstRandomDistribution(generator),
			           firstRandomDistribution(generator),
					   firstRandomDistribution(generator));

		axis.Normalize();

		double angle(secondRandomDistribution(generator));

		double height(MathD::FAbs(firstRandomDistribution(generator)));

		Cone3D cone(vertex,axis,angle,height);

		ASSERT_TRUE(Vector3ToolsD::Approximate(cone.GetVertex(),vertex));
		ASSERT_TRUE(Vector3ToolsD::Approximate(cone.GetAxis(),axis));
		ASSERT_APPROXIMATE(MathD::Cos(angle),cone.GetCosAngle(),1e-10);
		ASSERT_APPROXIMATE(MathD::Sin(angle),cone.GetSinAngle(),1e-10);
		ASSERT_APPROXIMATE(height,cone.GetHeight(),1e-10);

		Cone3D secondCone(MathD::Cos(angle),MathD::Sin(angle),height,vertex,axis);

		ASSERT_TRUE(Vector3ToolsD::Approximate(secondCone.GetVertex(),vertex));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondCone.GetAxis(),axis));
		ASSERT_APPROXIMATE(MathD::Cos(angle),secondCone.GetCosAngle(),1e-10);
		ASSERT_APPROXIMATE(MathD::Sin(angle),secondCone.GetSinAngle(),1e-10);
		ASSERT_APPROXIMATE(height,secondCone.GetHeight(),1e-10);
	}
}


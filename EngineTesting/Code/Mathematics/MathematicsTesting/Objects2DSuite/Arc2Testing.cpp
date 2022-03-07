// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:02)

#include "Arc2Testing.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Arc2<float>;
	template class Arc2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Arc2Testing) 

void Mathematics::Arc2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(Arc2Test);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Arc2Testing
	::Arc2Test()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };
	uniform_real<double> secondRandomDistribution{ 0.0,MathD::GetTwoPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 center(firstRandomDistribution(generator),firstRandomDistribution(generator));

		double radius(MathD::FAbs(firstRandomDistribution(generator)));

		double firstAngle(secondRandomDistribution(generator));

		Vector2 end0(center[0] + radius * MathD::Cos(firstAngle),
			           center[1] + radius * MathD::Sin(firstAngle));

		uniform_real<double> thirdRandomDistribution(firstAngle,MathD::GetTwoPI());

		double secondAngle(thirdRandomDistribution(generator));

		Vector2 end1(center[0] + radius * MathD::Cos(secondAngle),center[1] + radius * MathD::Sin(secondAngle));

		Arc2D arc2(center,radius,end0,end1);

		ASSERT_TRUE(Vector2ToolsD::Approximate(center,arc2.GetCenter()));
		ASSERT_TRUE(Vector2ToolsD::Approximate(end0,arc2.GetEnd0()));
		ASSERT_TRUE(Vector2ToolsD::Approximate(end1,arc2.GetEnd1()));
		ASSERT_APPROXIMATE(arc2.GetRadius(),radius,1e-10);

		double thirdAngle(secondRandomDistribution(generator));

		Vector2 point(center[0] + radius * MathD::Cos(thirdAngle),center[1] + radius * MathD::Sin(thirdAngle));

		if(firstAngle <= thirdAngle && thirdAngle <= secondAngle)
		{
			ASSERT_TRUE(arc2.Contains(point));
		}
		else
		{
			ASSERT_FALSE(arc2.Contains(point));
		}
	}
}


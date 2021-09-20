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

void Mathematics::Arc2Testing
	::Arc2Test()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };
	uniform_real<double> secondRandomDistribution{ 0.0,DoubleMath::GetTwoPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D center(firstRandomDistribution(generator),firstRandomDistribution(generator));

		double radius(DoubleMath::FAbs(firstRandomDistribution(generator)));

		double firstAngle(secondRandomDistribution(generator));

		DoubleVector2D end0(center[0] + radius * DoubleMath::Cos(firstAngle),
			           center[1] + radius * DoubleMath::Sin(firstAngle));

		uniform_real<double> thirdRandomDistribution(firstAngle,DoubleMath::GetTwoPI());

		double secondAngle(thirdRandomDistribution(generator));

		DoubleVector2D end1(center[0] + radius * DoubleMath::Cos(secondAngle),center[1] + radius * DoubleMath::Sin(secondAngle));

		DoubleArc2 arc2(center,radius,end0,end1);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(center,arc2.GetCenter()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(end0,arc2.GetEnd0()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(end1,arc2.GetEnd1()));
		ASSERT_APPROXIMATE(arc2.GetRadius(),radius,1e-10);

		double thirdAngle(secondRandomDistribution(generator));

		DoubleVector2D point(center[0] + radius * DoubleMath::Cos(thirdAngle),center[1] + radius * DoubleMath::Sin(thirdAngle));

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


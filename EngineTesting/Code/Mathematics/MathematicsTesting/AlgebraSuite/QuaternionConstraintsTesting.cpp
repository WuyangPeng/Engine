// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 09:38)

#include "QuaternionConstraintsTesting.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/QuaternionConstraintsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <random> 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class QuaternionConstraints<float>;
	template class QuaternionConstraints<double>;
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,QuaternionConstraintsTesting) 

void Mathematics::QuaternionConstraintsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstraintsTest);
}

void Mathematics::QuaternionConstraintsTesting
	::ConstraintsTest()
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -MathF::GetHalfPI(),MathF::GetHalfPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		float firstAngle = firstRandomDistribution(generator);

		uniform_real<float> secondRandomDistribution(firstAngle,MathF::GetHalfPI());

		float secondAngle = secondRandomDistribution(generator);

		QuaternionConstraintsF firstQuaternionConstraints(firstAngle,secondAngle);

		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetCosMinAngle(),MathF::Cos(firstAngle),1e-8f);
		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetSinMinAngle(), MathF::Sin(firstAngle),1e-8f);
		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetCosMaxAngle(),MathF::Cos(secondAngle),1e-8f);
		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetSinMaxAngle(),MathF::Sin(secondAngle),1e-8f);
		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetMinAngle(),firstAngle,1e-8f);
		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetMaxAngle(),secondAngle,1e-8f);

		float avrAngle(0.5f * (firstAngle + secondAngle));

		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetCosAvrAngle(),MathF::Cos(avrAngle),1e-8f);
		ASSERT_APPROXIMATE(firstQuaternionConstraints.GetSinAvrAngle(),MathF::Sin(avrAngle),1e-8f);

		uniform_real<float> thirdRandomDistribution(-100.0f,100.0f);

		Vector2F firstVector(thirdRandomDistribution(generator),thirdRandomDistribution(generator));

		firstVector.Normalize();

		float angle = MathF::ATan(firstVector[1] / firstVector[0]);		

		if(firstAngle <= angle && angle <= secondAngle)
		{
			ASSERT_TRUE(firstQuaternionConstraints.IsValid(firstVector[0],firstVector[1]));
		}
		else
		{
			ASSERT_FALSE(firstQuaternionConstraints.IsValid(firstVector[0],firstVector[1]));
		}
	}
}


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 09:59)

#include "QuaternionSwingTwistTesting.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/QuaternionDetail.h"
#include "Mathematics/Algebra/QuaternionSwingTwistDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class QuaternionSwingTwist<float>;
	template class QuaternionSwingTwist<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,QuaternionSwingTwistTesting) 

void Mathematics::QuaternionSwingTwistTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(QuaternionSwingTwistTest); 
}

void Mathematics::QuaternionSwingTwistTesting
	::QuaternionSwingTwistTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -10.0,10.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstVector(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator));

		firstVector.Normalize();

		DoubleQuaternion firstQuaternion(randomDistribution(generator),
			                        randomDistribution(generator),
									randomDistribution(generator),
									randomDistribution(generator));

		firstQuaternion.Normalize();

		DoubleQuaternion::QuaternionSwingTwist quaternionSwingTwist = firstQuaternion.DecomposeTwistTimesSwing(firstVector,1e-10);

		DoubleQuaternion  secondQuaternion = quaternionSwingTwist.GetTwist() * quaternionSwingTwist.GetSwing();

		ASSERT_TRUE(Approximate(firstQuaternion, secondQuaternion,1e-10)); 

		quaternionSwingTwist =	firstQuaternion.DecomposeSwingTimesTwist(firstVector,1e-10);

		secondQuaternion = quaternionSwingTwist.GetSwing() * quaternionSwingTwist.GetTwist();

		ASSERT_TRUE(Approximate(firstQuaternion, secondQuaternion,1e-10)); 		 	
	}	
}


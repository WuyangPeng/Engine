// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:21)

#include "Frustum3Testing.h"
#include "Mathematics/Objects3D/Frustum3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Frustum3<float>;
	template class Frustum3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Frustum3Testing) 

void Mathematics::Frustum3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FrustumTest);
}

void Mathematics::Frustum3Testing
	::FrustumTest()
{
	default_random_engine generator{};
 
	uniform_real<double> firstRandomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D origin(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		DoubleVector3D firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		DoubleVector3D secondVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		DoubleVector3D thirdVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		double directionMin = DoubleMath::FAbs(firstRandomDistribution(generator));
		double directionMax = directionMin + DoubleMath::FAbs(firstRandomDistribution(generator));

		double upBound = DoubleVector3DTools::VectorMagnitude(firstVector);
		double rightBound = DoubleVector3DTools::VectorMagnitude(secondVector);

		DoubleVector3DTools::Vector3DOrthonormalize orthonormalize = DoubleVector3DTools::Orthonormalize(firstVector,secondVector,thirdVector,1e-10);

		DoubleFrustum3 frustum(origin, orthonormalize.GetUVector(),orthonormalize.GetVVector(), orthonormalize.GetWVector(),
						  directionMin,directionMax,upBound,rightBound);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(origin,frustum.GetOrigin()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(orthonormalize.GetUVector(),frustum.GetDirectionVector()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(orthonormalize.GetVVector(),frustum.GetUpVector()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(orthonormalize.GetWVector(),frustum.GetRightVector()));
	    ASSERT_APPROXIMATE(directionMin,frustum.GetDirectionMin(),1e-10);
		ASSERT_APPROXIMATE(directionMax,frustum.GetDirectionMax(),1e-10);
		ASSERT_APPROXIMATE(upBound,frustum.GetUpBound(),1e-10);
		ASSERT_APPROXIMATE(rightBound,frustum.GetRightBound(),1e-10);

		ASSERT_APPROXIMATE(directionMax / directionMin,frustum.GetDirectionRatio(),1e-10);
		ASSERT_APPROXIMATE(-2.0 * upBound * directionMax,frustum.GetMTwoUF(),1e-10);
		ASSERT_APPROXIMATE(-2.0 * rightBound * directionMax,frustum.GetMTwoRF(),1e-10);

		vector<DoubleVector3D> vertex = frustum.ComputeVertices();

		DoubleVector3D directionScaled = frustum.GetDirectionMin() * frustum.GetDirectionVector();
		DoubleVector3D upScaled = frustum.GetUpBound() * frustum.GetUpVector();
		DoubleVector3D rightScaled = frustum.GetRightBound() * frustum.GetRightVector();

		ASSERT_TRUE(DoubleVector3DTools::Approximate(directionScaled - upScaled - rightScaled + frustum.GetOrigin(),vertex[0]));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(directionScaled - upScaled + rightScaled + frustum.GetOrigin(),vertex[1]));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(directionScaled + upScaled + rightScaled + frustum.GetOrigin(),vertex[2]));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(directionScaled + upScaled - rightScaled + frustum.GetOrigin(),vertex[3]));

		ASSERT_TRUE(DoubleVector3DTools::Approximate((vertex[0] - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(),vertex[4],1e-10));
		ASSERT_TRUE(DoubleVector3DTools::Approximate((vertex[1] - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(),vertex[5],1e-10));
		ASSERT_TRUE(DoubleVector3DTools::Approximate((vertex[2] - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(), vertex[6],1e-10));
		ASSERT_TRUE(DoubleVector3DTools::Approximate((vertex[3] - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(),vertex[7],1e-10));
	}
}


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 13:10)

#include "DistancePoint3Segment3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Segment3Detail.h"

#include <random>

using std::swap;

namespace Mathematics
{
	template class DistancePoint3Segment3<float>;
	template class DistancePoint3Segment3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistancePoint3Segment3Testing) 

void Mathematics::DistancePoint3Segment3Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistancePoint3Segment3Testing
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		
		FloatVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		FloatVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		float rhsExtent = FloatMath::FAbs(randomDistribution(generator));

		FloatDistancePoint3Segment3 distance(point, FloatSegment3(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

		ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, distance.GetPoint(), point, 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, distance.GetSegment(), FloatSegment3(rhsExtent,rhsOrigin, rhsDirection,1e-5f), 1e-8f);
	}
}

void Mathematics::DistancePoint3Segment3Testing
	::StaticTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistancePoint3Segment3 distance(point, DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));
			 
		DoubleDistanceResult3 squaredResult = distance.GetSquared();
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(point - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), point, 1e-8);
		
		DoubleVector3D rhsDifference = rhsOrigin - squaredResult.GetRhsClosestPoint();
		if (!rhsDifference.IsZero())
		{
			ASSERT_TRUE(DoubleVector3DTools::VectorMagnitude(rhsDifference) <= rhsExtent + 1e-10);			
			rhsDifference.Normalize();
			ASSERT_TRUE(DoubleVector3DTools::Approximate(rhsDifference, -rhsDirection, 1e-10) ||
				        DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-10) );
		}		

		DoubleDistanceResult3 result = distance.Get();
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(point - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
	}
}

void Mathematics::DistancePoint3Segment3Testing
	::DynamicTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{

		DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistancePoint3Segment3 distance(point, DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));


		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		 DoubleDistanceResult3 squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), point + t * lhsVelocity, 1e-8);
		
		DoubleVector3D rhsDifference = rhsOrigin + t * rhsVelocity - squaredResult.GetRhsClosestPoint();
		if (!rhsDifference.IsZero())
		{
			ASSERT_TRUE(DoubleVector3DTools::VectorMagnitude(rhsDifference) <= rhsExtent + 1e-10);
			rhsDifference.Normalize();
			ASSERT_TRUE(DoubleVector3DTools::Approximate(rhsDifference, -rhsDirection, 1e-10) ||
				        DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-10) );
		}

		DoubleDistanceResult3 result = distance.Get(t,lhsVelocity,rhsVelocity);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
	
	}
}

void Mathematics::DistancePoint3Segment3Testing
	::DerivativeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistancePoint3Segment3 distance(point, DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));


		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();		
 
		DoubleDistanceResult3 funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		DoubleDistanceResult3 funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		double derivativeApproximation =
			0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

		double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

		double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);
		
		DoubleDistanceResult3 distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
	}
}

void Mathematics::DistancePoint3Segment3Testing
	::IntervalTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistancePoint3Segment3 distance(point, DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));

		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		double tMin = DoubleMath::FAbs(randomDistribution(generator));
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		if (tMax < tMin)
		{
			swap(tMin, tMax);
		}

		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();		

		DoubleDistanceResult3 squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult3 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-4);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult3 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult3 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-5);		
			ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
		}			
	}
}
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 11:44)

#include "DistancePoint2Hyperbola2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Hyperbola2Detail.h"

#include <random> 

using std::swap;
using std::uniform_real;
using std::default_random_engine; 

namespace Mathematics
{
	template class DistancePoint2Hyperbola2<float>;
	template class DistancePoint2Hyperbola2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistancePoint2Hyperbola2Testing) 

void Mathematics::DistancePoint2Hyperbola2Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistancePoint2Hyperbola2Testing
	::BaseTest()
{
	default_random_engine generator;
	uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector2D point(randomDistribution(generator), randomDistribution(generator));
		
		FloatVector2D extent(FloatMath::FAbs(randomDistribution(generator)), 
			             FloatMath::FAbs(randomDistribution(generator)));

		FloatDistancePoint2Hyperbola2 distance(point, extent);

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

		ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, distance.GetPoint(), point, 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector2DTools::Approximate, distance.GetExtent(), extent, 1e-8f);
	}
}

void Mathematics::DistancePoint2Hyperbola2Testing
	::StaticTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D point(randomDistribution(generator), randomDistribution(generator));
		
		DoubleVector2D extent(DoubleMath::FAbs(randomDistribution(generator)), 
			             DoubleMath::FAbs(randomDistribution(generator)));

		DoubleDistancePoint2Hyperbola2 distance(point, extent);
			 
		DoubleDistanceResult2 squaredResult = distance.GetSquared();
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector2DTools::VectorMagnitudeSquared(point - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), point, 1e-8); 

		DoubleDistanceResult2 result = distance.Get();
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(point - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
	}
}

void Mathematics::DistancePoint2Hyperbola2Testing
	::DynamicTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D point(randomDistribution(generator), randomDistribution(generator));
		
		DoubleVector2D extent(DoubleMath::FAbs(randomDistribution(generator)), 
			             DoubleMath::FAbs(randomDistribution(generator)));

		DoubleDistancePoint2Hyperbola2 distance(point, extent);

		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		 DoubleDistanceResult2 squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector2DTools::VectorMagnitudeSquared(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), point + t * lhsVelocity, 1e-8);	 

		DoubleDistanceResult2 result = distance.Get(t,lhsVelocity,rhsVelocity);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);	
	}
}

void Mathematics::DistancePoint2Hyperbola2Testing
	::DerivativeTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D point(randomDistribution(generator), randomDistribution(generator));
		
		DoubleVector2D extent(DoubleMath::FAbs(randomDistribution(generator)), 
			             DoubleMath::FAbs(randomDistribution(generator)));

		DoubleDistancePoint2Hyperbola2 distance(point, extent);

		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();		
 
		DoubleDistanceResult2 funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		DoubleDistanceResult2 funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		double derivativeApproximation =
			0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

		double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

		double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);
		
		DoubleDistanceResult2 distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
 	}
}

void Mathematics::DistancePoint2Hyperbola2Testing
	::IntervalTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D point(randomDistribution(generator), randomDistribution(generator));
		
		DoubleVector2D extent(DoubleMath::FAbs(randomDistribution(generator)), 
			             DoubleMath::FAbs(randomDistribution(generator)));

		DoubleDistancePoint2Hyperbola2 distance(point, extent);
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		double tMin = DoubleMath::FAbs(randomDistribution(generator));
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		if (tMax < tMin)
		{
			swap(tMin, tMax);
		}

		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity;		

		DoubleDistanceResult2 squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult2 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-4);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult2 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult2 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_LESS_EQUAL(result.GetDistance() , tResult.GetDistance() + 1e-4);		
			ASSERT_LESS_EQUAL(squaredResult.GetDistance() , tResultSquared.GetDistance() + 1e-3);
		}	 	
	}
}
 
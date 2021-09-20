// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/30 11:20)

#include "DistanceLine2Ray2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Line2Detail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Ray2Detail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"
#include <random> 

using std::swap;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class DistanceLine2Ray2<float>;
	template class DistanceLine2Ray2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceLine2Ray2Testing) 

void Mathematics::DistanceLine2Ray2Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistanceLine2Ray2Testing
	::BaseTest()
{
	default_random_engine generator;
	uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		FloatVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		FloatVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		FloatVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		FloatDistanceLine2Ray2 distance(FloatLine2(lhsOrigin, lhsDirection), FloatRay2(rhsOrigin, rhsDirection));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

		typedef bool(*RayApproximateFunction)(const FloatRay2& lhs, const FloatRay2& rhs, const float epsilon);
		RayApproximateFunction rayApproximate = Approximate<float>;
		typedef bool(*LineApproximateFunction)(const FloatLine2& lhs, const FloatLine2& rhs, const float epsilon);
		LineApproximateFunction lineApproximate = Approximate<float>;

		ASSERT_APPROXIMATE_USE_FUNCTION(lineApproximate, distance.GetLine(), FloatLine2(lhsOrigin, lhsDirection), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(rayApproximate, distance.GetRay(), FloatRay2(rhsOrigin, rhsDirection), 1e-8f);
	}
}

void Mathematics::DistanceLine2Ray2Testing
	::StaticTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		DoubleDistanceLine2Ray2 distance(DoubleLine2(lhsOrigin, lhsDirection), DoubleRay2(rhsOrigin, rhsDirection));
	 
		DoubleDistanceResult2 squaredResult = distance.GetSquared();
		DoubleDistanceResult2 result = distance.Get();		

		DoubleDistanceLine2Line2 lineDistance(DoubleLine2(lhsOrigin, lhsDirection), DoubleLine2(rhsOrigin,rhsDirection));
		DoubleDistanceResult2 lineSquaredResult = lineDistance.GetSquared();

		DoubleVector2D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin;
		lhsDifference.Normalize();
		DoubleVector2D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;
		rhsDifference.Normalize();

		if(DoubleVector2DTools::Approximate(rhsDifference,rhsDirection,1e-8))
		{
			// 最小值为射线内部点。
			DoubleVector2D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
			rhsDifference2.Normalize();

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, rhsDifference2,rhsDirection, 1e-8);
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else
		{			
			// 最小值为射线的原点到直线
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
					           DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - rhsOrigin), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector2DTools::VectorMagnitudeSquared(lhsOrigin - rhsOrigin));		
			ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin));
			ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin));		
			
		}		
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceLine2Ray2 firstEqualDistance(DoubleLine2(lhsOrigin, lhsDirection), DoubleRay2(lhsOrigin + lhsDirection, lhsDirection));
				 
		squaredResult = firstEqualDistance.GetSquared();
		result = firstEqualDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
		ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);

		DoubleDistanceLine2Ray2 firstParallelDistance(DoubleLine2(lhsOrigin, lhsDirection), DoubleRay2(rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared();
		result = firstParallelDistance.Get();		
		double rhsDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(rhsOrigin - squaredResult.GetLhsClosestPoint());
		
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(rhsDistanceSquared), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);		
	}
}

void Mathematics::DistanceLine2Ray2Testing
	::DynamicTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();		 

		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleDistanceLine2Ray2 distance(DoubleLine2(lhsOrigin, lhsDirection), DoubleRay2(rhsOrigin, rhsDirection));
	 
		DoubleDistanceResult2 squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		DoubleDistanceResult2 result = distance.Get(t, lhsVelocity, rhsVelocity);

		DoubleDistanceLine2Line2 lineDistance(DoubleLine2(lhsOrigin, lhsDirection), DoubleLine2(rhsOrigin,rhsDirection));
		DoubleDistanceResult2 lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

		DoubleVector2D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin - t * lhsVelocity;
		lhsDifference.Normalize();
		DoubleVector2D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
		rhsDifference.Normalize();

		if(DoubleVector2DTools::Approximate(rhsDifference,rhsDirection,1e-8))
		{
			// 最小值为射线内部点。
			DoubleVector2D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
			rhsDifference2.Normalize();

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, rhsDifference2,rhsDirection, 1e-8);
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else
		{			
			// 最小值为射线的原点到直线
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
					           DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin - t * rhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - rhsOrigin - t * rhsVelocity), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector2DTools::VectorMagnitudeSquared(lhsOrigin + t * lhsVelocity - rhsOrigin - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin - t * rhsVelocity));
			
		}		
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceLine2Ray2 firstParallelDistance(DoubleLine2(lhsOrigin, lhsDirection), DoubleRay2(rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
		result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);
		double rhsDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(rhsOrigin + t * rhsVelocity - squaredResult.GetLhsClosestPoint());
		
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(rhsDistanceSquared), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);
	}
}

void Mathematics::DistanceLine2Ray2Testing
	::DerivativeTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		DoubleDistanceLine2Ray2 distance(DoubleLine2(lhsOrigin, lhsDirection), DoubleRay2(rhsOrigin, rhsDirection));

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

void Mathematics::DistanceLine2Ray2Testing
	::IntervalTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double tMin = DoubleMath::FAbs(randomDistribution(generator));
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		if (tMax < tMin)
		{
			swap(tMin, tMax);
		}

		DoubleDistanceLine2Ray2 distance(DoubleLine2(lhsOrigin, lhsDirection), DoubleRay2(rhsOrigin, rhsDirection));
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();			

		DoubleDistanceResult2 squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult2 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-7);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-2);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-2);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-3);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult2 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult2 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());		
			ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
		}	
	}
}
 
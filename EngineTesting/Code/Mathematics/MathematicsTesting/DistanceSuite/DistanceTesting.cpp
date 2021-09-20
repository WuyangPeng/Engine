// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/29 18:02)

#include "DistanceTesting.h"
#include "Detail/DistanceTestDetail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"

#include <random> 

using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class DistanceTest<float, FloatVector2D>;
	template class DistanceTest<double, DoubleVector2D>;
	template class DistanceTest<float, FloatVector3D>;
	template class DistanceTest<double, DoubleVector3D>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceTesting) 

void Mathematics::DistanceTesting
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
	ASSERT_NOT_THROW_EXCEPTION_0(BeginIntervalTest);
	ASSERT_NOT_THROW_EXCEPTION_0(EndIntervalTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IterationIntervalTest);
}

void Mathematics::DistanceTesting
	::BaseTest()
{
	default_random_engine generator;
	uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DistanceTest<float, FloatVector2D> distance(FloatVector2D(randomDistribution(generator), randomDistribution(generator)),FloatVector2D(randomDistribution(generator), randomDistribution(generator)));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);
	}
}

void Mathematics::DistanceTesting
	::StaticTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DistanceTest<double, DoubleVector2D> distance(DoubleVector2D(randomDistribution(generator), randomDistribution(generator)),
			                                     DoubleVector2D(randomDistribution(generator), randomDistribution(generator)));

		double distanceSquared = DoubleVector2DTools::DistanceSquared(distance.GetLhs(), distance.GetRhs());

		DoubleDistanceResult2 squaredResult = distance.GetSquared();
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), distanceSquared, 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhs(), 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhs(), 1e-10);

		DoubleDistanceResult2 result = distance.Get();
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(distanceSquared), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), distance.GetLhs(), 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetRhsClosestPoint(), distance.GetRhs(), 1e-10);
	}
}

void Mathematics::DistanceTesting
	::DynamicTest()
{
	default_random_engine generator;
	uniform_real<float> randomDistribution(-10.0f, 10.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DistanceTest<float, FloatVector3D> distance(FloatVector3D(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)),
			                                    FloatVector3D(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)));

		float t = FloatMath::FAbs(randomDistribution(generator));
		FloatVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		FloatVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		double distanceSquared = DoubleVector3DTools::DistanceSquared(distance.GetLhs() + lhsVelocity * t,distance.GetRhs() + rhsVelocity * t);

		FloatDistanceResult3 squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), distanceSquared, 1e-4f);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhs() + lhsVelocity * t, 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhs() + rhsVelocity * t, 1e-8f);

		FloatDistanceResult3 result = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(distanceSquared), 1e-5f);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), distance.GetLhs() + lhsVelocity * t, 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), distance.GetRhs() + rhsVelocity * t, 1e-8f);
	}
}

void Mathematics::DistanceTesting
	::DerivativeTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DistanceTest<double, DoubleVector3D> distance(DoubleVector3D(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)),
			                                     DoubleVector3D(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)));

		DoubleDistanceResult3 funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		DoubleDistanceResult3 funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		double derivativeApproximation = 0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

		double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

		double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);
		
		DoubleDistanceResult3 distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
	}
}

void Mathematics::DistanceTesting
	::IntervalTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DistanceTest<double, DoubleVector2D> distance(DoubleVector2D(randomDistribution(generator), randomDistribution(generator)),
			                                     DoubleVector2D(randomDistribution(generator), randomDistribution(generator)));
		distance.SetMaximumIterations(10);

		double tMin = DoubleMath::FAbs(randomDistribution(generator));
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		if(tMax < tMin)
		{
			swap(tMin,tMax);
		}

		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleDistanceResult2 resultSquared = distance.GetIntervalSquared(tMin,tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult2 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-4);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-1);		 
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetLhsClosestPoint(), result.GetLhsClosestPoint(),1e-2);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetRhsClosestPoint(), result.GetRhsClosestPoint(),1e-1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult2 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult2 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_LESS_EQUAL(result.GetDistance() , tResult.GetDistance() + 0.0001);		
			ASSERT_LESS_EQUAL(resultSquared.GetDistance() , tResultSquared.GetDistance());
		}

	}
}

void Mathematics::DistanceTesting
	::BeginIntervalTest()
{
	// 测试距离为有效值零。对象是在最初位置接触。
	default_random_engine generator;
	uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

		DistanceTest<double, DoubleVector3D> distance(point,point);
	
		double tMin = 0.0;
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
	
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleDistanceResult3 resultSquared = distance.GetIntervalSquared(tMin,tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult3 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(0.0, result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(DoubleMath::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(0.0, result.GetContactTime(), 1e-10);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);		 
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            point,1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetRhsClosestPoint(),
			                            point,1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-10);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult3 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult3 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());		
			ASSERT_TRUE(resultSquared.GetDistance() <= tResultSquared.GetDistance());		
		}
	}
}

void Mathematics::DistanceTesting
	::EndIntervalTest()
{
	// 测试距离为有效值零。对象是在最终位置接触。
	default_random_engine generator;
	uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		double tMin = DoubleMath::FAbs(randomDistribution(generator));
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		if(tMax < tMin)
		{
			swap(tMin,tMax);
		}

		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

		DistanceTest<double, DoubleVector3D> distance(point - tMax * lhsVelocity,point - tMax * rhsVelocity);		

		DoubleDistanceResult3 resultSquared = distance.GetIntervalSquared(tMin,tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult3 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(0.0, result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(DoubleMath::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(tMax, result.GetContactTime(), 1e-10);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);		 
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            point,1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetRhsClosestPoint(),
			                            point,1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-10);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult3 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult3 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());		
			ASSERT_TRUE(resultSquared.GetDistance() <= tResultSquared.GetDistance());		
		}
	}
}

void Mathematics::DistanceTesting
	::IterationIntervalTest()
{
	// 测试牛顿法过程中返回的情况
	default_random_engine generator;
	uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		double tMin = 0.0;
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

		DistanceTest<double, DoubleVector3D> distance(point - tMax / 2.0 * lhsVelocity,point - tMax / 2.0 * rhsVelocity);		
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		DoubleDistanceResult3 resultSquared = distance.GetIntervalSquared(tMin,tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult3 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(0.0, result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(DoubleMath::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(tMax / 2.0, result.GetContactTime(), 1e-10);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-1);		 
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,result.GetLhsClosestPoint(),point,1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetLhsClosestPoint(),result.GetLhsClosestPoint(),1e-2);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,result.GetRhsClosestPoint(),point,1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate,resultSquared.GetRhsClosestPoint(),result.GetRhsClosestPoint(),1e-2);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult3 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult3 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());		
			ASSERT_TRUE(resultSquared.GetDistance() <= tResultSquared.GetDistance());		
		}
	}
}
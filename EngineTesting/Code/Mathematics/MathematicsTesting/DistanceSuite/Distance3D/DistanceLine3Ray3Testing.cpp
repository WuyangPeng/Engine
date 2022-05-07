// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 13:08)

#include "DistanceLine3Ray3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3Toolsdetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Ray3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"
#include <random>

using std::swap;
#include SYSTEM_WARNING_DISABLE(26496)
namespace Mathematics
{
	template class DistanceLine3Ray3<float>;
	template class DistanceLine3Ray3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceLine3Ray3Testing) 

void Mathematics::DistanceLine3Ray3Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistanceLine3Ray3Testing
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3F lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3F lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector3F rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3F rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		DistanceLine3Ray3F distance(Line3F(lhsOrigin, lhsDirection), Ray3F(rhsOrigin, rhsDirection));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(MathF::epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

		typedef bool(*RayApproximateFunction)(const Ray3F& lhs, const Ray3F& rhs, const float epsilon);
		RayApproximateFunction rayApproximate = Approximate<float>;
		typedef bool(*LineApproximateFunction)(const Line3F& lhs, const Line3F& rhs, const float epsilon);
		LineApproximateFunction lineApproximate = Approximate<float>;

		ASSERT_APPROXIMATE_USE_FUNCTION(lineApproximate, distance.GetLine(), Line3F(lhsOrigin, lhsDirection), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(rayApproximate, distance.GetRay(), Ray3F(rhsOrigin, rhsDirection), 1e-8f);
	}
}

void Mathematics::DistanceLine3Ray3Testing
	::StaticTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		DistanceLine3Ray3D distance(Line3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));
	 
		DistanceResult3D squaredResult = distance.GetSquared();
		DistanceResult3D result = distance.Get();		

		DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin,rhsDirection));
		DistanceResult3D lineSquaredResult = lineDistance.GetSquared();

		Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin;
		lhsDifference.Normalize();
		Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;
		rhsDifference.Normalize();

		if(Vector3ToolsD::Approximate(rhsDifference,rhsDirection,1e-8))
		{
			// ��СֵΪ�����ڲ��㡣
			Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
			rhsDifference2.Normalize();

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference2,rhsDirection, 1e-8);
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(),squaredResult.GetRhsClosestPoint()), 1e-8);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else
		{			
			// ��СֵΪ���ߵ�ԭ�㵽ֱ��
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
					           Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - rhsOrigin), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin - rhsOrigin));		
			ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin));
			ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin));		
			
		}		
		
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DistanceLine3Ray3D firstEqualDistance(Line3D(lhsOrigin, lhsDirection), Ray3D(lhsOrigin + lhsDirection, lhsDirection));
				 
		squaredResult = firstEqualDistance.GetSquared();
		result = firstEqualDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
		ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);

		DistanceLine3Ray3D firstParallelDistance(Line3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared();
		result = firstParallelDistance.Get();		
		double rhsDistanceSquared = Vector3ToolsD::GetLengthSquared(rhsOrigin - squaredResult.GetLhsClosestPoint());
		
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
		ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(rhsDistanceSquared), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);		
	}
}

void Mathematics::DistanceLine3Ray3Testing
	::DynamicTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();		 

		double t = MathD::FAbs(randomDistribution(generator));
		Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DistanceLine3Ray3D distance(Line3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));
	 
		DistanceResult3D squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		DistanceResult3D result = distance.Get(t, lhsVelocity, rhsVelocity);

		DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin,rhsDirection));
		DistanceResult3D lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

		Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin - t * lhsVelocity;
		lhsDifference.Normalize();
		Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
		rhsDifference.Normalize();

		if(Vector3ToolsD::Approximate(rhsDifference,rhsDirection,1e-8))
		{
			// ��СֵΪ�����ڲ��㡣
			Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
			rhsDifference2.Normalize();

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference2,rhsDirection, 1e-8);
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-9);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else
		{			
			// ��СֵΪ���ߵ�ԭ�㵽ֱ��
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
					           Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin - t * rhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - rhsOrigin - t * rhsVelocity), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin + t * lhsVelocity - rhsOrigin - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin - t * rhsVelocity));
			
		}		
		
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DistanceLine3Ray3D firstParallelDistance(Line3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
		result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);
		double rhsDistanceSquared = Vector3ToolsD::GetLengthSquared(rhsOrigin + t * rhsVelocity - squaredResult.GetLhsClosestPoint());
		
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);
		ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(rhsDistanceSquared), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);
	}
}

void Mathematics::DistanceLine3Ray3Testing
	::DerivativeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		DistanceLine3Ray3D distance(Line3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));

		double t = MathD::FAbs(randomDistribution(generator));
		Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();		
 
		DistanceResult3D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		DistanceResult3D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		double derivativeApproximation = 0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

		double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

		double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);
		
		DistanceResult3D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
	}
}

void Mathematics::DistanceLine3Ray3Testing
	::IntervalTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double tMin = MathD::FAbs(randomDistribution(generator));
		double tMax = MathD::FAbs(randomDistribution(generator));
		if (tMax < tMin)
		{
			swap(tMin, tMax);
		}

		DistanceLine3Ray3D distance(Line3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();			

		DistanceResult3D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DistanceResult3D result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate,squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());		
			ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
		}	
	}
}
 
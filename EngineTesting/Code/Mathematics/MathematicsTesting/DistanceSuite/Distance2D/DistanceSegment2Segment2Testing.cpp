// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/30 12:54)

#include "DistanceSegment2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Line2Detail.h"
#include "Mathematics/Distance/Distance2D/DistanceSegment2Segment2Detail.h"

#include <random>

using std::swap;

namespace Mathematics
{
	template class DistanceSegment2Segment2<float>;
	template class DistanceSegment2Segment2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceSegment2Segment2Testing) 

void Mathematics::DistanceSegment2Segment2Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistanceSegment2Segment2Testing
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		FloatVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		FloatVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		FloatVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		float lhsExtent = FloatMath::FAbs(randomDistribution(generator));
		float rhsExtent = FloatMath::FAbs(randomDistribution(generator));

		FloatDistanceSegment2Segment2 distance(FloatSegment2(lhsExtent, lhsOrigin, lhsDirection, 1e-5f), FloatSegment2(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

		typedef bool(*ApproximateFunction)(const FloatSegment2& lhs, const FloatSegment2& rhs, const float epsilon);

		ApproximateFunction approximate = Approximate<float>;
		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsSegment(), FloatSegment2(lhsExtent,lhsOrigin, lhsDirection,1e-5f), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsSegment(), FloatSegment2(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
	}
}

void Mathematics::DistanceSegment2Segment2Testing
	::StaticTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment2Segment2 distance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent,rhsOrigin, rhsDirection));

		DoubleDistanceResult2 squaredResult = distance.GetSquared();
		DoubleDistanceResult2 result = distance.Get();		

		DoubleDistanceLine2Line2 lineDistance(DoubleLine2(lhsOrigin, lhsDirection), DoubleLine2(rhsOrigin,rhsDirection));
		DoubleDistanceResult2 lineSquaredResult = lineDistance.GetSquared();

		DoubleVector2D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin;		
		DoubleVector2D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

		double lhsLength = DoubleVector2DTools::VectorMagnitude(lhsDifference);
		double rhsLength = DoubleVector2DTools::VectorMagnitude(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
		{
			// 最小值为两个线段内部点。
			DoubleVector2D lhsDifference2 = squaredResult.GetLhsClosestPoint()- lhsOrigin;		
			DoubleVector2D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
			double lhsLength2 = DoubleVector2DTools::VectorMagnitude(lhsDifference2);
			double rhsLength2 = DoubleVector2DTools::VectorMagnitude(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(lhsLength2 <= lhsExtent);
			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(DoubleVector2DTools::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
			            DoubleVector2DTools::Approximate(lhsDifference2, -lhsDirection, 1e-10));
			ASSERT_TRUE(DoubleVector2DTools::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            DoubleVector2DTools::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector2DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector2DTools::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs起始点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector2DTools::Approximate(lhsDifference, lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector2DTools::Approximate(lhsDifference, -lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs起点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
		{			
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),DoubleMath::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceSegment2Segment2 firstParallelDistance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared();
		result = firstParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		 
		DoubleDistanceSegment2Segment2 secondParallelDistance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared();
		result = secondParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
	}
}

void Mathematics::DistanceSegment2Segment2Testing
	::DynamicTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment2Segment2 distance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent,rhsOrigin, rhsDirection));

		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleDistanceResult2 squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		DoubleDistanceResult2 result = distance.Get(t,lhsVelocity,rhsVelocity);		

		DoubleDistanceLine2Line2 lineDistance(DoubleLine2(lhsOrigin, lhsDirection), DoubleLine2(rhsOrigin,rhsDirection));
		DoubleDistanceResult2 lineSquaredResult = lineDistance.GetSquared(t,lhsVelocity,rhsVelocity);

		DoubleVector2D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- (lhsOrigin + t * lhsVelocity);		
		DoubleVector2D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);

		double lhsLength = DoubleVector2DTools::VectorMagnitude(lhsDifference);
		double rhsLength = DoubleVector2DTools::VectorMagnitude(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
		{
			// 最小值为两个线段内部点。
			DoubleVector2D lhsDifference2 = squaredResult.GetLhsClosestPoint()- (lhsOrigin + t * lhsVelocity);		
			DoubleVector2D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
			double lhsLength2 = DoubleVector2DTools::VectorMagnitude(lhsDifference2);
			double rhsLength2 = DoubleVector2DTools::VectorMagnitude(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(lhsLength2 <= lhsExtent);
			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(DoubleVector2DTools::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
			            DoubleVector2DTools::Approximate(lhsDifference2, -lhsDirection, 1e-10));
			ASSERT_TRUE(DoubleVector2DTools::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            DoubleVector2DTools::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector2DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector2DTools::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs起始点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + + t * rhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector2DTools::Approximate(lhsDifference, lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint() - t * lhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector2DTools::Approximate(lhsDifference, -lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs起点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
						DoubleVector2DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
		}
		else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
		{			
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),DoubleMath::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE(DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceSegment2Segment2 firstParallelDistance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared(t,lhsVelocity,rhsVelocity);
		result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		DoubleDistanceSegment2Segment2 secondParallelDistance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
		result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector2DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector2DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10); 
	}
}

void Mathematics::DistanceSegment2Segment2Testing
	::DerivativeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector2D rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment2Segment2 distance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent, rhsOrigin, rhsDirection));
		
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

void Mathematics::DistanceSegment2Segment2Testing
	::IntervalTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-10.0, 10.0);

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

		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment2Segment2 distance(DoubleSegment2(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment2(rhsExtent,rhsOrigin, rhsDirection));
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		DoubleVector2D lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector2D rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();			

		DoubleDistanceResult2 squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult2 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult2 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult2 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-5);		
			ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());			
		}	
	}
}
 
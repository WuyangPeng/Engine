// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/30 13:08)

#include "DistanceLine3Segment3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"
#include <random>

using std::swap;

namespace Mathematics
{
	template class DistanceLine3Segment3<float>;
	template class DistanceLine3Segment3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceLine3Segment3Testing) 

void Mathematics::DistanceLine3Segment3Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistanceLine3Segment3Testing
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		FloatVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		FloatVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		FloatVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		float rhsExtent = FloatMath::FAbs(randomDistribution(generator));

		FloatDistanceLine3Segment3 distance(FloatLine3(lhsOrigin, lhsDirection), FloatSegment3(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

		typedef bool(*SegmentApproximateFunction)(const FloatSegment3& lhs, const FloatSegment3& rhs, const float epsilon);
		SegmentApproximateFunction segmentApproximate = Approximate<float>;

		typedef bool(*LineApproximateFunction)(const FloatLine3& lhs, const FloatLine3& rhs, const float epsilon);
		LineApproximateFunction lineApproximate = Approximate<float>;

		ASSERT_APPROXIMATE_USE_FUNCTION(lineApproximate, distance.GetLine(), FloatLine3(lhsOrigin, lhsDirection), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(segmentApproximate, distance.GetSegment(), FloatSegment3(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
	}
}

void Mathematics::DistanceLine3Segment3Testing
	::StaticTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceLine3Segment3 distance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));

		DoubleDistanceResult3 squaredResult = distance.GetSquared();
		DoubleDistanceResult3 result = distance.Get();		

		DoubleDistanceLine3Line3 lineDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleLine3(rhsOrigin,rhsDirection));
		DoubleDistanceResult3 lineSquaredResult = lineDistance.GetSquared();

		DoubleVector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin;		
		DoubleVector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

		double rhsLength = DoubleVector3DTools::VectorMagnitude(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (rhsLength <= rhsExtent)
		{
			// 最小值为线段内部点。
		
			DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;	
			double rhsLength2 = DoubleVector3DTools::VectorMagnitude(rhsDifference2);		
			rhsDifference2.Normalize();

			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(lhsDifference, -lhsDirection, 1e-10));
			ASSERT_TRUE(DoubleVector3DTools::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(),squaredResult.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

		}
		else if (rhsExtent < rhsLength &&
				 DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()));
		}
		else
		{
			// 最近点在lhs上某个点和rhs起始点
			ASSERT_TRUE(rhsExtent < rhsLength);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, rhsDifference, -rhsDirection,1e-8);

			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()));
		}
		
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceLine3Segment3 firstParallelDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared();
		result = firstParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLine().GetOrigin() - firstParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLine().GetOrigin() - firstParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLine().GetOrigin() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		 
		DoubleDistanceLine3Segment3 secondParallelDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = secondParallelDistance.GetSquared();
		result = secondParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLine().GetOrigin() - secondParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLine().GetOrigin() - secondParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLine().GetOrigin() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
	}
}

void Mathematics::DistanceLine3Segment3Testing
	::DynamicTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceLine3Segment3 distance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));

		DoubleDistanceResult3 squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		DoubleDistanceResult3 result = distance.Get(t, lhsVelocity, rhsVelocity);

		DoubleDistanceLine3Line3 lineDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleLine3(rhsOrigin,rhsDirection));
		DoubleDistanceResult3 lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

		DoubleVector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin - t * lhsVelocity;		
		DoubleVector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;

		double rhsLength = DoubleVector3DTools::VectorMagnitude(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (rhsLength <= rhsExtent)
		{
			// 最小值为线段内部点。
		
			DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
			double rhsLength2 = DoubleVector3DTools::VectorMagnitude(rhsDifference2);		
			rhsDifference2.Normalize();

			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(lhsDifference, -lhsDirection, 1e-10));
			ASSERT_TRUE(DoubleVector3DTools::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);


		}
		else if (rhsExtent < rhsLength &&
				 DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint() + t * rhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity));
		}
		else
		{
			// 最近点在lhs上某个点和rhs起始点
			ASSERT_TRUE(rhsExtent < rhsLength);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, rhsDifference, -rhsDirection,1e-8);

			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint() + t * rhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity));
		}
		
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceLine3Segment3 firstParallelDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared(t,lhsVelocity,rhsVelocity);
		result = firstParallelDistance.Get(t,lhsVelocity,rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity -firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		 
		DoubleDistanceLine3Segment3 secondParallelDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = secondParallelDistance.GetSquared(t,lhsVelocity,rhsVelocity);
		result = secondParallelDistance.Get(t,lhsVelocity,rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
	}
}

void Mathematics::DistanceLine3Segment3Testing
	::DerivativeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceLine3Segment3 distance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));
		
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

void Mathematics::DistanceLine3Segment3Testing
	::IntervalTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double tMin = DoubleMath::FAbs(randomDistribution(generator));
		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		if (tMax < tMin)
		{
			swap(tMin, tMax);
		}
				
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceLine3Segment3 distance(DoubleLine3(lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent,rhsOrigin, rhsDirection));
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();			

		DoubleDistanceResult3 squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult3 result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
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
 
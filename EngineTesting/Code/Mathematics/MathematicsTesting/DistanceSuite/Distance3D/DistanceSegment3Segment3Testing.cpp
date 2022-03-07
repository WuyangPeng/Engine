// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/30 13:12)

#include "DistanceSegment3Segment3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3Toolsdetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

#include <random>

using std::swap;
#include SYSTEM_WARNING_DISABLE(26496)
namespace Mathematics
{
	template class DistanceSegment3Segment3<float>;
	template class DistanceSegment3Segment3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceSegment3Segment3Testing) 

void Mathematics::DistanceSegment3Segment3Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistanceSegment3Segment3Testing
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

		float lhsExtent = MathF::FAbs(randomDistribution(generator));
		float rhsExtent = MathF::FAbs(randomDistribution(generator));

		DistanceSegment3Segment3F distance(Segment3F(lhsExtent, lhsOrigin, lhsDirection, 1e-5f), Segment3F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(MathF::epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

		typedef bool(*ApproximateFunction)(const Segment3F& lhs, const Segment3F& rhs, const float epsilon);

		ApproximateFunction approximate = Approximate<float>;
		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsSegment(), Segment3F(lhsExtent,lhsOrigin, lhsDirection,1e-5f), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsSegment(), Segment3F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
	}
}

void Mathematics::DistanceSegment3Segment3Testing
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

		double lhsExtent = MathD::FAbs(randomDistribution(generator));
		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceSegment3Segment3D distance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent,rhsOrigin, rhsDirection));

		DistanceResult3D squaredResult = distance.GetSquared();
		DistanceResult3D result = distance.Get();		

		DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin,rhsDirection));
		DistanceResult3D lineSquaredResult = lineDistance.GetSquared();

		Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin;		
		Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

		double lhsLength = Vector3ToolsD::GetLength(lhsDifference);
		double rhsLength = Vector3ToolsD::GetLength(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
		{
			// 最小值为两个线段内部点。
			Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint()- lhsOrigin;		
			Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
			double lhsLength2 = Vector3ToolsD::GetLength(lhsDifference2);
			double rhsLength2 = Vector3ToolsD::GetLength(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(lhsLength2 <= lhsExtent);
			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(Vector3ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
			            Vector3ToolsD::Approximate(lhsDifference2, -lhsDirection, 1e-10));
			ASSERT_TRUE(Vector3ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            Vector3ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(),squaredResult.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 Vector3ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs起始点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 Vector3ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs起点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
		{			
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DistanceSegment3Segment3D firstParallelDistance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared();
		result = firstParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		 
		DistanceSegment3Segment3D secondParallelDistance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared();
		result = secondParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
	}
}

void Mathematics::DistanceSegment3Segment3Testing
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

		double lhsExtent = MathD::FAbs(randomDistribution(generator));
		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceSegment3Segment3D distance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent,rhsOrigin, rhsDirection));

		double t = MathD::FAbs(randomDistribution(generator));
		Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DistanceResult3D squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		DistanceResult3D result = distance.Get(t,lhsVelocity,rhsVelocity);		

		DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin,rhsDirection));
		DistanceResult3D lineSquaredResult = lineDistance.GetSquared(t,lhsVelocity,rhsVelocity);

		Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- (lhsOrigin + t * lhsVelocity);		
		Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);

		double lhsLength = Vector3ToolsD::GetLength(lhsDifference);
		double rhsLength = Vector3ToolsD::GetLength(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
		{
			// 最小值为两个线段内部点。
			Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint()- (lhsOrigin + t * lhsVelocity);		
			Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
			double lhsLength2 = Vector3ToolsD::GetLength(lhsDifference2);
			double rhsLength2 = Vector3ToolsD::GetLength(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(lhsLength2 <= lhsExtent);
			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(Vector3ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
			            Vector3ToolsD::Approximate(lhsDifference2, -lhsDirection, 1e-10));
			ASSERT_TRUE(Vector3ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            Vector3ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 Vector3ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// 最近点在lhs上某个点和rhs起始点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + + t * rhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs终点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint() - t * lhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 Vector3ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-8))
		{
			// 最近点在rhs上某个点和lhs起点
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
						Vector3ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
		}
		else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
		{			
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE(Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DistanceSegment3Segment3D firstParallelDistance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared(t,lhsVelocity,rhsVelocity);
		result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		DistanceSegment3Segment3D secondParallelDistance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
		result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10); 
	}
}

void Mathematics::DistanceSegment3Segment3Testing
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
		double lhsExtent = MathD::FAbs(randomDistribution(generator));
		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceSegment3Segment3D distance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));
		
		double t = MathD::FAbs(randomDistribution(generator));
		Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();		
 
		DistanceResult3D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		DistanceResult3D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		double derivativeApproximation =
			0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

		double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

		double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);
		
		DistanceResult3D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
	}
}

void Mathematics::DistanceSegment3Segment3Testing
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

		double lhsExtent = MathD::FAbs(randomDistribution(generator));
		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceSegment3Segment3D distance(Segment3D(lhsExtent, lhsOrigin, lhsDirection), Segment3D(rhsExtent,rhsOrigin, rhsDirection));
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();			

		DistanceResult3D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DistanceResult3D result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-4);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate,squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-5);		
			ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());			
		}	
	}
}
 
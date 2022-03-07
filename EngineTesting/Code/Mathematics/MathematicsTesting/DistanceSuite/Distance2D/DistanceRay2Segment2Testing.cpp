// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 12:53)

#include "DistanceRay2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Line2Detail.h"
#include "Mathematics/Distance/Distance2D/DistanceRay2Segment2Detail.h"

#include <random>

using std::swap;

namespace Mathematics
{
	template class DistanceRay2Segment2<float>;
	template class DistanceRay2Segment2<double>;
}
#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceRay2Segment2Testing) 

void Mathematics::DistanceRay2Segment2Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistanceRay2Segment2Testing
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2F lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2F lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector2F rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2F rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		float rhsExtent = MathF::FAbs(randomDistribution(generator));

		DistanceRay2Segment2F distance(Ray2F(lhsOrigin, lhsDirection), Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(MathF::epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

		typedef bool(*SegmentApproximateFunction)(const Segment2F& lhs, const Segment2F& rhs, const float epsilon);
		SegmentApproximateFunction segmentApproximate = Approximate<float>;

		typedef bool(*RayApproximateFunction)(const Ray2F& lhs, const Ray2F& rhs, const float epsilon);
		RayApproximateFunction rayApproximateFunction = Approximate<float>;

		ASSERT_APPROXIMATE_USE_FUNCTION(rayApproximateFunction, distance.GetRay(), Ray2F(lhsOrigin, lhsDirection), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(segmentApproximate, distance.GetSegment(), Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
	}
}

void Mathematics::DistanceRay2Segment2Testing
	::StaticTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		 
		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceRay2Segment2D distance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

		DistanceResult2D squaredResult = distance.GetSquared();
		DistanceResult2D result = distance.Get();		

		DistanceLine2Line2D lineDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin,rhsDirection));
		DistanceResult2D lineSquaredResult = lineDistance.GetSquared();

		Vector2 lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin;		
		Vector2 rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

		double rhsLength = Vector2ToolsD::GetLength(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && 
			rhsLength <= rhsExtent)
		{
			// ��СֵΪ�߶κ������ڲ��㡣
			Vector2 lhsDifference2 = squaredResult.GetLhsClosestPoint()- lhsOrigin;		
			Vector2 rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
			double rhsLength2 = Vector2ToolsD::GetLength(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10));
			ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            Vector2ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && 
			     rhsExtent < rhsLength &&
				 Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// �������������ĳ�����rhs�յ�
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()) );
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()) ||
						Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin(), 1e-8));
		}
		else if (Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && rhsExtent < rhsLength &&
				 Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// �������������ĳ�����rhs��ʼ��
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()) ||
						Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin(), 1e-8));
		}
		else
		{
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() - distance.GetSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() - distance.GetSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DistanceRay2Segment2D firstParallelDistance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));


		squaredResult = firstParallelDistance.GetSquared();
		result = firstParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() - firstParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() - firstParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		
		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		 
		DistanceRay2Segment2D secondParallelDistance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared();
		result = secondParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() - secondParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() - secondParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
	}
}

void Mathematics::DistanceRay2Segment2Testing
	::DynamicTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

	 
		double t = MathD::FAbs(randomDistribution(generator));
		Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceRay2Segment2D distance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

		DistanceResult2D squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		DistanceResult2D result = distance.Get(t, lhsVelocity, rhsVelocity);

		DistanceLine2Line2D lineDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin,rhsDirection));
		DistanceResult2D lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

		Vector2 lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin - t * lhsVelocity;		
		Vector2 rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;

		double rhsLength = Vector2ToolsD::GetLength(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && 
			rhsLength <= rhsExtent)
		{
			// ��СֵΪ�߶κ������ڲ��㡣
			Vector2 lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin - t * lhsVelocity;
			Vector2 rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
			double rhsLength2 = Vector2ToolsD::GetLength(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10));
			ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            Vector2ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && 
			     rhsExtent < rhsLength &&
				 Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// �������������ĳ�����rhs�յ�
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint() + t * rhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity) ||
						Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin() + t * lhsVelocity, 1e-8));
		}
		else if (Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && rhsExtent < rhsLength &&
				 Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// �������������ĳ�����rhs��ʼ��
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint() + t * rhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity) ||
						Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin() + t * lhsVelocity, 1e-8));
		}
		else
		{
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE(Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() + t * lhsVelocity - distance.GetSegment().GetBeginPoint() - t * rhsVelocity);
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() + t * lhsVelocity - distance.GetSegment().GetEndPoint() - t * rhsVelocity);
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity);
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity);
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DistanceRay2Segment2D firstParallelDistance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));


		squaredResult = firstParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
		result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin()  + t * lhsVelocity - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		
		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		 
		DistanceRay2Segment2D secondParallelDistance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
		result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
	}
}

void Mathematics::DistanceRay2Segment2Testing
	::DerivativeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
	 
		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceRay2Segment2D distance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

		double t = MathD::FAbs(randomDistribution(generator));
		Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();		
 
		DistanceResult2D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		DistanceResult2D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		double derivativeApproximation =
			0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

		double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

		double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);
		
		DistanceResult2D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
	}
}

void Mathematics::DistanceRay2Segment2Testing
	::IntervalTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-10.0, 10.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
		Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double tMin = MathD::FAbs(randomDistribution(generator));
		double tMax = MathD::FAbs(randomDistribution(generator));
		if (tMax < tMin)
		{
			swap(tMin, tMax);
		}
			 
		double rhsExtent = MathD::FAbs(randomDistribution(generator));

		DistanceRay2Segment2D distance(Ray2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

		Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();			

		DistanceResult2D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
		DistanceResult2D result = distance.GetInterval(tMin,tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate,squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DistanceResult2D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DistanceResult2D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-5);		
			ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());	
		}
		
	}
}
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 13:12)

#include "DistanceSegment3Segment3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3DToolsdetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

#include <random>

using std::swap;

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
		FloatVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		FloatVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		FloatVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		FloatVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		float lhsExtent = FloatMath::FAbs(randomDistribution(generator));
		float rhsExtent = FloatMath::FAbs(randomDistribution(generator));

		FloatDistanceSegment3Segment3 distance(FloatSegment3(lhsExtent, lhsOrigin, lhsDirection, 1e-5f), FloatSegment3(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

		typedef bool(*ApproximateFunction)(const FloatSegment3& lhs, const FloatSegment3& rhs, const float epsilon);

		ApproximateFunction approximate = Approximate<float>;
		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsSegment(), FloatSegment3(lhsExtent,lhsOrigin, lhsDirection,1e-5f), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsSegment(), FloatSegment3(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
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
		DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment3Segment3 distance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent,rhsOrigin, rhsDirection));

		DoubleDistanceResult3 squaredResult = distance.GetSquared();
		DoubleDistanceResult3 result = distance.Get();		

		DoubleDistanceLine3Line3 lineDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleLine3(rhsOrigin,rhsDirection));
		DoubleDistanceResult3 lineSquaredResult = lineDistance.GetSquared();

		DoubleVector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- lhsOrigin;		
		DoubleVector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

		double lhsLength = DoubleVector3DTools::VectorMagnitude(lhsDifference);
		double rhsLength = DoubleVector3DTools::VectorMagnitude(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
		{
			// ��СֵΪ�����߶��ڲ��㡣
			DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint()- lhsOrigin;		
			DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
			double lhsLength2 = DoubleVector3DTools::VectorMagnitude(lhsDifference2);
			double rhsLength2 = DoubleVector3DTools::VectorMagnitude(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(lhsLength2 <= lhsExtent);
			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(DoubleVector3DTools::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(lhsDifference2, -lhsDirection, 1e-10));
			ASSERT_TRUE(DoubleVector3DTools::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(),squaredResult.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// �������lhs��ĳ�����rhs�յ�
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector3DTools::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// �������lhs��ĳ�����rhs��ʼ��
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-8))
		{
			// �������rhs��ĳ�����lhs�յ�
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector3DTools::Approximate(lhsDifference, -lhsDirection, 1e-8))
		{
			// �������rhs��ĳ�����lhs���
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
		}
		else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
		{			
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),0.0, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),DoubleMath::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
			ASSERT_APPROXIMATE(DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceSegment3Segment3 firstParallelDistance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared();
		result = firstParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
		 
		DoubleDistanceSegment3Segment3 secondParallelDistance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared();
		result = secondParallelDistance.Get();

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
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
		DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();

		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment3Segment3 distance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent,rhsOrigin, rhsDirection));

		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleDistanceResult3 squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		DoubleDistanceResult3 result = distance.Get(t,lhsVelocity,rhsVelocity);		

		DoubleDistanceLine3Line3 lineDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleLine3(rhsOrigin,rhsDirection));
		DoubleDistanceResult3 lineSquaredResult = lineDistance.GetSquared(t,lhsVelocity,rhsVelocity);

		DoubleVector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint()- (lhsOrigin + t * lhsVelocity);		
		DoubleVector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);

		double lhsLength = DoubleVector3DTools::VectorMagnitude(lhsDifference);
		double rhsLength = DoubleVector3DTools::VectorMagnitude(rhsDifference);	
		lhsDifference.Normalize();
		rhsDifference.Normalize();

		if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
		{
			// ��СֵΪ�����߶��ڲ��㡣
			DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint()- (lhsOrigin + t * lhsVelocity);		
			DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
			double lhsLength2 = DoubleVector3DTools::VectorMagnitude(lhsDifference2);
			double rhsLength2 = DoubleVector3DTools::VectorMagnitude(rhsDifference2);
			lhsDifference2.Normalize();
			rhsDifference2.Normalize();

			ASSERT_TRUE(lhsLength2 <= lhsExtent);
			ASSERT_TRUE(rhsLength2 <= rhsExtent);

			ASSERT_TRUE(DoubleVector3DTools::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(lhsDifference2, -lhsDirection, 1e-10));
			ASSERT_TRUE(DoubleVector3DTools::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
			            DoubleVector3DTools::Approximate(rhsDifference2, -rhsDirection, 1e-10));
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
		{
			// �������lhs��ĳ�����rhs�յ�
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
		}
		else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
				 DoubleVector3DTools::Approximate(rhsDifference, -rhsDirection, 1e-8))
		{
			// �������lhs��ĳ�����rhs��ʼ��
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <=  
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + + t * rhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-8))
		{
			// �������rhs��ĳ�����lhs�յ�
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint() - t * lhsVelocity),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
		}
		else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
				 DoubleVector3DTools::Approximate(lhsDifference, -lhsDirection, 1e-8))
		{
			// �������rhs��ĳ�����lhs���
			ASSERT_APPROXIMATE(squaredResult.GetDistance(), 
				               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)),
							   1e-10);
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity), 1e-8);

			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
			ASSERT_TRUE(squaredResult.GetDistance() <= 
				        DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
						DoubleVector3DTools::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
		}
		else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
		{			
			ASSERT_APPROXIMATE(squaredResult.GetContactTime(),t, 1e-10);
			ASSERT_APPROXIMATE(result.GetDistance(),DoubleMath::Sqrt(squaredResult.GetDistance()), 1e-10);
			ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
			ASSERT_APPROXIMATE(DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()),squaredResult.GetDistance(), 1e-10);

			double distanceSquared = squaredResult.GetDistance();
			double testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
			
			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

			testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
			ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		}
		
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
	
		DoubleDistanceSegment3Segment3 firstParallelDistance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, lhsDirection));

		squaredResult = firstParallelDistance.GetSquared(t,lhsVelocity,rhsVelocity);
		result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		double distanceSquared = squaredResult.GetDistance();
		double testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		DoubleDistanceSegment3Segment3 secondParallelDistance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, -lhsDirection));

		squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
		result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

		distanceSquared = squaredResult.GetDistance();
		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
		ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

		testDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
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
		DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsDirection.Normalize();

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment3Segment3 distance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent, rhsOrigin, rhsDirection));
		
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

void Mathematics::DistanceSegment3Segment3Testing
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

		double lhsExtent = DoubleMath::FAbs(randomDistribution(generator));
		double rhsExtent = DoubleMath::FAbs(randomDistribution(generator));

		DoubleDistanceSegment3Segment3 distance(DoubleSegment3(lhsExtent, lhsOrigin, lhsDirection), DoubleSegment3(rhsExtent,rhsOrigin, rhsDirection));
		distance.SetMaximumIterations(20);
		distance.SetZeroThreshold(1e-6);

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
 
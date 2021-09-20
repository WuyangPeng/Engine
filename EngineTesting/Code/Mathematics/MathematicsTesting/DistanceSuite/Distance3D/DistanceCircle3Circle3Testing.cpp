// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 13:07)

#include "DistanceCircle3Circle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceCircle3Circle3Detail.h"
#include "Mathematics/Objects3D/Circle3Detail.h"
#include <random>

using std::swap;

namespace Mathematics
{
	template class DistanceCircle3Circle3<float>;
	template class DistanceCircle3Circle3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceCircle3Circle3Testing) 

void Mathematics::DistanceCircle3Circle3Testing
	::MainTest()
{	
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);	
}

void Mathematics::DistanceCircle3Circle3Testing
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
		float lhsRadius(FloatMath::FAbs(randomDistribution(generator)));	
		FloatVector3DOrthonormalBasis lhsBasis = FloatVector3DTools::GenerateOrthonormalBasis(lhsDirection);

		FloatVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		FloatVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
		float rhsRadius(FloatMath::FAbs(randomDistribution(generator)));
		FloatVector3DOrthonormalBasis rhsBasis = FloatVector3DTools::GenerateOrthonormalBasis(rhsDirection);

		FloatDistanceCircle3Circle3 distance(FloatCircle3(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius), 
			                             FloatCircle3(rhsOrigin, rhsBasis.GetUVector(),rhsBasis.GetVVector(),rhsBasis.GetWVector(),rhsRadius));

		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

		distance.SetDifferenceStep(1e-4f);
		ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

		distance.SetMaximumIterations(10);
		ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

		distance.SetZeroThreshold(FloatMath::sm_Epsilon);
		ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

		typedef bool(*ApproximateFunction)(const FloatCircle3& lhs, const FloatCircle3& rhs, const float epsilon);
		ApproximateFunction approximate = Approximate<float>;

		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsCircle(), FloatCircle3(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius), 1e-8f);
		ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsCircle(), FloatCircle3(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius), 1e-8f);
	}
}

void Mathematics::DistanceCircle3Circle3Testing
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
		double lhsRadius(DoubleMath::FAbs(randomDistribution(generator)));	
		DoubleVector3DOrthonormalBasis lhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(lhsDirection);

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
		double rhsRadius(DoubleMath::FAbs(randomDistribution(generator)));
		DoubleVector3DOrthonormalBasis rhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(rhsDirection);

		DoubleDistanceCircle3Circle3 distance(DoubleCircle3(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(),lhsBasis.GetWVector(),lhsRadius), 
			                             DoubleCircle3(rhsOrigin, rhsBasis.GetUVector(),rhsBasis.GetVVector(),rhsBasis.GetWVector(),rhsRadius));

		DoubleDistanceResult3 squaredResult = distance.GetSquared();
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-8);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10); 
		 
		DoubleDistanceResult3 result = distance.Get();
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);

		ASSERT_APPROXIMATE(result.GetDistance(),DoubleMath::Sqrt(squaredResult.GetDistance()), 1e-10);
	}
}

void Mathematics::DistanceCircle3Circle3Testing
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
		double lhsRadius(DoubleMath::FAbs(randomDistribution(generator)));	
		DoubleVector3DOrthonormalBasis lhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(lhsDirection);

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
		double rhsRadius(DoubleMath::FAbs(randomDistribution(generator)));
		DoubleVector3DOrthonormalBasis rhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(rhsDirection);

		DoubleDistanceCircle3Circle3 distance(DoubleCircle3(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(),lhsBasis.GetWVector(),lhsRadius), 
			                             DoubleCircle3(rhsOrigin, rhsBasis.GetUVector(),rhsBasis.GetVVector(),rhsBasis.GetWVector(),rhsRadius));

		double t = DoubleMath::FAbs(randomDistribution(generator));
		DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		lhsVelocity.Normalize();
		DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsVelocity.Normalize();

		DoubleDistanceResult3 squaredResult = distance.GetSquared(t,lhsVelocity,rhsVelocity);
		ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-8);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

		DoubleDistanceResult3 result = distance.Get(t, lhsVelocity, rhsVelocity);
		ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
		ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);

		ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(squaredResult.GetDistance()), 1e-10);
	}
}

void Mathematics::DistanceCircle3Circle3Testing
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
		double lhsRadius(DoubleMath::FAbs(randomDistribution(generator)));	
		DoubleVector3DOrthonormalBasis lhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(lhsDirection);

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
		double rhsRadius(DoubleMath::FAbs(randomDistribution(generator)));
		DoubleVector3DOrthonormalBasis rhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(rhsDirection);

		DoubleDistanceCircle3Circle3 distance(DoubleCircle3(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(),lhsBasis.GetWVector(),lhsRadius), 
			                             DoubleCircle3(rhsOrigin, rhsBasis.GetUVector(),rhsBasis.GetVVector(),rhsBasis.GetWVector(),rhsRadius));

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

void Mathematics::DistanceCircle3Circle3Testing
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
		double lhsRadius(DoubleMath::FAbs(randomDistribution(generator)));	
		DoubleVector3DOrthonormalBasis lhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(lhsDirection);

		DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
		rhsDirection.Normalize();
		double rhsRadius(DoubleMath::FAbs(randomDistribution(generator)));
		DoubleVector3DOrthonormalBasis rhsBasis = DoubleVector3DTools::GenerateOrthonormalBasis(rhsDirection);

		DoubleDistanceCircle3Circle3 distance(DoubleCircle3(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(),lhsBasis.GetWVector(),lhsRadius), 
			                             DoubleCircle3(rhsOrigin, rhsBasis.GetUVector(),rhsBasis.GetVVector(),rhsBasis.GetWVector(),rhsRadius));
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
		DoubleDistanceResult3 result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
		ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-2);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-2);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-2);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult3 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult3 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_LESS_EQUAL(result.GetDistance() , tResult.GetDistance() + 0.2);		
			ASSERT_LESS_EQUAL(squaredResult.GetDistance() , tResultSquared.GetDistance() + 0.3);
		}	
	}
}
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 11:40)

#include "DistancePoint2Ellipse2Testing.h"
#include "Mathematics/NumericalAnalysis/Equation.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Ellipse2Detail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::swap;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class DistancePoint2Ellipse2<float>;
	template class DistancePoint2Ellipse2<double>; 
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistancePoint2Ellipse2Testing) 

void Mathematics::DistancePoint2Ellipse2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StaticDistanceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DynamicDistanceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativeDistanceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntervalDistanceTest);
}

void Mathematics::DistancePoint2Ellipse2Testing
	::BaseTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_real<double> secondRandomDistribution(0.0 ,100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D center(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D axis1(firstRandomDistribution(generator), firstRandomDistribution(generator));
		double extent0(secondRandomDistribution(generator));
		double extent1(secondRandomDistribution(generator));

		axis0.Normalize();
		axis1.Normalize();

		DoubleEllipse2 firstEllipse(center, axis0, axis1, extent0, extent1);

		DoubleDistancePoint2Ellipse2 firstDistance(firstPoint, firstEllipse);

		ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-3, 1e-10);

		firstDistance.SetDifferenceStep(1e-1);

		ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-1, 1e-10);

		ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 8);

		firstDistance.SetMaximumIterations(10);

		ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 10);

		ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), DoubleMath::GetZeroTolerance(), 1e-10);

		firstDistance.SetZeroThreshold(1e-2);

		ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), 1e-2, 1e-10);

		DoubleVector2D secondPoint = firstDistance.GetPoint();
		DoubleEllipse2 secondEllipse = firstDistance.GetEllipse();

		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, firstPoint, secondPoint, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, secondEllipse.GetCenter(), firstEllipse.GetCenter(), 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, secondEllipse.GetAxis0(), firstEllipse.GetAxis0(), 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, secondEllipse.GetAxis1(), firstEllipse.GetAxis1(), 1e-10);
		ASSERT_APPROXIMATE(secondEllipse.GetExtent0(), firstEllipse.GetExtent0(), 1e-10);
		ASSERT_APPROXIMATE(secondEllipse.GetExtent1(), firstEllipse.GetExtent1(), 1e-10);
	}
}

void Mathematics::DistancePoint2Ellipse2Testing
	::StaticDistanceTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_real<double> secondRandomDistribution(0.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D center(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));		 
		double extent0(secondRandomDistribution(generator));
		double extent1(secondRandomDistribution(generator));

		axis0.Normalize(); 

		DoubleVector2DOrthonormalBasis basis = DoubleVector2DTools::GenerateOrthonormalBasis(axis0);

		DoubleEllipse2 firstEllipse(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

		DoubleDistancePoint2Ellipse2 firstDistance(firstPoint, firstEllipse);
		 
		DoubleDistanceResult2 result = firstDistance.Get();
		DoubleDistanceResult2 resultSquared = firstDistance.GetSquared();

		ASSERT_APPROXIMATE(resultSquared.GetDistance(), result.GetDistance() * result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), 0.0, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-10);
		ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
		ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
		ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
		ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

		ASSERT_TRUE(firstEllipse.Contains(resultSquared.GetRhsClosestPoint()));
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            firstPoint,1e-10);		

		double distance = DoubleVector2DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
		ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);

		double xMin = (center - basis.GetUVector()).GetX() - extent0;
		double xMax = (center + basis.GetUVector()).GetX() + extent0;

		for (double value = xMin; value < xMax; value += 1.0)
		{			
			double constantU = (basis.GetUVector().GetX() * (value - center.GetX()) -
			                    basis.GetUVector().GetY() * center.GetY());
			double secondaryU = basis.GetUVector().GetY();
			double constantV = (basis.GetVVector().GetX() * (value - center.GetX()) -
			                    basis.GetVVector().GetY() * center.GetY());
			double secondaryV = basis.GetVVector().GetY();

			double secondary = (secondaryU * secondaryU) / (extent0 * extent0) +
				               (secondaryV * secondaryV) / (extent1 * extent1);
			double once = (2.0 * secondaryU * constantU) / (extent0 * extent0) +
			              (2.0 * secondaryV * constantV) / (extent1 * extent1);
			double constant = (constantU * constantU) / (extent0 * extent0) +
				              (constantV * constantV) / (extent1 * extent1) - 1.0;

			Equation equation(constant, once, secondary);

			for (Equation::RealConstIterator iter = equation.GetRealBegin(), end = equation.GetRealEnd();
				 iter != end;++iter)
			{
				DoubleVector2D eachPoint(value, *iter);
				
				double distance2 = DoubleVector2DTools::Distance(eachPoint, firstPoint);

				ASSERT_TRUE(result.GetDistance() <= distance2); 

				ASSERT_TRUE(firstEllipse.Contains(eachPoint));
			}
		}
	}
}

void Mathematics::DistancePoint2Ellipse2Testing
	::DynamicDistanceTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_real<double> secondRandomDistribution(0.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D center(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));		 
		double extent0(secondRandomDistribution(generator));
		double extent1(secondRandomDistribution(generator));

		axis0.Normalize(); 

		DoubleVector2DOrthonormalBasis basis = DoubleVector2DTools::GenerateOrthonormalBasis(axis0);

		DoubleEllipse2 firstEllipse(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

		DoubleDistancePoint2Ellipse2 firstDistance(firstPoint, firstEllipse);

		DoubleVector2D lhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D rhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator));

		lhsVelocity.Normalize();
		rhsVelocity.Normalize();

		double t = secondRandomDistribution(generator);

		DoubleDistanceResult2 result = firstDistance.Get(t,lhsVelocity,rhsVelocity);
		DoubleDistanceResult2 resultSquared = firstDistance.GetSquared(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(resultSquared.GetDistance(), result.GetDistance() * result.GetDistance(), 1e-10);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), t, 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-10);
		ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
		ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
		ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
		ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

		DoubleEllipse2 secondEllipse(center + t * rhsVelocity, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

		ASSERT_TRUE(secondEllipse.Contains(resultSquared.GetRhsClosestPoint()));
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            firstPoint + t * lhsVelocity,1e-10);		


		double distance = DoubleVector2DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
		ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);


		double xMin = (secondEllipse.GetCenter() - basis.GetUVector()).GetX() - extent0;
		double xMax = (secondEllipse.GetCenter() + basis.GetUVector()).GetX() + extent0;

		for (double value = xMin; value < xMax; value += 1.0)
		{			
			double constantU = (basis.GetUVector().GetX() * (value - secondEllipse.GetCenter().GetX()) -
			                    basis.GetUVector().GetY() * secondEllipse.GetCenter().GetY());
			double secondaryU = basis.GetUVector().GetY();
			double constantV = (basis.GetVVector().GetX() * (value - secondEllipse.GetCenter().GetX()) -
			                    basis.GetVVector().GetY() * secondEllipse.GetCenter().GetY());
			double secondaryV = basis.GetVVector().GetY();

			double secondary = (secondaryU * secondaryU) / (extent0 * extent0) +
				               (secondaryV * secondaryV) / (extent1 * extent1);
			double once = (2.0 * secondaryU * constantU) / (extent0 * extent0) +
			              (2.0 * secondaryV * constantV) / (extent1 * extent1);
			double constant = (constantU * constantU) / (extent0 * extent0) +
				              (constantV * constantV) / (extent1 * extent1) - 1.0;

			Equation equation(constant, once, secondary);

			for (Equation::RealConstIterator iter = equation.GetRealBegin(), end = equation.GetRealEnd();
				 iter != end;++iter)
			{
				DoubleVector2D eachPoint(value, *iter);
				
				double distance2 = DoubleVector2DTools::Distance(eachPoint, resultSquared.GetLhsClosestPoint());

				ASSERT_TRUE(result.GetDistance() <= distance2); 

				ASSERT_TRUE(secondEllipse.Contains(eachPoint));
			}
		}
	}
}

void Mathematics::DistancePoint2Ellipse2Testing
	::DerivativeDistanceTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_real<double> secondRandomDistribution(0.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D center(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));		 
		double extent0(secondRandomDistribution(generator));
		double extent1(secondRandomDistribution(generator));

		axis0.Normalize(); 

		DoubleVector2DOrthonormalBasis basis = DoubleVector2DTools::GenerateOrthonormalBasis(axis0);

		DoubleEllipse2 firstEllipse(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

		DoubleDistancePoint2Ellipse2 firstDistance(firstPoint, firstEllipse);

		DoubleVector2D lhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D rhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator));

		lhsVelocity.Normalize();
		rhsVelocity.Normalize();

		double t = secondRandomDistribution(generator);

		double result = firstDistance.GetDerivative(t, lhsVelocity, rhsVelocity);
		double resultSquared = firstDistance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

		DoubleDistanceResult2 funcp = firstDistance.Get(t + firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		DoubleDistanceResult2 funcm = firstDistance.Get(t - firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
		double derApprox = 0.5 / firstDistance.GetDifferenceStep() * (funcp.GetDistance() - funcm.GetDistance());
	 
		ASSERT_APPROXIMATE(derApprox, result, 1e-10);

		DoubleDistanceResult2 distance = firstDistance.Get(t, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(distance.GetDistance() * result * 2.0, resultSquared, 1e-10);		 
	}
}

void Mathematics::DistancePoint2Ellipse2Testing
	::IntervalDistanceTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_real<double> secondRandomDistribution(0.0, 20.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D center(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));		 
		double extent0(secondRandomDistribution(generator));
		double extent1(secondRandomDistribution(generator));

		axis0.Normalize(); 

		DoubleVector2DOrthonormalBasis basis = DoubleVector2DTools::GenerateOrthonormalBasis(axis0);

		DoubleEllipse2 firstEllipse(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

		DoubleDistancePoint2Ellipse2 firstDistance(firstPoint, firstEllipse);
		firstDistance.SetMaximumIterations(20);
	
		DoubleVector2D lhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D rhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator));

		lhsVelocity.Normalize();
		rhsVelocity.Normalize();

		double tMin = secondRandomDistribution(generator);
		double tMax = tMin + secondRandomDistribution(generator);

		DoubleDistanceResult2 result = firstDistance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);
		DoubleDistanceResult2 resultSquared = firstDistance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);

		ASSERT_APPROXIMATE(DoubleMath::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-3);
		ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-1);		 
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetLhsClosestPoint(),
			                            result.GetLhsClosestPoint(),1e-1);
		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate,resultSquared.GetRhsClosestPoint(),
			                            result.GetRhsClosestPoint(),1e-1);
		ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
		ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
		ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
		ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

		for (double t = tMin; t < tMax; t += 0.1)
		{
			DoubleDistanceResult2 tResult = firstDistance.Get(t, lhsVelocity, rhsVelocity);
			DoubleDistanceResult2 tResultSquared = firstDistance.GetSquared(t, lhsVelocity, rhsVelocity);

			ASSERT_LESS_EQUAL(result.GetDistance() ,tResult.GetDistance() + 1e-5);		
			ASSERT_LESS_EQUAL(resultSquared.GetDistance() , tResultSquared.GetDistance());
		}
	}
}


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 09:28)

#include "PlaneTesting.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Plane<float>;
	template class Plane<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,PlaneTesting) 

void Mathematics::PlaneTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
}

void Mathematics::PlaneTesting
	::ConstructionTest()
{
	FloatPlane firstPlane;

	ASSERT_APPROXIMATE(firstPlane.GetConstant(),0.0f,1e-8f);
	ASSERT_TRUE(Approximate(firstPlane.GetNormal(),FloatAVector::GetUnitX(),1e-8f));	

	DoubleAVector firstNormal(6.0,1.0,3.0);
	firstNormal.Normalize();

	DoublePlane secondPlane(firstNormal[0],firstNormal[1],firstNormal[2],5.0);
	DoubleAVector secondNormal = secondPlane.GetNormal();

	ASSERT_APPROXIMATE(secondPlane.GetConstant(),5.0,1e-10);
	ASSERT_TRUE(Approximate(secondNormal,firstNormal,1e-10));

	DoublePlane thirdPlane(firstNormal,6.0);
	DoubleAVector thirdNormal = thirdPlane.GetNormal();

	ASSERT_APPROXIMATE(thirdPlane.GetConstant(),6.0,1e-10);
	ASSERT_TRUE(Approximate(thirdNormal,firstNormal,1e-10));

	DoubleAPoint firstPoint(9.0,2.0,3.0);

	DoublePlane fourthPlane(firstNormal,firstPoint);
	ASSERT_APPROXIMATE(fourthPlane.DistanceTo(firstPoint),0.0,1e-10);

	DoubleAPoint secondPoint(19.0,22.0,13.0);
	DoubleAPoint thirdPoint(-19.0,-22.0,3.0);

	DoublePlane fifthPlane(firstPoint,secondPoint,thirdPoint);
	ASSERT_APPROXIMATE(fifthPlane.DistanceTo(firstPoint),0.0,1e-10);
	ASSERT_APPROXIMATE(fifthPlane.DistanceTo(secondPoint),0.0,1e-10);
	ASSERT_APPROXIMATE(fifthPlane.DistanceTo(thirdPoint),0.0,1e-10);

	DoubleHomogeneousPoint homogeneousPoint(3.0,5.0,6.0,1.0);

	DoublePlane sixthPlane(homogeneousPoint);

	double length =  DoubleMath::Sqrt(homogeneousPoint[0] * homogeneousPoint[0] + 
		                         homogeneousPoint[1] * homogeneousPoint[1] +
					             homogeneousPoint[2] * homogeneousPoint[2]);

	ASSERT_APPROXIMATE(sixthPlane[0],3.0 / length,1e-10);
	ASSERT_APPROXIMATE(sixthPlane[1],5.0 / length,1e-10);
	ASSERT_APPROXIMATE(sixthPlane[2],6.0 / length,1e-10);
	ASSERT_APPROXIMATE(sixthPlane[3],1.0 / length,1e-10);
}

void Mathematics::PlaneTesting
	::AccessTest()
{
	DoubleAVector firstNormal(6.0,1.0,3.0);
	firstNormal.Normalize();

	DoublePlane firstPlane(firstNormal,3.0);

	DoubleHomogeneousPoint secondHomogeneousPoint = firstPlane.GetHomogeneousPoint();

	ASSERT_APPROXIMATE(secondHomogeneousPoint[0],firstNormal[0],1e-10);
	ASSERT_APPROXIMATE(secondHomogeneousPoint[1],firstNormal[1],1e-10);
	ASSERT_APPROXIMATE(secondHomogeneousPoint[2],firstNormal[2],1e-10);
	ASSERT_APPROXIMATE(secondHomogeneousPoint[3],-3.0,1e-10);

// 	const double* firstDoublePtr = firstPlane.GetElements();
// 	double* secondDoublePtr = firstPlane.GetElements();
// 
// 	ASSERT_APPROXIMATE(firstDoublePtr[0],firstNormal[0],1e-10);
// 	ASSERT_APPROXIMATE(firstDoublePtr[1],firstNormal[1],1e-10);
// 	ASSERT_APPROXIMATE(firstDoublePtr[2],firstNormal[2],1e-10);
// 	ASSERT_APPROXIMATE(firstDoublePtr[3],-3.0,1e-10);
// 
// 	ASSERT_APPROXIMATE(secondDoublePtr[0],firstNormal[0],1e-10);
// 	ASSERT_APPROXIMATE(secondDoublePtr[1],firstNormal[1],1e-10);
// 	ASSERT_APPROXIMATE(secondDoublePtr[2],firstNormal[2],1e-10);
// 	ASSERT_APPROXIMATE(secondDoublePtr[3],-3.0,1e-10);
// 
// 	const DoublePlane secondPlane(firstNormal,13.0);
// 
// 	ASSERT_APPROXIMATE(secondPlane[0],firstNormal[0],1e-10);
// 	ASSERT_APPROXIMATE(secondPlane[1],firstNormal[1],1e-10);
// 	ASSERT_APPROXIMATE(secondPlane[2],firstNormal[2],1e-10);
// 	ASSERT_APPROXIMATE(secondPlane[3],-13.0,1e-10);
// 
// 	DoubleAVector secondNormal(61.0,11.0,13.0);
// 	secondNormal.Normalize();
// 
// 	firstPlane.SetNormal(secondNormal);
// 
// 	DoubleAVector thirdNormal = firstPlane.GetNormal();
// 
// 	ASSERT_TRUE(Approximate(secondNormal,thirdNormal,1e-10)); 
// 
// 	firstPlane.SetConstant(9.0);
// 
// 	ASSERT_APPROXIMATE(firstPlane.GetConstant(),9.0,1e-10);
// 
// 	firstPlane.SetEpsilon(1e-12);
// 
// 	ASSERT_APPROXIMATE(firstPlane.GetEpsilon(),1e-12,1e-12);
}

void Mathematics::PlaneTesting
	::CompareTest()
{
	DoubleAVector firstNormal(6.0,1.0,3.0);
	firstNormal.Normalize();

	DoublePlane firstPlane(firstNormal,-3.0);
	DoublePlane secondPlane(firstNormal,-13.0);

	ASSERT_TRUE(firstPlane == firstPlane);
	ASSERT_TRUE(secondPlane == secondPlane);
	ASSERT_FALSE(firstPlane == secondPlane);
	ASSERT_TRUE(firstPlane != secondPlane);
	ASSERT_TRUE(firstPlane < secondPlane);
	ASSERT_TRUE(firstPlane <= secondPlane);
	ASSERT_FALSE(firstPlane > secondPlane);
	ASSERT_FALSE(firstPlane >= secondPlane);

	ASSERT_TRUE(Approximate(firstPlane, firstPlane,1e-10)); 
	ASSERT_TRUE(Approximate(secondPlane, secondPlane)); 
	ASSERT_FALSE(Approximate(firstPlane, secondPlane)); 
}

void Mathematics::PlaneTesting
	::DistanceTest()
{
	default_random_engine generator{};
	uniform_real<float> randomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
 		DoubleAPoint firstPoint(randomDistribution(generator),
			               randomDistribution(generator),
						   randomDistribution(generator));

		DoubleAPoint secondPoint(randomDistribution(generator),
			                randomDistribution(generator),
							randomDistribution(generator) );

		DoubleAPoint thirdPoint(randomDistribution(generator),
			               randomDistribution(generator),
						   randomDistribution(generator) );

		DoublePlane plane(firstPoint,secondPoint,thirdPoint);

		ASSERT_APPROXIMATE(plane.DistanceTo(firstPoint),0.0,1e-10);
		ASSERT_APPROXIMATE(plane.DistanceTo(secondPoint),0.0,1e-10);
		ASSERT_APPROXIMATE(plane.DistanceTo(thirdPoint),0.0,1e-10);

		ASSERT_ENUM_EQUAL(plane.WhichSide(firstPoint),NumericalValueSymbol::Zero);
		ASSERT_ENUM_EQUAL(plane.WhichSide(secondPoint),NumericalValueSymbol::Zero);
		ASSERT_ENUM_EQUAL(plane.WhichSide(thirdPoint),NumericalValueSymbol::Zero);

		DoubleAPoint fourthPoint(randomDistribution(generator),
			                randomDistribution(generator),
						    randomDistribution(generator) );

		double distance = plane.DistanceTo(fourthPoint);
		double epsilon = plane.GetEpsilon();

		if(epsilon < distance)
			ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint),NumericalValueSymbol::Positive);
		else if(distance < epsilon)
			ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint),NumericalValueSymbol::Negative);
		else
			ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint),NumericalValueSymbol::Zero);
	}
}


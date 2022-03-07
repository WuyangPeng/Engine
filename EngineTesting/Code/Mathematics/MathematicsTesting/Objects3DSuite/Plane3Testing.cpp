// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:42)

#include "Plane3Testing.h"
#include "Mathematics/Objects3D/Plane3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Plane3<float>;
	template class Plane3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Plane3Testing) 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Plane3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
}

void Mathematics::Plane3Testing
	::ConstructionTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D normal(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		normal.Normalize();

		double constant(firstRandomDistribution(generator));

		Plane3D plane(normal,constant);

		ASSERT_TRUE(Vector3ToolsD::Approximate(normal,plane.GetNormal()));
		ASSERT_APPROXIMATE(constant,plane.GetConstant(),1e-10);

		Vector3D firstPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		Plane3D secondPlane(normal,firstPoint);

		constant = Vector3ToolsD::DotProduct(normal,firstPoint);

		ASSERT_TRUE(Vector3ToolsD::Approximate(normal,secondPlane.GetNormal()));
		ASSERT_APPROXIMATE(constant,secondPlane.GetConstant(),1e-10);

		Vector3D secondPoint(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		Vector3D thirdPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		Vector3D edge1 = secondPoint - firstPoint;
		Vector3D edge2 = thirdPoint - firstPoint;
		normal = Vector3ToolsD::UnitCrossProduct(edge1,edge2);
		constant = Vector3ToolsD::DotProduct(normal,firstPoint);

		Plane3D thirdPlane(firstPoint,secondPoint,thirdPoint);

		ASSERT_TRUE(Vector3ToolsD::Approximate(normal,thirdPlane.GetNormal()));
		ASSERT_APPROXIMATE(constant,thirdPlane.GetConstant(),1e-10);
	}		
}

void Mathematics::Plane3Testing
	::DistanceTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
 		Vector3D firstPoint(randomDistribution(generator),
			                 randomDistribution(generator),
						     randomDistribution(generator));

		Vector3D secondPoint(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator) );

		Vector3D thirdPoint(randomDistribution(generator),
			                 randomDistribution(generator),
						     randomDistribution(generator) );

		Plane3D plane(firstPoint,secondPoint,thirdPoint);

		ASSERT_APPROXIMATE(plane.DistanceTo(firstPoint),0.0,1e-10);
		ASSERT_APPROXIMATE(plane.DistanceTo(secondPoint),0.0,1e-10);
		ASSERT_APPROXIMATE(plane.DistanceTo(thirdPoint),0.0,1e-10);

		ASSERT_ENUM_EQUAL(plane.WhichSide(firstPoint),NumericalValueSymbol::Zero);
		ASSERT_ENUM_EQUAL(plane.WhichSide(secondPoint),NumericalValueSymbol::Zero);
		ASSERT_ENUM_EQUAL(plane.WhichSide(thirdPoint),NumericalValueSymbol::Zero);

		Vector3D fourthPoint(randomDistribution(generator),randomDistribution(generator),randomDistribution(generator));

		double distance = plane.DistanceTo(fourthPoint);

		if(MathD::GetZeroTolerance() < distance)
			ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint),NumericalValueSymbol::Positive);
		else if(distance < MathD::GetZeroTolerance())
			ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint),NumericalValueSymbol::Negative);
		else
			ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint),NumericalValueSymbol::Zero);
	}
}


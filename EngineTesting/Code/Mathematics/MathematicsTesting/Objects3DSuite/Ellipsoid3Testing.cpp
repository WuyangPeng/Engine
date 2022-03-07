// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/22 17:18)

#include "Ellipsoid3Testing.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Ellipsoid3<float>;
	template class Ellipsoid3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Ellipsoid3Testing) 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Ellipsoid3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::Ellipsoid3Testing
	::ConstructionTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };
	uniform_real<double> secondRandomDistribution(1.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		Vector3D axis0(firstRandomDistribution(generator),
			            firstRandomDistribution(generator),
			            firstRandomDistribution(generator));

		axis0.Normalize();

		Vector3D axis1(firstRandomDistribution(generator),
			            firstRandomDistribution(generator),
			            firstRandomDistribution(generator));

		axis1.Normalize();

		Vector3D axis2(firstRandomDistribution(generator),
			            firstRandomDistribution(generator),
			            firstRandomDistribution(generator));

		axis2.Normalize();

		double extent0(MathD::FAbs(secondRandomDistribution(generator)));
		double extent1(MathD::FAbs(secondRandomDistribution(generator)));
		double extent2(MathD::FAbs(secondRandomDistribution(generator)));

		Ellipsoid3D firstEllipsoid3(center,axis0,axis1,axis2,extent0,extent1,extent2);

		ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetCenter(),center));

		ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetAxis0(),axis0));
		ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetAxis1(),axis1));
		ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetAxis2(),axis2));
		ASSERT_APPROXIMATE(firstEllipsoid3.GetExtent0(),extent0,1e-10);
		ASSERT_APPROXIMATE(firstEllipsoid3.GetExtent1(),extent1,1e-10);
		ASSERT_APPROXIMATE(firstEllipsoid3.GetExtent2(),extent2,1e-10);

		auto matrix = firstEllipsoid3.GetMatrix();

		if (MathD::FAbs(matrix.Determinant()) <= 1e-8)
			continue;

		Ellipsoid3CoefficientsD firstEllipsoid3Coefficients = firstEllipsoid3.ToCoefficients();

		Ellipsoid3D secondEllipsoid3(firstEllipsoid3Coefficients,1e-10);
		
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetCenter(),center,1e-8f)); 

		center = secondEllipsoid3.GetCenter();
		axis0 = secondEllipsoid3.GetAxis0();
		axis1 = secondEllipsoid3.GetAxis1();
		axis2 = secondEllipsoid3.GetAxis2();
		extent0 = secondEllipsoid3.GetExtent0();
		extent1 = secondEllipsoid3.GetExtent1();
		extent2 = secondEllipsoid3.GetExtent2();

		Ellipsoid3D thirdEllipsoid3(center,axis0,axis1,axis2,extent0,extent1,extent2);

		ASSERT_TRUE(Approximate(secondEllipsoid3.ToCoefficients(),thirdEllipsoid3.ToCoefficients(),1e-10));

		secondEllipsoid3.FromCoefficients(thirdEllipsoid3.ToCoefficients(),1e-10);
		
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetCenter(),thirdEllipsoid3.GetCenter(),1e-9));

		ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetAxis0(),thirdEllipsoid3.GetAxis0(),1e-10));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetAxis1(),thirdEllipsoid3.GetAxis1(),1e-10));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetAxis2(),thirdEllipsoid3.GetAxis2(),1e-10));
		ASSERT_APPROXIMATE(secondEllipsoid3.GetExtent0(),thirdEllipsoid3.GetExtent0(),1e-5);
		ASSERT_APPROXIMATE(secondEllipsoid3.GetExtent1(),thirdEllipsoid3.GetExtent1(),1e-7);	
		ASSERT_APPROXIMATE(secondEllipsoid3.GetExtent2(),thirdEllipsoid3.GetExtent2(),1e-8f);		
	}
}

void Mathematics::Ellipsoid3Testing
	::CalculateTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -50.0,50.0 };
	uniform_real<double> secondRandomDistribution(1.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
			             firstRandomDistribution(generator));

		Vector3D axis0(firstRandomDistribution(generator),
			            firstRandomDistribution(generator),
			             firstRandomDistribution(generator));

		axis0.Normalize();

		Vector3D axis1(firstRandomDistribution(generator),
			            firstRandomDistribution(generator),
			             firstRandomDistribution(generator));

		axis1.Normalize();

		Vector3D axis2(firstRandomDistribution(generator),
			            firstRandomDistribution(generator),
			            firstRandomDistribution(generator));

		axis2.Normalize();

		double extent0(MathD::FAbs(secondRandomDistribution(generator)));
		double extent1(MathD::FAbs(secondRandomDistribution(generator)));
		double extent2(MathD::FAbs(secondRandomDistribution(generator)));

		Ellipsoid3D firstEllipse2(center,axis0,axis1,axis2,extent0,extent1,extent2);	

		auto matrix = firstEllipse2.GetMatrix();

		if (MathD::FAbs(matrix.Determinant()) <= 1e-8)
			continue;

		Ellipsoid3CoefficientsD firstEllipse2Coefficients =	firstEllipse2.ToCoefficients();

		Ellipsoid3D secondEllipse2(firstEllipse2Coefficients,1e-10);

		firstEllipse2.FromCoefficients(secondEllipse2.ToCoefficients(),1e-10);
		
		// 测试firstEllipse2和secondEllipse2计算相等性

		Matrix3D firstMatrix = firstEllipse2.GetMatrix();
		Matrix3D secondMatrix = secondEllipse2.GetMatrix();
		Matrix3D thirdMatrix = Matrix3D(firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0(), 
										firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0()) + 
								Matrix3D(firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1(), 
										firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1()) +
								Matrix3D(firstEllipse2.GetAxis2() / firstEllipse2.GetExtent2(), 
										firstEllipse2.GetAxis2() / firstEllipse2.GetExtent2());

		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix,1e-7)); 
		ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix,1e-10)); 

		firstMatrix = firstEllipse2.GetMatrixInverse();
		secondMatrix = secondEllipse2.GetMatrixInverse();
		thirdMatrix = Matrix3D(firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0(), 
							   firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0()) + 
					  Matrix3D(firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1(), 
							   firstEllipse2.GetAxis1() *  firstEllipse2.GetExtent1())+
					  Matrix3D(firstEllipse2.GetAxis2() *  firstEllipse2.GetExtent2(), 
							   firstEllipse2.GetAxis2() * firstEllipse2.GetExtent2());;

		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix,1e-3));
		ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix,1e-10)); 	
 
		Vector3D point(firstRandomDistribution(generator),
			            firstRandomDistribution(generator),
			            firstRandomDistribution(generator));
			
		Vector3D diff = point - firstEllipse2.GetCenter();
		double ratio0 = Vector3ToolsD::DotProduct(firstEllipse2.GetAxis0(),diff) /  firstEllipse2.GetExtent0();
		double ratio1 = Vector3ToolsD::DotProduct(firstEllipse2.GetAxis1(),diff) /  firstEllipse2.GetExtent1();
		double ratio2 = Vector3ToolsD::DotProduct(firstEllipse2.GetAxis2(),diff) /  firstEllipse2.GetExtent2();
		double evaluate = ratio0 * ratio0 + ratio1 * ratio1 + ratio2 * ratio2 - 1.0;
		
		ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), secondEllipse2.Evaluate(point),1e-3);
			
		ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), evaluate, 1e-10);

		ASSERT_EQUAL(firstEllipse2.Contains(point), secondEllipse2.Contains(point));

		ASSERT_EQUAL(firstEllipse2.Contains(point), evaluate <= 0.0);	 
	}
}


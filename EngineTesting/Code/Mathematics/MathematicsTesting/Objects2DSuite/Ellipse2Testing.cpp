// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/22 14:16)

#include "Ellipse2Testing.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Ellipse2<float>;
	template class Ellipse2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Ellipse2Testing) 

void Mathematics::Ellipse2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::Ellipse2Testing
	::ConstructionTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };
	uniform_real<double> secondRandomDistribution(1.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D center(firstRandomDistribution(generator), firstRandomDistribution(generator));

		DoubleVector2D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));

		axis0.Normalize();

		DoubleVector2D axis1(firstRandomDistribution(generator), firstRandomDistribution(generator));

		axis1.Normalize();

		double extent0(DoubleMath::FAbs(secondRandomDistribution(generator)));
		double extent1(DoubleMath::FAbs(secondRandomDistribution(generator)));

		DoubleEllipse2 firstEllipse2(center, axis0, axis1, extent0, extent1);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstEllipse2.GetCenter(), center));

		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstEllipse2.GetAxis0(), axis0));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstEllipse2.GetAxis1(), axis1));
		ASSERT_APPROXIMATE(firstEllipse2.GetExtent0(), extent0, 1e-10);
		ASSERT_APPROXIMATE(firstEllipse2.GetExtent1(), extent1, 1e-10);		

		auto matrix = firstEllipse2.GetMatrix();

		if(DoubleMath::FAbs(matrix.Determinant()) <= 1e-8)
			continue;

		DoubleEllipse2Coefficients firstEllipse2Coefficients = firstEllipse2.ToCoefficients();

		DoubleEllipse2 secondEllipse2(firstEllipse2Coefficients);

		center = secondEllipse2.GetCenter();
		axis0 = secondEllipse2.GetAxis0();
		axis1 = secondEllipse2.GetAxis1();
		extent0 = secondEllipse2.GetExtent0();
		extent1 = secondEllipse2.GetExtent1();

		DoubleEllipse2 thirdEllipse2(center, axis0, axis1, extent0, extent1);

		ASSERT_TRUE(Approximate(secondEllipse2.ToCoefficients(), thirdEllipse2.ToCoefficients(), 1e-10));

		secondEllipse2.FromCoefficients(thirdEllipse2.ToCoefficients());

		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondEllipse2.GetCenter(), thirdEllipse2.GetCenter()));

		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondEllipse2.GetAxis0(), thirdEllipse2.GetAxis0()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondEllipse2.GetAxis1(), thirdEllipse2.GetAxis1()));
		ASSERT_APPROXIMATE(secondEllipse2.GetExtent0(), thirdEllipse2.GetExtent0(), 1e-4f);
		ASSERT_APPROXIMATE(secondEllipse2.GetExtent1(), thirdEllipse2.GetExtent1(), 1e-7f);
	}
}

void Mathematics::Ellipse2Testing
	::CalculateTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };
	uniform_real<double> secondRandomDistribution(1.0, 10.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D center(firstRandomDistribution(generator), firstRandomDistribution(generator));

		DoubleVector2D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));

		axis0.Normalize();

		DoubleVector2D axis1(firstRandomDistribution(generator), firstRandomDistribution(generator));

		axis1.Normalize();

		double extent0(DoubleMath::FAbs(secondRandomDistribution(generator)));
		double extent1(DoubleMath::FAbs(secondRandomDistribution(generator)));

		DoubleEllipse2 firstEllipse2(center, axis0, axis1, extent0, extent1);

		auto matrix = firstEllipse2.GetMatrix();

		if (DoubleMath::FAbs(matrix.Determinant()) <= 1e-8)
			continue;

		DoubleEllipse2Coefficients firstEllipse2Coefficients = firstEllipse2.ToCoefficients();

		DoubleEllipse2 secondEllipse2(firstEllipse2Coefficients);

		firstEllipse2.FromCoefficients(secondEllipse2.ToCoefficients());

		// 测试firstEllipse2和secondEllipse2计算相等性
		DoubleMatrix2 firstMatrix = firstEllipse2.GetMatrix();
		DoubleMatrix2 secondMatrix = secondEllipse2.GetMatrix();
		DoubleMatrix2 thirdMatrix = DoubleMatrix2(firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0()) +
						       DoubleMatrix2(firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1());

		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-9));
		ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix, 1e-10));

		firstMatrix = firstEllipse2.GetMatrixInverse();
		secondMatrix = secondEllipse2.GetMatrixInverse();
		thirdMatrix = DoubleMatrix2(firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0()) +
					  DoubleMatrix2(firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1());

		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-3));
		ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix, 1e-10));

		DoubleVector2D point(firstRandomDistribution(generator), firstRandomDistribution(generator));

		DoubleVector2D diff = point - firstEllipse2.GetCenter();
		double ratio0 = DoubleVector2DTools::DotProduct(firstEllipse2.GetAxis0(), diff) / firstEllipse2.GetExtent0();
		double ratio1 = DoubleVector2DTools::DotProduct(firstEllipse2.GetAxis1(), diff) / firstEllipse2.GetExtent1();
		double evaluate = ratio0 * ratio0 + ratio1 * ratio1 - 1.0;

		ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), secondEllipse2.Evaluate(point), 1e-5);

		ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), evaluate, 1e-10);

		ASSERT_EQUAL(firstEllipse2.Contains(point), secondEllipse2.Contains(point));

		ASSERT_EQUAL(firstEllipse2.Contains(point), evaluate <= 1e-10);
	}
}


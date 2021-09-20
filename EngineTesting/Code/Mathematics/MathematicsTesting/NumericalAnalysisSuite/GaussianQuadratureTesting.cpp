// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.2 (2019/08/27 15:27)

#include "GaussianQuadratureTesting.h"
#include "Mathematics/NumericalAnalysis/GaussianQuadratureDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class GaussianQuadrature<float,GaussianQuadratureTesting>;
	template class GaussianQuadrature<double,GaussianQuadratureTesting>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,GaussianQuadratureTesting) 

void Mathematics::GaussianQuadratureTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ResultTest);
}

double Mathematics::GaussianQuadratureTesting
	::Solution(double input, const GaussianQuadratureTesting* userData)
{
	return input * userData->GetUserData() + 3;
}

double Mathematics::GaussianQuadratureTesting
	::GetUserData() const 
{
	return -5;
}

void Mathematics::GaussianQuadratureTesting
	::ResultTest() 
{
	const int degree = 5;
	const double root[degree]{ -0.9061798459,-0.5384693101,0.0,+0.5384693101,+0.9061798459	};
	const double coeff[degree] { 0.2369268850,0.4786286705,0.5688888889,0.4786286705, 0.2369268850 };

	double firstValue = 3.5;
	double secondValue = 1.5;
	
	double radius = (0.5) * (secondValue - firstValue);
	double center = (0.5) * (secondValue + firstValue);

	double result = 0.0;
	
	for (int i = 0; i < degree; ++i)
	{
		result += coeff[i] * Solution(radius * root[i] + center, this);
	}
	
	result *= radius;

	GaussianQuadrature<double, GaussianQuadratureTesting> gaussianQuadrature(firstValue, secondValue, Solution,this);

	ASSERT_APPROXIMATE(result, gaussianQuadrature.GetResult(), 1e-10);
}


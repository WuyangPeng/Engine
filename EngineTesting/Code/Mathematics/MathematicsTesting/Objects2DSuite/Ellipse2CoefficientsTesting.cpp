// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:15)

#include "Ellipse2CoefficientsTesting.h"
#include "Mathematics/Objects2D/Ellipse2CoefficientsDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Ellipse2Coefficients<float>;
	template class Ellipse2Coefficients<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Ellipse2CoefficientsTesting) 

void Mathematics::Ellipse2CoefficientsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(EllipseTest);
}

void Mathematics::Ellipse2CoefficientsTesting
	::EllipseTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator));

		DoubleMatrix2 firstMatrix(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 0.0,firstRandomDistribution(generator));

		firstMatrix(1,0) = firstMatrix(0,1);

		double constants(firstRandomDistribution(generator));
		
		DoubleEllipse2Coefficients ellipse2Coefficients(firstMatrix,firstVector,constants);

		DoubleMatrix2 secondMatrix = ellipse2Coefficients.GetMatrix();
		
		ASSERT_TRUE(Approximate(firstMatrix,secondMatrix,1e-10));		

		ASSERT_TRUE(DoubleVector2DTools::Approximate(ellipse2Coefficients.GetVector(), firstVector));

		ASSERT_APPROXIMATE(constants,ellipse2Coefficients.GetConstants(),1e-10);

		std::vector<double> coefficient = ellipse2Coefficients.GetCoefficients();

		DoubleEllipse2Coefficients secondEllipse2Coefficients(coefficient);

		std::vector<double> secondCoefficient =  secondEllipse2Coefficients.GetCoefficients();

		for(int m = 0;m < 6;++m)
		{
			ASSERT_APPROXIMATE(coefficient[m],secondCoefficient[m],1e-10);
		}

		firstVector = secondEllipse2Coefficients.GetVector();
		firstMatrix = secondEllipse2Coefficients.GetMatrix();
		constants = secondEllipse2Coefficients.GetConstants();

		DoubleEllipse2Coefficients  thirdEllipse2Coefficients(firstMatrix,firstVector,constants);

		secondMatrix = thirdEllipse2Coefficients.GetMatrix();
		
		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix,1e-10));

		ASSERT_TRUE(DoubleVector2DTools::Approximate(thirdEllipse2Coefficients.GetVector(),  firstVector,1e-10));

		ASSERT_APPROXIMATE(constants,thirdEllipse2Coefficients.GetConstants(),1e-10);

		coefficient = thirdEllipse2Coefficients.GetCoefficients();

		for(int m = 0;m < 6;++m)
		{
			ASSERT_APPROXIMATE(coefficient[m],secondCoefficient[m],1e-10);
		}

		ASSERT_TRUE(Approximate(secondEllipse2Coefficients, thirdEllipse2Coefficients, 1e-10));

	}
}


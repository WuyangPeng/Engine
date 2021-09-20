// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:29)

#include "PolynomialFit3Testing.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Approximation/PolynomialFit3Detail.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class PolynomialFit3<float>;
	template class PolynomialFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit3Testing) 

void Mathematics::PolynomialFit3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit3Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(0.0, 50.0);
	uniform_int<> secondRandomDistribution(5, 50); 
	uniform_int<> thirdRandomDistribution(1, 5);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<double> x;
		std::vector<double> y;
		std::vector<double> w;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			x.push_back(firstRandomDistribution(generator));
			y.push_back(firstRandomDistribution(generator));
			w.push_back(firstRandomDistribution(generator));
		}

		int xDegree = thirdRandomDistribution(generator);
		int yDegree = thirdRandomDistribution(generator);

		DoublePolynomialFit3 polynomialFit(x, y, w, xDegree, yDegree);

		if (polynomialFit.IsSolveSucceed())
		{
			vector<double> polynomial = polynomialFit.GetCoeff();

			for (int i = 0; i < size; ++i)
			{
				double sum = 0.0;
				for (int yIndex = 0; yIndex <= yDegree; ++yIndex)				
				{
					for (int xIndex = 0; xIndex <= xDegree; ++xIndex)
					{
						auto tempValue = xIndex + (xDegree + 1) * yIndex;
						sum += polynomial[tempValue] * DoubleMath::Pow(x[i], xIndex) * DoubleMath::Pow(y[i], yIndex);
					}
				}

				double value = sum - w[i];

				ASSERT_LESS_EQUAL(DoubleMath::FAbs(value) , 35.0);
			}
		}		
	}
}


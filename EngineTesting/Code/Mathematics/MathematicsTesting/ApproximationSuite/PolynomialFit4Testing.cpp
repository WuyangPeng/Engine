// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:44)

#include "PolynomialFit4Testing.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Approximation/PolynomialFit4Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class PolynomialFit4<float>;
	template class PolynomialFit4<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit4Testing) 

void Mathematics::PolynomialFit4Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit4Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(0.0, 50.0);
	uniform_int<> secondRandomDistribution(5, 40);
	uniform_int<> thirdRandomDistribution(1, 4);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<double> x;
		std::vector<double> y;
		std::vector<double> z;
		std::vector<double> w;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			x.push_back(firstRandomDistribution(generator));
			y.push_back(firstRandomDistribution(generator));
			z.push_back(firstRandomDistribution(generator));
			w.push_back(firstRandomDistribution(generator));
		}

		int xDegree = thirdRandomDistribution(generator);
		int yDegree = thirdRandomDistribution(generator);
		int zDegree = thirdRandomDistribution(generator);

		PolynomialFit4D polynomialFit(x, y,z, w, xDegree,yDegree,zDegree);

		if (polynomialFit.IsSolveSucceed())
		{
			vector<double> polynomial = polynomialFit.GetCoeff();

			for (int i = 0; i < size; ++i)
			{
				double sum = 0.0;
				for (int zIndex = 0; zIndex <= zDegree; ++zIndex)
				{
					for (int yIndex = 0; yIndex <= yDegree; ++yIndex)
					{
						for (int xIndex = 0; xIndex <= xDegree; ++xIndex)
						{						
							auto temp = xIndex + (xDegree + 1) * (yIndex + (yDegree + 1) * zIndex);
							sum += polynomial[temp] * MathD::Pow(x[i], xIndex) * MathD::Pow(y[i], yIndex) * MathD::Pow(z[i], zIndex);
						}
					}
				}

				double value = sum - w[i];

				ASSERT_LESS_EQUAL(MathD::FAbs(value) , 35.0);
			}
		}
	}
}


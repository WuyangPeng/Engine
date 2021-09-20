// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:25)

#include "PolynomialFit2PowersTesting.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Approximation/PolynomialFit2PowersDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class PolynomialFit2Powers<float>;
	template class PolynomialFit2Powers<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit2PowersTesting) 

void Mathematics::PolynomialFit2PowersTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit2PowersTesting
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(0.0, 50.0);
	uniform_int<> secondRandomDistribution(10, 50);
	uniform_int<> thirdRandomDistribution(3, 5);
	uniform_int<> fourthRandomDistribution(0, 7);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		vector<double> x;
		vector<double> w;
		vector<int> power;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			x.push_back(firstRandomDistribution(generator));
			w.push_back(firstRandomDistribution(generator));
		}

		int powSize = thirdRandomDistribution(generator);

		for (int i = 0; i < powSize; ++i)
		{
			power.push_back(fourthRandomDistribution(generator));
		}

		DoublePolynomialFit2Powers polynomialFit(x, w, power);

		if (polynomialFit.IsSolveSucceed())
		{			 
			for (int i = 0; i < size; ++i)
			{
				double value = polynomialFit(x[i]) - w[i];

				ASSERT_LESS_EQUAL(DoubleMath::FAbs(value) , 75.0);
			}
		}
	}
}


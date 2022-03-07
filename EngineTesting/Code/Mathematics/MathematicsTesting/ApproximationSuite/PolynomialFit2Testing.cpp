// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:27)

#include "PolynomialFit2Testing.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Approximation/PolynomialFit2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/PolynomialDetail.h"

using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26481)
namespace Mathematics
{
	template class PolynomialFit2<float>;
	template class PolynomialFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit2Testing) 

void Mathematics::PolynomialFit2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit2Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-50.0, 50.0);
	uniform_int<> secondRandomDistribution(10, 50);
	uniform_int<> thirdRandomDistribution(3, 10);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<double> x;
		std::vector<double> w;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			x.push_back(firstRandomDistribution(generator));
			w.push_back(firstRandomDistribution(generator));
		}

		PolynomialFit2D polynomialFit2(x, w, thirdRandomDistribution(generator));

		if (polynomialFit2.IsSolveSucceed())
		{
			PolynomialD polynomial = polynomialFit2.GetCoeff();

			for (int i = 0; i < size; ++i)
			{
				double value = polynomial(x[i]) - w[i];

				ASSERT_LESS_EQUAL(MathD::FAbs(value) , 75.0);
			}
		}		
	}
}


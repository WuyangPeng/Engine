// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:43)

#include "PolynomialFit4PowersTesting.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Approximation/PolynomialFit4PowersDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include <random> 

using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class PolynomialFit4Powers<float>;
	template class PolynomialFit4Powers<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit4PowersTesting) 

void Mathematics::PolynomialFit4PowersTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit4PowersTesting
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(0.0, 1.0);
	uniform_int<> secondRandomDistribution(2, 5);
	uniform_int<> thirdRandomDistribution(2, 3);
	uniform_int<> fourthRandomDistribution(0, 2);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<double> x;
		std::vector<double> y;
		std::vector<double> z;
		std::vector<double> w;
		int xSize = secondRandomDistribution(generator);
		int ySize = secondRandomDistribution(generator);
		int zSize = secondRandomDistribution(generator);

		for (int i = 0; i < xSize; ++i)
		{
			x.push_back(firstRandomDistribution(generator));		 
		}

		for (int i = 0; i < ySize; ++i)
		{
			y.push_back(firstRandomDistribution(generator));
		}

		for (int i = 0; i < zSize; ++i)
		{
			z.push_back(firstRandomDistribution(generator));
		}

		for (int i = 0; i < xSize * ySize * zSize; ++i)
		{
			w.push_back(firstRandomDistribution(generator));
		}

		int powSize = thirdRandomDistribution(generator);
		vector<CoreTools::Tuple<3,int> > power;

		for (int i = 0; i < powSize; ++i)
		{
			CoreTools::Tuple<3, int> tuple(fourthRandomDistribution(generator),
				                           fourthRandomDistribution(generator),
				                           fourthRandomDistribution(generator));
			power.push_back(tuple);
		}

		PolynomialFit4PowersD polynomialFit(x, y,z,w, power,true);

		if (polynomialFit.IsSolveSucceed())
		{
			for (int zIndex = 0; zIndex < zSize; ++zIndex)
			{
				for (int yIndex = 0; yIndex < ySize; ++yIndex)
				{
					for (int xIndex = 0; xIndex < xSize; ++xIndex)
					{
						auto temp = xIndex + (yIndex + zIndex * ySize) * xSize;
						double value = polynomialFit(x[xIndex], y[yIndex],z[zIndex]) - w[temp];

						ASSERT_LESS_EQUAL(MathD::FAbs(value) , 40000.0);
					}
				}
			}
		}

		 		
	}
}


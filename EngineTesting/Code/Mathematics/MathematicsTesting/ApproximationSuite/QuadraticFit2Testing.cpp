// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 14:34)

#include "QuadraticFit2Testing.h"
#include "Mathematics/Approximation/QuadraticFit2Detail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class QuadraticFit2<float>;
	template class QuadraticFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuadraticFit2Testing) 

void Mathematics::QuadraticFit2Testing
	::MainTest()
{
	 ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticFit2Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(3, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> vertices;
		int size = secondRandomDistribution(generator);

		for (int k = 0; k < size; ++k)
		{
			vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleQuadraticFit2 quadraticFit2(vertices);

		DoubleVariableLengthVector coeff = quadraticFit2.GetCoeff();
		double eigenValue = quadraticFit2.GetEigenValue();

		ASSERT_TRUE(0.0 <= eigenValue && eigenValue <= 1.0);

		ASSERT_TRUE(DoubleMath::FAbs(coeff.Length() - 1.0) <= DoubleMath::GetZeroTolerance());
		
		 
		for (int k = 0; k < size; ++k)
		{
			 double value = coeff[0] + coeff[1] * vertices[k].GetX() +
				            coeff[2] * vertices[k].GetY() +
							coeff[3] * vertices[k].GetX() * vertices[k].GetX() +
							coeff[4] * vertices[k].GetY() * vertices[k].GetY() +
							coeff[5] * vertices[k].GetX() * vertices[k].GetY(); 

			 if(eigenValue <= DoubleMath::GetZeroTolerance())
			 {
				 ASSERT_APPROXIMATE(value,0.0,1e-8);			 
			 }
			 else if (eigenValue <= 0.6)
			 {
				 ASSERT_TRUE(DoubleMath::FAbs(value) <= 1.2);
			 }
			 else if (eigenValue <= 1.0)
			 {
				 ASSERT_TRUE(DoubleMath::FAbs(value) <= 1.5);
			 }
			 
		}
	}
}


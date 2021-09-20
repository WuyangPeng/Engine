// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 14:34)

#include "QuadraticFit3Testing.h"
#include "Mathematics/Approximation/QuadraticFit3Detail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class QuadraticFit3<float>;
	template class QuadraticFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuadraticFit3Testing) 

void Mathematics::QuadraticFit3Testing
	::MainTest()
{
	 ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticFit3Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(3, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		
		std::vector<DoubleVector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int k = 0; k < size; ++k)
		{
			vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleQuadraticFit3 quadraticFit2(vertices);

		DoubleVariableLengthVector coeff = quadraticFit2.GetCoeff();
		double eigenValue = quadraticFit2.GetEigenValue();

		ASSERT_TRUE(0.0 <= eigenValue && eigenValue <= 1.0);

		ASSERT_TRUE(DoubleMath::FAbs(coeff.Length() - 1.0) <= DoubleMath::GetZeroTolerance());
		
		 
		for (int i = 0; i < size; ++i)
		{
			double value = coeff[0] + coeff[1] * vertices[i].GetX() +
				           coeff[2] * vertices[i].GetY() +
						   coeff[3] * vertices[i].GetZ() +
						   coeff[4] * vertices[i].GetX() * vertices[i].GetX() +
						   coeff[5] * vertices[i].GetY() * vertices[i].GetY() +
						   coeff[6] * vertices[i].GetZ() * vertices[i].GetZ() +
						   coeff[7] * vertices[i].GetX() * vertices[i].GetY() +
						   coeff[8] * vertices[i].GetX() * vertices[i].GetZ() +
						   coeff[9] * vertices[i].GetY() * vertices[i].GetZ();

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


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:26)

#include "BandedMatrixInvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/BandedMatrixInvertDetail.h"

#include <random> 

using std::vector;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class BandedMatrixInvert<float>;
	template class BandedMatrixInvert<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, BandedMatrixInvertTesting) 

void Mathematics::BandedMatrixInvertTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BandedTest);	
}
  
void Mathematics::BandedMatrixInvertTesting
	::BandedTest()
{
	default_random_engine generator;
	uniform_real<double> floatRandomDistribution(-100.0,100.0);
	uniform_int<>  integerRandomDistribution(4,10);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{ 
		int size = integerRandomDistribution(generator);

		DoubleBandedMatrix firstMatrix(size, size - 1,size - 2);
		
		auto diagonalBand = firstMatrix.GetDiagonalBand();
		for(int i = 0;i < firstMatrix.GetSize();++i)
		{
			diagonalBand[i] = floatRandomDistribution(generator);
		}

		for (int row = 0; row < firstMatrix.GetSize(); ++row)
		{
			for (int column = 0; column < firstMatrix.GetSize(); ++column)
			{
				int band = column - row;
				if (band < 0 && -band - 1 < firstMatrix.GetLowerBandsNumber())
				{
					firstMatrix(row, column) = floatRandomDistribution(generator);
				}
			}
		}

		for (int row = 0; row < firstMatrix.GetSize(); ++row)
		{
			for (int column = 0; column < firstMatrix.GetSize(); ++column)
			{
				int band = column - row;
				if (0 < band && band - 1 < firstMatrix.GetUpperBandsNumber())
				{
					firstMatrix(row, column) = floatRandomDistribution(generator);
				}
			}
		}
		 
		
		BandedMatrixInvert<double> invert(firstMatrix, 1e-10);
		
		DoubleVariableMatrix secondMatrix = invert.GetInvert();
		DoubleVariableMatrix thirdMatrix = firstMatrix.ToVariableMatrix() * secondMatrix;
		DoubleVariableMatrix fourthMatrix(size, size);

		for (int row = 0; row < fourthMatrix.GetRowsNumber(); ++row)
		{
			fourthMatrix(row, row) = 1.0;			
		}

		typedef bool(*VariableMatrixdApproximate)(const DoubleVariableMatrix& lhs,const DoubleVariableMatrix& rhs,const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdMatrix, fourthMatrix, 1e-10);
	}
}

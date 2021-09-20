// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 09:59)

#include "SolveBandedTesting.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SolveBandedTesting) 

void Mathematics::SolveBandedTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BandedTest);	
}
  
void Mathematics::SolveBandedTesting
	::BandedTest()
{
	default_random_engine generator;
	uniform_real<double> floatRandomDistribution(-100.0,100.0);
	uniform_int<>  integerRandomDistribution(4,10);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{ 
/*		int size = integerRandomDistribution(generator);*/

// 		DoubleBandedMatrix firstMatrix(size, size - 1,size - 2);
// 		
// 		double* diagonalBand = firstMatrix.GetDiagonalBand();
// 		for(int i = 0;i < firstMatrix.GetSize();++i)
// 		{
// 			diagonalBand[i] = floatRandomDistribution(generator);
// 		}
// 
// 		for (int row = 0; row < firstMatrix.GetSize(); ++row)
// 		{
// 			for (int column = 0; column < firstMatrix.GetSize(); ++column)
// 			{
// 				int band = column - row;
// 				if (band < 0 && -band - 1 < firstMatrix.GetLowerBandsNumber())
// 				{
// 					firstMatrix(row, column) = floatRandomDistribution(generator);
// 				}
// 			}
// 		}
// 
// 		for (int row = 0; row < firstMatrix.GetSize(); ++row)
// 		{
// 			for (int column = 0; column < firstMatrix.GetSize(); ++column)
// 			{
// 				int band = column - row;
// 				if (0 < band && band - 1 < firstMatrix.GetUpperBandsNumber())
// 				{
// 					firstMatrix(row, column) = floatRandomDistribution(generator);
// 				}
// 			}
// 		}
// 		vector<double> input(size);
// 
// 		for (int i = 0; i < size;++i)
// 		{
// 			input[i] = floatRandomDistribution(generator);
// 		}
// 		
// 		SolveBanded<double>	solveBanded(firstMatrix, &input[0], 1e-10);
// 		
// 		vector<double> output;
// 
// 		for (SolveBanded<double>::OutputConstIterator iter = solveBanded.GetBegin(),
// 			 end = solveBanded.GetEnd(); iter != end;++iter)
// 		{
// 			output.push_back(*iter);
// 		}
// 
// 		ASSERT_EQUAL(output.size(), input.size());
// 		DoubleVariableLengthVector firstVariableLengthVector(input);
// 		DoubleVariableLengthVector secondVariableLengthVector(output);
// 		DoubleVariableLengthVector thirdVariableLengthVector =
// 			firstMatrix.ToVariableMatrix() * secondVariableLengthVector;
// 		 
// 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs,const DoubleVariableLengthVector& rhs,const double epsilon);
// 
// 		VariableLengthVectordApproximate function = Approximate<double>;
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8); 
	}
}

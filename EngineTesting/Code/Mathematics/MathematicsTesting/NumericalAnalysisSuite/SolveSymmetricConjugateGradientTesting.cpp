// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:00)

#include "SolveSymmetricConjugateGradientTesting.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SolveSymmetricConjugateGradientTesting) 

void Mathematics::SolveSymmetricConjugateGradientTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(VariableMatrixTest);	
	ASSERT_NOT_THROW_EXCEPTION_0(SparseMatrixTest);
}
  
void Mathematics::SolveSymmetricConjugateGradientTesting
	::VariableMatrixTest()
{
// 	default_random_engine generator;
// 	uniform_real<double> floatRandomDistribution(-100.0,100.0);
// 	uniform_int<>  integerRandomDistribution(1,10);
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{ 
// 		int size = integerRandomDistribution(generator);
// 
// 		DoubleVariableMatrix firstMatrix(size,size);
// 		
// 		for(int row = 0;row < firstMatrix.GetRowsNumber();++row)
// 		{
// 			for(int column = 0;column < firstMatrix.GetColumnsNumber();++column)
// 			{
// 				firstMatrix(row,column) = floatRandomDistribution(generator);
// 			}
// 		}
// 
// 		for (int row = 0; row < firstMatrix.GetRowsNumber(); ++row)
// 		{
// 			for (int column = 0; column < firstMatrix.GetColumnsNumber();++column)
// 			{
// 				if (row < column)
// 					firstMatrix(row, column) = firstMatrix(column, row);
// 			}
// 		}
// 
// 		vector<double> input(size);
// 
// 		for (int i = 0; i < size;++i)
// 		{
// 			input[i] = floatRandomDistribution(generator);
// 		}
// 		
// 		SolveSymmetricConjugateGradient<double, VariableMatrix>	solveSymmetricConjugateGradient(firstMatrix, &input[0], 1e-10 );
// 		
// 		vector<double> output;
// 
// 		for (SolveSymmetricConjugateGradient<double, VariableMatrix>::OutputConstIterator iter = solveSymmetricConjugateGradient.GetBegin(),
// 			 end = solveSymmetricConjugateGradient.GetEnd(); iter != end;++iter)
// 		{
// 			output.push_back(*iter);
// 		}
// 
// 		ASSERT_EQUAL(output.size(), input.size());
// 		DoubleVariableLengthVector firstVariableLengthVector(input);
// 		DoubleVariableLengthVector secondVariableLengthVector(output);
// 		DoubleVariableLengthVector thirdVariableLengthVector = firstMatrix * secondVariableLengthVector;
// 		 
// 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs, const DoubleVariableLengthVector& rhs,const double epsilon);
// 
// 		VariableLengthVectordApproximate function = Approximate<double>;
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8); 
// 	}
}

void Mathematics::SolveSymmetricConjugateGradientTesting
	::SparseMatrixTest()
{
// 	default_random_engine generator;
// 	uniform_real<double> floatRandomDistribution(-100.0,100.0);
// 	uniform_int<>  integerRandomDistribution(1,10);
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{ 
// 		int size = integerRandomDistribution(generator);
// 
// 		DoubleSparseMatrix firstMatrix(size, size);
// 		
// 		for(int row = 0;row < firstMatrix.GetRowsNumber();++row)
// 		{
// 			for(int column = 0;column < firstMatrix.GetColumnsNumber();++column)
// 			{
// 				firstMatrix(row,column) = floatRandomDistribution(generator);
// 			}
// 		}
// 
// 		vector<double> input(size);
// 
// 		for (int i = 0; i < size;++i)
// 		{
// 			input[i] = floatRandomDistribution(generator);
// 		}
// 		
// 		SolveSymmetricConjugateGradient<double, SparseMatrix> solveSymmetricConjugateGradient(firstMatrix, &input[0], 1e-10 );
// 		
// 		vector<double> output;
// 
// 		for (SolveSymmetricConjugateGradient<double, SparseMatrix>::OutputConstIterator iter = solveSymmetricConjugateGradient.GetBegin(),
// 			 end = solveSymmetricConjugateGradient.GetEnd(); iter != end;++iter)
// 		{
// 			output.push_back(*iter);
// 		}
// 
// 		ASSERT_EQUAL(output.size(), input.size());
// 		DoubleVariableLengthVector firstVariableLengthVector(input);
// 		DoubleVariableLengthVector secondVariableLengthVector(output);
// 		DoubleVariableLengthVector thirdVariableLengthVector =
// 			firstMatrix * secondVariableLengthVector;
// 		 
// 		typedef bool(*VariableLengthVectordApproximate)(const DoubleVariableLengthVector& lhs,const DoubleVariableLengthVector& rhs,const double epsilon);
// 
// 		VariableLengthVectordApproximate function = Approximate<double>;
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdVariableLengthVector, firstVariableLengthVector, 1e-8); 
// 	}
}


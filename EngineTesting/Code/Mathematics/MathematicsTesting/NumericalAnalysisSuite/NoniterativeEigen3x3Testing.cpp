// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:13)

#include "NoniterativeEigen3x3Testing.h"
#include "Mathematics/NumericalAnalysis/NoniterativeEigen3x3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class NoniterativeEigen3x3<float>;
	template class NoniterativeEigen3x3<double>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, NoniterativeEigen3x3Testing) 

void Mathematics::NoniterativeEigen3x3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(EigenTest);
}

void Mathematics::NoniterativeEigen3x3Testing
	::EigenTest()
{
	default_random_engine generator;
	uniform_real<double> randomDistribution(-1.0e2, 1.0e2); 
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleMatrix3 firstMatrix(randomDistribution(generator),
			                 randomDistribution(generator),	
							 randomDistribution(generator),		
			                 0.0,
							 randomDistribution(generator),
							 randomDistribution(generator),	
							 0.0,
							 0.0,	
							 randomDistribution(generator)); 

		firstMatrix(1,0) = firstMatrix(0,1);
		firstMatrix(2,0) = firstMatrix(0,2);
		firstMatrix(2,1) = firstMatrix(1,2);	

		DoubleNoniterativeEigen3x3 eigenDecomposition(firstMatrix);		 

		DoubleMatrix3 rotation(eigenDecomposition.GetEigenvector(0),
			              eigenDecomposition.GetEigenvector(1),
						  eigenDecomposition.GetEigenvector(2),
						  MatrixMajorFlags::Column);
		DoubleMatrix3 diagonal(eigenDecomposition.GetEigenvalue(0),
			              eigenDecomposition.GetEigenvalue(1),
			              eigenDecomposition.GetEigenvalue(2));

		DoubleMatrix3 secondMatrix = rotation * diagonal * rotation.Transpose();

		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix,1e-8));			
	}
}



// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 15:56)

#include "Matrix3EigenDecompositionTesting.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix3EigenDecompositionDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Matrix3EigenDecomposition<float>;
	template class Matrix3EigenDecomposition<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Matrix3EigenDecompositionTesting) 

void Mathematics::Matrix3EigenDecompositionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(EigenDecompositionTest); 
}

void Mathematics::Matrix3EigenDecompositionTesting
	::EigenDecompositionTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -10.0,10.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)	
	{
		DoubleMatrix3 firstMatrix{ randomDistribution(generator),randomDistribution(generator),randomDistribution(generator),
							  0.0,randomDistribution(generator),randomDistribution(generator),
							  0.0,0.0,randomDistribution(generator) };

		firstMatrix(1,0) = firstMatrix(0,1);
		firstMatrix(2,0) = firstMatrix(0,2);
		firstMatrix(2,1) = firstMatrix(1,2);

		auto eigenDecomposition = firstMatrix.EigenDecomposition(1e-10);

		DoubleMatrix3 rotation = eigenDecomposition.GetRotation();
		DoubleMatrix3 diagonal = eigenDecomposition.GetDiagonal();

		DoubleMatrix3 secondMatrix = rotation * diagonal * rotation.Transpose();

		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix,1e-10));	
	}	
}


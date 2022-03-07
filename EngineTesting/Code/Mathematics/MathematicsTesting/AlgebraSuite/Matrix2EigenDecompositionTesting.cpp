// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 15:34)

#include "Matrix2EigenDecompositionTesting.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Matrix2EigenDecompositionDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
namespace Mathematics
{
	template class Matrix2EigenDecomposition<float>;
	template class Matrix2EigenDecomposition<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Matrix2EigenDecompositionTesting) 

void Mathematics::Matrix2EigenDecompositionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(EigenDecompositionTest); 
}

void Mathematics::Matrix2EigenDecompositionTesting
	::EigenDecompositionTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -10.0,10.0 }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Matrix2D firstMatrix(randomDistribution(generator),randomDistribution(generator), 0.0, randomDistribution(generator)); 

		firstMatrix(1,0) = firstMatrix(0,1);

		auto eigenDecomposition = firstMatrix.EigenDecomposition(1e-10);

		auto rotation = eigenDecomposition.GetRotation();
		auto diagonal = eigenDecomposition.GetDiagonal();

		auto secondMatrix = rotation * diagonal * rotation.Transpose();

		ASSERT_TRUE(Approximate(firstMatrix, secondMatrix,1e-10)); 	
	}	

}


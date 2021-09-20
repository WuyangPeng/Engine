// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 09:56)

#include "SingularValueDecompositionTesting.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/SingularValueDecompositionDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class SingularValueDecomposition<float>;
	template class SingularValueDecomposition<double>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SingularValueDecompositionTesting) 

void Mathematics::SingularValueDecompositionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
}

void Mathematics::SingularValueDecompositionTesting
	::SingularValueTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5); 
	uniform_int<> secondRandomDistribution(2,10);
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		int row = secondRandomDistribution(generator);
		int colomn = secondRandomDistribution(generator);

		if (row < colomn) 
		{
			swap(row, colomn);
		}

		DoubleVariableMatrix matrix(row, colomn);

		for (int m = 0; m < row;++m)
		{
			for (int j = 0; j < colomn;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}

		DoubleSingularValueDecomposition singularValueDecomposition(matrix);

		DoubleVariableMatrix leftMatrix = singularValueDecomposition.GetLeftMatrix();
		DoubleVariableMatrix diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
		DoubleVariableMatrix rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

		DoubleVariableMatrix result = leftMatrix * diagonalMatrix;
		result *= rightTransposeMatrix;

		typedef bool(*VariableMatrixdApproximate)(const DoubleVariableMatrix& lhs,const DoubleVariableMatrix& rhs, const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-6);
	}
}


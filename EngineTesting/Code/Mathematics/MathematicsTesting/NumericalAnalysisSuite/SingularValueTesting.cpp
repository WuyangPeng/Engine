// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 09:57)

#include "SingularValueTesting.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/SingularValueDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class SingularValue<float>;
	template class SingularValue<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SingularValueTesting) 

void Mathematics::SingularValueTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
}

void Mathematics::SingularValueTesting
	::SingularValueTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5); 
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleMatrix3 matrix;

		for (int m = 0; m < 3;++m)
		{
			for (int j = 0; j < 3;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}

		DoubleSingularValue singularValueDecomposition(matrix);

		DoubleMatrix3 leftMatrix = singularValueDecomposition.GetLeftMatrix();
		DoubleMatrix3 diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
		DoubleMatrix3 rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

		DoubleMatrix3 result = leftMatrix * diagonalMatrix;
		result *= rightTransposeMatrix;

		typedef bool(*VariableMatrixdApproximate)(const DoubleMatrix3& lhs,const DoubleMatrix3& rhs, const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-6);
	}
}


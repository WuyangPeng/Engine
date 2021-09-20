// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 09:55)

#include "QDUDecompositionValueTesting.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/QDUDecompositionValueDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class QDUDecompositionValue<float>;
	template class QDUDecompositionValue<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QDUDecompositionValueTesting) 

void Mathematics::QDUDecompositionValueTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(QDUDecompositionValueTest);
}

void Mathematics::QDUDecompositionValueTesting
	::QDUDecompositionValueTest()
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

		DoubleQDUDecompositionValue qDUDecompositionValue(matrix);

		DoubleMatrix3 orthogonalMatrix = qDUDecompositionValue.GeOrthogonalMatrix();
		DoubleMatrix3 diagonalMatrix = qDUDecompositionValue.GetDiagonalMatrix();
		DoubleMatrix3 upperTriangularMatrix = qDUDecompositionValue.GetUpperTriangularMatrix();

		DoubleMatrix3 result = orthogonalMatrix * diagonalMatrix;
		result *= upperTriangularMatrix;

		typedef bool(*VariableMatrixdApproximate)(const DoubleMatrix3& lhs,const DoubleMatrix3& rhs,const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-5);
	}
}


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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
		Matrix3D matrix;

		for (int m = 0; m < 3;++m)
		{
			for (int j = 0; j < 3;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}

		QDUDecompositionValueD qDUDecompositionValue(matrix);

		Matrix3D orthogonalMatrix = qDUDecompositionValue.GeOrthogonalMatrix();
		Matrix3D diagonalMatrix = qDUDecompositionValue.GetDiagonalMatrix();
		Matrix3D upperTriangularMatrix = qDUDecompositionValue.GetUpperTriangularMatrix();

		Matrix3D result = orthogonalMatrix * diagonalMatrix;
		result *= upperTriangularMatrix;

		typedef bool(*VariableMatrixdApproximate)(const Matrix3D& lhs,const Matrix3D& rhs,const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-5);
	}
}


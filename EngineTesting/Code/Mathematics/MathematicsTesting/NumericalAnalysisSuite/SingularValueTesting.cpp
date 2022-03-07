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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
		Matrix3D matrix;

		for (int m = 0; m < 3;++m)
		{
			for (int j = 0; j < 3;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}

		SingularValueD singularValueDecomposition(matrix);

		Matrix3D leftMatrix = singularValueDecomposition.GetLeftMatrix();
		Matrix3D diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
		Matrix3D rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

		Matrix3D result = leftMatrix * diagonalMatrix;
		result *= rightTransposeMatrix;

		typedef bool(*VariableMatrixdApproximate)(const Matrix3D& lhs,const Matrix3D& rhs, const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-6);
	}
}

